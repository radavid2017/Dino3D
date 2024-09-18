# Dino3D
C++ 3D Game Engine

# Template for copyright
```cpp
//=============================================================================
//  C O P Y R I G H T
//-----------------------------------------------------------------------------
// Copyright (c) 2024 by [Your Name]. All rights reserved.
//
//  This file is property of [Your Name]. Any unauthorized copy, use or
//  distribution is an offensive act against international law and may be
//  prosecuted under federal law. Its content is personal confidential.
//=============================================================================
// P R O J E C T   I N F O R M A T I O N
//-----------------------------------------------------------------------------
//       Project name: [Your Project Name]
//           Synopsis: [Short Description]
//   Target system(s): 
//        Compiler(s): VS16
//=============================================================================
//  N O T E S
//-----------------------------------------------------------------------------
//  Notes:
//=============================================================================
//  I N I T I A L   A U T H O R   I D E N T I T Y
//-----------------------------------------------------------------------------
//        Name: [Your Name]
//  Department: [Your Department]
//=============================================================================
//  R E V I S I O N   I N F O R M A T I O N
//-----------------------------------------------------------------------------
/// @file
/// @brief Short description here
/// @par Revision History:
///      $Source: $
///      $Revision: $
///      $Author: [Your Name] $
///      $Date: $
///      $State: $
//=============================================================================
```

# Template for class
```cpp
#ifndef _CLASS_NAME_H_
#define _CLASS_NAME_H_

/**
 * @class ClassName
 * @brief Brief description of the class.
 * 
 * Detailed description of the class, including its purpose, design, 
 * and usage examples if applicable.
 * 
 * Example usage:
 * @code
 * ClassName obj;
 * obj.init();
 * // ...
 * obj.release();
 * @endcode
 */
class ClassName {
public:
    /*--------------------------------------------------------------
        Types and Type Aliases                    
    --------------------------------------------------------------*/
    // using ExampleType = ...;             // Example type alias
    // enum ExampleEnum { ... };            // Example enum

    /*--------------------------------------------------------------
        Static Constants (if any)                        
    --------------------------------------------------------------*/
    // static constexpr Type kConstantName = ...; // Example constant

    /*--------------------------------------------------------------
        Factory Methods                              
    --------------------------------------------------------------*/
    // static ClassName* create();

    /*--------------------------------------------------------------
        Constructors and Assignment Operators              
    --------------------------------------------------------------*/
    // ClassName();                          // Default constructor
    // ClassName(const ClassName& other);   // Copy constructor
    // ClassName& operator=(const ClassName& other); // Copy assignment
    // ClassName(ClassName&& other) noexcept; // Move constructor
    // ClassName& operator=(ClassName&& other) noexcept; // Move assignment

    /*--------------------------------------------------------------
        Destructor                            
    --------------------------------------------------------------*/
    // ~ClassName();

    /*--------------------------------------------------------------
        Public Methods                        
    --------------------------------------------------------------*/
    /* 
        // Method description here
        // e.g., bool init();
    */
    // bool init();

    /* 
        // Method description here
        // e.g., void release();
    */
    // void release();

private:
    /*--------------------------------------------------------------
        Private Data Members                     
    --------------------------------------------------------------*/
    // Type m_memberName;  // Example private member

    /*--------------------------------------------------------------
        All Other Functions                       
    --------------------------------------------------------------*/
    // void helperFunction(); // Example of a private helper function
};

#endif // !_CLASS_NAME_H_