#pragma once
#include <Windows.h>
#include <string>
#include "ErrorLogger.h"
using namespace std;
class MyWindow
{
private:
	HWND _handle;
	HINSTANCE _hInstance;
	string _window_title = "";
	string _window_class = "";
	int _width = 0;
	int _height = 0;

public:
	bool Initialize();
	bool ProcessMessage();
	HWND GetHWND() const;
	~MyWindow();
};

