#pragma once

struct Vector2 {
    double x;
    double y;

    Vector2();
    Vector2(double x, double y);

    double length() const;

    Vector2 operator+(const Vector2& other) const;
    Vector2 operator*(double scalar) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 normalized() const;
};