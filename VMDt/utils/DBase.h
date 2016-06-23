#pragma once
#include "../libs/VMprocess.h"
#include "hdrSet.h"
#include "../libs/vmReg.h"
#include "encrypt.h"

RegDB *parseDatabase(HKEY RootKey);
int getSwitch(HKEY);
typedef struct DatabaseFmt {
	char Signature[6];
	int NumberOfData;
	char **Data;
}db_fmt, *pdb_fmt;