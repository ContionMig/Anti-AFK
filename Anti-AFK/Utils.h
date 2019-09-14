#pragma once
#include "includes.h"

namespace Utils
{
	extern void WelcomeMessage();
	extern void SendKeyStroke(DWORD key);
	extern DWORD FindProcessId(const std::wstring& processName);
	extern int random(int min, int max);
}