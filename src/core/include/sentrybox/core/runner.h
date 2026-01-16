#ifndef SENTRYBOX_CORE_RUNNER_H
#define SENTRYBOX_CORE_RUNNER_H

#include "plugin.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    const char *request_json;
    int timeout_ms;
} RunnerConfig;

typedef struct {
    int exit_code;
    char *stdout_output;
    char *stderr_output;
    size_t stdout_len;
    size_t stderr_len;
} RunnerResult;

/**
 * Execute a plugin with the given configuration.
 */
int sentry_runner_execute(const SentryPlugin *plugin, const RunnerConfig *config, RunnerResult *result);

void sentry_runner_result_free(RunnerResult *result);

#ifdef __cplusplus
}
#endif

#endif // SENTRYBOX_CORE_RUNNER_H
