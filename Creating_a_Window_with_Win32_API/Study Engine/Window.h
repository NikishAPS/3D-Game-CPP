#pragma once

#include <iostream>
#include <stdio.h>
#include <Windows.h>

class Window
{
public:
	Window();

	bool Init();
	bool Broadcast();

	bool Release();
	bool IsRun();

	virtual void OnCreate();
	virtual void OnUpdate();
	virtual void OnDestroy();

	~Window();

protected:
	HWND hWnd{};
	bool is_run{};
};

