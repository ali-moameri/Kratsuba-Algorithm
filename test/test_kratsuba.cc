#include <gtest/gtest.h>
#include <string>

#include "kratsuba.cc"

TEST(KratsubaTest, VeryLargeMultiplyTest) {

  std::string x{
      "3141592653589793238462643383279502884197169399375105820974944592"};
  std::string y{
      "2718281828459045235360287471352662497757247093699959574966967627"};

  const std::string expected_result =
      "853973422267356706546355086954657449503488853576511496187960112706774304"
      "4893204848617875072216249073013374895871952806582723184";

  EXPECT_EQ(Kratsuba::multiply(x, y), expected_result);
}

TEST(KratsubaTest, MultiplyByZeroTest) {

  std::string x{"0"};
  std::string y{"123456799"};

  const std::string expected_result = "0";

  EXPECT_EQ(Kratsuba::multiply(x, y), expected_result);
}

TEST(KratsubaTest, MultiplyByOneTest) {

  std::string x{"1"};
  std::string y{"123456799"};

  EXPECT_EQ(Kratsuba::multiply(x, y), y);
}

TEST(KratsubaTest, NormalMultiplyTest) {

  std::string x{"2"};
  std::string y{"12"};

  const std::string expected_result = "24";

  EXPECT_EQ(Kratsuba::multiply(x, y), expected_result);
}
