#pragma once
#include <cmath>
#include <iostream>

struct Vec3 {
    double x, y, z;

    // Constructor
    Vec3(double x, double y, double z);


    bool operator==(const Vec3& other) const;

    // Vector addition
    Vec3 operator+(const Vec3& other) const;

    // Vector subtraction
    Vec3 operator-(const Vec3& other) const;

    // Scalar multiplication
    Vec3 operator*(double scalar) const;

    // Dot product
    double dot(const Vec3& other) const;

    // Cross product
    Vec3 cross(const Vec3& other) const;

    // Magnitude of the vector
    double magnitude() const;

    // Normalize the vector
    Vec3 normalize() const;
};

// Output operator for easy printing
std::ostream& operator<<(std::ostream& os, const Vec3& v);