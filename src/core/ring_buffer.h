#ifndef GOW3_CORE_RING_BUFFER_H
#define GOW3_CORE_RING_BUFFER_H

#include <stddef.h>
#include "result.h"

typedef struct gow3_ring_buffer {
    unsigned char *data;
    size_t capacity;
    size_t head;
    size_t size;
} gow3_ring_buffer;

gow3_result gow3_ring_buffer_init(gow3_ring_buffer *buffer,
                                  unsigned char *storage,
                                  size_t capacity);
gow3_result gow3_ring_buffer_write(gow3_ring_buffer *buffer,
                                   const unsigned char *data,
                                   size_t length);
gow3_result gow3_ring_buffer_read(gow3_ring_buffer *buffer,
                                  unsigned char *out,
                                  size_t length);
size_t gow3_ring_buffer_size(const gow3_ring_buffer *buffer);

#endif
