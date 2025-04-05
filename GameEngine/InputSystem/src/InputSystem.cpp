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
#include <Windows.h>

void InputSystem::update()
{
	if (::GetKeyboardState(m_keysState))
	{
		for (unsigned int i = 0; i < 256; ++i)
		{
			if (m_keysState[i] & 0x80) // Key is down
			{
				for (auto& it = m_listeners.begin() ; it != m_listeners.end(); ++it)
				{
					(*it)->onKeyDown(i);
				}
			}
			else if(m_keysState[i] != m_oldKeyState[i]) // Key is up
			{
				for (auto& it = m_listeners.begin(); it != m_listeners.end(); ++it)
				{
					(*it)->onKeyUp(i);
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
