#pragma once
#include "../utils/hdrSet.h"

#pragma comment (lib, "Mpr.lib")
typedef class vbox_trick {
public:
	bool library_chk(wchar_t *);
	bool get_provider(wchar_t *);
	bool registry_chk(HKEY, wchar_t *);
	bool drive_chk(wchar_t *);
	bool get_bios(wchar_t *);
	bool ipc_chk(wchar_t *);
}*vx_trick;