add_executable(sentryctl
    main.c
)

target_link_libraries(sentryctl PRIVATE sentrybox)
