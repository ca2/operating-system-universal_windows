#pragma once

/////////////////////////////////////////////////////////////////////////////
// Master version numbers

#define _AFX     1      // Microsoft Application Framework Classes
#ifndef _MFC_VER
#define _MFC_VER 0x0800 // Microsoft Foundation Classes version 8.00
#endif

/////////////////////////////////////////////////////////////////////////////
// turn off reference tracking for certain often used symbols

#ifndef ___PORTABLE
#pragma component(browser, off, references, "ASSERT")
#pragma component(browser, off, references, "__assert_failed_line")
#pragma component(browser, off, references, "__debug_break")
#pragma component(browser, off, references, "bool")
#pragma component(browser, off, references, "BYTE")
#pragma component(browser, off, references, "DECLSPEC_IMPORT")
#pragma component(browser, off, references, "DWORD")
#pragma component(browser, off, references, "FALSE")
#pragma component(browser, off, references, "FAR")
#pragma component(browser, off, references, "LPSTR")
#pragma component(browser, off, references, "LPTSTR")
#pragma component(browser, off, references, "LPCSTR")
#pragma component(browser, off, references, "LPCTSTR")
#pragma component(browser, off, references, "NULL")
#pragma component(browser, off, references, "PASCAL")
#pragma component(browser, off, references, "THIS_FILE")
#pragma component(browser, off, references, "TRUE")
#pragma component(browser, off, references, "UINT")
#pragma component(browser, off, references, "WINAPI")
#pragma component(browser, off, references, "WORD")
#endif  //!___PORTABLE

/////////////////////////////////////////////////////////////////////////////
// For target version (one of)
//   _CUSTOM   : for custom configurations (causes afxv_cfg.h to be included)
//
// Additional build options:
//  DEBUG              debug versions (full diagnostics)
//  _ApplicationFrameworkDLL             use shared MFC DLL
//  _AFXEXT             extension DLL version, implies _ApplicationFrameworkDLL
//  _USRDLL             create regular DLL (_ApplicationFrameworkDLL is valid too)
//

#ifndef DEBUG
#ifndef ___DISABLE_INLINES
//	#define ___ENABLE_INLINES
#endif
#endif

#define ___NO_NESTED_DERIVATION




/////////////////////////////////////////////////////////////////////////////
// Special configurations

// _AFXEXT implies _ApplicationFrameworkDLL
#if defined(_AFXEXT) && !defined(_ApplicationFrameworkDLL)
	#define _ApplicationFrameworkDLL
#endif

#if defined(_ApplicationFrameworkDLL) && !defined(_DLL) && defined(WIN32)
//	#error Please use the /MD switch for _ApplicationFrameworkDLL builds
#endif

#if defined(_ApplicationFrameworkDLL) && !defined(_MT) && defined(WIN32)
	#error Please use the /MD switch (multithreaded DLL C-runtime)
#endif

/////////////////////////////////////////////////////////////////////////////
// special include files

#ifndef __INLINE
	#define __INLINE inline /*__forceinline*/
#endif

#include "v_w32.h"

// Include any non-Intel platform specific items
#ifndef X86
	#include "v_cpu.h"
#endif

#ifdef X86
	#define ___MINREBUILD
#endif

#ifdef _CUSTOM
// Put any custom configuration items in afxv_cfg.h
	#include <afxv_cfg.h>
#endif

// setup default packing value
#ifndef ___PACKING
	#define ___PACKING    4   // default packs structs at 4 bytes
#endif

#ifdef _ApplicationFrameworkDLL
	#include "v_dll.h"
#endif

// Define this virtual key for use by status bar
#ifndef VK_KANA
#define VK_KANA             0x15
#endif

/////////////////////////////////////////////////////////////////////////////
// Special __debug_break: used to break into debugger at critical times

#ifndef __debug_break
#ifdef ___NO_DEBUG_CRT
// by default, debug break is asm int 3, or a call to DebugBreak, or nothing
#if defined(_M_IX86) && !defined(___PORTABLE)
#define __debug_break() _asm { int 3 }
#else
#define __debug_break() DebugBreak()
#endif
#else
#define __debug_break() _CrtDbgBreak()
#endif
#endif

/*#ifndef DEBUG
#ifdef __debug_break
#undef __debug_break
#endif
#define __debug_break()
#endif  // DEBUG*/

/////////////////////////////////////////////////////////////////////////////
// Standard preprocessor symbols if not already defined
/////////////////////////////////////////////////////////////////////////////

// SIZE_T_MAX is used by the collection classes
#ifndef SIZE_T_MAX
	#define SIZE_T_MAX  UINT_MAX
#endif

// is used for static member functions
#ifndef PASCAL
	#define  __stdcall
#endif

// FASTCALL is used for static member functions with little or no params
#ifndef FASTCALL
	#define FASTCALL __fastcall
#endif

// CDECL and EXPORT are defined in case WINDOWS.H doesn't
#ifndef CDECL
	#define CDECL __cdecl
#endif

#ifndef EXPORT
	#define EXPORT
#endif

// UNALIGNED is used for unaligned data access (in CArchive mostly)
#if !defined(UNALIGNED)
#if defined(_M_IA64) || defined(_M_AMD64)
#define UNALIGNED __unaligned
#else
#define UNALIGNED
#endif
#endif

// __DEPRECATED is used for functions that should no longer be used
#ifndef __DEPRECATED
#ifdef ___DISABLE_DEPRECATED
	#define __DEPRECATED(_Message)
#else
	#define __DEPRECATED(_Message) __declspec(deprecated(_Message))
#endif
#endif

// ___INSECURE_DEPRECATE is used for deprecated, insecure functions.
#ifndef ___INSECURE_DEPRECATE
#ifdef ___SECURE_NO_DEPRECATE
#define ___INSECURE_DEPRECATE(_Message)
#else
#define ___INSECURE_DEPRECATE(_Message) __declspec(deprecated(_Message))
#endif // ___SECURE_NO_DEPRECATE
#endif // ___INSECURE_DEPRECATE

// AFXAPI is used on global public functions
#ifndef AFXAPI
	#define AFXAPI __stdcall
#endif

// AFXOLEAPI is used for some special OLE functions
#ifndef AFXOLEAPI
	#define AFXOLEAPI __stdcall
#endif

// c_cdecl is used for rare functions taking variable arguments
#ifndef c_cdecl
	#define c_cdecl __cdecl
#endif

// __EXPORT is used for functions which need to be exported
#ifndef __EXPORT
	#define __EXPORT EXPORT
#endif

#ifndef __STATIC
	#define __STATIC extern
	#define __STATIC_DATA extern __declspec(selectany)
#endif

// The following macros are used to enable export/import

// for data
#ifndef __DATA_EXPORT
	#define __DATA_EXPORT __declspec(dllexport)
#endif
#ifndef __DATA_IMPORT
	#define __DATA_IMPORT __declspec(dllimport)
#endif

// for classes
#ifndef __CLASS_EXPORT
	#define __CLASS_EXPORT __declspec(dllexport)
#endif
#ifndef __CLASS_IMPORT
	#define __CLASS_IMPORT __declspec(dllimport)
#endif

// for global APIs
#ifndef __API_EXPORT
	#define __API_EXPORT __declspec(dllexport)
#endif
#ifndef __API_IMPORT
	#define __API_IMPORT __declspec(dllimport)
#endif

// This macro is used to reduce size requirements of some classes
#ifndef __ALWAYS_VTABLE
#ifndef __NOVTABLE
#if _MSC_VER >= 1100 && !defined(DEBUG)
#define __NOVTABLE __declspec(novtable)
#else
#define __NOVTABLE
#endif
#endif
#endif

// for global data that should be in COMDATs (packaged data)
#ifndef __COMDAT
#define __COMDAT __declspec(selectany)
#endif

// The following macros are used on data declarations/definitions
//  (they are redefined for extension DLLs and the shared MFC DLL)
#define __DATADEF
#define __API CLASS_DECL_BOOT

// used when building the "core" MFC80.DLL
#ifndef __CORE_DATA
	#define __CORE_DATA CLASS_DECL_BOOT
	#define __CORE_DATADEF
#endif

// used when building the MFC/OLE support MFCO80.DLL
#ifndef __OLE_DATA
	#define __OLE_DATA
	#define __OLE_DATADEF
#endif

// used when building the MFC/DB support MFCD80.DLL
#ifndef __DB_DATA
	#define __DB_DATA
	#define __DB_DATADEF
#endif

// used when building the MFC/NET support MFCN80.DLL
#ifndef __NET_DATA
	#define __NET_DATA
	#define __NET_DATADEF
#endif

// used when building extension DLLs
#ifndef __EXT_DATA
	#define __EXT_DATA
	#define __EXT_DATADEF
	#define __EXT_CLASS
	#define __EXT_API
#endif

// BASED_XXXX macros are provided for backward compatibility
#ifndef BASED_CODE
	#define BASED_CODE
#endif

#ifndef BASED_DEBUG
	#define BASED_DEBUG
#endif

#ifndef BASED_STACK
	#define BASED_STACK
#endif
/////////////////////////////////////////////////////////////////////////////


#include "v_cpu.h"











// ca2 API inline constructors (including compiler generated) can get deep
#pragma inline_depth(16)

#ifdef ___DEVBUILD
	#define __IMPL_DATA __DATA_EXPORT
#else
	#define __IMPL_DATA CLASS_DECL_BOOT 
#endif


// #define ___NOFORCE_LIBS
#define ___FULLTYPEINFO
#define VC_EXTRALEAN
#define NO_ANSIUNI_ONLY
#define _MFC_OVERRIDES_NEW

#define __COMDAT __declspec(selectany)

#include <winreg.h>
#include <winnls.h>
#include <stddef.h>
#include <limits.h>
#include <malloc.h>
#include <new.h>
#include <eh.h>

#undef __window_procedure


#define MAX_DWORD_PTR (0xffffffff)