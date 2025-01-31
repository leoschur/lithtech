// ----------------------------------------------------------------------- //
//
// MODULE  : Globals.h
//
// PURPOSE : Global data
//
// CREATED : 4/26/99
//
// (c) 1999 Monolith Productions, Inc.  All Rights Reserved
//
// ----------------------------------------------------------------------- //

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

//#define _TRON_E3_DEMO

// global constants
const int MAX_OBJECT_ARRAY_SIZE = 32;

#define	COORD_CENTER	0x80000000

// Version to use with dinput.
#define DIRECTINPUT_VERSION  0x0800

inline bool PtInRect(RECT* pRect, int x, int y)
{
	if((x >= pRect->right) || (x < pRect->left) ||
	   (y >= pRect->bottom) || (y < pRect->top))
	   return false;

	return true;
}

// Helper classes

template<class TYPE>
class CRange
{
	public:

		CRange() { }
		CRange(TYPE fMin, TYPE fMax) { m_fMin = fMin; m_fMax = fMax; }

		void Set(TYPE fMin, TYPE fMax) { m_fMin = fMin; m_fMax = fMax; }

		TYPE GetMin() { return m_fMin; }
		TYPE GetMax() { return m_fMax; }

	protected:

		TYPE m_fMin;
		TYPE m_fMax;
};

// Miscellaneous functions...

template< class T >
inline T MinAbs( T a, T b)
{
    return (T)fabs(a) < (T)fabs(b) ? a : b;
}

template< class T >
inline T MaxAbs( T a, T b)
{
    return (T)fabs(a) > (T)fabs(b) ? a : b;
}

template< class T >
inline T Clamp( T val, T min, T max )
{
	return Min( max, Max( val, min ));
}

#ifndef _ASSERT
#define _ASSERT(x)
#endif

#endif  // _GLOBALS_H_
