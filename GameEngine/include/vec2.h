#pragma once

#include <cmath>

class vec2 {
 public:
  vec2() 
    : x_(0), y_(0) { }

  vec2(const vec2& other) { 
    x_ = other.x_;
    y_ = other.y_;
  }

  vec2(float x)
    : x_(x), y_(x) {}

  vec2(float x, float y)
      : x_(x), y_(y) { }

  vec2 operator+(const vec2& other) const { 
    return vec2(x_ + other.x_, y_ + other.y_);
  }

  vec2 operator-(const vec2& other) const { 
    return vec2(x_ - other.x_, y_ - other.y_);
  }
  
  vec2 operator*(const float& scalar) const { 
    return vec2(x_ * scalar, y_ * scalar);
  }

  vec2 operator/(const float& scalar) const { 
    return *this * (1 / scalar);
  }

  bool operator==(const vec2& other) const {
    return x_ == other.x_ && y_ == other.y_;
  }

  bool operator!=(const vec2& other) const { 
    return !(*this == other);
  }

  float& operator[](int coord) {
    switch (coord) {
      case 0:
        return x_;
      case 1:
        return y_;
    }
  }

  float operator[](int coord) const {
    switch (coord) {
      case 0:
        return x_;
      case 1:
        return y_;
    }
  }

  float length() const {
    return sqrt(pow(x_, 2) + pow(y_, 2));
  }

  static float dot_product(const vec2& lhs, const vec2& rhs) {
    return lhs.x_ * rhs.x_ + lhs.y_ * rhs.y_;
  }

  vec2 normalize() const { 
    return *this / this->length();
  }

 private:
  float x_;
  float y_;
};