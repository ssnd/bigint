#include <gtest/gtest.h>
#include "../bigint.h"

TEST(OperatorTests, TestEqualityOperator) {
  // operator==
  EXPECT_TRUE(bigint("0") == bigint("0"));
  EXPECT_TRUE(bigint("-100") == bigint("-100"));
  EXPECT_TRUE(bigint("-99999999999999999999999999999999999") == bigint("-99999999999999999999999999999999999"));
  EXPECT_TRUE(bigint("-9999999999999999999999999999999999999999999999999999999999999999999999") == bigint("-9999999999999999999999999999999999999999999999999999999999999999999999"));

  // operator!=
  EXPECT_FALSE(bigint("0") == bigint("1"));
  EXPECT_FALSE(bigint("1") == bigint("-1"));
  EXPECT_FALSE(bigint("-99999999999999999999999999999999999") == \
              bigint("-999999999999999999999999999"));
  EXPECT_FALSE(bigint("-999999999999999999999999999999999999999999999999999999999999999999991") ==  \
              bigint("-99999999999999999999999999999999999999999999999999999"));
  EXPECT_FALSE(bigint("-1999999999999999999999999999999999999999999999999999999999999999999999") == \
              bigint("-999999999999999999999999999999999999999999999999999999"));

}

TEST(OperatorTests, TestInequalities) {
  // <
  EXPECT_TRUE(bigint("-1") < bigint("0"));
  EXPECT_TRUE(bigint("-2") < bigint("-1"));
  EXPECT_TRUE(bigint("1") < bigint("2"));
  EXPECT_TRUE(bigint("1") < bigint("2"));
  EXPECT_TRUE(bigint("100") < bigint("100000000"));
  EXPECT_TRUE(bigint("999999999") < bigint("999999999999"));
  EXPECT_TRUE(bigint("999999989999999999") < bigint("999999999999999999"));
  EXPECT_TRUE(bigint("89999999999999999") < bigint("99999999999999999"));
  EXPECT_TRUE(bigint("89999999999999990") < bigint("89999999999999991"));
}

TEST(OperatorTests, TestUnaryOperators) {
  // <
  EXPECT_TRUE(-bigint("-1") == bigint("1"));
  EXPECT_TRUE(-bigint("-999999999999999") == bigint("999999999999999"));

}