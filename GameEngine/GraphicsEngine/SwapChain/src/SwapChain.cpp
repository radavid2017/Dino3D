//=============================================================================
//  C O P Y R I G H T
//-----------------------------------------------------------------------------
// Copyright (c) 2024 by Hoka David-Stelian. All rights reserved.
//
//  This file is property of Hoka David-Stelian. Any unauthorized copy, use or
//  distribution is an offensive act against international law and may be
//  prosecuted under federal law. Its content is personal confidential.
//=============================================================================
// P R O J E C T   I N F O R M A T I O N
//-----------------------------------------------------------------------------
//       Project name: Dino3D
//           Synopsis: Definition of the SwapChain class for managing swap chains
//   Target system(s):
//        Compiler(s): VS16
//=============================================================================
//  N O T E S
//-----------------------------------------------------------------------------
//  Notes:
//  - Ensure that the DirectX 11 runtime is available on the target system.
//  - The SwapChain class must be properly initialized before use.
//=============================================================================
//  I N I T I A L   A U T H O R   I D E N T I T Y
//-----------------------------------------------------------------------------
//        Name: Hoka David-Stelian
//  Department: Project Owner (CEO)
//     Purpose: Design the SwapChain class to manage DirectX swap chains for rendering.
//=============================================================================
//  R E V I S I O N   I N F O R M A T I O N
//-----------------------------------------------------------------------------
/// @file
/// @brief Defines the SwapChain class for managing DirectX swap chains.
/// @par Revision History:
///      $Source: SwapChain.hpp $
///      $Revision: 1.1 $
///      $Author: Hoka David-Stelian (CEO) (Dino3D) $
///      $Date: 2024/08/04 18:50:01 PM $
///      $Name:  $
///      $State: in_work $
//=============================================================================

#include "SwapChain.hpp"
#include "Windows.h"
#include "IGraphicsEngine.hpp"
#include "GraphicsEngine.hpp"
#include "d3d11.h"

SwapChain::SwapChain()
{
}

bool SwapChain::init(HWND f_hwnd, UINT f_width, UINT f_height, IGraphicsEngine* f_engine)
{
	ID3D11Device* device = f_engine->getDevice();
	IDXGIFactory* factory = f_engine->getDXGIFactory();
	
	DXGI_SWAP_CHAIN_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.BufferCount = 1;
	desc.BufferDesc.Width = f_width;
	desc.BufferDesc.Height = f_height;
	desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	DEVMODE devMode;
	bool gotDisplayData = EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode);
	desc.BufferDesc.RefreshRate.Numerator = gotDisplayData ? devMode.dmDisplayFrequency : 60;
	desc.BufferDesc.RefreshRate.Denominator = 1;
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	desc.OutputWindow = f_hwnd;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Windowed = TRUE;

	// Create the swap chain for the window indicated by HWND parameter
	HRESULT hresult = factory->CreateSwapChain(device, &desc, &m_swapChain_p);
	
	if (FAILED(hresult))
	{
		return false;
	}

	ID3D11Texture2D* buffer = NULL;
	hresult = m_swapChain_p->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer);

	if (FAILED(hresult))
	{
		return false;
	}

	hresult = device->CreateRenderTargetView(buffer, NULL, &m_rtv);
	buffer->Release();

	return SUCCEEDED(hresult);
}

bool SwapChain::present(bool vsync)
{
	m_swapChain_p->Present(vsync, NULL);
	return true;
}

bool SwapChain::release()
{
	if (m_swapChain_p != nullptr) m_swapChain_p->Release();
	return true;
}

SwapChain::~SwapChain()
{

}