#include <stdio.h>
#include <string.h>

#include "sentryctl.h"

static void print_help(void) {
    printf("sentryctl - defensive security testing CLI\n\n");
    printf("usage: sentryctl <command> [options]\n\n");
    printf("commands:\n");
    printf("  help                    Show this help message\n");
    printf("  version                 Print version information\n");
    printf("  plugin list             List available plugins\n");
    printf("  plugin info <plugin_id> Show plugin details\n\n");
    printf("notes:\n");
    printf("  Use only on systems you own or have explicit permission to test.\n");
}

static void print_version(void) {
    printf("sentryctl version 0.1.0 (scaffold)\n");
}

int main(int argc, char **argv) {
    const char *plugins_root = "plugins";

    if (argc < 2) {
        print_help();
        return 0;
    }

    if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0) {
        print_help();
        return 0;
    }

    if (strcmp(argv[1], "version") == 0 || strcmp(argv[1], "--version") == 0) {
        print_version();
        return 0;
    }

    if (strcmp(argv[1], "plugin") == 0) {
        if (argc >= 3 && strcmp(argv[2], "list") == 0) {
            list_plugins(plugins_root);
            return 0;
        }

        if (argc >= 3 && strcmp(argv[2], "info") == 0) {
            if (argc < 4) {
                printf("Missing plugin ID. Usage: sentryctl plugin info <plugin_id>\n");
                return 1;
            }

            show_plugin_info(plugins_root, argv[3]);
            return 0;
        }

        printf("Unknown plugin command. Use 'sentryctl help'.\n");
        return 1;
    }

    printf("Unknown command. Use 'sentryctl help'.\n");
    return 1;
}
