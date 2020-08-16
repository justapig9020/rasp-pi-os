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
    . = ALIGN(8);
    .bss :
    {
        bss_begin = .;
        *(.bss*)
        bss_end = .;
    }
}
