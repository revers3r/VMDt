#include "vmware-toolkit.h"

void vmware_tk::vmware_idt(int target_idt) {
	for (int i = 0; i < 10; i++) {
		if (getidt() >= target_idt) {
			DETECT_START			"VMware Detected"			DETECT_END;
			QuitProcess(0);
		}
	}
}
void vmware_tk::vmware_ldt() {
	if (getldt()) {
		DETECT_START			"VMware Detected"				DETECT_END
			QuitProcess(0);
	}
}
void vmware_tk::vmware_registry(char *dbpath) {
	dbSetup(HKEY_CLASSES_ROOT, dbpath);
	dbSetup(HKEY_CURRENT_CONFIG, dbpath);
	dbSetup(HKEY_CURRENT_USER, dbpath);
	dbSetup(HKEY_LOCAL_MACHINE, dbpath);
}
void vmware_tk::cpu_cycling(int cycle_num) {
	if (rdtsc() > cycle_num) {
		DETECT_START			"VMware Detected"				DETECT_END
			QuitProcess(0);
	}
}
void vmware_tk::vmware_ioport() {
	if (!vmware_iop()) {
		DETECT_START			"VMware Detected"				DETECT_END
			QuitProcess(0);
	}
}
void vmware_tk::vmware_process(char *path) {
	int serviceCheck = CheckProcessList(path);
	if (serviceCheck == 0) {
		DETECT_START			"VMware Detected"			DETECT_END
			QuitProcess(0);
	}
}
void vmware_tk::vmware_str(int vmware_STR) {
	if (str() != vmware_STR) {
		DETECT_START			"VMware Detected"			DETECT_END
			QuitProcess(0);
	}
}
void QuitProcess(unsigned int num) {
	printf("[*] Exit Process.. CODE : 0x%x\n", num);
	_exit(num);
}