#pragma once
#include <iostream>
#include <fstream>

class Complex
{
private:
	int Re; // real part
	int Im; // imaginary part
public:
	Complex(int Re, int Im) : Im(Im), Re(Re) {};
	Complex() {};




	int getIm() {
		return Im;
	}

	int getRe() {
		return Re;
	}
	

	Complex operator+(Complex other) {
		return Complex(Re + other.Re, Im + other.Im);
	}

	Complex operator-(Complex other) {
		return Complex(Re - other.Re, Im - other.Im);
	}

	Complex operator*(Complex other) {
		return Complex(Re * other.Re - Im * other.Im, Re * other.Im + Im * other.Re); // (a+bi)(c+di) = (ac - bd)+(ad+bc)i
	}

	Complex operator*(int mult) {
		return Complex(Re * mult, Im * mult);
	}

	Complex operator++() { // ++a
		Re = Re + 1;
		return *this;
	}

	Complex operator++(int) { // a++
		Complex old = *this;
		Re = Re + 1;
		return old;
	}

	Complex operator--() {
		Re = Re - 1;
		return *this;
	}

	Complex operator--(int) {
		Complex old = *this;
		Re = Re - 1;
		return old;
	}


	friend std::ostream& operator<<(std::ostream&, Complex);
	friend std::istream& operator>>(std::istream&, Complex&);
	friend bool save(std::string path, Complex number);
};

std::ostream& operator<<(std::ostream& out, Complex number) {
	if (number.Re == 0 && number.Im == 0)
		return out << "0";
	if (number.Re == 0)
		return out << number.Im << "i";
	else {
		if (number.Im == 1)
			return out << number.Re << "+i";
		if (number.Im == -1)
			return out << number.Re << "-i";
		if (number.Im > 0)
			return out << number.Re << "+" << number.Im << "i";
		if (number.Im < 0)
			return out << number.Re << number.Im << "i";
		if (number.Im == 0)
			return out << number.Re;
	}

}

std::istream& operator>>(std::istream& in, Complex& number) {
	char trash;
	return in >> number.Re >> number.Im >> trash; // 5+2i
}

bool save(std::string path, Complex number) {
	std::ofstream output(path, std::ios::app);
	if (output.is_open()) {
		output << number.getRe() << ", " << number.getIm() << std::endl;
		output.close();
		return true;
	}
	else {
		return false;
	}
}
