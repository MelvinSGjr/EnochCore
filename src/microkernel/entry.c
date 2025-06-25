// EnochCore entry point
#include "include/console.h"

void enochcore_main(void) {
    console_init();
    console_write("[EnochCore] Hello from EnochCore!\n");
    while (1) {}
} 