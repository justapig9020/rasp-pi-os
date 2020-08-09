SECTIONS
{
    .boot.text :
    {
        *(.boot.text)
    }
    .text :
    {
        *(.text)
    }
    .rodata :
    {
        *(.rodata)
    }
    .data :
    {
        *(.data)
    }
    .=ALIGN(4)
    .bss :
    {
        *(.bss)
    }
}
