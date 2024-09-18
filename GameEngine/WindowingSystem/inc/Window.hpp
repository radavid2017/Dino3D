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
//=============================================================================
//  I N I T I A L   A U T H O R   I D E N T I T Y
//-----------------------------------------------------------------------------
//        Name: Hoka David-Stelian
//  Department: Project Owner (CEO)
//=============================================================================
//  R E V I S I O N   I N F O R M A T I O N
//-----------------------------------------------------------------------------
/// @file
/// @brief add short description here
/// @par Revision History:
///      $Source: Window.hpp $
///      $Revision: 1.1 $
///      $Author: Hoka David-Stelian (CEO) (Dino3D) $
///      $Date: 2024/08/04 18:50:01 PM
///      $Name:  $
///      $State: in_work $
//=============================================================================

#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <Windows.h>

/**
 * @class Window
 * @brief Abstract base class for managing a system window.
 *
 * The `Window` class provides the basic structure and functionality for creating and managing a window
 * on the Windows OS platform. It includes methods for initializing the window, processing messages,
 * and handling the window's lifecycle events such as creation, updates, and destruction.
 *
 * This class is abstract, meaning it cannot be instantiated directly. Derived classes must implement
 * the `onCreate()`, `onUpdate()`, and potentially override `onDestroy()` to handle specific behavior
 * during these phases of the window's lifecycle.
 *
 * Key functionalities:
 * - Creating and initializing a window.
 * - Processing Windows OS messages to handle events such as input.
 * - Abstract methods for handling window creation, updates, and destruction.
 *
 * Example Usage:
 * @code
 * class MyAppWindow : public Window {
 * public:
 *     void onCreate() override {
 *         // Handle window creation logic here
 *     }
 *
 *     void onUpdate() override {
 *         // Handle per-frame update logic here
 *     }
 * };
 *
 * MyAppWindow appWindow;
 * if (appWindow.init()) {
 *     while (appWindow.isRunning()) {
 *         appWindow.broadcast();
 *     }
 * }
 * appWindow.release();
 * @endcode
 */
class Window
{
public:

	/*--------------------------------------------------------------
		Constructors and Destructor
	--------------------------------------------------------------*/

	/// <summary>
	/// Constructs a Window object.
	/// Initializes internal state but does not create the actual window on the screen.
	/// </summary>
	Window();

	/// <summary>
	/// Destructor for the Window class.
	/// Ensures that resources are released properly.
	/// </summary>
	~Window();
	
	/*--------------------------------------------------------------
		Public Methods
	--------------------------------------------------------------*/
	
	/// <summary>
	/// Initializes and creates the window on the screen, making it ready for use.
	/// This method must be called before interacting with the window.
	/// </summary>
	/// <returns>True if the window is successfully created, false otherwise.</returns>
	bool init();

	/// <summary>
	/// Processes incoming system messages (such as input events)
	/// and sends them to the window for handling.
	/// This method should be called frequently to keep the application responsive.
	/// </summary>
	/// <returns>True if messages are processed correctly, false otherwise.</returns>
	bool broadcast();

	/// <summary>
	/// Releases any resources or handles used by the window.
	/// Should be called when the window is no longer needed.
	/// </summary>
	/// <returns>True if resources are successfully released, false otherwise.</returns>
	bool release();

	/// <summary>
	/// Checks if the window is still open and processing messages.
	/// </summary>
	/// <returns>True if the window is running, false otherwise.</returns>
	bool isRunning();

	/*--------------------------------------------------------------
		Virtual Methods
	--------------------------------------------------------------*/

	/// <summary>
	/// Called when the window is created.
	/// It must be implemented by any class that derives from Window to handle initialization logic.
	/// </summary>
	virtual void onCreate() = 0;

	/// <summary>
	/// Called every time the window needs to be updated (e.g., during each frame).
	/// It must be implemented by any class that derives from Window to handle updates.
	/// </summary>
	virtual void onUpdate() = 0;

	/// <summary>
	/// Called when the window is about to be destroyed.
	/// Can be overridden to handle cleanup tasks specific to the derived class.
	/// </summary>
	virtual void onDestroy();

protected:

	/*--------------------------------------------------------------
		Protected Data Members
	--------------------------------------------------------------*/

	/// <summary>
	/// Handle to the created window (HWND), used for interacting with the Window OS.
	/// </summary>
	HWND m_hwnd;

	/// <summary>
	/// Boolean flag indicating whether the window is still running and processing events.
	/// </summary>
	bool m_isRunning;
};

#endif // !_WINDOW_H_