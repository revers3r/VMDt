#include "libs/VMprocess.h"
#include "libs/vmReg.h"
#include "utils/DBase.h"
#include "libs/idt.h"
#include "libs/ioport.h"
#include "libs/rdtsc.h"
#include "libs/str.h"

int main() {
/*
	// 1. Checking Process List
	HKEY hKey = NULL;
	int serviceCheck = CheckProcessList();
	if (serviceCheck == 0) {
		DETECT_START		"Process"		DETECT_END
	}
	// 2. Checking Registery from VMware System
	dbSetup();

	// 3. Checking IDT table from VMware System
	for (int i = 0; i < 10; i++) {
		if (getidt() >= 0xd0) {
			DETECT_START		"IDT"		DETECT_END
		}
	}
	// 4. Checking LDT table from VMware System
	if (getldt()) {
		DETECT_START		"LDT"		DETECT_END
	}
	// 5. Checking IO port from VMware System
	if (!vmware_ioport()) {
		DETECT_START		"IOport"		DETECT_END
	}
	// 6. Checking time delaying from VMware System
	if (rdtsc() > 512) {
		DETECT_START		"rdtsc"		DETECT_END
	}
	// 7. Checking STR table from VMware System
	if (str() != 0x40) {
		DETECT_START		"STR"		DETECT_END
	}
	return	0;
*/
}