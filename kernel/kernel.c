#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "../libc/mem.h"
#include <stdint.h>

void kernel_main() {
    isr_install();
    irq_install();

    asm("int $2");
    asm("int $3");

    kprint("Waiting for input...\n"
        "Press END for kmalloc()\nkernel $ ");
}

void user_input(char *input) {
    if (strcmp(input, "END") == 0) 
    {
        kprint("CPU Stopped. GG!\n");
        asm volatile("hlt");
    } 
    else if (strcmp(input, "INFO") == 0) 
    {
        uint32_t phys_addr;
        uint32_t page = kmalloc(1000, 1, &phys_addr);
        char page_str[16] = "";
        hex_to_ascii(page, page_str);
        char phys_str[16] = "";
        hex_to_ascii(phys_addr, phys_str);
        kprint("Page: ");
        kprint(page_str);
        kprint(", physical address: ");
        kprint(phys_str);
        kprint("\n");
    }
    
    kprint("ECH: ");
    kprint(input);
    kprint("\nkernel $ ");
}
