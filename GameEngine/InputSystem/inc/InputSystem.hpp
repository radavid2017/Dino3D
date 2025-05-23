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
/// @file InputSystem.hpp
/// @brief Input System class for keyboard and mouse input handling.
/// @par Revision History:
///      $Source: InputSystem.hpp $
///      $Revision: 1.1 $
///      $Author: Hoka David-Stelian (CEO) (Dino3D) $
///      $Date: 2024/08/04 18:50:01 PM
///      $Name:  $
///      $State: in_work $
//=============================================================================

#ifndef _INPUT_SYSTEM_H_
#define _INPUT_SYSTEM_H_

// Forward declarations
class InputListener;
#include "Point.hpp"
#include <unordered_set>

class InputSystem
{
public:
	InputSystem() = default;
	~InputSystem() = default;

	void update();
	void addListener(InputListener* listener);
	void removeListener(InputListener* listener);
	static InputSystem* get(); // Singleton pattern - get instance

private:
	std::unordered_set<InputListener*> m_listeners; // List of listeners
	unsigned char m_keysState[256] = {}; // Keyboard state array
	unsigned char m_oldKeyState[256] = {}; // Previous keyboard state array
	Point m_oldMousePos; // Previous mouse position
	Point m_currentMousePos; // Current mouse position
	bool m_firstTime = true; // First time flag
};

#endif // !_INPUT_SYSTEM_H_