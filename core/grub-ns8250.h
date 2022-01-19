#ifndef GRUB_NS8250_H
#define GRUB_NS8250_H

/* Macros.  */

/* The offsets of UART registers.  */
#define UART_TX		0
#define UART_RX		0
#define UART_DLL	0
#define UART_IER	1
#define UART_DLH	1
#define UART_IIR	2
#define UART_FCR	2
#define UART_LCR	3
#define UART_MCR	4
#define UART_LSR	5
#define UART_MSR	6
#define UART_SR		7

/* For LSR bits.  */
#define UART_DATA_READY		0x01
#define UART_EMPTY_TRANSMITTER	0x20

/* The type of parity.  */
#define UART_NO_PARITY		0x00
#define UART_ODD_PARITY		0x08
#define UART_EVEN_PARITY	0x18

/* The type of word length.  */
#define UART_5BITS_WORD	0x00
#define UART_6BITS_WORD	0x01
#define UART_7BITS_WORD	0x02
#define UART_8BITS_WORD	0x03

/* The type of the length of stop bit.  */
#define UART_1_STOP_BIT		0x00
#define UART_2_STOP_BITS	0x04

/* the switch of DLAB.  */
#define UART_DLAB	0x80

/* Enable the FIFO.  */
#define UART_ENABLE_FIFO_TRIGGER14	0xC7

/* Enable the FIFO.  */
#define UART_ENABLE_FIFO_TRIGGER1       0x07

/* Turn on DTR, RTS, and OUT2.  */
#define UART_ENABLE_DTRRTS	0x03

/* Turn on DTR, RTS, and OUT2.  */
#define UART_ENABLE_OUT2	0x08

#ifndef ASM_FILE
#include <grub/cpu/io.h>

grub_port_t
grub_ns8250_hw_get_port (const unsigned int unit);
#endif

#endif /* ! GRUB_SERIAL_MACHINE_HEADER */
