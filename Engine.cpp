#pragma once
#include "Engine.h"

bool Engine::Initialize(SOCKET* pSocket, HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height)
{
	mSocket = pSocket;
	if (!this->render_window.Initialize(this, hInstance, window_title, window_class, width, height))
		return false;

	if (!gfx.Initialize(this->render_window.GetHWND(), width, height))
		return false;

	return true;
}

bool Engine::ProcessMessages()
{
	return this->render_window.ProcessMessages();
}

void Engine::Update(float x, float y)
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
	gfx.objectPosition[0] = x;
	gfx.objectPosition[1] = y;
	if (keyboard.KeyIsPressed('W'))
	{
		float myValue[2] = { gfx.objectPosition[0],gfx.objectPosition[1]+0.01f };
		char data[8] = { 0, };
		memcpy(data, &myValue, 8);
		send(*mSocket, data, 8, 0);
		//send data
		//this->gfx.objectPosition[1] += 0.01f;
	}
	if (keyboard.KeyIsPressed('A'))
	{
		float myValue[2] = { gfx.objectPosition[0] - 0.01f,gfx.objectPosition[1]};
		char data[8] = { 0, };
		memcpy(data, &myValue, 8);
		send(*mSocket, data, 8, 0);
		//send data
		//this->gfx.objectPosition[0] -= 0.01f;
	}
	if (keyboard.KeyIsPressed('S'))
	{
		float myValue[2] = { gfx.objectPosition[0],gfx.objectPosition[1] - 0.01f };
		char data[8] = { 0, };
		memcpy(data, &myValue, 8);
		send(*mSocket, data, 8, 0);
		//send data
		//this->gfx.objectPosition[1] -= 0.01f;
	}
	if (keyboard.KeyIsPressed('D'))
	{
		float myValue[2] = { gfx.objectPosition[0] + 0.01f,gfx.objectPosition[1]};
		char data[8] = { 0, };
		memcpy(data, &myValue, 8);
		send(*mSocket, data, 8, 0);
		//send data
		//this->gfx.objectPosition[0] += 0.01f;
	}
}

void Engine::RenderFrame()
{
	this->gfx.RenderFrame();
}