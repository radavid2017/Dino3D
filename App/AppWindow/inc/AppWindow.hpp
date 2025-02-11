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

#ifndef _APP_WINDOW_H_

#define _APP_WINDOW_H_

#include "Window.hpp"

class GraphicsEngine;
class SwapChain;
class VertexBuffer;
class VertexShader;
class PixelShader;
class ConstantBuffer;

/**
 * @class AppWindow
 * @brief Manages the application-specific window lifecycle and behavior.
 *
 * The AppWindow class inherits from the Window class and provides specific
 * functionality needed for an application window. This class is responsible
 * for handling window creation, updates, and destruction, which are essential
 * for the application's runtime behavior.
 *
 * AppWindow extends the functionality of Window by overriding several key
 * methods that control the window's lifecycle, such as onCreate(), onUpdate(),
 * and onDestroy().
 *
 * Example Usage:
 * @code
 * AppWindow app;
 * app.createWindow(800, 600, "My Application");
 * app.show();
 * // Application loop would go here
 * app.close();
 * @endcode
 */
class AppWindow : public Window
{
public:

    /*--------------------------------------------------------------
        Constructors and Destructor
    --------------------------------------------------------------*/

    /// <summary>
    /// Constructs an AppWindow object, initializing the application-specific settings.
    /// </summary>
    AppWindow();

    /*--------------------------------------------------------------
		Public Methods
    --------------------------------------------------------------*/

	void updateQuadPosition();

    /// <summary>
    /// Destructor for the AppWindow class.
    /// Ensures that all resources are cleaned up correctly when the window is closed.
    /// </summary>
    ~AppWindow();

    /*--------------------------------------------------------------
        Inherited Methods
    --------------------------------------------------------------*/

    /// <summary>
    /// Called when the application window is created.
    /// Initializes any resources or application state needed at startup.
    /// </summary>
    virtual void onCreate() override;

    /// <summary>
    /// Called during each frame or update cycle.
    /// Handles logic that needs to occur periodically, such as rendering or input processing.
    /// </summary>
    virtual void onUpdate() override;

    /// <summary>
    /// Called when the application window is destroyed.
    /// Cleans up any resources allocated during the window's lifetime.
    /// </summary>
    virtual void onDestroy() override;

private:

    /*--------------------------------------------------------------
        Private Data Members
    --------------------------------------------------------------*/

    /// <summary>
    /// A pointer to the SwapChain instance associated with the AppWindow.
    /// This swap chain manages the presentation of rendered images.
    /// </summary>
    SwapChain* m_swap_chain_p;

	/// <summary>
	/// A pointer to the VertexBuffer instance associated with the AppWindow.
	/// </summary>
	VertexBuffer* m_vertex_buffer_p;

	/// <summary>
	/// A pointer to the VertexShader instance associated with the AppWindow.
	/// </summary>
	VertexShader* m_vertex_shader_p;

	/// <summary>
	/// A pointer to the PixelShader instance associated with the AppWindow.
	/// </summary>
	PixelShader* m_pixel_shader_p;

	/// <summary>
	/// A pointer to the ConstantBuffer instance associated with the AppWindow.
	/// </summary>
	ConstantBuffer* m_constant_buffer_p;
	
	long m_old_delta;
	long m_new_delta;
	float m_delta_time;

    float m_delta_pos;
	float m_delta_scale;

    /*--------------------------------------------------------------
		Friends
	--------------------------------------------------------------*/
	
    /// <summary>
	/// Declares GraphicsEngine as a friend class, allowing it access to the private members
	/// of AppWindow. This is necessary because the GraphicsEngine class needs direct
	/// access to certain low-level DirectX objects managed by AppWindow, such as
	/// the swap chain, to function properly.
	/// </summary>
	friend class GraphicsEngine;
};

#endif // _APP_WINDOW_H_