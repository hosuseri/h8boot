OUTPUT_FORMAT("coff-h8300")
OUTPUT_ARCH(h8300hn)
ENTRY("_start")
MEMORY
{
	ram     : o = 0xf780, l = 0x780
	stack   : o = 0xff80, l = 0x0
}
SECTIONS
{
.vectors :
	{
	} > ram
.text :
	{
	  *(.rodata)
	  *(.text)
	  *(.strings)
   	   _etext = . ;
	}  > ram
.tors :
	{
	  ___ctors = . ;
	  *(.ctors)
	  ___ctors_end = . ;
	  ___dtors = . ;
	  *(.dtors)
	  ___dtors_end = . ;
	} > ram
.data :
	{
	  *(.data)
	   _edata = . ;
	}  > ram
.bss :
	{
	   _bss_start = . ;
	  *(.bss)
	  *(COMMON)
	   _end = . ;
	}  >ram
.stack :
	{
	   _stack = . ;
	  *(.stack)
	}  > stack
}
