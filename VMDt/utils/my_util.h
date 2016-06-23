#pragma once
#include "hdrSet.h"

// void MvCharTMultiByte(wchar_t *src, char *dest);
// void MvMultiByteTChar(char *str, wchar_t *dest);
void Detectlog(char *);
#define DETECT_START			Detectlog(
#define DETECT_END				);