#pragma once

#include "vec2.h"
#include <vector>
#include <cassert>

class mat2 {
 public:
   mat2() { 
      matrix = std::vector<vec2>(2, 0);
   }

   mat2(float num) { 
     matrix = {
       vec2(num, 0), 
       vec2(0, num)
     };
   }

   mat2(float x1, float y1, float x2, float y2) {
     matrix = {
       vec2(x1, y1),
       vec2(x2, y2)
     };
   }

   mat2(vec2 r1, vec2 r2) { 
     matrix.clear();
     matrix.push_back(r1);
     matrix.push_back(r2);
   }

    mat2(const mat2& other) { 
      matrix = other.matrix;
    }

    mat2 operator*(const mat2& other) const { 
      std::vector<vec2> result;

      for (int i = 0; i < 2; i++) {
        vec2 r_vector;
        vec2 row = get_row(i);

        for (int j = 0; j < 2; j++) {
          vec2 col = other.get_col(j);
          r_vector[j] = vec2::dot_product(row, col);
        }

        result.push_back(r_vector);
      }

      return { result[0], result[1] };
    }

    vec2 operator*(const vec2& other) const { 
      vec2 result;

      int i = 0;
      for (const auto& row : matrix) {
        result[i++] = vec2::dot_product(row, other);
      }

      return result;
    }

    bool operator==(const mat2& other) const {
      
      for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i] != other.matrix[i]) { return false;
        }
      }

      return true;
    }

    bool operator!=(const mat2& other) const { 
      return !(*this == other);
    }

    mat2 operator+(const mat2& other) const { 
      return mat2
      (
        matrix[0] + other.matrix[0],
        matrix[1] + other.matrix[1]
      );
    }

    mat2 operator-(const mat2& other) const {
      return mat2
      (
        matrix[0] - other.matrix[0],
        matrix[1] - other.matrix[1]
      );
    }

    mat2 operator+(const int& num) const {
      return mat2(matrix[0] + num, matrix[1] + num);
    }

    mat2 operator-(const int& num) const {
      return mat2(matrix[0] - num, matrix[1] - num);
    }

    mat2 operator*(const float& num) const { 
      return mat2
      (
        matrix[0] * num,
        matrix[1] * num
      );
    }

    mat2 operator/(const float& num) const { 
      float inverse = 1 / num;
      return *this * inverse;
    }

    vec2 operator[](int coord) const { return get_row(coord); }

    vec2 get_row(int n) const { 
      assert(0 <= n && n < 2);

      return matrix[n];
    }

    vec2 get_col(int n) const { 
      assert(0 <= n && n < 2);

      vec2 result;

      int i = 0;
      for (const auto& vec : matrix) {
        result[i++] = vec[n];
      }

      return result;
    }

    mat2 get_transpose_matrix() const { 
      return { get_col(0), get_col(1) };
    }

    mat2 get_invertible_matrix() const {
      return { get_transpose_matrix().get_algebraic_complements() / det()};
    }

    float get_minor(int row, int col) const {
      float result;

      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          if (i == row || j == col) {
            continue;
          }

          result = matrix[i][j];
        }
      }

      return result;
    }

    float calculate_algebraic_complement(int row, int col) const {
      float factor = 1;

      if ((row + col) % 2 == 1) {
        factor = -1;
      }

      return factor * get_minor(row, col);
    }

    mat2 get_algebraic_complements() const {
      mat2 result;

      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          result.matrix[i][j] = calculate_algebraic_complement(i, j);
        }
      }

      return result;
    }

    float det() const { 
      vec2 first = get_row(0);
      vec2 second = get_row(1);

      return first[0] * second[1] - first[1] * second[0];
    }

    static mat2 get_identity_matrix() {
      return { 1.0 };
    }

 private:
   std::vector<vec2> matrix;
};
