/*SECTIONS*/
/*{*/
    /*.text.boot : { *(.text.boot) } [> load kernal img<]*/

    /*.text : { *(.text) }*/
    /*.rodata : { *(.rodata) } */
    /*.data : { *(.data) }*/

       /*adddress multiple 8 */
    /*. = ALIGN(0x8); */
    /*bss_begin = .;*/
    /*.bss : { *(.bss) }*/
    /*bss_end = .;*/
/*}*/
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

