#include "GraphicsEngine.h"



GraphicsEngine::GraphicsEngine()
{
}

bool GraphicsEngine::Init()
{
	D3D_DRIVER_TYPE driver_types[] =
	{
		D3D_DRIVER_TYPE_HARDWARE, //драйвер для вызовов рисования с помощью GPU
		D3D_DRIVER_TYPE_WARP, //CPU
		D3D_DRIVER_TYPE_REFERENCE //
	};
	UINT num_driver_types = ARRAYSIZE(driver_types);

	D3D_FEATURE_LEVEL feature_levels[] =
	{
		D3D_FEATURE_LEVEL_11_0
	};
	UINT num_feature_levels = ARRAYSIZE(feature_levels);

	HRESULT hResult{};
	for (UINT driver_type_index = 0; driver_type_index < num_driver_types; driver_type_index++)
	{
		//получение доступа к ресурсам DX
		hResult = D3D11CreateDevice(NULL, driver_types[driver_type_index], NULL, NULL, feature_levels,
			num_feature_levels, D3D11_SDK_VERSION, &m_d3d_device, &m_feature_level, &m_imm_context);

		if (SUCCEEDED(hResult))
		{
			break;
		}
	}

	if (FAILED(hResult))
	{
		return false;
	}

	return true;
}

bool GraphicsEngine::Release()
{
	m_d3d_device->Release();
	m_imm_context->Release();
	return true;
}

GraphicsEngine::~GraphicsEngine()
{
}

GraphicsEngine* GraphicsEngine::Get()
{
	static GraphicsEngine engine;
	return &engine;
}
