#include <assert.h>
#include <string.h>
#include "../src/core/result.h"
#include "../src/core/ring_buffer.h"

static void test_result_names(void)
{
    assert(strcmp(gow3_result_name(GOW3_OK), "ok") == 0);
    assert(strcmp(gow3_result_name(GOW3_ERROR_IO), "io_error") == 0);
    assert(strcmp(gow3_result_name((gow3_result)99), "unknown_error") == 0);
}

static void test_ring_buffer_roundtrip(void)
{
    unsigned char storage[4];
    unsigned char input[3] = { 10U, 20U, 30U };
    unsigned char output[3] = { 0U, 0U, 0U };
    gow3_ring_buffer buffer;
    assert(gow3_ring_buffer_init(&buffer, storage, sizeof(storage)) == GOW3_OK);
    assert(gow3_ring_buffer_write(&buffer, input, sizeof(input)) == GOW3_OK);
    assert(gow3_ring_buffer_size(&buffer) == 3U);
    assert(gow3_ring_buffer_read(&buffer, output, sizeof(output)) == GOW3_OK);
    assert(memcmp(input, output, sizeof(input)) == 0);
    assert(gow3_ring_buffer_size(&buffer) == 0U);
}

static void test_ring_buffer_wraparound(void)
{
    unsigned char storage[3];
    unsigned char first[2] = { 1U, 2U };
    unsigned char second[2] = { 3U, 4U };
    unsigned char discard[2];
    unsigned char output[2];
    gow3_ring_buffer buffer;
    assert(gow3_ring_buffer_init(&buffer, storage, sizeof(storage)) == GOW3_OK);
    assert(gow3_ring_buffer_write(&buffer, first, 2U) == GOW3_OK);
    assert(gow3_ring_buffer_read(&buffer, discard, 2U) == GOW3_OK);
    assert(gow3_ring_buffer_write(&buffer, second, 2U) == GOW3_OK);
    assert(gow3_ring_buffer_read(&buffer, output, 2U) == GOW3_OK);
    assert(output[0] == 3U && output[1] == 4U);
}

static void test_ring_buffer_rejects_overflow(void)
{
    unsigned char storage[2];
    unsigned char input[3] = { 1U, 2U, 3U };
    gow3_ring_buffer buffer;
    assert(gow3_ring_buffer_init(&buffer, storage, sizeof(storage)) == GOW3_OK);
    assert(gow3_ring_buffer_write(&buffer, input, sizeof(input)) == GOW3_ERROR_UNSUPPORTED);
}

static void test_invalid_init(void)
{
    gow3_ring_buffer buffer;
    assert(gow3_ring_buffer_init(&buffer, NULL, 2U) == GOW3_ERROR_INVALID_ARGUMENT);
}

int main(void)
{
    test_result_names();
    test_ring_buffer_roundtrip();
    test_ring_buffer_wraparound();
    test_ring_buffer_rejects_overflow();
    test_invalid_init();
    return 0;
}
