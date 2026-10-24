#ifndef GOW3_CORE_RESULT_H
#define GOW3_CORE_RESULT_H
typedef enum gow3_result {
    GOW3_OK = 0,
    GOW3_ERROR_INVALID_ARGUMENT = 1,
    GOW3_ERROR_NOT_INITIALIZED = 2,
    GOW3_ERROR_UNSUPPORTED = 3,
    GOW3_ERROR_IO = 4,
    GOW3_ERROR_OUT_OF_MEMORY = 5
} gow3_result;
const char *gow3_result_name(gow3_result result);
#endif
