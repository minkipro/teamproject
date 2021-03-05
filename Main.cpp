#include "Engine.h"

bool checkOn = false;
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

	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

	int strLen = 0;
	int idx = 0;
	int readLen = 0;

	const char* fortNum = "17777";
	const char* ip = "192.168.75.149";

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		assert(false);
	}

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET)
	{
		assert(false);
	}

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr(ip);
	servAddr.sin_port = htons(atoi(fortNum));

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
	{
		assert(false);
	}

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

	closesocket(hSocket);
	WSACleanup();
	return 0;
}