#ifndef SENTRYBOX_CORE_PLUGIN_H
#define SENTRYBOX_CORE_PLUGIN_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    PLUGIN_CAPABILITY_NONE = 0,
    PLUGIN_CAPABILITY_FS_READ = 1 << 0,
    PLUGIN_CAPABILITY_NETWORK = 1 << 1,
    PLUGIN_CAPABILITY_ENV = 1 << 2
} PluginCapability;

typedef struct {
    char id[128];
    char version[32];
    char name[256];
    char path[1024]; /* Path to the plugin executable or directory */
    PluginCapability capabilities;
} SentryPlugin;

void sentry_plugin_free(SentryPlugin *plugin);

#ifdef __cplusplus
}
#endif

#endif // SENTRYBOX_CORE_PLUGIN_H
