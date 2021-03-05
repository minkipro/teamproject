#pragma once
#include "WindowContainer.h"

#include <thread>



class Engine : WindowContainer
{
public:
	bool Initialize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height);
	bool ProcessMessages();
	void Update(float x, float y);
	void RenderFrame();
};
