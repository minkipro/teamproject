#pragma once
#include "WindowContainer.h"

#include <thread>
#include <stdio.h>
#include <assert.h>

class Engine : WindowContainer
{
private:
	SOCKET* mSocket = nullptr;
public:
	bool Initialize(SOCKET* pSocket, HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height);
	bool ProcessMessages();
	void Update(float x, float y);
	void RenderFrame();
};
