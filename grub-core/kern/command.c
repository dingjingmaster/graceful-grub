#include <grub/lockdown.h>
#include <grub/mm.h>
#include <grub/command.h>

grub_command_t grub_command_list;

grub_command_t grub_register_command_prio (const char *name, grub_command_func_t func, const char *summary, const char *description, int prio)
{
    grub_command_t cmd;
    int inactive = 0;

    grub_command_t *p, q;

    cmd = (grub_command_t) grub_zalloc (sizeof (*cmd));
    if (!cmd)
        return 0;

    cmd->name = name;
    cmd->func = func;
    cmd->summary = (summary) ? summary : "";
    cmd->description = description;

    cmd->flags = 0;
    cmd->prio = prio;
    
    for (p = &grub_command_list, q = *p; q; p = &(q->next), q = q->next) {
        int r;

        r = grub_strcmp (cmd->name, q->name);
        if (r < 0)
	        break;
        if (r > 0)
	        continue;

        if (cmd->prio >= (q->prio & GRUB_COMMAND_PRIO_MASK)) {
	        q->prio &= ~GRUB_COMMAND_FLAG_ACTIVE;
	        break;
	    }

        inactive = 1;
    }

    *p = cmd;
    cmd->next = q;
    if (q)
        q->prev = &cmd->next;
    cmd->prev = p;

    if (! inactive)
        cmd->prio |= GRUB_COMMAND_FLAG_ACTIVE;

    return cmd;
}

static grub_err_t grub_cmd_lockdown (grub_command_t cmd __attribute__ ((unused)), int argc __attribute__ ((unused)), char **argv __attribute__ ((unused)))

{
    return grub_error (GRUB_ERR_ACCESS_DENIED, N_("%s: the command is not allowed when lockdown is enforced"), cmd->name);
}

grub_command_t grub_register_command_lockdown (const char *name, grub_command_func_t func, const char *summary, const char *description)
{
    if (grub_is_lockdown () == GRUB_LOCKDOWN_ENABLED)
        func = grub_cmd_lockdown;

    return grub_register_command_prio (name, func, summary, description, 0);
}

void grub_unregister_command (grub_command_t cmd)
{
    if ((cmd->prio & GRUB_COMMAND_FLAG_ACTIVE) && (cmd->next))
        cmd->next->prio |= GRUB_COMMAND_FLAG_ACTIVE;

    grub_list_remove (GRUB_AS_LIST (cmd));
    grub_free (cmd);
}
