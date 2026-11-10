#include <cassert>
#include <cstdint>
#include <stddef.h>
#include <stdint.h>

typedef struct Arena {
    unsigned char* buf;
    size_t buf_len;
    size_t prev_offset;
    size_t curr_offset;
} Arena;

static bool is_power_of_two(uintptr_t x) {
    return (x & (x-1)) == 0;
}

static uintptr_t align_forward(uintptr_t ptr, size_t align) {
    uintptr_t p, a, modulo;
    assert(is_power_of_two(align));
    p = ptr;
    a = (uintptr_t)align;
    modulo = p & (a-1);
    if (modulo != 0) {
        p += a - modulo;
    }
    return p;
}

static void* arena_alloc_align(Arena* a, size_t size, size_t align) {
    uintptr_t curr_ptr = (uintptr_t)a->buf + (uintptr_t)a->curr_offset;
    uintptr_t offset = align_forward(curr_ptr, align);
    offset -= (uintptr_t)a->buf;

    return nullptr;
}
