#include <sys/mman.h>
#include "libc.h"

int __madvise(void *addr, size_t len, int advice)
{
	// WASM doesn't currently support advising about memory, or even shrinking allocated memory
	return 0;
}

weak_alias(__madvise, madvise);
