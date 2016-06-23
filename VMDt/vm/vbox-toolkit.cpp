#include "vbox-toolkit.h"

bool vbox_tk::vbox_load_library(wchar_t *dll_path) {
	if (vb_tk->library_chk(dll_path)) {
		DETECT_START			"VirtualBox Detected"			DETECT_END
			return false;
	}
	return true;
}
bool vbox_tk::vbox_provider(wchar_t *provider) {
	if (vb_tk->get_provider(provider)) {
		DETECT_START			"VirtualBox Detected"			DETECT_END
			return false;
	}
	return true;
}
HKEY vbox_tk::vbox_registry(HKEY RootKey, wchar_t *registry_path, unsigned int mode = 0x0) {
	switch (mode) {
	case 0x0:
		if (vb_tk->registry_chk(RootKey, registry_path)) {
			return NULL;
		}
	case 0x1:
		/* OpenKey Section */
		return NULL;
	}
}
bool vbox_tk::vbox_drive(wchar_t *drive_path) {
	if (vb_tk->drive_chk(drive_path)) {
		DETECT_START			"VirtualBox Detected"			DETECT_END
		return false;
	}
	return true;
}