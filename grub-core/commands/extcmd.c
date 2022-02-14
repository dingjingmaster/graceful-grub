#include <grub/mm.h>
#include <grub/list.h>
#include <grub/lockdown.h>
#include <grub/misc.h>
#include <grub/extcmd.h>
#include <grub/script_sh.h>
#include <grub/dl.h>

GRUB_MOD_LICENSE ("GPLv3+");

grub_err_t grub_extcmd_dispatcher (struct grub_command *cmd, int argc, char **args, struct grub_script *script)
{
    int new_argc;
    char **new_args;
    struct grub_arg_list *state;
    struct grub_extcmd_context context;
    grub_err_t ret;
    grub_extcmd_t ext = cmd->data;

    context.state = 0;
    context.extcmd = ext;
    context.script = script;

    if (!ext->options) {
        ret = (ext->func) (&context, argc, args);
        return ret;
    }

    state = grub_arg_list_alloc (ext, argc, args);
    if (grub_arg_parse (ext, argc, args, state, &new_args, &new_argc)) {
        context.state = state;
        ret = (ext->func) (&context, new_argc, new_args);
        grub_free (new_args);
        grub_free (state);
        return ret;
    }
    grub_free (state);

    return grub_errno;
}

static grub_err_t grub_extcmd_dispatch (struct grub_command *cmd, int argc, char **args)
{
    return grub_extcmd_dispatcher (cmd, argc, args, 0);
}

grub_extcmd_t grub_register_extcmd_prio (const char *name, grub_extcmd_func_t func, grub_command_flags_t flags, const char *summary,
			   const char *description, const struct grub_arg_option *parser, int prio)
{
    grub_extcmd_t ext;
    grub_command_t cmd;

    ext = (grub_extcmd_t) grub_malloc (sizeof (*ext));
    if (! ext)
        return 0;

    cmd = grub_register_command_prio (name, grub_extcmd_dispatch, summary, description, prio);
    if (! cmd) {
        grub_free (ext);
        return 0;
    }

    cmd->flags = (flags | GRUB_COMMAND_FLAG_EXTCMD);
    cmd->data = ext;

    ext->cmd = cmd;
    ext->func = func;
    ext->options = parser;
    ext->data = 0;

    return ext;
}

grub_extcmd_t grub_register_extcmd (const char *name, grub_extcmd_func_t func,
		      grub_command_flags_t flags, const char *summary, const char *description,
		      const struct grub_arg_option *parser)
{
    return grub_register_extcmd_prio (name, func, flags, summary, description, parser, 1);
}

static grub_err_t grub_extcmd_lockdown (grub_extcmd_context_t ctxt __attribute__ ((unused)),
                      int argc __attribute__ ((unused)), char **argv __attribute__ ((unused)))
{
    return grub_error (GRUB_ERR_ACCESS_DENIED,
                       N_("%s: the command is not allowed when lockdown is enforced"), ctxt->extcmd->cmd->name);
}

grub_extcmd_t grub_register_extcmd_lockdown (const char *name, grub_extcmd_func_t func,
                               grub_command_flags_t flags, const char *summary, const char *description, const struct grub_arg_option *parser)
{
    if (grub_is_lockdown () == GRUB_LOCKDOWN_ENABLED)
        func = grub_extcmd_lockdown;

    return grub_register_extcmd (name, func, flags, summary, description, parser);
}

void grub_unregister_extcmd (grub_extcmd_t ext)
{
    grub_unregister_command (ext->cmd);
    grub_free (ext);
}
