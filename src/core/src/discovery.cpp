#include "sentrybox/core/discovery.h"
#include <vector>
#include <string>
#include <filesystem>
#include <cstring>
#include <cstdlib>

namespace fs = std::filesystem;

extern "C" {

PluginList sentry_discovery_scan(const char **search_paths, size_t count) {
    PluginList list = {0};
    if (count == 0) return list;

    std::vector<SentryPlugin*> discovered;

    for (size_t i = 0; i < count; ++i) {
        if (!search_paths[i]) continue;
        // Basic error safety
        try {
            fs::path p(search_paths[i]);
            if (!fs::exists(p) || !fs::is_directory(p)) continue;
            
            // Iterate directory
            for(const auto& entry : fs::directory_iterator(p)) {
                if (entry.is_directory()) {
                    // Check for manifest.json
                    fs::path manifest = entry.path() / "manifest.json";
                    if (fs::exists(manifest)) {
                        // It's a plugin candidate
                        SentryPlugin *pl = (SentryPlugin*)calloc(1, sizeof(SentryPlugin));
                        if(pl) {
                            strncpy(pl->path, entry.path().string().c_str(), sizeof(pl->path)-1);
                            strncpy(pl->id, entry.path().filename().string().c_str(), sizeof(pl->id)-1);
                            // TODO: Read manifest.json for real name/version
                            strncpy(pl->name, pl->id, sizeof(pl->name)-1); 
                            
                            discovered.push_back(pl);
                        }
                    }
                }
            }
        } catch (...) {
            // Ignore errors for robust scanning
        }
    }

    if (!discovered.empty()) {
        list.count = discovered.size();
        list.plugins = (SentryPlugin**)calloc(list.count, sizeof(SentryPlugin*));
        if (list.plugins) {
            for(size_t i=0; i<list.count; ++i) {
                list.plugins[i] = discovered[i];
            }
        }
    }
    return list;
}

void sentry_plugin_list_free(PluginList list) {
    if (list.plugins) {
        for(size_t i=0; i<list.count; ++i) {
             sentry_plugin_free(list.plugins[i]);
             free(list.plugins[i]);
        }
        free(list.plugins);
    }
}

}
