#include "Engine.h"
#include <atomic>

std::atomic<float> position[2] = { 0.0f, };

int listenFunction(SOCKET mySocket)
{
	while (true)
	{
		char buffer[8] = { 0, };
		recv(mySocket, buffer, 8, 0);
		float fbuffer[2] = { 0, };
		memcpy(fbuffer, buffer, 8);
		position[0].store(fbuffer[0]);
		position[1].store(fbuffer[1]);
	}
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

	const char* fortNum = "24642";
	const char* ip = "211.192.102.158";

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
	int portNumtemp = atoi(fortNum);
	servAddr.sin_port = htons(portNumtemp);

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
	{
		assert(false);
	}
	const char* data;
	std::thread t1(listenFunction, hSocket);
	
	
	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		ErrorLogger::Log(hr, "Failed to call CoInitialize.");
		return -1;
	}

	Engine engine;
	if (engine.Initialize(&hSocket, hInstance, "Title", "MyWindowClass", 800, 600))
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