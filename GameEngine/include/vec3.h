#pragma once

#include <cmath>
#include "include/vec4.h"

class vec3 {
 public:
  vec3() 
    : x_(0), y_(0), z_(0) { }

  vec3(float x) 
    : x_(x), y_(x), z_(x) { }

  vec3(float x, float y, float z)
    : x_(x), y_(y), z_(z) { }

  vec3(const vec3& other) {
    x_ = other.x_;
    y_ = other.y_;
    z_ = other.z_;
  }

  vec3(vec4 other) { 
    x_ = other[0];
    y_ = other[1];
    z_ = other[2];
  }

  vec3 operator+(const vec3& other) const {
    return vec3(x_ + other.x_, y_ + other.y_, z_ + other.z_);
  }

  vec3 operator-(const vec3& other) const {
    return vec3(x_ - other.x_, y_ - other.y_, z_ - other.z_);
  }

  vec3 operator*(const float& scalar) const {
    return vec3(x_ * scalar, y_ * scalar, z_ * scalar);
  }

  vec3 operator/(const float& scalar) const {
    return *this * (1 / scalar); 
  }

  vec3 operator-() const { 
    return {-x_, -y_, -z_};
  }

  bool operator==(const vec3& other) const {
    return x_ == other.x_ && y_ == other.y_ && z_ == other.z_;
  }

  bool operator!=(const vec3& other) const {
    return !(*this == other);
  }

  float& operator[](int coord) {
    switch (coord) {
      case 0:
        return x_;
      case 1:
        return y_;
      case 2:
        return z_;
    }
  }

  float operator[](int coord) const {
    switch (coord) {
      case 0:
        return x_;
      case 1:
        return y_;
      case 2:
        return z_;
    }
  }

  static float dot_product(const vec3& lhs, const vec3& rhs) {
    return lhs.x_ * rhs.x_ + lhs.y_ * rhs.y_ + lhs.z_ * rhs.z_;
  }

  static vec3 cross_product(const vec3& lhs, const vec3& rhs) { 
    return vec3(lhs.y_ * rhs.z_ - lhs.z_ * rhs.y_,
      lhs.z_ * rhs.x_ - lhs.x_ * rhs.z_,
      lhs.x_ * rhs.y_ - lhs.y_ * rhs.x_);
  }


  float length() const {
    return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
  }

  vec3 normalize() const {
    return *this / this->length();
  }

 private:
  float x_;
  float y_;
  float z_;
};
