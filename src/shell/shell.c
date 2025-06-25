/**
 * @file shell.c
 * @brief Minimal shell for EnochCore with BusyBox integration
 *
 * Example usage:
 *   shell_main();
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void shell_main(void) {
    // Simple shell loop with BusyBox integration
    char input[128];
    while (1) {
        printf("EnochCore$ ");
        if (!fgets(input, sizeof(input), stdin))
            break;
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "help") == 0) {
            printf("Available commands: help, exit, busybox <cmd>\n");
        } else if (strcmp(input, "exit") == 0) {
            printf("Exiting shell.\n");
            break;
        } else if (strncmp(input, "busybox ", 9) == 0) {
            // Execute BusyBox applet
            char *cmd = input + 9;
            char syscmd[160];
            snprintf(syscmd, sizeof(syscmd), "/bin/busybox %s", cmd);
            system(syscmd);
        } else if (input[0]) {
            printf("Unknown command: %s\n", input);
        }
    }
} 