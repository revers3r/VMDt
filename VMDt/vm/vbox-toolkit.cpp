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
bool vbox_tk::vbox_bios(wchar_t *bios_name) {
	if (vb_tk->get_bios(bios_name)) {
		DETECT_START			"VirtualBox Detected"			DETECT_END
			return false;
	}
	return true;
}
bool vbox_tk::vbox_ipc(wchar_t *ipc_name) {
	if (vb_tk->ipc_chk(ipc_name)) {
		DETECT_START			"VirtualBox Detected"			DETECT_END
			return false;
	}
	return true;
}
void vbox_tk::closetk() {
	free(vb_tk);
}
bool vbox_tk::vbox_mac(unsigned char mac1, unsigned char mac2, unsigned char mac3) {
	PIP_ADAPTER_INFO AdapterInfo;
	DWORD dwBufLen = sizeof(AdapterInfo);
	char *mac_addr = (char *)malloc(17);
	AdapterInfo = (IP_ADAPTER_INFO *)malloc(sizeof(IP_ADAPTER_INFO));
	if (GetAdaptersInfo(AdapterInfo, &dwBufLen) == NO_ERROR) {
		PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;
		if ((pAdapterInfo->Address[0] == mac1) && (pAdapterInfo->Address[1] == mac2) && (pAdapterInfo->Address[2] == mac3)) {
			DETECT_START			"VirtualBox Detected"				DETECT_END
			return false;
		}
	}
	else {
		return false;
	}
	
return		true;
}