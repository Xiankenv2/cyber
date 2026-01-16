#include <stdio.h>
#include "sentrybox.h"

int main(int argc, char **argv) {
    printf("sentryctl starting...\n");
    
    // Minimal bootstrap
    if (sentrybox_init() != 0) {
        fprintf(stderr, "Failed to initialize SentryBox engine.\n");
        return 1;
    }

    printf("Ready.\n");
    return 0;
}
