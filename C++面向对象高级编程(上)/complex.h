#ifndef __COMPLEX__
#define __COMPLEX__

#include <cmath>
'''forward declarations'''
class ostream;
class complex;

complex& __doapl (complex* ths, const complex& r);

'''class declarations'''
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

inline double
imag (const compplex& x)
{
	return x.imag ()
}
#endif