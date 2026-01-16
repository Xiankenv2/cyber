add_library(sentrybox SHARED
    src/sentrybox.c
)

target_include_directories(sentrybox PUBLIC include)
target_link_libraries(sentrybox PRIVATE sentrybox_core)

if(WIN32)
    target_compile_definitions(sentrybox PRIVATE SENTRYBOX_EXPORTS)
endif()
