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
#include "IndexBuffer.hpp"
#include "VertexShader.hpp"
#include "PixelShader.hpp"
#include "ConstantBuffer.hpp"
#include "Vector3D.hpp"
#include "Matrix4x4.hpp"
#include "InputSystem.hpp"
#include <iostream>

struct vertex
{
	Vector3D position;
	Vector3D color;
	Vector3D color1;
};

__declspec(align(16))
struct constant
{
	Matrix4x4 m_world;
	Matrix4x4 m_view;
	Matrix4x4 m_proj;
	unsigned int m_time;
};

AppWindow::AppWindow()
	: m_swap_chain_p(nullptr), m_vertex_buffer_p(nullptr), m_vertex_shader_p(nullptr), m_pixel_shader_p(nullptr), m_constant_buffer_p(nullptr), 
	m_old_delta(0), m_new_delta(0), m_delta_time(0), m_delta_pos(0), m_delta_scale(0)
{
	// Constructor
}

void AppWindow::updateQuadPosition()
{
	constant cc;
	cc.m_time = ::GetTickCount64();

	m_delta_pos += m_delta_time / 10.0f;

	if (m_delta_pos > 1.0f)
	{
		m_delta_pos = 0;
	}

	Matrix4x4 temp;

	//cc.m_world.setTranslation(Vector3D::lerp(Vector3D(-1.5f,-1.5f,0), Vector3D(1.5f,1.5f,0), m_delta_pos));
	
	m_delta_scale += m_delta_time / 0.55f;

	//cc.m_world.setScale(Vector3D::lerp(Vector3D(0.5f,0.5f,0), Vector3D(1.0f, 1.0f,0), (sin(m_delta_scale)+1.0f)/2.0f));

	//temp.setTranslation(Vector3D::lerp(Vector3D(-1.5f, -1.5f, 0), Vector3D(1.5f, 1.5f, 0), m_delta_pos));

	//cc.m_world *= temp;

	cc.m_world.setScale(Vector3D(m_scale_cube, m_scale_cube, m_scale_cube));

	temp.setIdentity();
	temp.setRotationX(m_rot_x);
	cc.m_world *= temp;

	temp.setIdentity();
	temp.setRotationY(m_rot_y);
	cc.m_world *= temp;

	temp.setIdentity();
	temp.setRotationZ(0.0f);
	cc.m_world *= temp;

	cc.m_view.setIdentity();
	cc.m_proj.setOrthoLH
	(
		(this->getClientWindowRect().right - this->getClientWindowRect().left) / 300.0f,
		(this->getClientWindowRect().bottom - this->getClientWindowRect().top) / 300.0f,
		-4.0f,
		4.0f
	);

	m_constant_buffer_p->update(GraphicsEngine::get()->getImmediateDeviceContext(), &cc);
}

AppWindow::~AppWindow()
{
	// Destructor
}

void AppWindow::onCreate()
{
	InputSystem::get()->addListener(this);
	GraphicsEngine::get()->init();
	m_swap_chain_p = GraphicsEngine::get()->createSwapChain();

	RECT rectClient = this->getClientWindowRect();
	LONG rcWidth = rectClient.right - rectClient.left;
	LONG rcHeight = rectClient.bottom - rectClient.top;

	if (!m_swap_chain_p->init(this->m_hwnd, rcWidth, rcHeight, GraphicsEngine::get()))
	{
		std::cout << "Swap chain initialization failed" << std::endl;
	}

	vertex vertex_list[] =
	{
		//X - Y - Z
		//FRONT FACE
		{Vector3D(-0.5f,-0.5f,-0.5f),    Vector3D(1,0,0),  Vector3D(0.2f,0,0) },
		{Vector3D(-0.5f,0.5f,-0.5f),    Vector3D(1,1,0), Vector3D(0.2f,0.2f,0) },
		{ Vector3D(0.5f,0.5f,-0.5f),   Vector3D(1,1,0),  Vector3D(0.2f,0.2f,0) },
		{ Vector3D(0.5f,-0.5f,-0.5f),     Vector3D(1,0,0), Vector3D(0.2f,0,0) },

		//BACK FACE
		{ Vector3D(0.5f,-0.5f,0.5f),    Vector3D(0,1,0), Vector3D(0,0.2f,0) },
		{ Vector3D(0.5f,0.5f,0.5f),    Vector3D(0,1,1), Vector3D(0,0.2f,0.2f) },
		{ Vector3D(-0.5f,0.5f,0.5f),   Vector3D(0,1,1),  Vector3D(0,0.2f,0.2f) },
		{ Vector3D(-0.5f,-0.5f,0.5f),     Vector3D(0,1,0), Vector3D(0,0.2f,0) }
	};

	m_vertex_buffer_p = GraphicsEngine::get()->createVertexBuffer();

	unsigned int index_list[] = 
	{
		// FRONT SIDE
		0, 1, 2, // first triangle
		2, 3, 0, // second triangle
		// BACK SIDE
		4, 5, 6,
		6, 7, 4,
		// TOP SIDE
		1, 6, 5,
		5, 2, 1,
		// BOTTOM SIDE
		7, 0, 3,
		3, 4, 7,
		// RIGHT SIDE
		3, 2, 5,
		5, 4, 3,
		// LEFT SIDE
		7, 6, 1,
		1, 0, 7
	};

	m_index_buffer_p = GraphicsEngine::get()->createIndexBuffer();
	m_index_buffer_p->load(index_list, ARRAYSIZE(index_list), GraphicsEngine::get());

	void* shader_byte_code = nullptr;
	size_t shader_size = 0;
	GraphicsEngine::get()->compileVertexShader(L"VertexShader.hlsl", "vsmain", &shader_byte_code, &shader_size);
	
	m_vertex_shader_p = GraphicsEngine::get()->createVertexShader(shader_byte_code, shader_size);
	m_vertex_buffer_p->load(vertex_list, sizeof(vertex), ARRAYSIZE(vertex_list), shader_byte_code, shader_size, GraphicsEngine::get());

	GraphicsEngine::get()->releaseCompiledShader();

	GraphicsEngine::get()->compilePixelShader(L"PixelShader.hlsl", "psmain", &shader_byte_code, &shader_size);
	m_pixel_shader_p = GraphicsEngine::get()->createPixelShader(shader_byte_code, shader_size);
	GraphicsEngine::get()->releaseCompiledShader();

	constant cc;
	cc.m_time = 0;

	m_constant_buffer_p = GraphicsEngine::get()->createConstantBuffer();
	m_constant_buffer_p->load(&cc, sizeof(constant), GraphicsEngine::get());
}

void AppWindow::onUpdate()
{
	InputSystem::get()->update();

	GraphicsEngine::get()->getImmediateDeviceContext()->clearRenderTargetColor(this->m_swap_chain_p,
		0.2, 0, 0.4f, 1);

	RECT rc = this->getClientWindowRect();
	GraphicsEngine::get()->getImmediateDeviceContext()->setViewportSize(rc.right - rc.left, rc.bottom - rc.top);
	
	updateQuadPosition();

	GraphicsEngine::get()->getImmediateDeviceContext()->setConstantBuffer(m_vertex_shader_p, m_constant_buffer_p);
	GraphicsEngine::get()->getImmediateDeviceContext()->setConstantBuffer(m_pixel_shader_p, m_constant_buffer_p);

	GraphicsEngine::get()->getImmediateDeviceContext()->setVertexShader(m_vertex_shader_p);

	GraphicsEngine::get()->getImmediateDeviceContext()->setPixelShader(m_pixel_shader_p);

	GraphicsEngine::get()->getImmediateDeviceContext()->setVertexBuffer(m_vertex_buffer_p);
	
	GraphicsEngine::get()->getImmediateDeviceContext()->setIndexBuffer(m_index_buffer_p);

	GraphicsEngine::get()->getImmediateDeviceContext()->drawIndexedTriangleList(m_index_buffer_p->getSizeIndexList(), 0, 0);

	//GraphicsEngine::get()->getImmediateDeviceContext()->drawTriangleStrip(m_vertex_buffer_p->getSizeVertexList(), 0);
	m_swap_chain_p->present(true);

	m_old_delta = m_new_delta;
	m_new_delta = ::GetTickCount64();
	m_delta_time = (m_old_delta) ? ((m_new_delta - m_old_delta) / 1000.0f) : 0;
}

void AppWindow::onDestroy()
{
	Window::onDestroy();
	m_vertex_buffer_p->release();
	m_index_buffer_p->release();
	m_constant_buffer_p->release();
	m_swap_chain_p->release();
	m_vertex_shader_p->release();
	m_pixel_shader_p->release();
	GraphicsEngine::get()->release();
}

void AppWindow::onFocus()
{
	InputSystem::get()->addListener(this);
}

void AppWindow::onLostFocus()
{
	InputSystem::get()->removeListener(this);
}

void AppWindow::onKeyDown(int key)
{
	if (key == 'W')
	{
		m_rot_x += 3.14f * m_delta_time;
	}
	else if (key == 'S')
	{
		m_rot_x -= 3.14f * m_delta_time;
	}
	else if (key == 'A')
	{
		m_rot_y += 3.14f * m_delta_time;
	}
	else if (key == 'D')
	{
		m_rot_y -= 3.14f * m_delta_time;
	}
}

void AppWindow::onKeyUp(int key)
{

}

void AppWindow::onMouseMove(const Point& deltaMousePos)
{
	m_rot_x -= deltaMousePos.y * m_delta_time;
	m_rot_y -= deltaMousePos.x * m_delta_time;
}

void AppWindow::onLeftMouseDown(const Point& mousePos)
{
	m_scale_cube = 0.5f;
}

void AppWindow::onLeftMouseUp(const Point& mousePos)
{
	m_scale_cube = 1.0f;
}

void AppWindow::onRightMouseDown(const Point& mousePos)
{
	m_scale_cube = 2.0f;
}

void AppWindow::onRightMouseUp(const Point& mousePos)
{
	m_scale_cube = 1.0f;
}
