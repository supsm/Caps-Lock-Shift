#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	int cycles = 48;
	ShowWindow(GetConsoleWindow(), SW_HIDE);
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
		input.ki.wVk = 161;
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
		int count = 0;
		while (GetAsyncKeyState(20) == 0)
		{
			if (caps && !shift)
			{
				input.ki.wVk = 161;
				input.ki.dwFlags = 0;
				SendInput(1, &input, sizeof(INPUT));
				shift = true;
				cycles = 16;
			}
			Sleep(32);
			count++;
			if (count == cycles && shift)
			{
				if (cycles < 48)
				{
					cycles += 8;
				}
				count = 0;
				input.ki.wVk = 20;
				input.ki.dwFlags = 0;
				SendInput(1, &input, sizeof(INPUT));
				input.ki.dwFlags = KEYEVENTF_KEYUP;
				SendInput(1, &input, sizeof(INPUT));
				Sleep(32);
				GetAsyncKeyState(20);
				input.ki.dwFlags = 0;
				SendInput(1, &input, sizeof(INPUT));
				input.ki.dwFlags = KEYEVENTF_KEYUP;
				SendInput(1, &input, sizeof(INPUT));
				input.ki.dwFlags = 0;
				GetAsyncKeyState(20);
			}
			if (GetAsyncKeyState(161) == 0 && caps)
			{
				input.ki.wVk = 161;
				input.ki.dwFlags = 0;
				SendInput(1, &input, sizeof(INPUT));
			}
		}
		while (GetAsyncKeyState(20) != 0)
		{
			Sleep(16);
		}
		if (shift)
		{
			input.ki.wVk = 161;
			input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(INPUT));
			shift = false;
		}
		input.ki.wVk = 20;
		input.ki.dwFlags = 0;
		SendInput(1, &input, sizeof(INPUT));
		input.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &input, sizeof(INPUT));
		caps = !caps;
	}
}
