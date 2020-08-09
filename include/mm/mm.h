#ifndef _MM_H_
#define _MM_H_

#define PAGE_SHIFT 12
#define TABLE_SHIFT 9
#define SECTION_SHIFT (PAGE_SHIFT + TABLE_SHIFT)
#define PAGE_SIZE (1 << PAGE_SHIFT)
#define SECTION_SIZE (1 << SECTION_SHIFT)

#define LOW_MEMORY (SECTION_SHIFT << 1)

// Reference from https://github.com/s-matyukevich/raspberry-pi-os
#endif
