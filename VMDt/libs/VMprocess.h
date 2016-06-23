#pragma once
#include "../utils/hdrSet.h"
#include "../utils/vmdb.h"

void PrintProcessList(DWORD);
unsigned int CheckProcessList(char *);

int Filter(DWORD, char *);
vmdb *SetVariable(char *);
int getNumberOfData(char *);