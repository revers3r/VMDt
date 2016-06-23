#include "vmReg.h"
#include "VMprocess.h"
#include "../utils/my_util.h"
#include "../utils/DBase.h"

bool OpenKey_readmode(HKEY hKey, const wchar_t* SubKeyName) {
	HKEY hSubKey = NULL;
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, SubKeyName, 0, KEY_READ, &hSubKey) == ERROR_SUCCESS) {
		CloseKey(hSubKey);
		return true;
	}
	return false;
}

HKEY OpenKey(HKEY hKey, const wchar_t* SubKeyName) {
	HKEY hSubKey = NULL;
	REGSAM sam = KEY_ALL_ACCESS;
	DWORD ret = RegOpenKeyExW(hKey, SubKeyName, 0, sam, &hSubKey);

	if (ret != ERROR_SUCCESS) {
		error_log	"RegOpenKeyExW(%ws) fail.., ret = %u", SubKeyName, ret		error_end
		return NULL;
	}
	return hSubKey;
}

bool CloseKey(HKEY hKey) {
	DWORD ret = RegCloseKey(hKey);
	if (ret != ERROR_SUCCESS) {
		error_log		"RegCloseKey(hKey) is fail.."		error_end
			return false;
	}
	return true;
}

void dbSetup(HKEY hKey, char *path) {
	RegDB *regist = (RegDB *)malloc(sizeof(RegistryDB));
	HKEY key = hKey;
	int nLen;
	wchar_t ctemp[512] = { 0 };
	if (path == NULL) {
		regist = parseDatabase(key);
	}
	else {
		regist = parseUserInput(path);
	}
	if	(regist == NULL) {
		printf("[*] Can't open database file\n");
		return;
	}
	for (int i = 0; i < regist->num; i++) {
		memset(ctemp, 0, 512);
		nLen = MultiByteToWideChar(CP_ACP, 0, regist->strg[i], strlen(regist->strg[i]), NULL, NULL);
		MultiByteToWideChar(CP_ACP, 0, regist->strg[i], strlen(regist->strg[i]), ctemp, nLen);
		if (OpenKey(key, ctemp)) {
			DETECT_START		"Registry"		DETECT_END
			_exit(0);
		}
	}
	free(regist);
}