#include "my_util.h"

void Detectlog(char *str) {
	printf("[*] VM Detected!! (%s)\n", str);
	_exit(0);
}