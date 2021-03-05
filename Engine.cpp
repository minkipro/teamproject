#include "Engine.h"
#include <stdio.h>
#include <WinSock2.h>
#include <assert.h>

bool Engine::Initialize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height)
{
	if (!this->render_window.Initialize(this, hInstance, window_title, window_class, width, height))
		return false;

	if (!gfx.Initialize(this->render_window.GetHWND(), width, height))
		return false;

	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

	int strLen = 0;
	int idx = 0;
	int readLen = 0;

	int fortNum = 17777;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		assert("")
	}

	return true;
}

bool Engine::ProcessMessages()
{
	return this->render_window.ProcessMessages();
}

void Engine::Update()
{
	while (!keyboard.CharBufferIsEmpty())
	{
		unsigned char ch = keyboard.ReadChar();
	}

	while (!keyboard.KeyBufferIsEmpty())
	{
		KeyboardEvent kbe = keyboard.ReadKey();
		unsigned char keycode = kbe.GetKeyCode();
	}

	while (!mouse.EventBufferIsEmpty())
	{
		MouseEvent me = mouse.ReadEvent();
	}

	if (keyboard.KeyIsPressed('W'))
	{
		this->gfx.objectPosition[1] += 0.01f;
	}
	if (keyboard.KeyIsPressed('A'))
	{
		this->gfx.objectPosition[0] -= 0.01f;
	}
	if (keyboard.KeyIsPressed('S'))
	{
		this->gfx.objectPosition[1] -= 0.01f;
	}
	if (keyboard.KeyIsPressed('D'))
	{
		this->gfx.objectPosition[0] += 0.01f;
	}
}

void Engine::RenderFrame()
{
	this->gfx.RenderFrame();
}