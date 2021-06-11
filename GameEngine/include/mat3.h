#pragma once
#include <vector>
#include "vec3.h"
#include <cassert>
#include "mat2.h"

class mat3 {
 public:
   mat3() {
     matrix = std::vector<vec3>(3, 0);
  }
  
   mat3(float num) {
     matrix = {
       vec3(num, 0, 0),
       vec3(0, num, 0), 
       vec3(0, 0, num)
     };
   }

   mat3(float x1, float y1, float z1,
     float x2, float y2, float z2,
     float x3, float y3, float z3) {
     matrix = {
       vec3(x1, y1, z1),
       vec3(x2, y2, z2), 
       vec3(x3, y3, z3)
     };
   }

   mat3(vec3 r1, vec3 r2, vec3 r3) {
     matrix.clear();
     matrix.push_back(r1);
     matrix.push_back(r2);
     matrix.push_back(r3);
   }

   mat3(const mat3& other) { matrix = other.matrix; }

     mat3 operator*(const mat3& other) const {
     std::vector<vec3> result;

     for (int i = 0; i < 3; i++) {
       vec3 r_vector;
       vec3 row = get_row(i);

       for (int j = 0; j < 3; j++) {
         vec3 col = other.get_col(j);
         r_vector[j] = vec3::dot_product(row, col);
       }

       result.push_back(r_vector);
     }

     return { result[0], result[1], result[2] };
   }

   vec3 operator*(const vec3& other) const {
     vec3 result;

     int i = 0;
     for (const auto& row : matrix) {
       result[i++] = vec3::dot_product(row, other);
     }

     return result;
   }

    mat3 operator+(const mat3& other) const {
     return mat3(matrix[0] + other.matrix[0],
       matrix[1] + other.matrix[1],
       matrix[2] + other.matrix[2]);
    }

    mat3 operator-(const mat3& other) const {
      return mat3(matrix[0] - other.matrix[0],
        matrix[1] - other.matrix[1],
        matrix[2] - other.matrix[2]);
    }

    mat3 operator+(const float& num) const {
      return mat3(matrix[0] + num, matrix[1] + num, matrix[2] + num);
    }

    mat3 operator-(const float& num) const {
      return mat3(matrix[0] - num, matrix[1] - num, matrix[2] - num);
    }

    mat3 operator*(const float& num) const {
      return mat3(matrix[0] * num, matrix[1] * num, matrix[2] * num);
    }

    mat3 operator/(const float& num) const {
      float inverse = 1 / num;
      return *this * inverse;
    }

   bool operator==(const mat3& other) const {
     for (int i = 0; i < matrix.size(); i++) {
       if (matrix[i] != other.matrix[i]) { return false; }
     }

     return true;
   }

   bool operator!=(const mat3& other) const { 
     return !(*this == other); 
   }

    vec3 operator[](int coord) const { 
      return get_row(coord);
    }

   vec3 get_row(int n) const {
     assert(0 <= n && n < 3);

     return matrix[n];
   }

   vec3 get_col(int n) const {
     assert(0 <= n && n < 3);

     vec3 result;

     int i = 0;
     for (const auto& vec : matrix) {
       result[i++] = vec[n];
     }

     return result;
   }

   mat3 get_transpose_matrix() const {
     return { get_col(0), get_col(1), get_col(2) };
   }

    mat3 get_invertible_matrix() const {
     return { get_transpose_matrix().get_algebraic_complements_matrix() / det() };
       }

    float calculate_minor(int row, int col) const {
         std::vector<float> values;

         for (int i = 0; i < 3; i++) {
           for (int j = 0; j < 3; j++) {
             if (i == row || j == col) {
               continue;
             }

             values.emplace_back(matrix[i][j]);
           }
         }

         return mat2(values[0], values[1], values[2], values[3]).det();
    }
    
    float get_algebraic_complement(int row, int col) const {
         int factor = 1;

         if ((row + col) % 2 == 1) {
           factor = -1;
         }

         return factor * calculate_minor(row, col);
       }

   mat3 get_algebraic_complements_matrix() const {
     mat3 result;

     for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 3; j++) {
         result.matrix[i][j] = get_algebraic_complement(i, j);
       }
     }

     return result;
   }

   float det() const {
     auto first_triangle = matrix[0][0] * matrix[1][1] * matrix[2][2] +
                           matrix[0][1] * matrix[1][2] * matrix[2][0] +
                           matrix[0][2] * matrix[2][1] * matrix[1][0];

     auto second_triangle = matrix[0][2] * matrix[1][1] * matrix[2][0] +
                            matrix[0][0] * matrix[2][1] * matrix[1][2] +
                            matrix[2][2] * matrix[1][0] * matrix[0][1];

     return first_triangle - second_triangle;
   }

   static mat3 get_identity_matrix() { 
     return { 1.0 };
   }

 private:
  std::vector<vec3> matrix;
};
