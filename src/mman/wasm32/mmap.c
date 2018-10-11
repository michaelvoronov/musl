#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <stdint.h>
#include <limits.h>
#include "libc.h"

void *__mmap(void *start, size_t len, int prot, int flags, int fd, off_t off)
{
	if ((start == 0) && (flags & MAP_ANONYMOUS)) {
		return __builtin_wasm_memory_grow(0, len);
	}

	return MAP_FAILED;
}

weak_alias(__mmap, mmap);

LFS64(mmap);
