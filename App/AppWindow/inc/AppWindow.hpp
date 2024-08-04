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

class AppWindow : public Window
{
public:
    AppWindow();
    ~AppWindow();

    // Inherited via Window
    virtual void onCreate() override;
    virtual void onUpdate() override;
    virtual void onDestroy() override;
};

#endif // _APP_WINDOW_H_