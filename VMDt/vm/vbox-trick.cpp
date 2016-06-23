#include "vbox-trick.h"
#include "../utils/my_util.h"
#include "../libs/vmReg.h"

bool vbox_trick::library_chk(wchar_t *dll_path) {
	HMODULE hM = LoadLibrary(dll_path);
	if (hM) {
		return true;
	}
	return false;
}
bool vbox_trick::get_provider(wchar_t *provider) {
	unsigned long pnsize = 0x1000;
	wchar_t *provide = (wchar_t *)LocalAlloc(LMEM_ZEROINIT, pnsize);
	int ret = WNetGetProviderName(WNNC_NET_RDR2SAMPLE, provide, &pnsize);
	if (ret == NO_ERROR) {
		if (lstrcmpi(provide, provider) == 0) {
			LocalFree(provide);
			return true;
		}
	}
	LocalFree(provide);
	return false;
}
bool vbox_trick::registry_chk(HKEY RootKey, wchar_t *registry_path) {
	if (OpenKey_readmode(RootKey, registry_path)) {
		return true;
	}
	return false;
}
bool vbox_trick::drive_chk(wchar_t *driver) {
	HANDLE hHandle = NULL;
	if ((hHandle = CreateFile(driver, GENERIC_READ, FILE_SHARE_READ |
		FILE_SHARE_WRITE | FILE_SHARE_DELETE, 0, OPEN_EXISTING, 0, 0))) {
		if (hHandle != INVALID_HANDLE_VALUE) {
			return true;
		}
		return false;
	}
	return false;
}