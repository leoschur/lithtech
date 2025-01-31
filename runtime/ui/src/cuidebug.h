//-------------------------------------------------------------------
//
//   MODULE    : CUIDEBUG.H
//
//   PURPOSE   : defines a simple debugging printout
//
//   CREATED   : 1/01 
//
//   COPYRIGHT : (C) 2001 LithTech Inc
//
//-------------------------------------------------------------------


//	In which live all the CUI Debugging Macros and Func. Defs
//	common to the CUI system


#ifndef __CUIDEBUG_H__
#define __CUIDEBUG_H__


#ifndef __STDARG_H__
#include <cstdarg> // for variable argument macros
#define __STDARG_H__
#endif

//  --------------------------------------------------------------------------
// 	CUI Debugging tools
//  --------------------------------------------------------------------------


#if defined __DEBUG || defined _DEBUG 

/*!
	CUI_PRINT is a macro which wraps a variable argument printf()-like syntax

	If __DEBUG and _DEBUG are not defined, CUI_PRINT resolves to a comment.
*/
#if _MSC_VER >= 1300
#define CUI_PRINT(x, ...) CUIDebug::DebugPrint(x, __VA_ARGS__)
#else
#define CUI_PRINT(x, ...) CUIDebug::DebugPrint(x __VA_OPT(,) __VA_ARGS__)
#endif


/*!
	CUI_DBG is a macro which wraps a variable argument printf()-like syntax
	and also prints out the name of the class requesting the debug printout.
	All CUI Classes must implement GetClassName() member function
	in order to use CUI_DBG.

	\b Note: the use of a comma (,) between the two calls to DebugPrint().
	This allows a statement such as:

		if (test) CUIDBG("Oops!\n");

	to be sucessful, even though 2 functions are being called and the conditional
	does not enclose a new code block in curly braces '{}'.

	If __DEBUG and _DEBUG are not defined, CUI_DBG resolves to a comment.
*/
#if _MSC_VER >= 1300
#define CUI_DBG(x, ...) CUIDebug::DebugPrint("%s: ", this->GetClassName()); CUIDebug::DebugPrint(x, __VA_ARGS__)
#else
#define CUI_DBG(x, ...) CUIDebug::DebugPrint("%s: ", this->GetClassName()); CUIDebug::DebugPrint(x __VA_OPT(,) __VA_ARGS__)
#endif



/*!
	CUI_ERR is a macro which wraps a variable argument printf()-like syntax
	and also prints out the filename and line number where the error occured.

	\b Note: the use of a comma (,) between the two calls to DebugPrint().
	This allows a statement such as:

		if (test) CUI_ERR("Oops!\n");

	to be sucessful, even though 2 functions are being called and the conditional
	does not enclose a new code block in curly braces '{}'.
*/
#if _MSC_VER >= 1300
#define CUI_ERR(x, ...) CUIDebug::DebugPrint("Error in %s at line %i:\n    ", __FILE__, __LINE__); CUIDebug::DebugPrint(x, __VA_ARGS__)
#else
#define CUI_ERR(x, ...) CUIDebug::DebugPrint("Error in %s at line %i:\n    ", __FILE__, __LINE__); CUIDebug::DebugPrint(x __VA_OPT(,) __VA_ARGS__)
#endif



/*!
	A simple class encapsulating a debug printout to a system specific console.
*/
class CUIDebug
{
	public:

/*!
\param pFormat a formatting string.
\prarm ... variable arguments

This functions works like printf().  Call it the same way.
*/
		static void DebugPrint(const char* pFormat, ...);

	public:

/*!
Text storage is defined statically for better performance.
*/
		static char sm_pText[256];
};


#else	//__DEBUG


// if debugging is not turned on, these macros will resolve to comments, and
// the CUIDebug class will not be defined.

#define CUI_DBG(x, ...) // x
#define CUI_ERR(x, ...) // x
#define CUI_PRINT(x, ...) // x


#endif  //__DEBUG


#endif // __CUIDEBUG_H__