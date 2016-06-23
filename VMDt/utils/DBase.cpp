#include "DBase.h"

RegDB *parseDatabase(HKEY RootKey) {
	RegDB *Reg = (RegDB *)malloc(sizeof(RegistryDB));
	DatabaseFmt *dbf = (DatabaseFmt *)malloc(sizeof(DatabaseFmt));
	char **keyTable;
#if defined(_X86_)
	keyTable = (char **)malloc(sizeof(char *) * 4);

	for (int i = 0; i < 4; i++) {
		keyTable[i] = (char *)malloc(sizeof(char) * 256);
	}
	keyTable[0] = ".\\dbase\\HKEY_CLASSES_ROOT.dbase";
	keyTable[1] = ".\\dbase\\HKEY_CURRENT_CONFIG.dbase";
	keyTable[2] = ".\\dbase\\HKEY_CURRENT_USER.dbase";
	keyTable[3] = ".\\dbase\\HKEY_LOCAL_MACHINE.dbase";
#endif
	int lst = getSwitch(RootKey);
	FILE *fp = fopen(keyTable[lst], "rb");
	if (fp == NULL) {
		error_log			"[*] Can't Open Database File..\n"			error_end
			return NULL;
	}
	memset(dbf->Signature, 0, 6);
	fread(dbf->Signature, sizeof(char), 5, fp);					// Read Signature
	dbf->NumberOfData = fgetc(fp);								// Read NumberOfData
	dbf->Data = (char **)malloc(sizeof(char *) * dbf->NumberOfData);
	Reg->strg = (char **)malloc(sizeof(char *) * dbf->NumberOfData);
	for (int idx = 0; idx < dbf->NumberOfData; idx++) {
		dbf->Data[idx] = (char *)malloc(sizeof(char) * 256);
		fgets(dbf->Data[idx], 256, fp);
	}
	/* Set Data in RegDB */
	Reg->num = dbf->NumberOfData;
	for (int i = 0; i < Reg->num; i++) {
		Reg->strg[i] = (char *)malloc(sizeof(char) * 256);
		strcpy(Reg->strg[i], dbf->Data[i]);
	}
	free(dbf);
	free(keyTable);
	return Reg;
}

int getSwitch(HKEY RootKey) {
	if (RootKey == HKEY_CLASSES_ROOT)
		return 0;
	else if (RootKey == HKEY_CURRENT_CONFIG)
		return 1;
	else if (RootKey == HKEY_CURRENT_USER)
		return 2;
	else if (RootKey == HKEY_LOCAL_MACHINE)
		return 3;
	else {
		error_log		"Invalid RootKey Option."		error_end
			return NULL;
	}
}

RegDB *parseUserInput(char *path) {
	RegDB *Reg = (RegDB *)malloc(sizeof(RegistryDB));
	DatabaseFmt *dbf = (DatabaseFmt *)malloc(sizeof(DatabaseFmt));
#if defined(_X86_)
#endif
	FILE *fp = fopen(path, "rb");
	if (fp == NULL) {
		error_log			"[*] Can't Open Database File..\n"			error_end
			return NULL;
	}
	memset(dbf->Signature, 0, 6);
	fread(dbf->Signature, sizeof(char), 5, fp);					// Read Signature
	dbf->NumberOfData = fgetc(fp);								// Read NumberOfData
	dbf->Data = (char **)malloc(sizeof(char *) * dbf->NumberOfData);
	Reg->strg = (char **)malloc(sizeof(char *) * dbf->NumberOfData);
	for (int idx = 0; idx < dbf->NumberOfData; idx++) {
		dbf->Data[idx] = (char *)malloc(sizeof(char) * 256);
		fgets(dbf->Data[idx], 256, fp);
	}
	/* Set Data in RegDB */
	Reg->num = dbf->NumberOfData;
	for (int i = 0; i < Reg->num; i++) {
		Reg->strg[i] = (char *)malloc(sizeof(char) * 256);
		strcpy(Reg->strg[i], dbf->Data[i]);
	}
	free(dbf);
	return Reg;
}