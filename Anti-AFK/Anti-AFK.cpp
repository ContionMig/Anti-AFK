// Anti-AFK.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "includes.h"

static bool Enabled = false;
static bool hasQuite = false;

DWORD ThreadID;
DWORD WINAPI CheckToggle(void* Param)
{
	while (!hasQuite)
	{
		if (GetAsyncKeyState(VK_F10) & 0x8000)
		{
			Enabled = !Enabled;
			printf("Toggled: %s\n", Enabled ? "On" : "Off");
		}

		if (GetAsyncKeyState(VK_F11) & 0x8000)
			hasQuite = !hasQuite;

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	return 0;
}

int main()
{
	DWORD WalkKeys[4] = { 0x57, 0x41, 0x53, 0x44 };

	Utils::WelcomeMessage();
	CreateThread(NULL, 0, CheckToggle, NULL, 0, &ThreadID);

	while (!hasQuite)
	{
		if (Enabled)
			Utils::SendKeyStroke(WalkKeys[Utils::random(1, 4)]);
		
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	printf("Good Bye!\n");
	system("pause");
}
