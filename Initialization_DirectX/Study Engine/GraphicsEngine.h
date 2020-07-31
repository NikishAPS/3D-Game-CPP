#pragma once
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

class GraphicsEngine
{
public:
	GraphicsEngine();

	bool Init(); //Initialize the GraphicsEngine and DirectX11 Device
	bool Release(); //Release all the resources loaded

	~GraphicsEngine();

	static GraphicsEngine* Get();

private:
	ID3D11Device *m_d3d_device;
	D3D_FEATURE_LEVEL m_feature_level;
	ID3D11DeviceContext* m_imm_context;
};

