add_library(sentrybox_core STATIC
    src/plugin.c
    src/runner.c
    src/schema.c
    src/discovery.cpp
)

target_include_directories(sentrybox_core PUBLIC include)
