#include "my_util.h"

void Detectlog(char *str) {
	printf("[*] VM Detected!! (%s)\n", str);
	_exit(0);
}
void QuitProcess(unsigned int num) {
	printf("[*] Exit Process.. CODE : 0x%x\n", num);
	_exit(num);
}
void tolowercase(unsigned char* Pstr) {
	char* P = (char*)Pstr;
	unsigned long length = strlen(P);
	for (unsigned long i = 0; i < length; i++) P[i] = tolower(P[i]);
	return;
}
HANDLE handle_ret(wchar_t *path) {
	HANDLE hHandle = CreateFile(path, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE,
		0, OPEN_EXISTING, 0, 0);
	return hHandle;
}