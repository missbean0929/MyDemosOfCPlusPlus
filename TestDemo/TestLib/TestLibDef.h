#pragma once

#ifdef TESTLIB_EXPORTS
#define TESTLIB_API __declspec(dllexport)
#else
#define TESTLIB_API __declspec(dllimport)
#endif


