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
//           Synopsis: Interface for graphics engine functionality
//   Target system(s):
//        Compiler(s): VS16
//=============================================================================
//  I N I T I A L   A U T H O R   I D E N T I T Y
//-----------------------------------------------------------------------------
//        Name: Hoka David-Stelian
//  Department: Project Owner (CEO)
//=============================================================================
//  R E V I S I O N   I N F O R M A T I O N
//-----------------------------------------------------------------------------
/// @file
/// @brief Defines the IGraphicsEngine interface for graphics engine implementations.
/// @par Revision History:
///      $Source: IGraphicsEngine.hpp $
///      $Revision: 1.1 $
///      $Author: Hoka David-Stelian (CEO) (Dino3D) $
///      $Date: 2024/08/04 18:50:01 PM $
///      $Name:  $
///      $State: in_work $
//=============================================================================

#ifndef IGRAPHICSENGINE_H
#define IGRAPHICSENGINE_H

#include <d3d11.h>

/**
 * @interface IGraphicsEngine
 * @brief Interface for graphics engine functionality.
 *
 * The IGraphicsEngine interface defines the essential methods that any graphics
 * engine implementation must provide. This interface enables abstraction over
 * the underlying graphics API (DirectX 11 in this case), allowing for flexibility
 * and easier maintenance of code.
 */
class IGraphicsEngine 
{
public:

    /*--------------------------------------------------------------
        Destructor
    --------------------------------------------------------------*/

    /// <summary>
    /// Virtual destructor for the IGraphicsEngine interface.
    /// This ensures that derived classes can clean up resources properly.
    /// </summary>
    virtual ~IGraphicsEngine() = default;

    /*--------------------------------------------------------------
        Public Methods
    --------------------------------------------------------------*/

    /// <summary>
    /// Retrieves the DirectX 11 device associated with the graphics engine.
    /// The device is used to create and manage resources like buffers and shaders.
    /// </summary>
    /// <returns>A pointer to the ID3D11Device instance.</returns>
    virtual ID3D11Device* getDevice() = 0;

    /// <summary>
    /// Retrieves the DXGI factory associated with the graphics engine.
    /// The factory is responsible for creating DXGI objects such as swap chains and adapters.
    /// </summary>
    /// <returns>A pointer to the IDXGIFactory instance.</returns>
    virtual IDXGIFactory* getDXGIFactory() = 0;
};

#endif // IGRAPHICSENGINE_H
