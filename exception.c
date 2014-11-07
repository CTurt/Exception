#include "exception.h"

struct jmp_table jmp_table = { NULL, 0 };

inline void free_exceptions(void) {
	free(jmp_table.buf);
	jmp_table.count = 0;
}
