#include "unistd.h"
#include <windows.h>

void usleep(int32_t microsecond)
{
	Sleep(microsecond / 1000);
}