#ifndef SENTRYBOX_H
#define SENTRYBOX_H

#if defined(_WIN32)
  #if defined(SENTRYBOX_EXPORTS)
    #define SENTRYBOX_API __declspec(dllexport)
  #else
    #define SENTRYBOX_API __declspec(dllimport)
  #endif
#else
  #define SENTRYBOX_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialize the SentryBox engine.
 * @return 0 on success, non-zero on error.
 */
SENTRYBOX_API int sentrybox_init(void);

#ifdef __cplusplus
}
#endif

#endif // SENTRYBOX_H
