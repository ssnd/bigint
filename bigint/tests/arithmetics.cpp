#include <gtest/gtest.h>
#include "../bigint.h"

TEST(ArithmeticTests, TestSubtraction) {
  auto ensure_diff_equal = [](const std::string& a, const std::string &b, const std::string & expected){
    EXPECT_TRUE(bigint(a)-bigint(b) == bigint(expected));
  };

  ensure_diff_equal("2", "1", "1");
  ensure_diff_equal("2000000000000000000000000000000000000000000",
                    "1000000000000000000000000000000000000000000",
                    "1000000000000000000000000000000000000000000");
  ensure_diff_equal("1000000000000000000000000000000000000000000",
                    "2000000000000000000000000000000000000000000",
                    "-1000000000000000000000000000000000000000000");
  ensure_diff_equal("1000000000000000000000000000000000000000000",
                    "1",
                    "999999999999999999999999999999999999999999");
  ensure_diff_equal("999999999999", "999999999999", "0");

}

TEST(ArithmeticTests, TestAddition) {
  auto ensure_sum_equal = [](const std::string& a, const std::string &b, const std::string & expected){
    EXPECT_TRUE(bigint(a)+bigint(b) == bigint(expected));
  };

  ensure_sum_equal("999999999999", "-999999999999", "0");
  ensure_sum_equal("0", "0", "0");
  ensure_sum_equal("100", "100", "200");
  ensure_sum_equal("999999999", "-999999999", "0");
}
