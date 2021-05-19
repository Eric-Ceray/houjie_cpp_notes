#ifndef __COMPLEX__
#define __COMPLEX__

#include <cmath>

'''0. forward declarations'''
class ostream;
class complex;

complex& __doapl (complex* ths, const complex& r);

'''1. class declarations'''
class complex
{
public:
	complex (double r = 0, double i = 0): re (r), im (i) { }
	complex& operator += (const complex&);
	double real () const { return re; }
	double imag () const { return im; }
private:
	double re, im;

	friend complex& __doapl (complex*, const complex&);
}

'''2. class definition类定义'''

'''2.1'''
inline complex&
__doapl(complex* ths, const complex& r)

{
	ths -> re += r.re;
	ths -> im += r.im;
	return *ths;
}
'''操作符重载'''
inline complex&
complex::operator += (const complex& r)
{
	return __doapl (this, r);
}

'''2.2'''
inline double
imag (const complex& x)
{
	return x.imag ();
}

inline double
real (const complex& x)
{
	return x.real ();
}

'''2.3'''
inline complex
operator + (const complex& x, const complex& y)
{
	return complex (real (x) + real (y), imag (x) + imag (y));
}

inline complex
operator + (const complex& x, double y)
{
	reuturn complex (real (x) + y, imag (x));
}

inline complex
operator + (double x, const complex& y)
{
	return complex (x + real (y), imag (y))
}

'''2.4'''
inline complex
operator + (const complex& x)
{
	return x;
}

inline complex
operator - (const complex& x)
{
	return complex(-real (x), -imag (x));
}

'''2.5'''
inline bool
operator == (const complex& x, const complex& y)
{
	return real (x) == real (y) &&  imag (x) == imag (y);
}
inline bool
operator == (const complex& x, double y)
{
	return real (x) == y && imag (x) == 0;
}
inline bool
operator == (double x, const complex& y)
{
	return x == real (y) && imag (y) == 0;
}

'''2.6'''
inline bool
operator != (const complex& x, const complex& )
{
	return real (x) != real (y) ||  imag (x) != imag (y);
}
inline bool
operator != (const complex& x, double y)
{
	return real (x) != y || imag (x) != 0;
}
inline bool
operator != (double x, const complex& y)
{
	return x != real (y) || imag (y) != 0;
}

'''2.7'''
inline complex
conj (const complex& x)
{
	return complex (real (x), -imag (x));
}

#include <iostream.h>
ostream&
operator << (ostream& os, const complex& x)
{
	return os << '(' << real (x) << ',' << imag (x) << ')';
}
#endif
