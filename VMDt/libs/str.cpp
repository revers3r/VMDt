#include "str.h"

unsigned int str() {
	unsigned char mem[4] = { 0,0,0,0 };
	__asm {
		str mem;
	}
	return (mem[0] | mem[1]);
}