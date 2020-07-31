#include "AppWindow.h"



AppWindow::AppWindow()
{
}


void AppWindow::OnCreate()
{
	GraphicsEngine::Get()->Init();
}

void AppWindow::OnUpdate()
{

}

void AppWindow::OnDestroy()
{
	Window::OnDestroy();
	GraphicsEngine::Get()->Release();
}


AppWindow::~AppWindow()
{
}

