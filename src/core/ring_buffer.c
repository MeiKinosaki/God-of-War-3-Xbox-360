#include "ring_buffer.h"

gow3_result gow3_ring_buffer_init(gow3_ring_buffer *buffer,
                                  unsigned char *storage,
                                  size_t capacity)
{
    if (buffer == NULL || storage == NULL || capacity == 0U) {
        return GOW3_ERROR_INVALID_ARGUMENT;
    }
    buffer->data = storage;
    buffer->capacity = capacity;
    buffer->head = 0U;
    buffer->size = 0U;
    return GOW3_OK;
}

gow3_result gow3_ring_buffer_write(gow3_ring_buffer *buffer,
                                   const unsigned char *data,
                                   size_t length)
{
    size_t i;
    if (buffer == NULL || (data == NULL && length != 0U) ||
        buffer->data == NULL || buffer->capacity == 0U) {
        return GOW3_ERROR_INVALID_ARGUMENT;
    }
    if (length > buffer->capacity - buffer->size) {
        return GOW3_ERROR_UNSUPPORTED;
    }
    for (i = 0U; i < length; ++i) {
        size_t tail = (buffer->head + buffer->size) % buffer->capacity;
        buffer->data[tail] = data[i];
        ++buffer->size;
    }
    return GOW3_OK;
}

gow3_result gow3_ring_buffer_read(gow3_ring_buffer *buffer,
                                  unsigned char *out,
                                  size_t length)
{
    size_t i;
    if (buffer == NULL || (out == NULL && length != 0U) ||
        buffer->data == NULL || buffer->capacity == 0U) {
        return GOW3_ERROR_INVALID_ARGUMENT;
    }
    if (length > buffer->size) {
        return GOW3_ERROR_UNSUPPORTED;
    }
    for (i = 0U; i < length; ++i) {
        out[i] = buffer->data[buffer->head];
        buffer->head = (buffer->head + 1U) % buffer->capacity;
        --buffer->size;
    }
    return GOW3_OK;
}

size_t gow3_ring_buffer_size(const gow3_ring_buffer *buffer)
{
    if (buffer == NULL || buffer->data == NULL) {
        return 0U;
    }
    return buffer->size;
}
