#include "../libs/rdtsc.h"

unsigned int rdtsc() {
	unsigned long a, b, c;
	__asm {
		push eax
		push ebx

		rdtsc				// First CPU Cycle Checking
		mov b, eax
		mov ebx, eax
		rdtsc				// Second CPU Cycle Checking
		mov c, eax
		sub eax, ebx
		mov a, eax

		pop eax
		pop ebx
	}
	return a;
}