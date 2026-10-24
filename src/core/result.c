#include "result.h"
const char *gow3_result_name(gow3_result result)
{
    switch (result) {
    case GOW3_OK: return "ok";
    case GOW3_ERROR_INVALID_ARGUMENT: return "invalid_argument";
    case GOW3_ERROR_NOT_INITIALIZED: return "not_initialized";
    case GOW3_ERROR_UNSUPPORTED: return "unsupported";
    case GOW3_ERROR_IO: return "io_error";
    case GOW3_ERROR_OUT_OF_MEMORY: return "out_of_memory";
    default: return "unknown_error";
    }
}
