//=============================================================================
//  C O P Y R I G H T
//-----------------------------------------------------------------------------
// Copyright (c) 2025 by Hoka David-Stelian. All rights reserved.
//
//  This file is property of Hoka David-Stelian. Any unauthorized copy, use or
//  distribution is an offensive act against international law and may be
//  prosecuted under federal law. Its content is personal confidential.
//=============================================================================
// P R O J E C T   I N F O R M A T I O N
//-----------------------------------------------------------------------------
//       Project name: Dino3D
//           Synopsis: Interface for device context functionality
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

#ifndef IDEVICECONTEXT_H
#define IDEVICECONTEXT_H

#include <d3d11.h>

/**
 * @interface IDeviceContext
 * @brief Interface for device context functionality.
 *
 * The IDeviceContext interface defines the essential methods that any device
 * context implementation must provide. This interface enables abstraction over
 * the underlying graphics API (DirectX 11 in this case), allowing for flexibility
 * and easier maintenance of code.
 */
class IDeviceContext
{
public:

	/*--------------------------------------------------------------
		Destructor
	--------------------------------------------------------------*/

	/// <summary>
	/// Virtual destructor for the IDeviceContext interface.
	/// This ensures that derived classes can clean up resources properly.
	/// </summary>
	virtual ~IDeviceContext() = default;

	/// <summary>
	/// Retrieves the device context associated with the graphics engine.
	/// The device context is used to issue rendering commands to the GPU.
	/// </summary>
	/// <returns></returns>
	virtual ID3D11DeviceContext* getDeviceContext() = 0;
};

#endif // IDEVICECONTEXT_H