#pragma once
#include "../utils/hdrSet.h"
#include "../libs/idt.h"
#include "../libs/vmReg.h"
#include "../libs/VMprocess.h"
#include "../libs/rdtsc.h"
#include "../libs/ioport.h"
#include "../libs/str.h"

typedef class vmware_tk {
public:
	void vmware_registry(char *);
	void cpu_cycling(int);
	void vmware_idt(int);
	void vmware_ldt();
	void vmware_ioport();
	void vmware_process(char *);
	void vmware_str(int);
} *vm_tk;