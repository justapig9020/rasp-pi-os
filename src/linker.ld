SECTIONS
{
    .text.boot : { *(.text.boot) } /* load kernal img*/

    .text : { *(.text) }
    .rodata : { *(.rodata) } 
    .data : { *(.data) }

    /*.bss init to 0 
       adddress multiple 8 */
    . = ALIGN(0x8); 
    bss_begin = .;
    .bss : { *(.bss) }
    bss_end = .;
}
