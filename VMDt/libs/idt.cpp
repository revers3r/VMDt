#include "idt.h"

unsigned char getidt() {
	unsigned char idtr[6];
	_asm {
		sidt idtr;
	}
	return idtr[5];
}

unsigned char getldt() {
	unsigned char m[4];
	_asm {
		sldt m;
	}
	// printf("%x %x\n", m[0], m[1]);
	return (m[0] | m[1]);
}