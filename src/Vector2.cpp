#include "Vector2.hpp"
#include <cmath>

// default constructor using initializer list
//  - initialize Vector2.x = 0, Vector2.y = 0
Vector2::Vector2() : x(0), y(0) {}

// constructor using initializer list
//  - initializes Vector2.x = x, Vector2.y = y
Vector2::Vector2(double x, double y) : x(x), y(y) {}

// Overload operator +, so we can add vectors with cleaner syntax
Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
}

// Overload operator x, so we can multiply vectors with cleaner syntax
Vector2 Vector2::operator*(double scalar) const {
    return Vector2(x * scalar, y * scalar);
}

// Overload operator -, so we can subtract vectors with cleaner syntax
Vector2 Vector2::operator-(const Vector2& other) const {
    return Vector2(x - other.x, y - other.y);
}

double Vector2::length() const {
    return std::sqrt(x*x + y*y);
}

Vector2 Vector2::normalized() const {
    double len = length();
    // handle 0 case
    if (len == 0) return Vector2(0,0);
    return Vector2(x / len, y / len);
}

// When a function is declared as const, it can be called on any type of object.
// Non-const functions can only be called by non-const objects.