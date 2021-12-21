MEMORY
{
	/* FLASH RAM Section and permissions in brackets. R - read; X - execute */
	FLASH (RX) : ORIGIN = 0x08000000, LENGTH = 0x20000	/* 128kb */
	/* W - write, A - allocate, I - initialize?, L - load */ 
	SRAM (WAIL) : ORIGIN = 0x20000000, LENGTH = 0x5000 /* 20kb */
}
SECTIONS
{
	.text :	/*section type in binary file*/ 
	{
		*(.text);	/* section type in *.s file */ 
		*(.code);	/* in case we have .code sections in *.s file it should also go to FLASH RAM */
	} > FLASH		/* goes to FLASH RAM */
	.bss : /* bss section in binary file */
	{
		*(.bss);	/* .bss section in SRAM */
	} > SRAM
}
