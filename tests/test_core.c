#include <assert.h>
#include <string.h>
#include "../src/core/result.h"
#include "../src/core/ring_buffer.h"
static void test_results(void) {
    assert(strcmp(gow3_result_name(GOW3_OK), "ok") == 0);
    assert(strcmp(gow3_result_name(GOW3_ERROR_IO), "io_error") == 0);
    assert(strcmp(gow3_result_name((gow3_result)99), "unknown_error") == 0);
}
static void test_roundtrip_and_wraparound(void) {
    unsigned char storage[3], first[2] = {1U, 2U}, second[2] = {3U, 4U}, discard[2], out[2];
    gow3_ring_buffer b;
    assert(gow3_ring_buffer_init(&b, storage, sizeof(storage)) == GOW3_OK);
    assert(gow3_ring_buffer_write(&b, first, 2U) == GOW3_OK);
    assert(gow3_ring_buffer_read(&b, discard, 2U) == GOW3_OK);
    assert(gow3_ring_buffer_write(&b, second, 2U) == GOW3_OK);
    assert(gow3_ring_buffer_read(&b, out, 2U) == GOW3_OK);
    assert(out[0] == 3U && out[1] == 4U && gow3_ring_buffer_size(&b) == 0U);
}
static void test_invalid_and_overflow(void) {
    unsigned char storage[2], input[3] = {1U, 2U, 3U};
    gow3_ring_buffer b;
    assert(gow3_ring_buffer_init(&b, NULL, 2U) == GOW3_ERROR_INVALID_ARGUMENT);
    assert(gow3_ring_buffer_init(&b, storage, sizeof(storage)) == GOW3_OK);
    assert(gow3_ring_buffer_write(&b, input, sizeof(input)) == GOW3_ERROR_UNSUPPORTED);
}
int main(void) { test_results(); test_roundtrip_and_wraparound(); test_invalid_and_overflow(); return 0; }
