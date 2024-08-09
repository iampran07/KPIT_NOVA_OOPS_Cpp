#include <iostream>
#include<cmath>
using namespace std;

class Complex {
private:
    int real;
    int img;

public:
    Complex() : real(0), img(0) {}

    Complex(int r, int i) : real(r), img(i) {}

    void Accept() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> img;
    }

    void Display() const {
        cout << real << (img >= 0 ? "+" : "") << img << "i" << endl;
    }

    Complex operator+(Complex &c) {
        return Complex(real + c.real, img + c.img);
    }

    Complex operator-(Complex &c) {
        return Complex(real - c.real, img - c.img);
    }

    Complex operator++() {
        ++real;
        ++img;
        return *this;
    }

    Complex operator++(int) {
        Complex temp = *this;
        real++;
        img++;
        return temp;
    }

    bool operator==(Complex &c) {
        return (real == c.real) && (img == c.img);
    }
};

int main() {
    Complex c1, c2(3, 4), c3;

    cout << "Enter first complex number:" << endl;
    c1.Accept();

    cout << "First Complex Number: ";
    c1.Display();

    cout << "Second Complex Number: ";
    c2.Display();

    c3 = c1 + c2;
    cout << "After Addition: ";
    c3.Display();

    c3 = c1 - c2;
    cout << "After Subtraction: ";
    c3.Display();

    ++c1;
    cout << "After Pre-increment: ";
    c1.Display();

    c1++;
    cout << "After Post-increment: ";
    c1.Display();

    if (c1 == c2)
        cout << "Both complex numbers are equal." << endl;
    else
        cout << "Complex numbers are not equal." << endl;

    return 0;
}
