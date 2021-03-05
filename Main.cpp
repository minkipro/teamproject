#include "Engine.h"

float position[2] = { 0.0f, };

int listenFunction()
{
	/*while (true)
	{
		if (true)
		{
			return 1;
		}
	}*/
	return 1;
}
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	std::thread t1(listenFunction);

	
	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		ErrorLogger::Log(hr, "Failed to call CoInitialize.");
		return -1;
	}

	Engine engine;
	if (engine.Initialize(hInstance, "Title", "MyWindowClass", 800, 600))
	{
		while (engine.ProcessMessages() == true)
		{
			engine.Update(position[0], position[1]);
			engine.RenderFrame();
		}
	}
	t1.join();
	return 0;
}