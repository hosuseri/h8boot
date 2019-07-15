OUTPUT_FORMAT("coff-h8300")
OUTPUT_ARCH(h8300h)
ENTRY("_start")
MEMORY
{
	ram     : o = 0xf780, l = 0x76f
	stack   : o = 0xfeec, l = 0x4
}
SECTIONS
{
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
