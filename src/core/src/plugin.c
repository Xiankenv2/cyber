#include "sentrybox/core/plugin.h"
#include <stdlib.h>

void sentry_plugin_free(SentryPlugin *plugin) {
    if (plugin) {
        // Free resources if dynamically allocated members were added
    }
}
