#include "ioport.h"

unsigned int vmware_iop() {
	int ret = 0;
	unsigned int a, b;
	__try {
		__asm {
			pushad
			mov eax, 'VMXh'
			mov ebx, 0
			mov ecx, 0Ah
			mov edx, 'VX'

			in eax, dx
			mov a, ebx
			mov b, ecx
			popad
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER){
		ret = 1;
		return ret;
	}
	return ret;
}