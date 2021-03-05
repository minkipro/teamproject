#include "Engine.h"

bool Engine::Initialize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height)
{
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
		//send data
		//this->gfx.objectPosition[1] += 0.01f;
	}
	if (keyboard.KeyIsPressed('A'))
	{
		//send data
		//this->gfx.objectPosition[0] -= 0.01f;
	}
	if (keyboard.KeyIsPressed('S'))
	{
		//send data
		//this->gfx.objectPosition[1] -= 0.01f;
	}
	if (keyboard.KeyIsPressed('D'))
	{
		//send data
		//this->gfx.objectPosition[0] += 0.01f;
	}
}

void Engine::RenderFrame()
{
	this->gfx.RenderFrame();
}