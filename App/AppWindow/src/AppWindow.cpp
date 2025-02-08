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
//           Synopsis: Wrapper library for Window abstract class
//   Target system(s):
//        Compiler(s): VS16
//=============================================================================
//  N O T E S
//-----------------------------------------------------------------------------
//  Notes:
//  - This class is intended to manage application-specific window behavior.
//  - Ensure that the window lifecycle methods are properly overridden.
//=============================================================================
//  I N I T I A L   A U T H O R   I D E N T I T Y
//-----------------------------------------------------------------------------
//        Name: Hoka David-Stelian
//  Department: Project Owner (CEO)
//     Purpose: Design an application-specific window management class.
//=============================================================================
//  R E V I S I O N   I N F O R M A T I O N
//-----------------------------------------------------------------------------
/// @file
/// @brief Defines the AppWindow class for managing application windows.
/// @par Revision History:
///      $Source: AppWindow.hpp $
///      $Revision: 1.1 $
///      $Author: Hoka David-Stelian (CEO) (Dino3D) $
///      $Date: 2024/08/04 18:50:01 PM $
///      $Name:  $
///      $State: in_work $
//=============================================================================

#include "AppWindow.hpp"
#include "GraphicsEngine.hpp"
#include "SwapChain.hpp"
#include "DeviceContext.hpp"
#include "VertexBuffer.hpp"
#include "VertexShader.hpp"
#include "PixelShader.hpp"
#include <iostream>

struct vec3
{
	float x, y, z;
};

struct vertex
{
	vec3 position;
	vec3 color;
};

AppWindow::AppWindow()
{
	// Constructor
}

AppWindow::~AppWindow()
{
	// Destructor
}

void AppWindow::onCreate()
{
	GraphicsEngine::get()->init();
	m_swap_chain_p = GraphicsEngine::get()->createSwapChain();

	RECT rectClient = this->getClientWindowRect();
	LONG rcWidth = rectClient.right - rectClient.left;
	LONG rcHeight = rectClient.bottom - rectClient.top;

	if (!m_swap_chain_p->init(this->m_hwnd, rcWidth, rcHeight, GraphicsEngine::get()))
	{
		std::cout << "Swap chain initialization failed" << std::endl;
	}

	vertex list[] = {
		// X, Y, Z
		{-0.5f, -0.5f, 0.0f,	0,0,0},	// POS1, COLOR1
		{-0.5f, 0.5f, 0.0f,		1,1,0},	// POS2, COLOR2
		{0.5f, -0.5f, 0.0f,		0,0,1},	// POS3, COLOR3
		{0.5f, 0.5f, 0.0f,		1,1,1},	// POS4, COLOR4
	};

	m_vertex_buffer_p = GraphicsEngine::get()->createVertexBuffer();

	void* shader_byte_code = nullptr;
	size_t shader_size = 0;
	GraphicsEngine::get()->compileVertexShader(L"VertexShader.hlsl", "vsmain", &shader_byte_code, &shader_size);
	
	m_vertex_shader_p = GraphicsEngine::get()->createVertexShader(shader_byte_code, shader_size);
	m_vertex_buffer_p->load(list, sizeof(vertex), ARRAYSIZE(list), shader_byte_code, shader_size, GraphicsEngine::get());

	GraphicsEngine::get()->releaseCompiledShader();

	GraphicsEngine::get()->compilePixelShader(L"PixelShader.hlsl", "psmain", &shader_byte_code, &shader_size);
	m_pixel_shader_p = GraphicsEngine::get()->createPixelShader(shader_byte_code, shader_size);
	GraphicsEngine::get()->releaseCompiledShader();
}

void AppWindow::onUpdate()
{
	GraphicsEngine::get()->getImmediateDeviceContext()->clearRenderTargetColor(this->m_swap_chain_p,
		0.2, 0, 0.4f, 1);

	RECT rc = this->getClientWindowRect();
	GraphicsEngine::get()->getImmediateDeviceContext()->setViewportSize(rc.right - rc.left, rc.bottom - rc.top);
	
	GraphicsEngine::get()->getImmediateDeviceContext()->setVertexShader(m_vertex_shader_p);

	GraphicsEngine::get()->getImmediateDeviceContext()->setPixelShader(m_pixel_shader_p);

	GraphicsEngine::get()->getImmediateDeviceContext()->setvertexBuffer(m_vertex_buffer_p);

	GraphicsEngine::get()->getImmediateDeviceContext()->drawTriangleStrip(m_vertex_buffer_p->getSizeVertexList(), 0);
	m_swap_chain_p->present(true);
}

void AppWindow::onDestroy()
{
	Window::onDestroy();
	m_vertex_buffer_p->release();
	m_swap_chain_p->release();
	m_vertex_shader_p->release();
	m_pixel_shader_p->release();
	GraphicsEngine::get()->release();
}