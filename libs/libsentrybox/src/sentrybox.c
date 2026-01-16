#include "sentrybox.h"
#include <stdio.h>

#include "sentrybox/core/discovery.h"
#include <stdio.h>

int sentrybox_init(void) {
    // Initialize logging, discovery, etc.
    printf("SentryBox Core Engine Initialized\n");
    
    const char *paths[] = { "./plugins" };
    PluginList list = sentry_discovery_scan(paths, 1);
    printf("Discovered %zu plugins.\n", list.count);
    sentry_plugin_list_free(list);

    return 0;
}
