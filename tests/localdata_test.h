#pragma once

#ifdef _WIN32
#	include "localdata_win32_test.h"
#elif defined(__linux__)
#	include "localdata_posix_test.h"
#else
#	error "OS not supported"
#endif
