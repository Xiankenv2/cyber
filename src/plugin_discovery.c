#include "sentryctl.h"

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

static int file_exists(const char *path) {
    struct stat st;
    return stat(path, &st) == 0 && S_ISREG(st.st_mode);
}

static void build_plugin_json_path(char *buffer, size_t buffer_size, const char *plugins_root,
                                   const char *plugin_id) {
    snprintf(buffer, buffer_size, "%s/%s/plugin.json", plugins_root, plugin_id);
}

void list_plugins(const char *plugins_root) {
    DIR *dir = opendir(plugins_root);
    if (!dir) {
        printf("No plugins directory found at '%s'.\n", plugins_root);
        return;
    }

    struct dirent *entry;
    int found = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char plugin_json[512];
        build_plugin_json_path(plugin_json, sizeof(plugin_json), plugins_root, entry->d_name);

        if (file_exists(plugin_json)) {
            printf("%s\n", entry->d_name);
            found = 1;
        }
    }

    closedir(dir);

    if (!found) {
        printf("No plugins discovered in '%s'.\n", plugins_root);
    }
}

void show_plugin_info(const char *plugins_root, const char *plugin_id) {
    char plugin_json[512];
    build_plugin_json_path(plugin_json, sizeof(plugin_json), plugins_root, plugin_id);

    if (!file_exists(plugin_json)) {
        printf("Plugin '%s' not found.\n", plugin_id);
        return;
    }

    printf("Plugin ID: %s\n", plugin_id);
    printf("Manifest: %s\n", plugin_json);
    printf("Metadata parsing is not implemented yet.\n");
}
