#ifndef SENTRYBOX_CORE_SCHEMA_H
#define SENTRYBOX_CORE_SCHEMA_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    SCHEMA_TYPE_MANIFEST,
    SCHEMA_TYPE_SCAN_REQUEST,
    SCHEMA_TYPE_FINDING,
    SCHEMA_TYPE_SCAN_RESULT
} SchemaType;

/**
 * Validate a JSON string against a built-in schema.
 * @return true if valid, false otherwise.
 */
bool sentry_schema_validate(SchemaType type, const char *json_content, char *error_out, size_t error_size);

#ifdef __cplusplus
}
#endif

#endif // SENTRYBOX_CORE_SCHEMA_H
