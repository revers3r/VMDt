#pragma once
#include "../utils/hdrSet.h"

#define MAX_REGISTRY_KEY_LENGTH		256
#define MAX_VALUE_NAME_LENGTH		16383
bool OpenKey_readmode(HKEY hKey, const wchar_t* SubKeyName);
HKEY OpenKey(HKEY hKey, const wchar_t* SubKeyName);
bool CloseKey(HKEY hKey);
typedef struct RegistryDB {
	int num;
	char **strg;
}RegDB;

void dbSetup(HKEY, char *);