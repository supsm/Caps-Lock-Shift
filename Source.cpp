#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	bool caps = false, shift = false;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.time = 0;
	input.ki.wVk = 20;
	input.ki.dwFlags = 0;
	if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0)
	{
		SendInput(1, &input, sizeof(INPUT));
		input.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &input, sizeof(INPUT));
		input.ki.dwFlags = 0;
		input.ki.wVk = 160;
		SendInput(1, &input, sizeof(INPUT));
		shift = true;
		caps = true;
	}
	while(true)
	{
		GetAsyncKeyState(20);
		system("CLS");
		cout << "Shift ";
		if (caps)
		{
			SetConsoleTextAttribute(console, 10);
			cout << "ON" << endl;
		}
		else
		{
			SetConsoleTextAttribute(console, 12);
			cout << "OFF" << endl;
		}
		SetConsoleTextAttribute(console, 15);
		while (GetAsyncKeyState(20) == 0)
		{
			if (caps && !shift)
			{
				input.ki.wVk = 160;
				SendInput(1, &input, sizeof(INPUT));
				shift = true;
			}
			Sleep(32);
		}
		while (GetAsyncKeyState(20) != 0)
		{
			Sleep(16);
		}
		if (shift)
		{
			input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(INPUT));
			input.ki.dwFlags = 0;
			input.ki.wVk = 20;
			shift = false;
		}
		SendInput(1, &input, sizeof(INPUT));
		input.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &input, sizeof(INPUT));
		input.ki.dwFlags = 0;
		caps = !caps;
	}
}