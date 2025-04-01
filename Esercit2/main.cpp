#include <iostream>
#include "complex.hpp"

int main(void) {
	using Complex = complex<double>;
	
	//initializing two complex numbers and a double
	Complex c1(1,2);
	Complex c2(3,4);
	double k = 5;
	
	// printing the real and the imaginary part of a complex number
	std::cout << "the real part of " << c1 << " is " << c1.getreal() << std::endl;
	std::cout << "the imaginary part of " << c1 << " is " << c1.getimag() << std::endl;
	
	// printing the conjugate of a complex number
	std::cout << "conjugate of number " << c1 << " is: " << c1.conjugate() << std::endl;
	
	// printing the sum and product between two complex
	std::cout << c1 << " + " << c2 << " = " << c1+c2 << std::endl;
	std::cout << "(" << c1 << ") * (" << c2 << ") = " << c1*c2 << std::endl;
	
	// printing sum and product on both the left and the right between a complex and a double
	std::cout << c1 << " + 5 = " << c1+k << std::endl;
	std::cout << "5 + " << c1 << " = " << k+c1 << std::endl;
	std::cout << "(" << c2 << ")" << " * 5 = " << c2*k << std::endl;
	std::cout << "5 * (" << c2 << ") = " << k*c2 << std::endl;
	
	return 0;
}
	
	