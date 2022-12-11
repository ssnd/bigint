//
// Created by Kiritsa Sandu on 01.12.2022.
//

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>


class bigint {
 public:
  bigint();
  explicit bigint(const std::string& input);
  bool is_negative() const;
  static void validate_input(const std::string & input) ;

  // unary operators
  bigint operator-() const;

  // binary operators
  friend bool operator==(const bigint & lhs, const bigint &rhs);
  friend bool operator!=(const bigint & lhs, const bigint &rhs) { return !(rhs == lhs); }

  friend bool operator<(const bigint & lhs, const bigint &rhs);
  friend bool operator> (const bigint& lhs, const bigint& rhs) { return rhs < lhs; }
  friend bool operator<=(const bigint& lhs, const bigint& rhs) { return !(lhs > rhs); }
  friend bool operator>=(const bigint& lhs, const bigint& rhs) { return !(lhs < rhs); }

  friend bigint operator+(const bigint& lhs, const bigint& rhs);
  friend bigint operator-(const bigint& lhs, const bigint& rhs);

  // stream operators
  friend std::ostream& operator<<(std::ostream& os, const bigint& self);
 private:
  void cleanup();
  std::vector<int> _digits;
  bool _is_negative = false;
  static const int base = 1000000000;
};


