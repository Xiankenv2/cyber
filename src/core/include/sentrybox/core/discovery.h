#ifndef SENTRYBOX_CORE_DISCOVERY_H
#define SENTRYBOX_CORE_DISCOVERY_H

#include "plugin.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    SentryPlugin **plugins;
    size_t count;
} PluginList;

/**
 * Scan the given directories for plugins.
 * @param search_paths Array of paths to search strings.
 * @param count Number of paths.
 * @return PluginList result (must be freed).
 */
PluginList sentry_discovery_scan(const char **search_paths, size_t count);

void sentry_plugin_list_free(PluginList list);

#ifdef __cplusplus
}
#endif

#endif // SENTRYBOX_CORE_DISCOVERY_H
