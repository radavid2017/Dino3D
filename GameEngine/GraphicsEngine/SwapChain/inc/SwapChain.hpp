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
//           Synopsis: Definition of the SwapChain class for managing swap chains
//   Target system(s):
//        Compiler(s): VS16
//=============================================================================
//  N O T E S
//-----------------------------------------------------------------------------
//  Notes:
//  - Ensure that the DirectX 11 runtime is available on the target system.
//  - The SwapChain class must be properly initialized before use.
//=============================================================================
//  I N I T I A L   A U T H O R   I D E N T I T Y
//-----------------------------------------------------------------------------
//        Name: Hoka David-Stelian
//  Department: Project Owner (CEO)
//     Purpose: Design the SwapChain class to manage DirectX swap chains for rendering.
//=============================================================================
//  R E V I S I O N   I N F O R M A T I O N
//-----------------------------------------------------------------------------
/// @file
/// @brief Defines the SwapChain class for managing DirectX swap chains.
/// @par Revision History:
///      $Source: SwapChain.hpp $
///      $Revision: 1.1 $
///      $Author: Hoka David-Stelian (CEO) (Dino3D) $
///      $Date: 2024/08/04 18:50:01 PM $
///      $Name:  $
///      $State: in_work $
//=============================================================================

#ifndef _SWAP_CHAIN_H_
#define _SWAP_CHAIN_H_

#ifndef _WINDEF_
class HWND__; // Forward declaration for HWND
typedef HWND__* HWND; // Define HWND as a pointer to HWND__
#endif

typedef unsigned int UINT; // Define UINT as an unsigned int
class IDXGISwapChain; // Forward declaration for IDXGISwapChain
class IGraphicsEngine; // Forward declaration for IGraphicsEngine

class ID3D11RenderTargetView;

class DeviceContext;

/**
 * @class SwapChain
 * @brief Manages the swap chain for rendering in DirectX.
 *
 * The SwapChain class is responsible for creating and managing the swap chain,
 * which is used to present rendered images to the screen. It provides methods
 * for initializing and releasing the swap chain.
 */
class SwapChain
{
public:

	/*--------------------------------------------------------------
		Constructor
	--------------------------------------------------------------*/

	/// <summary>
	/// Default constructor for the SwapChain class.
	/// Initializes member variables.
	/// </summary>
	SwapChain();

	/*--------------------------------------------------------------
		Destructor
	--------------------------------------------------------------*/

	~SwapChain();

	/*--------------------------------------------------------------
		Public Methods
	--------------------------------------------------------------*/

	/// <summary>
	/// Initializes the swap chain with the specified parameters.
	/// </summary>
	/// <param name="f_hwnd">Handle to the window for which the swap chain is created.</param>
	/// <param name="f_width">Width of the swap chain's buffers.</param>
	/// <param name="f_height">Height of the swap chain's buffers.</param>
	/// <param name="f_engine">Pointer to the graphics engine instance managing the swap chain.</param>
	/// <returns>True if initialization is successful, false otherwise.</returns>
	bool init(HWND f_hwnd, UINT f_width, UINT f_height, IGraphicsEngine* f_engine);

	bool present(bool vsync);

	/// <summary>
	/// Releases resources associated with the swap chain.
	/// This method should be called to clean up resources when done.
	/// </summary>
	/// <returns>True if release is successful, false otherwise.</returns>
	bool release();

private:

	/*--------------------------------------------------------------
		Private Data Members
	--------------------------------------------------------------*/

	/// <summary>
	/// A pointer to the IDXGISwapChain interface.
	/// This interface is used to manage the swap chain operations.
	/// </summary>
	IDXGISwapChain* m_swapChain_p;

	ID3D11RenderTargetView* m_rtv;

	friend class DeviceContext;
};

#endif // !_SWAP_CHAIN_H_
