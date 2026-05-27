#include "triangle.h"

bool is_triangle(triangle_t t) {
    if (t.a <= 0 || t.b <= 0 || t.c <= 0) return false;
    if (t.a + t.b < t.c) {
        return false;
    }
    if (t.b + t.c < t.a) {
        return false;
    }
    if (t.a + t.c < t.b) {
        return false;
    }
    return true;
}
bool is_equilateral(triangle_t t) {
    if (!is_triangle(t)) return false;
    if (t.a == t.b && t.b == t.c) return true;
    else return false;
}

bool is_isosceles(triangle_t t) {
    if (!is_triangle(t)) return false;
    int same_count = 0;

    if (t.a == t.b) same_count++;
    if (t.b == t.c) same_count++;
    if (t.a == t.c) same_count++;

    if (same_count >= 1) return true;
    else return false;
}

bool is_scalene(triangle_t t) {
    if (!is_triangle(t)) return false;
    if (is_isosceles(t)) return false;
    return true;
}
