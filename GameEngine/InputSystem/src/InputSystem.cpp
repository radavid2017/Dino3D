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
//           Synopsis: Input System class for keyboard and mouse input handling.
//   Target system(s):
//        Compiler(s): VS16
//=============================================================================
//  N O T E S
//-----------------------------------------------------------------------------
//  Notes:
//=============================================================================
//  I N I T I A L   A U T H O R   I D E N T I T Y
//-----------------------------------------------------------------------------
//        Name: Hoka David-Stelian
//  Department: Project Owner (CEO)
//=============================================================================
//  R E V I S I O N   I N F O R M A T I O N
//-----------------------------------------------------------------------------
/// @file InputSystem.cpp
/// @brief Input System class for keyboard and mouse input handling.
/// @par Revision History:
///      $Source: InputSystem.cpp $
///      $Revision: 1.1 $
///      $Author: Hoka David-Stelian (CEO) (Dino3D) $
///      $Date: 2024/08/04 18:50:01 PM
///      $Name:  $
///      $State: in_work $
//=============================================================================

#include "InputSystem.hpp"
#include "InputListener.hpp"
#include "Point.hpp"
#include <Windows.h>

void InputSystem::update()
{
	POINT l_currentMousePos = {};
	::GetCursorPos(&l_currentMousePos);
	m_currentMousePos = Point(l_currentMousePos.x, l_currentMousePos.y);

	// First time initialization
	if(m_firstTime)
	{
		m_oldMousePos = m_currentMousePos;
		m_firstTime = false;
	}

	if (m_currentMousePos.x != m_oldMousePos.x || m_currentMousePos.y != m_oldMousePos.y)
	{
		for (auto& it = m_listeners.begin(); it != m_listeners.end(); ++it)
		{
			(*it)->onMouseMove(Point(
				m_currentMousePos.x - m_oldMousePos.x,
				m_currentMousePos.y - m_oldMousePos.y
			));
		}
		// Store the old position
		m_oldMousePos = m_currentMousePos;
	}

	if (::GetKeyboardState(m_keysState))
	{
		for (unsigned int i = 0; i < 256; ++i)
		{
			if (m_keysState[i] & 0x80) // Key is down
			{
				for (auto& it = m_listeners.begin() ; it != m_listeners.end(); ++it)
				{
					if (i == VK_LBUTTON && m_keysState[i] != m_oldKeyState[i]) // Left mouse button is down
					{
						(*it)->onLeftMouseDown(m_currentMousePos);
					}
					else if (i == VK_RBUTTON && m_keysState[i] != m_oldKeyState[i]) // Right mouse button is down
					{
						(*it)->onRightMouseDown(m_currentMousePos);
					}
					else // Key is down
					{
						(*it)->onKeyDown(i);
					}
				}
			}
			else if(m_keysState[i] != m_oldKeyState[i]) // Key is up
			{
				for (auto& it = m_listeners.begin(); it != m_listeners.end(); ++it)
				{
					if (i == VK_LBUTTON) // Left mouse button is up
					{
						(*it)->onLeftMouseUp(m_currentMousePos);
					}
					else if (i == VK_RBUTTON) // Right mouse button is up
					{
						(*it)->onRightMouseUp(m_currentMousePos);
					}
					else // Key is up
					{
						(*it)->onKeyUp(i);
					}
				}
			}
		}
		// Store the old state
		::memcpy(m_oldKeyState, m_keysState, sizeof(m_keysState));
	}
}

void InputSystem::addListener(InputListener* listener)
{
	m_listeners.insert(listener);
}

void InputSystem::removeListener(InputListener* listener)
{
	m_listeners.erase(listener);
}

InputSystem* InputSystem::get()
{
	static InputSystem instance;
	return &instance;
}
