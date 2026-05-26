#include "complex_numbers.h"
#include <math.h>

#define E exp(1)

complex_t c_add(complex_t a, complex_t b) {
    complex_t y;
    y.real = a.real + b.real;
    y.imag = a.imag + b.imag;
    return y;
}

complex_t c_sub(complex_t a, complex_t b) {
    complex_t y;
    y.real = a.real - b.real;
    y.imag = a.imag - b.imag;
    return y;
}

complex_t c_mul(complex_t a, complex_t b) {
    complex_t y;
    y.real = a.real * b.real - a.imag * b.imag;
    y.imag = a.imag * b.real + a.real * b.imag;
    return y;
}

complex_t c_div(complex_t a, complex_t b) {
    complex_t y;
    y.real = (a.real * b.real + a.imag * b.imag) /
             (b.real * b.real + b.imag * b.imag);

    y.imag = (a.imag * b.real - a.real * b.imag) /
             (b.real * b.real + b.imag * b.imag);
    return y;
}

double c_abs(complex_t x) { return sqrt(x.imag * x.imag + x.real * x.real); }

complex_t c_conjugate(complex_t x) {
    complex_t y;
    y.real = x.real;
    y.imag = -x.imag;
    return y;
}

double c_real(complex_t x) { return x.real; }

double c_imag(complex_t x) { return x.imag; }

complex_t c_exp(complex_t x) {
    complex_t y;
    y.real = pow(E, x.real) * cos(x.imag);
    y.imag = pow(E, x.real) * sin(x.imag);
    return y;
}
