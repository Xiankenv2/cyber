#include "sentrybox/core/runner.h"
#include <string.h>
#include <stdlib.h>

int sentry_runner_execute(const SentryPlugin *plugin, const RunnerConfig *config, RunnerResult *result) {
    // Stub implementation
    result->exit_code = 0;
    result->stdout_output = strdup("{}");
    result->stderr_output = strdup("");
    result->stdout_len = 2;
    result->stderr_len = 0;
    return 0;
}

void sentry_runner_result_free(RunnerResult *result) {
    if (result) {
        free(result->stdout_output);
        free(result->stderr_output);
    }
}
