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
//           Synopsis: wrapper library for Window abstract class
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
///      $Source: AppWindow.hpp $
///      $Revision: 1.1 $
///      $Author: Hoka David-Stelian (CEO) (Dino3D) $
///      $Date: 2024/08/04 18:50:01 PM
///      $Name:  $
///      $State: in_work $
//=============================================================================

#ifndef _APP_WINDOW_H_

#define _APP_WINDOW_H_

#include "Window.hpp"

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
};

#endif // _APP_WINDOW_H_