#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <iostream>

#define EPS 0.00001

#define CATCH_CONFIG_MAIN
#include "../catch2.hpp"

#include "include/vec2.h"
#include "include/vec3.h"
#include "include/vec4.h"

#include "include/mat2.h"
#include "include/mat3.h"
#include "include/mat4.h"

using namespace std;

TEST_CASE("Class vec2 testing", "[vec2]") {
  SECTION("Vec2 Constructors") {
    {
      const vec2 my_vector(5);
      const glm::vec2 glm_vector(5);

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
    }
    {
      const vec2 my_vector(5, 1);
      const glm::vec2 glm_vector(5, 1);

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
    }
    {
      const vec2 my_vector(5, 1);
      const vec2 my_vector_copy(my_vector);

      const glm::vec2 glm_vector(5, 1);
      const glm::vec2 glm_vector_copy(glm_vector);

      REQUIRE(my_vector_copy[0] == glm_vector_copy[0]);
      REQUIRE(my_vector_copy[1] == glm_vector_copy[1]);
    }
  }

  SECTION("Vec2 operations") {
    {
      const vec2 my_vecA(5);
      const vec2 my_vecB(1, 17);

      const glm::vec2 glm_vecA(5);
      const glm::vec2 glm_vecB(1, 17);

      const vec2 my_result = my_vecA + my_vecB;
      const glm::vec2 glm_result = glm_vecA + glm_vecB;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
    }
    {
      const vec2 my_vecA(5);
      const vec2 my_vecB(1, 17);

      const glm::vec2 glm_vecA(5);
      const glm::vec2 glm_vecB(1, 17);

      const vec2 my_result = my_vecA - my_vecB;
      const glm::vec2 glm_result = glm_vecA - glm_vecB;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
    }
    {
      const vec2 my_vector(7, 1);
      const glm::vec2 glm_vector(7, 1);

      const vec2 my_result = my_vector * 5.5f;
      const glm::vec2 glm_result = glm_vector * 5.5f;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
    }
    {
      const vec2 my_vector(7, 1);
      const glm::vec2 glm_vector(7, 1);

      const vec2 my_result = my_vector / 5.5f;
      const glm::vec2 glm_result = glm_vector / 5.5f;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
    }
    {
      const vec2 vec_1;
      const vec2 vec_2;
      REQUIRE(vec_1 == vec_2);
    }
    {
      const vec2 vec_1(1.1, 2);
      const vec2 vec_2(1.1, 2);
      REQUIRE(vec_1 == vec_2);
    }
    {
      const vec2 vec_1;
      const vec2 vec_2;
      REQUIRE_FALSE(vec_1 != vec_2);
    }
    {
      const vec2 vec_1(1.1, 2);
      const vec2 vec_2(1.1, 2);
      REQUIRE_FALSE(vec_1 != vec_2);
    }
    {
      vec2 vec_1(115, -9);
      vec2 vec_2(115, -9);

      REQUIRE(vec_1[0] == vec_2[0]);
      REQUIRE(vec_1[1] == vec_2[1]);
    }
  }

  SECTION("Vec2 functions") {
    {
      const vec2 my_vector(5, 5);
      const glm::vec2 glm_vector(5, 6);

      REQUIRE_FALSE(my_vector.length() == glm::length(glm_vector));
    }
    {
      const vec2 my_vector(-4);
      const glm::vec2 glm_vector(-4);

      REQUIRE(my_vector.length() == glm::length(glm_vector));
    }
    {
      const vec2 my_vec1(-4, 15);
      const vec2 my_vec2(1, -8);

      const glm::vec2 glm_vec1(-4, 15);
      const glm::vec2 glm_vec2(1, -8);

      float first = vec2::dot_product(my_vec1, my_vec2);
      float second = glm::dot(glm_vec1, glm_vec2);

      REQUIRE(first == second);
    }
    {
      const vec2 my_vec1(-4, 15);
      const glm::vec2 glm_vec1(-4, 15);

      vec2 n1 = my_vec1.normalize();
      auto n2 = glm::normalize(glm_vec1);

      REQUIRE(n1[0] == n2[0]);
      REQUIRE(n1[1] == n2[1]);
    }
  }
}

TEST_CASE("Class vec3 testing", "[vec3]") {
  SECTION("Vec3 Constructors") {
   {
      const vec3 my_vector(5);
      const glm::vec3 glm_vector(5);

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
      REQUIRE(my_vector[2] == glm_vector[2]);
    }
    {
      const vec3 my_vector(5, 1, 7);
      const glm::vec3 glm_vector(5, 1, 7);

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
      REQUIRE(my_vector[2] == glm_vector[2]);
    }
    {
      const vec3 my_vector(-5, 1, 0);
      const vec3 my_vector_copy(my_vector);

      const glm::vec3 glm_vector(-5, 1, -0);
      const glm::vec3 glm_vector_copy(glm_vector);

      REQUIRE(my_vector_copy[0] == glm_vector_copy[0]);
      REQUIRE(my_vector_copy[1] == glm_vector_copy[1]);
      REQUIRE(my_vector_copy[2] == glm_vector_copy[2]);
    }
  }

  SECTION("Vec3 operations") {
    {
      const vec3 my_vecA(5);
      const vec3 my_vecB(1, 17, -1);

      const glm::vec3 glm_vecA(5);
      const glm::vec3 glm_vecB(1, 17, -1);

      const vec3 my_result = my_vecA + my_vecB;
      const glm::vec3 glm_result = glm_vecA + glm_vecB;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
      REQUIRE(my_result[2] == glm_result[2]);
    }
    {
      const vec3 my_vecA(5);
      const vec3 my_vecB(1, 17, -1);

      const glm::vec3 glm_vecA(5);
      const glm::vec3 glm_vecB(1, 17, -1);

      const vec3 my_result = my_vecA - my_vecB;
      const glm::vec3 glm_result = glm_vecA - glm_vecB;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
      REQUIRE(my_result[2] == glm_result[2]);
    }
    {
      const vec3 my_vector(7, 1, -4.5);
      const glm::vec3 glm_vector(7, 1, -4.5);

      const vec3 my_result = my_vector * 5.5f;
      const glm::vec3 glm_result = glm_vector * 5.5f;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
      REQUIRE(my_result[2] == glm_result[2]);
    }
    {
      const vec3 my_vector(7, 1, -4.5);
      const glm::vec3 glm_vector(7, 1, -4.5);

      const vec3 my_result = my_vector / 5.5f;
      const glm::vec3 glm_result = glm_vector / 5.5f;

      REQUIRE(my_result[0] == Approx(glm_result[0]).epsilon(EPS));
      REQUIRE(my_result[1] == Approx(glm_result[1]).epsilon(EPS));
      REQUIRE(my_result[2] == Approx(glm_result[2]).epsilon(EPS));
    }
    {
      const vec3 vec_1;
      const vec3 vec_2;
      REQUIRE(vec_1 == vec_2);
    }
    {
      const vec3 vec_1(1.1, 2, -9.1);
      const vec3 vec_2(1.1, 2, -9.1);
      REQUIRE(vec_1 == vec_2);
    }
    {
      const vec3 vec_1;
      const vec3 vec_2;
      REQUIRE_FALSE(vec_1 != vec_2);
    }
    {
      const vec3 vec_1(1.1, 2, 5);
      const vec3 vec_2(1.1, 2, 5);
      REQUIRE_FALSE(vec_1 != vec_2);
    }
    {
      vec3 vec_1(115, -9, 2);
      vec3 vec_2(115, -9, 2);

      REQUIRE(vec_1[0] == vec_2[0]);
      REQUIRE(vec_1[1] == vec_2[1]);
      REQUIRE(vec_1[2] == vec_2[2]);
    }
  }

  SECTION("Vec3 functions") {
    {
      const vec3 my_vector(5, 6, 5);
      const glm::vec3 glm_vector(5, 6, 5);

      REQUIRE(my_vector.length() == glm::length(glm_vector));
    }
    {
      const vec3 my_vector(-4);
      const glm::vec3 glm_vector(-4);

      REQUIRE(my_vector.length() == glm::length(glm_vector));
    }
    {
      const vec3 my_vec1(-4, 15, 87.4);
      const vec3 my_vec2(1, -8, 12.125);

      const glm::vec3 glm_vec1(-4, 15, 87.4);
      const glm::vec3 glm_vec2(1, -8, 12.125);

      float first = vec3::dot_product(my_vec1, my_vec2);
      float second = glm::dot(glm_vec1, glm_vec2);

      REQUIRE(first == Approx(second).epsilon(EPS));
    }
    {
      const vec3 my_vec1(-4.8, 15.1, 21.3);
      const glm::vec3 glm_vec1(-4.8, 15.1, 21.3);

      vec3 n1 = my_vec1.normalize();
      glm::vec3 n2 = glm::normalize(glm_vec1);

      REQUIRE(n1[0] == Approx(n2[0]).epsilon(EPS));
      REQUIRE(n1[1] == Approx(n2[1]).epsilon(EPS));
      REQUIRE(n1[2] == Approx(n2[2]).epsilon(EPS));
    }
    {
      const vec3 my_vec1(-4, 15, 87.4);
      const vec3 my_vec2(1, -8, 12.125);

      const glm::vec3 glm_vec1(-4, 15, 87.4);
      const glm::vec3 glm_vec2(1, -8, 12.125);

      vec3 first = vec3::cross_product(my_vec1, my_vec2);
      glm::vec3 second = glm::cross(glm_vec1, glm_vec2);

      REQUIRE(first[0] == Approx(second[0]).epsilon(EPS));
      REQUIRE(first[1] == Approx(second[1]).epsilon(EPS));
      REQUIRE(first[2] == Approx(second[2]).epsilon(EPS));
    }
  }
}

TEST_CASE("Class vec4 testing", "[vec4]") {
  SECTION("Vec4 Constructors") {
   {
      const vec4 my_vector(5);
      const glm::vec4 glm_vector(5);

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
      REQUIRE(my_vector[2] == glm_vector[2]);
    }
    {
      const vec4 my_vector(5, 1, 7, 8);
      const glm::vec4 glm_vector(5, 1, 7, 8);

      REQUIRE(my_vector[0] == glm_vector[0]);
      REQUIRE(my_vector[1] == glm_vector[1]);
      REQUIRE(my_vector[2] == glm_vector[2]);
      REQUIRE(my_vector[3] == glm_vector[3]);
    }
    {
      const vec4 my_vector(-5, 1, 0, 0);
      const vec4 my_vector_copy(my_vector);

      const glm::vec4 glm_vector(-5, 1, -0, -0);
      const glm::vec4 glm_vector_copy(glm_vector);

      REQUIRE(my_vector_copy[0] == glm_vector_copy[0]);
      REQUIRE(my_vector_copy[1] == glm_vector_copy[1]);
      REQUIRE(my_vector_copy[2] == glm_vector_copy[2]);
      REQUIRE(my_vector_copy[3] == glm_vector_copy[3]);
    }
  }

  SECTION("Vec4 operations") {
    {
      const vec4 my_vecA(5);
      const vec4 my_vecB(1, 17, -1, 2);

      const glm::vec4 glm_vecA(5);
      const glm::vec4 glm_vecB(1, 17, -1, 2);

      const vec4 my_result = my_vecA + my_vecB;
      const glm::vec4 glm_result = glm_vecA + glm_vecB;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
      REQUIRE(my_result[2] == glm_result[2]);
      REQUIRE(my_result[3] == glm_result[3]);
    }
    {
      const vec4 my_vecA(5);
      const vec4 my_vecB(1, 17, -1, 2);

      const glm::vec4 glm_vecA(5);
      const glm::vec4 glm_vecB(1, 17, -1, 2);

      const vec4 my_result = my_vecA - my_vecB;
      const glm::vec4 glm_result = glm_vecA - glm_vecB;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
      REQUIRE(my_result[2] == glm_result[2]);
      REQUIRE(my_result[3] == glm_result[3]);
    }
    {
      const vec4 my_vector(7, 1, -4.5, -1);
      const glm::vec4 glm_vector(7, 1, -4.5, -1);

      const vec4 my_result = my_vector * 5.5f;
      const glm::vec4 glm_result = glm_vector * 5.5f;

      REQUIRE(my_result[0] == Approx(glm_result[0]).epsilon(EPS));
      REQUIRE(my_result[1] == Approx(glm_result[1]).epsilon(EPS));
      REQUIRE(my_result[2] == Approx(glm_result[2]).epsilon(EPS));
      REQUIRE(my_result[3] == Approx(glm_result[3]).epsilon(EPS));
    }
    {
      const vec4 my_vector(7, 1, -4.5, -1);
      const glm::vec4 glm_vector(7, 1, -4.5, -1);

      const vec4 my_result = my_vector / 5.5f;
      const glm::vec4 glm_result = glm_vector / 5.5f;

      REQUIRE(my_result[0] == Approx(glm_result[0]).epsilon(EPS));
      REQUIRE(my_result[1] == Approx(glm_result[1]).epsilon(EPS));
      REQUIRE(my_result[2] == Approx(glm_result[2]).epsilon(EPS));
      REQUIRE(my_result[3] == Approx(glm_result[3]).epsilon(EPS));
    }
    {
      const vec4 vec_1;
      const vec4 vec_2;
      REQUIRE(vec_1 == vec_2);
    }
    {
      const vec4 vec_1(1.1, 2, -9.1, 15.6);
      const vec4 vec_2(1.1, 2, -9.1, 15.6);
      REQUIRE(vec_1 == vec_2);
    }
    {
      const vec4 vec_1;
      const vec4 vec_2;
      REQUIRE_FALSE(vec_1 != vec_2);
    }
    {
      const vec4 vec_1(1.1, 2, 5, 3);
      const vec4 vec_2(1.1, 2, 5, 3);
      REQUIRE_FALSE(vec_1 != vec_2);
    }
    {
      vec4 vec_1(115, -9, 2, 900);
      vec4 vec_2(115, -9, 2, 900);

      REQUIRE(vec_1[0] == vec_2[0]);
      REQUIRE(vec_1[1] == vec_2[1]);
      REQUIRE(vec_1[2] == vec_2[2]);
      REQUIRE(vec_1[3] == vec_2[3]);
    }
  }

  SECTION("Vec3 functions") {
    {
      const vec4 my_vector(5, 6, 5, -7);
      const glm::vec4 glm_vector(5, 6, 5, -7);

      REQUIRE(my_vector.length() == glm::length(glm_vector));
    }
    {
      const vec4 my_vector(-4);
      const glm::vec4 glm_vector(-4);

      REQUIRE(my_vector.length() == glm::length(glm_vector));
    }
    {
      const vec4 my_vec1(-4, 15, 87.4, 21.851);
      const vec4 my_vec2(1, -8, 12.125, 21.851);

      const glm::vec4 glm_vec1(-4, 15, 87.4, 21.851);
      const glm::vec4 glm_vec2(1, -8, 12.125, 21.851);

      float first = vec4::dot_product(my_vec1, my_vec2);
      float second = glm::dot(glm_vec1, glm_vec2);

      REQUIRE(first == Approx(second).epsilon(EPS));
    }
    {
      const vec4 my_vec1(-4.8, 15.1, 21.3, 5);
      const glm::vec4 glm_vec1(-4.8, 15.1, 21.3, 5);

      const vec4 n1 = my_vec1.normalize();
      const glm::vec4 n2 = glm::normalize(glm_vec1);

      REQUIRE(n1[0] == Approx(n2[0]).epsilon(EPS));
      REQUIRE(n1[1] == Approx(n2[1]).epsilon(EPS));
      REQUIRE(n1[2] == Approx(n2[2]).epsilon(EPS));
      REQUIRE(n1[3] == Approx(n2[3]).epsilon(EPS));
    }
  }
}

TEST_CASE("Class mat2 testing", "[mat]") {
  SECTION("Mat2 constructors") {
    {
      const mat2 my_mat(1);
      const glm::mat2 glm_mat(1);

      REQUIRE(my_mat[0][0] == glm_mat[0][0]);
      REQUIRE(my_mat[0][1] == glm_mat[0][1]);
      REQUIRE(my_mat[1][0] == glm_mat[1][0]);
      REQUIRE(my_mat[1][1] == glm_mat[1][1]);
    }
    {
      const mat2 my_mat(1, 2, 3, 4);
      const glm::mat2 glm_mat(1, 2, 3, 4);

      REQUIRE(my_mat[0][0] == glm_mat[0][0]);
      REQUIRE(my_mat[0][1] == glm_mat[0][1]);
      REQUIRE(my_mat[1][0] == glm_mat[1][0]);
      REQUIRE(my_mat[1][1] == glm_mat[1][1]);
    }
    {
      const mat2 my_mat(1, 2, 3, 4);
      const mat2 my_mat_copy(my_mat);

      const glm::mat2 glm_mat(1, 2, 3, 4);
      const glm::mat2 glm_mat_copy(glm_mat);

      REQUIRE(my_mat_copy[0][0] == glm_mat_copy[0][0]);
      REQUIRE(my_mat_copy[0][1] == glm_mat_copy[0][1]);
      REQUIRE(my_mat_copy[1][0] == glm_mat_copy[1][0]);
      REQUIRE(my_mat_copy[1][1] == glm_mat_copy[1][1]);
    }
    {
      const mat2 my_mat({1, 2}, {3, 4});
      const glm::mat2 glm_mat(1, 2, 3, 4);

      REQUIRE(my_mat[0][0] == glm_mat[0][0]);
      REQUIRE(my_mat[0][1] == glm_mat[0][1]);
      REQUIRE(my_mat[1][0] == glm_mat[1][0]);
      REQUIRE(my_mat[1][1] == glm_mat[1][1]);
    }
  }

  SECTION("Mat2 operations") {
    {
      const mat2 my_mat_1(1, 2, 3, 4);
      const mat2 my_mat_2(3, 4, 5, 6);

      const glm::mat2x2 glm_mat_1(1, 2, 3, 4);
      const glm::mat2x2 glm_mat_2(3, 4, 5, 6);

      const auto my_result = (my_mat_1 * my_mat_2);
      const auto glm_result = glm_mat_2 * glm_mat_1;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
    {
      const mat2 my_mat_1(1, 2, 3, 4);
      const vec2 my_mat_2(3, 4);

      const glm::mat2x2 glm_mat_1(1, 2, 3, 4);
      const glm::vec2 glm_mat_2(3, 4);

      const auto my_result = (my_mat_1 * my_mat_2);
      const auto glm_result = glm_mat_2 * glm_mat_1;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
    }
    {
      const mat2 my_mat_1(1);
      const mat2 my_mat_2(1);

      REQUIRE(my_mat_1 == my_mat_2);
      REQUIRE_FALSE(my_mat_1[0][0] != my_mat_2[0][0]);
    }
    {
      const mat2 my_mat_1;
      const mat2 my_mat_2;

      REQUIRE(my_mat_1== my_mat_2);
      REQUIRE_FALSE(my_mat_1 != my_mat_2);
    }
    {
      const mat2 my_mat_1(1, 2, 3, 4);
      const mat2 my_mat_2(1, 2, 3, 4);

      REQUIRE(my_mat_1 == my_mat_2);
      REQUIRE_FALSE(my_mat_1 != my_mat_2);
    }
    {
      const mat2 my_mat_1(1, 2, 3, 4);
      const mat2 my_mat_2(3, 4, 5, 6);

      const glm::mat2 glm_mat_1(1, 2, 3, 4);
      const glm::mat2 glm_mat_2(3, 4, 5, 6);

      const auto my_result = my_mat_1 + my_mat_2;
      const auto glm_result = glm_mat_1 + glm_mat_2;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
    {
      const mat2 my_mat_1(1, 2, 3, 4);
      const mat2 my_mat_2(3, 4, 5, 6);

      const glm::mat2 glm_mat_1(1, 2, 3, 4);
      const glm::mat2 glm_mat_2(3, 4, 5, 6);

      const auto my_result = my_mat_1 - my_mat_2;
      const auto glm_result = glm_mat_1 - glm_mat_2;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
    {
      const mat2 my_mat_1(1, 2, 3, 4);

      const glm::mat2 glm_mat_1(1, 2, 3, 4);

      const auto my_result = my_mat_1 + 5;
      const auto glm_result = glm_mat_1 + 5.0f;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
    {
      const mat2 my_mat_1(1, 2, 3, 4);

      const glm::mat2 glm_mat_1(1, 2, 3, 4);

      const auto my_result = my_mat_1 - 5;
      const auto glm_result = glm_mat_1 - 5.0f;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
    {
      const mat2 my_mat_1(1, 2, 3, 4);

      const glm::mat2 glm_mat_1(1, 2, 3, 4);

      const auto my_result = my_mat_1 * 5;
      const auto glm_result = glm_mat_1 * 5.0f;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
    {
      const mat2 my_mat_1(1, 2, 3, 4);

      const glm::mat2 glm_mat_1(1, 2, 3, 4);

      const auto my_result = my_mat_1 / 5;
      const auto glm_result = glm_mat_1 / 5.0f;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
  }

  SECTION("Mat2 functions") {
    {
      const mat2 my_mat(1, 2, 3, 4);
      const glm::mat2 glm_mat = glm::transpose(glm::mat2(1, 2, 3, 4));

      for (int i = 0; i < 2; i++) {
        const auto my_vec = my_mat.get_col(i);
        const auto glm_vec = glm_mat[i];

        REQUIRE(my_vec[0] == glm_vec[0]);
        REQUIRE(my_vec[1] == glm_vec[1]);
      }
    }
    {
      const mat2 my_mat(1, 2, 3, 4);
      const glm::mat2 glm_mat(1, 2, 3, 4);

      for (int i = 0; i < 2; i++) {
        const auto my_vec = my_mat.get_row(i);
        const auto glm_vec = glm_mat[i];

        REQUIRE(my_vec[0] == glm_vec[0]);
        REQUIRE(my_vec[1] == glm_vec[1]);
      }
    }
    {
      const mat2 my_mat(1, 2, 3, 4);
      const glm::mat2 glm_mat(1, 2, 3, 4);

      const mat2 my_transpose_mat = my_mat.get_transpose_matrix();
      const glm::mat2 glm_transpose_mat = glm::transpose(glm_mat);

      REQUIRE(my_transpose_mat[0][0] == glm_transpose_mat[0][0]);
      REQUIRE(my_transpose_mat[0][1] == glm_transpose_mat[0][1]);
      REQUIRE(my_transpose_mat[1][0] == glm_transpose_mat[1][0]);
      REQUIRE(my_transpose_mat[1][1] == glm_transpose_mat[1][1]);
    }
    {
      const mat2 my_mat(1, 2, 3, 4);
      const glm::mat2 glm_mat(1, 2, 3, 4);

      float my_det = my_mat.det();
      float glm_det = glm::determinant(glm_mat);

      REQUIRE(my_det == glm_det);
    }
    {
        const mat2 my_mat(1, 2, 3, 4);
        const glm::mat2 glm_mat(1, 2, 3, 4);

        const mat2 my_invertible_mat = my_mat.get_invertible_matrix();
        const glm::mat2 glm_invertible_mat = glm::inverse(glm_mat);

        REQUIRE(my_invertible_mat[0][0] == glm_invertible_mat[0][0]);
        REQUIRE(my_invertible_mat[0][1] == glm_invertible_mat[0][1]);
        REQUIRE(my_invertible_mat[1][0] == glm_invertible_mat[1][0]);
        REQUIRE(my_invertible_mat[1][1] == glm_invertible_mat[1][1]);
    } 
    {
      const mat2 my_result = mat2::get_identity_matrix();
      const glm::mat2 glm_result(1.0f);

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
    }
  }
}

TEST_CASE("Class Mat3 testing", "[mat]") {
  SECTION("Mat3 constructors") {
    {
      const mat3 my_mat(1);
      const glm::mat3 glm_mat(1);

      REQUIRE(my_mat[0][0] == glm_mat[0][0]);
      REQUIRE(my_mat[0][1] == glm_mat[0][1]);
      REQUIRE(my_mat[0][2] == glm_mat[0][2]);
      REQUIRE(my_mat[1][0] == glm_mat[1][0]);
      REQUIRE(my_mat[1][1] == glm_mat[1][1]);
      REQUIRE(my_mat[1][2] == glm_mat[1][2]);
      REQUIRE(my_mat[2][0] == glm_mat[2][0]);
      REQUIRE(my_mat[2][1] == glm_mat[2][1]);
      REQUIRE(my_mat[2][2] == glm_mat[2][2]);
    }
    {
      const mat3 my_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const glm::mat3 glm_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      REQUIRE(my_mat[0][0] == glm_mat[0][0]);
      REQUIRE(my_mat[0][1] == glm_mat[0][1]);
      REQUIRE(my_mat[0][2] == glm_mat[0][2]);
      REQUIRE(my_mat[1][0] == glm_mat[1][0]);
      REQUIRE(my_mat[1][1] == glm_mat[1][1]);
      REQUIRE(my_mat[1][2] == glm_mat[1][2]);
      REQUIRE(my_mat[2][0] == glm_mat[2][0]);
      REQUIRE(my_mat[2][1] == glm_mat[2][1]);
      REQUIRE(my_mat[2][2] == glm_mat[2][2]);
    }
    {
      const mat3 my_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const mat3 my_mat_copy(my_mat);

      const glm::mat3 glm_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const glm::mat3 glm_mat_copy(glm_mat);

      REQUIRE(my_mat_copy[0][0] == glm_mat_copy[0][0]);
      REQUIRE(my_mat_copy[0][1] == glm_mat_copy[0][1]);
      REQUIRE(my_mat_copy[0][2] == glm_mat_copy[0][2]);
      REQUIRE(my_mat_copy[1][0] == glm_mat_copy[1][0]);
      REQUIRE(my_mat_copy[1][1] == glm_mat_copy[1][1]);
      REQUIRE(my_mat_copy[1][2] == glm_mat_copy[1][2]);
      REQUIRE(my_mat_copy[2][0] == glm_mat_copy[2][0]);
      REQUIRE(my_mat_copy[2][1] == glm_mat_copy[2][1]);
      REQUIRE(my_mat_copy[2][2] == glm_mat_copy[2][2]);
    }
    {
      const mat3 my_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const glm::mat3 glm_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      REQUIRE(my_mat[0][0] == glm_mat[0][0]);
      REQUIRE(my_mat[0][1] == glm_mat[0][1]);
      REQUIRE(my_mat[0][2] == glm_mat[0][2]);
      REQUIRE(my_mat[1][0] == glm_mat[1][0]);
      REQUIRE(my_mat[1][1] == glm_mat[1][1]);
      REQUIRE(my_mat[1][2] == glm_mat[1][2]);
      REQUIRE(my_mat[2][0] == glm_mat[2][0]);
      REQUIRE(my_mat[2][1] == glm_mat[2][1]);
      REQUIRE(my_mat[2][2] == glm_mat[2][2]);
    }
  }

    SECTION("Mat3 operations") {
    {
      const mat3 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const mat3 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      const glm::mat3x3 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const glm::mat3x3 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      const auto my_result = my_mat_1 * my_mat_2;
      const auto glm_result = glm_mat_1 * glm_mat_2;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[0][2] == glm_result[0][2]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
      REQUIRE(my_result[1][2] == glm_result[1][2]);
      REQUIRE(my_result[2][0] == glm_result[2][0]);
      REQUIRE(my_result[2][1] == glm_result[2][1]);
      REQUIRE(my_result[2][2] == glm_result[2][2]);
    }
    {
      const mat3 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const vec3 my_mat_2(1, 2, 3);

      const glm::mat3x3 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const glm::vec3 glm_mat_2(1, 2, 3);

      const auto my_result = my_mat_1 * my_mat_2;
      const auto glm_result = glm_mat_2 * glm_mat_1;

      REQUIRE(my_result[0] == glm_result[0]);
      REQUIRE(my_result[1] == glm_result[1]);
      REQUIRE(my_result[2] == glm_result[2]);
    }
    {
      const mat3 my_mat_1(1);
      const mat3 my_mat_2(1);

      REQUIRE(my_mat_1 == my_mat_2);
      REQUIRE_FALSE(my_mat_1 != my_mat_2);
    }
    {
      const mat3 my_mat_1;
      const mat3 my_mat_2;

      REQUIRE(my_mat_1 == my_mat_2);
      REQUIRE_FALSE(my_mat_1 != my_mat_2);
    }
    {
      const mat3 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);
      const mat3 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      REQUIRE(my_mat_1 == my_mat_2);
      REQUIRE_FALSE(my_mat_1 != my_mat_2);
    }
    {
      const mat3 my_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);
      const mat3 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      const glm::mat3 glm_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);
      const glm::mat3 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      const auto my_result = my_mat_1 + my_mat_2;
      const auto glm_result = glm_mat_1 + glm_mat_2;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[0][2] == glm_result[0][2]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
      REQUIRE(my_result[1][2] == glm_result[1][2]);
      REQUIRE(my_result[2][0] == glm_result[2][0]);
      REQUIRE(my_result[2][1] == glm_result[2][1]);
      REQUIRE(my_result[2][2] == glm_result[2][2]);
    }
    {
      const mat3 my_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);
      const mat3 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      const glm::mat3 glm_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);
      const glm::mat3 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3);

      const auto my_result = my_mat_1 - my_mat_2;
      const auto glm_result = glm_mat_1 - glm_mat_2;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[0][2] == glm_result[0][2]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
      REQUIRE(my_result[1][2] == glm_result[1][2]);
      REQUIRE(my_result[2][0] == glm_result[2][0]);
      REQUIRE(my_result[2][1] == glm_result[2][1]);
      REQUIRE(my_result[2][2] == glm_result[2][2]);
    }
    {
      const mat3 my_mat_1(
        vec3(11, -2.3, 3),
        vec3(4, 0.3f, 0),
        vec3(123, 2, 2)
      );

      const glm::mat3 glm_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const auto my_result = my_mat_1 + 46.6f;
      const auto glm_result = glm_mat_1 + 46.6f;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[0][2] == glm_result[0][2]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
      REQUIRE(my_result[1][2] == glm_result[1][2]);
      REQUIRE(my_result[2][0] == glm_result[2][0]);
      REQUIRE(my_result[2][1] == glm_result[2][1]);
      REQUIRE(my_result[2][2] == glm_result[2][2]);
    }
    {
      const mat3 my_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const glm::mat3 glm_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const auto my_result = my_mat_1 - 46.6f;
      const auto glm_result = glm_mat_1 - 46.6f;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[0][2] == glm_result[0][2]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
      REQUIRE(my_result[1][2] == glm_result[1][2]);
      REQUIRE(my_result[2][0] == glm_result[2][0]);
      REQUIRE(my_result[2][1] == glm_result[2][1]);
      REQUIRE(my_result[2][2] == glm_result[2][2]);
    }
    {
      const mat3 my_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const glm::mat3 glm_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const auto my_result = my_mat_1 * 46.6f;
      const auto glm_result = glm_mat_1 * 46.6f;

      REQUIRE(my_result[0][0] == glm_result[0][0]);
      REQUIRE(my_result[0][1] == glm_result[0][1]);
      REQUIRE(my_result[0][2] == glm_result[0][2]);
      REQUIRE(my_result[1][0] == glm_result[1][0]);
      REQUIRE(my_result[1][1] == glm_result[1][1]);
      REQUIRE(my_result[1][2] == glm_result[1][2]);
      REQUIRE(my_result[2][0] == glm_result[2][0]);
      REQUIRE(my_result[2][1] == glm_result[2][1]);
      REQUIRE(my_result[2][2] == glm_result[2][2]);
    }
    {
      const mat3 my_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const glm::mat3 glm_mat_1(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      const auto my_result = my_mat_1 / 46.6f;
      const auto glm_result = glm_mat_1 / 46.6f;

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          REQUIRE(my_result[i][j] == Approx(glm_result[i][j]).epsilon(EPS));
        }
      }
    }
  }

  SECTION("Mat3 functions") {
    {
      const mat3 my_mat =
          mat3(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2).get_transpose_matrix();
      const glm::mat3 glm_mat =
          glm::transpose(glm::mat3(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2));

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          REQUIRE(my_mat[i][j] == glm_mat[i][j]);
        }
      }
    }
    {
      const mat3 my_mat(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);
      const glm::mat3 glm_mat(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2);

      for (int i = 0; i < 3; i++) {
        auto row = my_mat[i];

        for (int j = 0; j < 3; j++) {
          REQUIRE(row[j] == glm_mat[i][j]);
        }
      }
    }
    {
      float my_det = mat3(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2).det();
      float glm_det =
          glm::determinant(glm::mat3(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2));

      REQUIRE(my_det == glm_det);
    }
    {
      const mat3 my_invertible_mat =
          mat3(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2).get_invertible_matrix();
      const glm::mat3 glm_invertible_mat =
          glm::inverse(glm::mat3(11, -2.3, 3, 4, 0.3f, 0, 123, 2, 2));

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          REQUIRE(my_invertible_mat[i][j] ==
                  Approx(glm_invertible_mat[i][j]).epsilon(EPS));
        }
      }
    }
    {
      const mat3 my_invertible_mat =
          mat3(11.111, -2, 3, 4, 0.f, 0, -123, -2, -2).get_invertible_matrix();
      const glm::mat3 glm_invertible_mat =
          glm::inverse(glm::mat3(11.111, -2, 3, 4, 0.f, 0, -123, -2, -2));

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          REQUIRE(my_invertible_mat[i][j] ==
                  Approx(glm_invertible_mat[i][j]).epsilon(EPS));
        }
      }
    }
    {
      const mat3 my_result = mat3::get_identity_matrix();
      const glm::mat3 glm_result(1.0f);

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          REQUIRE(my_result[i][j] == Approx(glm_result[i][j]).epsilon(EPS));
        }
      }
    }
  }
}

TEST_CASE("Class Mat4 testing", "[mat]") {
  SECTION("Mat4 constructors") {
    {
      const mat4 my_mat(1);
      const glm::mat4 glm_mat(1);

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          REQUIRE(my_mat[i][j] == glm_mat[i][j]);
        }
      }
    }
    {
      const mat4 my_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                        10, 2, 3, 4);
      const glm::mat4 glm_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                              -777, 10, 2, 3, 4);

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          REQUIRE(my_mat[i][j] == glm_mat[i][j]);
        }
      }
    }
    {
      const mat4 my_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                        10, 2, 3, 4);
      const mat4 my_mat_copy(my_mat);

      const glm::mat4 glm_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                              -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_copy(glm_mat);

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          REQUIRE(my_mat[i][j] == glm_mat[i][j]);
        }
      }
    }
    {
      const mat4 my_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                        10, 2, 3, 4);
      const glm::mat4 glm_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                              -777, 10, 2, 3, 4);

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          REQUIRE(my_mat[i][j] == glm_mat[i][j]);
        }
      }
    }
  }

  SECTION("Mat4 operations") {
    {
      const mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);
      const mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);

      const glm::mat4x4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12,
                                  -40.3f, -777, 10, 2, 3, 4);
      const glm::mat4x4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12,
                                  -40.3f, -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 * my_mat_2;
      const auto glm_result = glm_mat_1 * glm_mat_2;

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);
      const vec4 my_mat_2(1, 2, 3, 4);

      const glm::mat4x4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12,
                                  -40.3f, -777, 10, 2, 3, 4);
      const glm::vec4 glm_mat_2(1, 2, 3, 4);

      const auto my_result = my_mat_1 * my_mat_2;
      const auto glm_result = glm_mat_2 * glm_mat_1;

      for (int i = 0; i < 4; i++) {
          REQUIRE(my_result[i] == glm_result[i]);
      }
    }
    {
      const mat4 my_mat_1(1);
      const mat4 my_mat_2(1);

      REQUIRE(my_mat_1 == my_mat_2);
      REQUIRE_FALSE(my_mat_1 != my_mat_2);
    }
    {
      const mat4 my_mat_1;
      const mat4 my_mat_2;

      REQUIRE(my_mat_1 == my_mat_2);
      REQUIRE_FALSE(my_mat_1 != my_mat_2);
    }
    {
      const mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);
      const mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);

      REQUIRE(my_mat_1 == my_mat_2);
      REQUIRE_FALSE(my_mat_1 != my_mat_2);
    }
    {
      const mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);
      const mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);

      const glm::mat4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                                -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                                -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 + my_mat_2;
      const auto glm_result = glm_mat_1 + glm_mat_2;

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);
      const mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);

      const glm::mat4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                                -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                                -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 - my_mat_2;
      const auto glm_result = glm_mat_1 - glm_mat_2;

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);
      const mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);

      const glm::mat4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                                -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                                -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 + 77.8f;
      const auto glm_result = glm_mat_1 + 77.8f;

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);
      const mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);

      const glm::mat4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                                -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                                -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 - 77.8f;
      const auto glm_result = glm_mat_1 - 77.8f;

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);
      const mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);

      const glm::mat4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                                -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                                -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 * 77.8f;
      const auto glm_result = glm_mat_1 * 77.8f;

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
    {
      const mat4 my_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);
      const mat4 my_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4);

      const glm::mat4 glm_mat_1(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                                -777, 10, 2, 3, 4);
      const glm::mat4 glm_mat_2(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                                -777, 10, 2, 3, 4);

      const auto my_result = my_mat_1 * 77.8f;
      const auto glm_result = glm_mat_1 * 77.8f;

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          REQUIRE(my_result[i][j] == glm_result[i][j]);
        }
      }
    }
  }

  SECTION("Mat4 functions") {
    {
      const mat4 my_mat = mat4(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                               -777, 10, 2, 3, 4).get_transpose_matrix();
      const glm::mat4 glm_mat = glm::transpose(glm::mat4(
          1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4));

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          REQUIRE(my_mat[i][j] == glm_mat[i][j]);
        }
      }
    }
    {
      const mat4 my_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                        10, 2, 3, 4);
      const glm::mat4 glm_mat(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f,
                              -777, 10, 2, 3, 4);

      for (int i = 0; i < 4; i++) {
        auto row = my_mat[i];

        for (int j = 0; j < 4; j++) {
          REQUIRE(row[j] == glm_mat[i][j]);
        }
      }
    }
    {
      float my_det = mat4(1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777,
                          10, 2, 3, 4).det();
      float glm_det = glm::determinant(glm::mat4(
          1, 2, 3, 4, -10.f, 944.4f, 5, 4, 3, 12, -40.3f, -777, 10, 2, 3, 4));

      REQUIRE(my_det == glm_det);
    }
    {
      const mat4 my_invertible_mat =
          mat4(1, 2, 3, 4, 10.f, 12, 14, 4, 3, 12, -10, -77, 10, 2, 3, 4).get_invertible_matrix();
      const glm::mat4 glm_invertible_mat = glm::inverse(
          glm::mat4(1, 2, 3, 4, 10.f, 12, 14, 4, 3, 12, -10, -77, 10, 2, 3, 4));

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          REQUIRE(my_invertible_mat[i][j] ==
                  Approx(glm_invertible_mat[i][j]).epsilon(EPS));
        }
      }
    }
    {
      const mat4 my_result = mat4::get_identity_matrix();
      const glm::mat4 glm_result(1.0f);

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          REQUIRE(my_result[i][j] == Approx(glm_result[i][j]).epsilon(EPS));
        }
      }
    }
    {
      glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
      glm::mat4 trans(1.0f);
      trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
      vec = trans * vec;

      vec4 vec_2(1.0f, 0.0f, 0.0f, 1.0f);
      vec3 tr_vec({1.0f, 1.0f, 0.0f});
      auto res_math = mat4::offset_matrix(tr_vec);
      auto res = res_math * vec_2;

      REQUIRE(res[0] == vec.x);
      REQUIRE(res[1] == vec.y);
      REQUIRE(res[2] == vec.z);
    }
    {
      glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
      glm::mat4 trans(1.0f);
      trans = glm::rotate(trans, 90.0f, glm::vec3(0.0, 0.0, 1.0));
      vec = trans * vec;

      vec4 vec_2(1.0f, 0.0f, 0.0f, 1.0f);

      vec3 tr_vec({0.0, 0.0, 1.0});
      auto res_math = mat4::rotation_matrix(90.0f, tr_vec);
      auto res = res_math * vec_2;

      REQUIRE(res[0] == vec.x);
      REQUIRE(res[1] == vec.y);
      REQUIRE(res[2] == vec.z);
    }
    {
      glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
      glm::mat4 trans(1.0f);
      trans = glm::scale(trans, glm::vec3(1.5f, 1.5f, 0.0f));
      vec = trans * vec;

      vec4 vec_2(1.0f, 0.0f, 0.0f, 1.0f);
      vec3 tr_vec({1.5f, 1.5f, 0.0f});
      auto res_math = mat4::scale_matrix(tr_vec);
      auto res = res_math * vec_2;

      REQUIRE(res[0] == vec.x);
      REQUIRE(res[1] == vec.y);
      REQUIRE(res[2] == vec.z);
    }
  }
}