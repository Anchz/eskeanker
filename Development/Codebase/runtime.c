#include <stddef.h>

void *memcpy(void *restrict destination, const void *restrict source, size_t size) {
	unsigned char *destination_position = destination;
	const unsigned char *source_position = source;

	while (size--) {
		*destination_position++ = *source_position++;
	}

	return destination;
}

void *memset(void *destination, int content, size_t size) {
	unsigned char *position = destination;

	while (size--) {
		*position++ = content;
	}

	return destination;
}

/*
void *memmove(void *destination, const void *source, size_t size) {
	
}

int memcmp(const void *a, const void *b, size_t size) {
	
}
*/
