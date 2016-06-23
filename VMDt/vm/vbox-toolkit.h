#pragma once
#include "../utils/hdrSet.h"
#include "vbox-trick.h"

#define CHECK_MODE				0x0
#define RETURN_MODE				0x1
typedef class vbox_tk{
public:
	bool vbox_load_library(wchar_t *);
	bool vbox_provider(wchar_t *);
	HKEY vbox_registry(HKEY, wchar_t *, unsigned int);
	bool vbox_drive(wchar_t *);
private:
	vbox_trick *vb_tk;
}*vx_tk;