#include "Vec3.h"

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {};

Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3& other) const {
    return Vec3(x - other.x, y - other.y, z - other.z);
}


Vec3 operator*(double scalar, const Vec3& vec) {
    return Vec3(scalar * vec.x, scalar * vec.y, scalar * vec.z);
}

Vec3 Vec3::operator*(double scalar) const {
    return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::cross(const Vec3& other) const {
    return Vec3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

double Vec3::magnitude() const {
    return sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::normalize() const {
    double mag = magnitude();
    return Vec3(x / mag, y / mag, z / mag);
}

bool Vec3::operator==(const Vec3 &other) const {
        return x == other.x && y == other.y && z == other.z;
}

std::ostream& operator<<(std::ostream& os, const Vec3& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}