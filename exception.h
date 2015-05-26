#pragma once

#include <stdlib.h>
#include <setjmp.h>

#define exception(...) do { int e; volatile int b = 0; { int j = push_jmp(); e = setjmp(jmp_table.buf[j]); b++; if(b == 2) pop_jmp(); } __VA_ARGS__ if(b == 1) pop_jmp(); } while(0)
#define try() if(!e)
#define throw(e) longjmp(jmp_table.buf[jmp_table.count - 1], e)
#define catch(ex) else if(e == ex)
#define finally() else

struct jmp_table {
	jmp_buf *buf;
	unsigned int count;
};

extern struct jmp_table jmp_table;

static inline int push_jmp(void) {
	jmp_table.buf = realloc(jmp_table.buf, sizeof(jmp_buf) * (jmp_table.count + 1));
	return jmp_table.count++;
}

static inline void pop_jmp(void) {
	jmp_table.buf = realloc(jmp_table.buf, sizeof(jmp_buf) * (--jmp_table.count));
}

void free_exceptions(void);
