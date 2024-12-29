//=============================================================================
//  C O P Y R I G H T
//-----------------------------------------------------------------------------
// Copyright (c) 2024 by Hoka David-Stelian. All rights reserved.
//
//  This file is property of Hoka David-Stelian. Any unauthorised copy, use or
//  distribution is an offensive act against international law and may be
//  prosecuted under federal law. Its content is personal confidential.
//=============================================================================
// P R O J E C T   I N F O R M A T I O N
//-----------------------------------------------------------------------------
//       Project name: Dino3D
//           Synopsis: abstract wrapper library for Windows class
//   Target system(s):
//        Compiler(s): VS16
//=============================================================================
//  N O T E S
//-----------------------------------------------------------------------------
//  Notes:
//  - Ensure that the DirectX 11 runtime is available on the target system.
//  - The GraphicsEngine class should only be used after initializing with init().
//=============================================================================
//  I N I T I A L   A U T H O R   I D E N T I T Y
//-----------------------------------------------------------------------------
//        Name: Hoka David-Stelian
//  Department: Project Owner (CEO)
//     Purpose: Design the core graphics engine wrapper using DirectX 11.
//=============================================================================
//  R E V I S I O N   I N F O R M A T I O N
//-----------------------------------------------------------------------------
/// @file
/// @brief add short description here
/// @par Revision History:
///      $Source: GraphicsEngine.cpp $
///      $Revision: 1.1 $
///      $Author: Hoka David-Stelian (CEO) (Dino3D) $
///      $Date: 2024/08/04 18:50:01 PM
///      $Name:  $
///      $State: in_work $
//=============================================================================

#include "GraphicsEngine.hpp"
#include "SwapChain.hpp"
#include "DeviceContext.hpp"
#include <d3d11.h>

SwapChain* GraphicsEngine::createSwapChain()
{
    return new SwapChain();
}

DeviceContext* GraphicsEngine::getImmediateDeviceContext()
{
    return this->m_imm_device_context_p;
}

GraphicsEngine* GraphicsEngine::get()
{
    static GraphicsEngine engine;
    return &engine;
}

GraphicsEngine::GraphicsEngine()
{
}

bool GraphicsEngine::init()
{
    D3D_DRIVER_TYPE driver_types[] =
    {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE
    };
    UINT num_driver_types = ARRAYSIZE(driver_types);
    
    D3D_FEATURE_LEVEL feature_levels[] =
    {
        D3D_FEATURE_LEVEL_11_0
    };
    UINT num_feature_levels = ARRAYSIZE(feature_levels);

    HRESULT res = 0;
    ID3D11DeviceContext* imm_context_p;
    for (UINT idx = 0; idx < num_driver_types; idx++)
    {
         res = D3D11CreateDevice(NULL, driver_types[idx], NULL, NULL,
            feature_levels, num_feature_levels, D3D11_SDK_VERSION,
            &m_d3d_device_p, &m_feature_level_p, &imm_context_p);
         if (SUCCEEDED(res)) break;
    }

    if (FAILED(res))
    {
        return false;
    }

    m_imm_device_context_p = new DeviceContext(imm_context_p);

    m_d3d_device_p->QueryInterface(__uuidof(IDXGIDevice), (void**)&m_dxgi_device_p);
    m_dxgi_device_p->GetParent(__uuidof(IDXGIAdapter), (void**)&m_dxgi_adapter_p);
    m_dxgi_adapter_p->GetParent(__uuidof(IDXGIFactory), (void**)&m_dxgi_factory_p);

    return true;
}

bool GraphicsEngine::release()
{
    if (m_dxgi_device_p) m_dxgi_device_p->Release();
    if (m_dxgi_adapter_p) m_dxgi_adapter_p->Release();
    if (m_dxgi_factory_p) m_dxgi_factory_p->Release();
    if (m_imm_device_context_p) m_imm_device_context_p->release();
    if (m_d3d_device_p) m_d3d_device_p->Release();
    return true;
}

GraphicsEngine::~GraphicsEngine()
{

}