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
///      $Source: GraphicsEngine.hpp $
///      $Revision: 1.1 $
///      $Author: Hoka David-Stelian (CEO) (Dino3D) $
///      $Date: 2024/08/04 18:50:01 PM
///      $Name:  $
///      $State: in_work $
//=============================================================================

#ifndef _GRAPHICS_ENGINE_H_
#define _GRAPHICS_ENGINE_H_

#include <d3d11.h>

/**
 * @class GraphicsEngine
 * @brief Manages the initialization, operation, and cleanup of DirectX 11 resources for rendering.
 *
 * The GraphicsEngine class is designed to be a singleton, ensuring that only one instance of the
 * engine exists at any given time. It is responsible for creating and maintaining the DirectX 11
 * device, the immediate device context, and managing the DirectX feature level.
 *
 * This engine provides an interface for initializing and releasing DirectX 11 resources, which
 * are necessary for rendering operations in a 3D application. Users of this class should first
 * call the init() method to initialize the DirectX components, and release() to clean up resources
 * when done.
 *
 * Key functionalities:
 * - Initialization and configuration of DirectX 11 Device and Device Context.
 * - Singleton design pattern ensuring only one GraphicsEngine instance exists.
 * - Management of DirectX resources lifecycle (init and release methods).
 *
 * Example Usage:
 * @code
 * // Get the singleton instance of GraphicsEngine
 * GraphicsEngine* engine = GraphicsEngine::get();
 *
 * // Initialize the engine
 * if (!engine->init()) {
 *     // Handle initialization failure
 * }
 *
 * // Perform rendering operations here
 *
 * // Release resources when done
 * engine->release();
 * @endcode
 */
class GraphicsEngine {

public:

    /*--------------------------------------------------------------
        Factory Methods
    --------------------------------------------------------------*/

    /// <summary>
    /// Retrieves the singleton instance of the GraphicsEngine.
    /// This ensures only one instance of the GraphicsEngine exists at any time.
    /// </summary>
    /// <returns>A pointer to the GraphicsEngine instance.</returns>
    static GraphicsEngine* get();

    /*--------------------------------------------------------------
        Constructors and Assignment Operators
    --------------------------------------------------------------*/

    /// <summary>
    /// Constructor for GraphicsEngine.
    /// Initializes members but does not set up the DirectX device.
    /// </summary>
    GraphicsEngine();

    /// <summary>
    /// Copy constructor is deleted to prevent copying of the singleton.
    /// </summary>
    GraphicsEngine(const GraphicsEngine&) = delete;

    /// <summary>
    /// Copy assignment operator is deleted to prevent copying of the singleton.
    /// </summary>
    GraphicsEngine& operator=(const GraphicsEngine&) = delete;

    /*--------------------------------------------------------------
        Destructor
    --------------------------------------------------------------*/

    /// <summary>
    /// Destructor for GraphicsEngine.
    /// Calls the release method to clean up resources.
    /// </summary>
    ~GraphicsEngine();

    /*--------------------------------------------------------------
        Public Methods
    --------------------------------------------------------------*/

    /// <summary>
    /// Initializes the GraphicsEngine and sets up the DirectX 11 Device and Context.
    /// This method should be called before any rendering operations.
    /// </summary>
    /// <returns>True if initialization is successful, false if it fails.</returns>
    bool init();

    /// <summary>
    /// Releases all resources associated with the GraphicsEngine, including the DirectX device and context.
    /// </summary>
    /// <returns>True if resources were successfully released, false if an error occurred.</returns>
    bool release();

private:

    /*--------------------------------------------------------------
        Private Data Members
    --------------------------------------------------------------*/

    /// <summary>
    /// A pointer to the DirectX 11 device interface.
    /// This device is used to create resources such as buffers and textures.
    /// </summary>
    ID3D11Device* m_d3d_device_p = nullptr;

    /// <summary>
    /// A pointer to the feature level of the DirectX device.
    /// This determines the feature set supported by the device (e.g., DirectX 11.0, 11.1).
    /// </summary>
    D3D_FEATURE_LEVEL m_feature_level_p = D3D_FEATURE_LEVEL_11_0;

    /// <summary>
    /// A pointer to the immediate device context.
    /// The context is used to issue rendering commands to the GPU.
    /// </summary>
    ID3D11DeviceContext* m_imm_context_p = nullptr;
};

#endif // !_GRAPHICS_ENGINE_H_