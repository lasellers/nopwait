// nopwait.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "conio.h"

#include <stdio.h>
#include <intrin.h>

#include "windows.h"
#include "winbase.h"

#pragma intrinsic(__rdtsc) //  /Oi (Generate Intrinsic Functions)
#ifdef _WIN64
__int64 get_rdtsc_64()
{
	return __rdtsc();
}
#else
__int64 get_rdtsc_32() {
	unsigned int hiword = 0, loword = 0;
	_asm
	{
		_emit 0x0f	// insert rtdsc opcode
		_emit 0x31
		mov hiword , edx
		mov loword , eax
	}
	return ((__int64) hiword << 32) + loword;
}
#endif

//int main(int argc, char* argv[])
int _tmain(int argc, _TCHAR* argv[])
{
	unsigned __int64 rdtsc = 0;
#ifdef _WIN64
	rdtsc=get_rdtsc_64();
#else
	rdtsc = get_rdtsc_32();
#endif

#ifdef _WIN64
	printf("_WIN64 (Thread #%u) This program does nothing but print this line of text. Then wait for you to press any key before exiting.... Processor Time Stamp Counter ==> %I64d\n",
		GetCurrentThreadId(),
		rdtsc);
#else
	printf(
			"_WIN32 (Thread #%u) This program does nothing but print this line of text. Then wait for you to press any key before exiting.... Processor Time Stamp Counter ==> %I64d\n",
		GetCurrentThreadId(),
		rdtsc);
#endif

	printf("\nPress any key.\n");

	_getch();

	printf("\nA key was pressed. Now exiting.\n");

#ifdef _WIN64
	rdtsc=get_rdtsc_64();
#else
	rdtsc = get_rdtsc_32();
#endif

#ifdef _WIN64
	printf("\n_WIN64 A key was pressed. Now exiting. Processor Time Stamp Counter ==> %I64d\n",rdtsc);
#else
	printf(
			"\n_WIN32 A key was pressed. Now exiting. Processor Time Stamp Counter ==> %I64d\n",
			rdtsc);
#endif

	return 0;
}
