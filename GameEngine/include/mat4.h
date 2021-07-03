#pragma once

#include <vector>
#include "vec4.h"
#include <cassert>
#include "include/vec3.h"
#include "mat3.h"

class mat4 {
 public:
  mat4() { matrix = std::vector<vec4>(4, 0); }

  mat4(float num) {
    matrix = {
      vec4(num, 0, 0, 0),
      vec4(0, num, 0, 0),
      vec4(0, 0, num, 0),
      vec4(0, 0, 0, num)
    };
  }

  mat4(
    float x1, float y1, float z1, float w1,
    float x2, float y2, float z2, float w2,
    float x3, float y3, float z3, float w3,
    float x4, float y4, float z4, float w4)
  {
    matrix = {
      vec4(x1, y1, z1, w1),
      vec4(x2, y2, z2, w2),
      vec4(x3, y3, z3, w3),
      vec4(x4, y4, z4, w4)
    };
  }

  mat4(vec4 r1, vec4 r2, vec4 r3, vec4 r4) {
    matrix.clear();
    matrix.push_back(r1);
    matrix.push_back(r2);
    matrix.push_back(r3);
    matrix.push_back(r4);
  }

  mat4(const mat4& other) { matrix = other.matrix; }

  mat4 operator+(const mat4& other) const {
    return mat4
    (
      matrix[0] + other.matrix[0],
      matrix[1] + other.matrix[1],
      matrix[2] + other.matrix[2],
      matrix[3] + other.matrix[3]
    );
  }

  mat4 operator-(const mat4& other) const {
    return mat4
    (
      matrix[0] - other.matrix[0],
      matrix[1] - other.matrix[1],
      matrix[2] - other.matrix[2],
      matrix[3] - other.matrix[3]
    );
  }

  mat4 operator*(const mat4& other) const {
    std::vector<vec4> result;

    for (int i = 0; i < 4; i++) {
      vec4 r_vector;
      vec4 row = get_row(i);

      for (int j = 0; j < 4; j++) {
        vec4 col = other.get_col(j);
        r_vector[j] = vec4::dot_product(row, col);
      }

      result.push_back(r_vector);
    }

    return { result[0], result[1], result[2], result[3] };
  }

  mat4 operator+(float num) const {
    return mat4
    (
      matrix[0] + num,
      matrix[1] + num,
      matrix[2] + num,
      matrix[3] + num);
  }

  mat4 operator-(float num) const {
    return mat4
    (
      matrix[0] - num,
      matrix[1] - num,
      matrix[2] - num,
      matrix[3] - num
    );
  }

  mat4 operator*(const float& num) const {
    return mat4
    (
      matrix[0] * num,
      matrix[1] * num,
      matrix[2] * num,
      matrix[3] * num
    );
  }

  mat4 operator/(const float& num) {
    float inverse = 1 / num;
    return *this * inverse;
  }

   vec4 operator*(const vec4& other) const {
      vec4 result;

      int i = 0;
      for (const auto& row : matrix) {
        result[i++] = vec4::dot_product(row, other);
      }

      return result;
   }

   bool operator==(const mat4& other) const {
    for (int i = 0; i < matrix.size(); i++) {
      if (matrix[i] != other.matrix[i]) { return false; }
    }

     return true;
   }

  bool operator!=(const mat4& other) const { return !(*this == other); }

  vec4& operator[](int coord) { return get_row(coord); }
  vec4 operator[](int coord) const { return get_row(coord); }

  vec4 get_row(int n) const {
    assert(0 <= n && n < 4);

    return matrix[n];
  }

  vec4& get_row(int n) {
    assert(0 <= n && n < 4);

    return matrix[n];
  }

  vec4 get_col(int n) const {
    assert(0 <= n && n < 4);

    vec4 result;

    int i = 0;
    for (const auto& vec : matrix) {
      result[i++] = vec[n];
    }

    return result;
  }

  mat4 get_transpose_matrix() const {
    return { get_col(0), get_col(1), get_col(2), get_col(3) };
  }

  mat4 get_invertible_matrix() const {
    return {get_transpose_matrix().get_algebraic_complements_matrix() / det() };
  }

  float calculate_minor(int row, int col) const {
        std::vector<float> values;

        for (int i = 0; i < 4; i++) {
          for (int j = 0; j < 4; j++) {
            if (i == row || j == col) {
              continue;
            }

            values.emplace_back(matrix[i][j]);
          }
        }

        return mat3(values[0], values[1], values[2], values[3], values[4],
                    values[5], values[6], values[7], values[8]).det();
      }

  float get_algebraic_complement(int row, int col) const {
    int factor = 1;

    if ((row + col) % 2 == 1) {
      factor = -1;
    }

    return factor * calculate_minor(row, col);
  }

  mat4 get_algebraic_complements_matrix() const {
    mat4 result;

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        result.matrix[i][j] = get_algebraic_complement(i, j);
      }
    }

    return result;
  }

  static mat4 offset_matrix(vec3 movement) { 
    return mat4
    (
      vec4(1, 0, 0, movement[0]),
      vec4(0, 1, 0, movement[1]),
      vec4(0, 0, 1, movement[2]),
      vec4(0, 0, 0, 1)
    );
  }

  static mat4 rotation_matrix(float angle, vec3 vec) {
    auto param = 1 - cos(angle);
    float x = vec[0];
    float y = vec[1];
    float z = vec[2];
    mat4 rotate_matrix;

    rotate_matrix[0][0] = cos(angle) + param * pow(x, 2);
    rotate_matrix[0][1] = param * x * y - sin(angle) * z;
    rotate_matrix[0][2] = param * x * z + sin(angle) * y;

    rotate_matrix[1][0] = param * y * x + sin(angle) * z;
    rotate_matrix[1][1] = cos(angle) + param * pow(y, 2);
    rotate_matrix[1][2] = param * y * z - sin(angle) * x;

    rotate_matrix[2][0] = param * z * x - sin(angle) * y;
    rotate_matrix[2][1] = param * z * y + sin(angle) * x;
    rotate_matrix[2][2] = cos(angle) + param * pow(z, 2);

    rotate_matrix[3][3] = 1;

    return rotate_matrix;
  }
  
  static mat4 perspective(float fov, float ratio, float nearVar, float farVar) {
    float tan_fov = tan(fov / 2.0f);
    auto a = 1.0f / (ratio * tan_fov);

    mat4 perspective_mat;
    perspective_mat.get_row(0)[0] = 1.0f / (ratio * tan_fov);
    perspective_mat.get_row(1)[1] = 1.0f / (tan_fov);
    perspective_mat.get_row(2)[2] =
        -(nearVar + farVar) / float(farVar - nearVar);
    perspective_mat.get_row(2)[3] = -1.0f;
    perspective_mat.get_row(3)[2] =
        (2.0f * farVar * nearVar) / (nearVar - farVar);

    return perspective_mat;
  }

  static mat4 look_at(vec3 position, vec3 direction, vec3 up) {
    vec3 vec_one(position - direction);
    vec3 z_axis(vec_one.normalize());

    vec3 vec_up(up.normalize());
    vec3 vector_product(vec3::cross_product(up, z_axis));
    vec3 x_axis(vector_product.normalize());

    vec3 y_axis(vec3::cross_product(z_axis, x_axis));

    mat4 rotation(1.0f);
    rotation[0][0] = x_axis[0];
    rotation[1][0] = x_axis[1];
    rotation[2][0] = x_axis[2];
    rotation[0][1] = y_axis[0];
    rotation[1][1] = y_axis[1];
    rotation[2][1] = y_axis[2];
    rotation[0][2] = z_axis[0];
    rotation[1][2] = z_axis[1];
    rotation[2][2] = z_axis[2];

    mat4 translation(1.0f);
    translation[3][0] = -position[0];
    translation[3][1] = -position[1];
    translation[3][2] = -position[2];

    return translation * rotation;
  }

  static mat4 scale_matrix(const vec3& scale_vector) {
    mat4 result;



    return mat4
    (
      vec4(scale_vector[0], 0, 0, 0), 
      vec4(0, scale_vector[1], 0, 0),
      vec4(0, 0, scale_vector[2], 0),
      vec4(0, 0, 0, 1)
    );
  }

  float det() const {
    return {
      matrix[0][0] * mat3
      (
        matrix[1][1], matrix[1][2], matrix[1][3],
        matrix[2][1], matrix[2][2], matrix[2][3],
        matrix[3][1], matrix[3][2], matrix[3][3]
      ).det() -
      matrix[0][1] * mat3
      (
        matrix[1][0], matrix[1][2], matrix[1][3],
        matrix[2][0], matrix[2][2], matrix[2][3],
        matrix[3][0], matrix[3][2], matrix[3][3]
      ).det() +
      matrix[0][2] * mat3
      (
        matrix[1][0], matrix[1][1], matrix[1][3],
        matrix[2][0], matrix[2][1], matrix[2][3],
        matrix[3][0], matrix[3][1], matrix[3][3]
      ).det() -
      matrix[0][3] * mat3
      (
        matrix[1][0], matrix[1][1], matrix[1][2],
        matrix[2][0], matrix[2][1], matrix[2][2],
        matrix[3][0], matrix[3][1], matrix[3][2]
      ).det()
    };
  }

  static mat4 get_identity_matrix() { return {1.0}; }

 private:
   std::vector<vec4> matrix;
};
