#pragma once

// define the complex class
template<typename T>
class complex
{
	//private members
	T real, imag;

public:

	// default constructor
	complex()
		: real(0), imag(0)
	{}
	
	// defined constrctor able to convert a real number to complex 
	complex(T n)
		: real(n), imag(0)
	{}
	
	// user-defined constructor
	explicit complex(T a, T b)
        : real(a), imag(b)
	{}
	
	// method to get the conjugate of a complex number
	complex<T> conjugate(void) const {
        return complex(real, -imag);
    }
	
	//methods to get the real and the imaginary part of a complex number
	T getreal(void) const {
		return real;
	}
	T getimag(void) const {
		return imag; 
	}
	
	// overload of += between complex numbers
	complex& operator+=(const complex& other) {
        real += other.real;
		imag += other.imag;
        return *this;
	}
		
	// overload of + using += between complex numbers
	complex operator+(const complex& other) const {
        complex ret = *this;
        ret += other;
        return ret;
    }
	
	// overload of += between a complex on the left and a T on the right
	complex& operator+=(const T& other) {
		real += other;
		return *this;
	}
	
	// overload of + between a complex on the left and a T on the right
	complex operator+(const T& other) const {
		complex ret = *this;
		ret += other;
		return ret;
	}
	
	// overload of *= between complex numbers
	complex& operator*=(const complex& other) {
		T real_ = real * other.real - imag * other.imag;
		imag = real * other.imag + imag * other.real;
		real = real_;
		return *this;
	}
	
	// overload of * using *= between complex numbers
	complex operator*(const complex& other) const {
		complex ret = *this;
		ret *= other;
		return ret;
	}
	
	// overload of *= between a complex on the left and a T on the right
	complex& operator*=(const T& other) {
		real = real * other;
		imag = imag * other;
		return *this;
	}
	
	// overload of * using *= between a complex on the left and a T on the right
	complex operator*(const T& other) const {
		complex ret = *this;
		ret *= other;
		return ret;
	}
};

// operator to compute the sum of a T on the left and a complex on the right
template<typename T>
complex<T>
operator+(const T& t, const complex<T>& c)
{
    return c + t;
}

// operator to compute the product of a T on the left and a coimplex on the right
template<typename T>
complex<T>
operator*(const T& t, const complex<T>& c)
{
	return c * t;
}

// overload of << to make a complex printable 
template<typename T>
std::ostream&
operator<<(std::ostream& os, const complex<T>& c) {
    if (c.getimag() > 0)
        os << c.getreal() << " + " << c.getimag() << "i";
	if (c.getimag() < 0)
		os << c.getreal() << " " << c.getimag() << "i";
    if (c.getimag() == 0)
        os << c.getreal();

    return os;
}

