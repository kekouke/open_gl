#pragma once

#include <cmath>

class vec4 {
 public:
  vec4() 
    : x_(0), y_(0), z_(0), w_(0) { }

  vec4(float x) 
    : x_(x), y_(x), z_(x), w_(x) { }

  vec4(float x, float y, float z, float w) 
    : x_(x), y_(y), z_(z), w_(w) { }

  vec4(const vec4& other) {
    x_ = other.x_;
    y_ = other.y_;
    z_ = other.z_;
    w_ = other.w_;
  }

  vec4 operator+(const vec4& other) const {
    return vec4(x_ + other.x_, y_ + other.y_, z_ + other.z_, w_ + other.w_);
  }

  vec4 operator-(const vec4& other) const {
    return vec4(x_ - other.x_, y_ - other.y_, z_ - other.z_, w_ - other.w_);
  }

  vec4 operator*(const float& scalar) const {
    return vec4(x_ * scalar, y_ * scalar, z_ * scalar, w_ * scalar);
  }

  vec4 operator/(const float& scalar) const { 
    return *this * (1 / scalar);
  }

  bool operator==(const vec4& other) const {
    return 
      x_ == other.x_ && y_ == other.y_
      &&
      z_ == other.z_ && w_ == other.w_;
  }

  bool operator!=(const vec4& other) const { 
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
      case 3:
        return w_;
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
      case 3:
        return w_;
    }
  }

  static float dot_product(const vec4& lhs, const vec4& rhs) {
    return lhs.x_ * rhs.x_ + lhs.y_ * rhs.y_ + lhs.z_ * rhs.z_ + lhs.w_ * rhs.w_;
  }

  float length() const { return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2) + pow(w_, 2)); }

  vec4 normalize() const { return *this / this->length(); }

 private:
  float x_;
  float y_;
  float z_;
  float w_;
};
