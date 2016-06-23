#include "vm/vmware-toolkit.h"

int main() {
	/* 1. VMware Detect */
	vmware_tk *vmtk = new vmware_tk();
	vmtk->cpu_cycling(512);
	vmtk->vmware_idt(0xd0);
	vmtk->vmware_ioport();
	vmtk->vmware_ldt();
	//vmtk->vmware_process("servicedb/vmware.service");
	//vmtk->vmware_registry("dbase/vmware.dbase");
	vmtk->vmware_str(0x40);

	free(vmtk);
	return 0;
}