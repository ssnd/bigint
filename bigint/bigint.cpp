//
// Created by Kiritsa Sandu on 01.12.2022.
//

#include "bigint.h"
#include <iomanip>


bigint::bigint(const std::string &input) {
  validate_input(input);

  auto begin = input.cbegin();
  auto end = input.cend();

  if (*begin == '-') { // the first element must exist as we checked for invalid inputs earlier
    begin++;
    _is_negative = true;
  }

  std::string buff;

  while (end - begin > 9) {
    for (auto it = end-9; it != end; it++) {
      buff.push_back(*it);
    }

    end-=9;
    _digits.push_back(stoi(buff));
    buff.clear();
  }

  if (end != begin) {
    for (auto it = begin; it != end; it++) {
      buff.push_back(*it);
    }

    _digits.push_back(stoi(buff));
  }

  cleanup();
  if (this->_digits.size() == 1 && this->_digits[0] == 0) this->_is_negative = false;
}

void bigint::validate_input(const std::string &input) {
  if (input.empty()) {
      throw std::invalid_argument("invalid input string");
  }

  if ((input[0] == '-' || input[0] =='+') && input.size()==1) {
      throw std::invalid_argument("invalid input string");
  }

  for (size_t i = 0; i < input.size(); ++i) {
      if (0==i && ('-'==input[i] || '+'==input[i] )) {
        continue;
      }

      if (!std::isdigit(input[i])) {
        throw std::invalid_argument("invalid input string");
      }
    }
}

std::ostream& operator<<(std::ostream& os, const bigint& self) {
  // handle zero separately
  if (self._digits.size() == 1 && self._digits[0] == 0) {
    os << 0;
    return os;
  }

  std::stringstream ss;
  for (auto it = self._digits.rbegin(); it != self._digits.rend(); ++it) {
    if (it - self._digits.rbegin() > 0) {
      ss << std::setw(9) << std::setfill('0') ;
    }
    ss << *it;
  }

  os << (self.is_negative() ? "-" : "") << ss.str() ;

  return os;
}

bigint::bigint() {

}

bool bigint::is_negative() const {
    return this->_is_negative;
}

bigint operator+(const bigint &lhs, const bigint &rhs) {
  if (lhs.is_negative() && rhs.is_negative()) {
    return -(-lhs + (-rhs));
  }

  if (lhs.is_negative() && !rhs.is_negative()) {
    return rhs - (-lhs);
  }

  if (!lhs.is_negative() && rhs.is_negative() ){
    return lhs - (-rhs);
  }

  bigint result = bigint(lhs);
  int carry = 0;

  for (size_t i = 0; i < std::max(result._digits.size(), rhs._digits.size()) || carry; ++i) {
    if( i==result._digits.size()) {
      result._digits.push_back(0);
    }
    int right = (i < rhs._digits.size()) ? rhs._digits[i] : 0;
    result._digits[i] += carry + right;

    if (result._digits[i] >= 1000000000) {
      result._digits[i] -= 1000000000;
      carry = 1;
    } else {
      carry = 0;
    }
  }

  return result;
}

bool operator==(const bigint &lhs, const bigint &rhs) {
  if (lhs.is_negative() != rhs.is_negative()) {
    return false;
  }

  if (lhs._digits.size() != rhs._digits.size()) {
    return false;
  }

  for (size_t i = 0; i < lhs._digits.size(); ++i){
    if (lhs._digits[i] != rhs._digits[i]){
      return false;
    }
  }

  return true;
}


bigint operator-(const bigint &lhs, const bigint &rhs) {
  if (rhs.is_negative()) {
    return lhs + (-rhs);
  }
  if (lhs.is_negative()) {
    return - (-lhs + rhs);
  }

  if  (lhs < rhs) {
    return - (rhs - lhs);
  }

  bigint result = bigint(lhs);
  int carry = 0;

  for (size_t i = 0; i < std::max(result._digits.size(), rhs._digits.size()) || carry; ++i) {
    int right = (i < rhs._digits.size()) ? rhs._digits[i] : 0;
    result._digits[i] -= carry + right;

    if (result._digits[i] < 0) {
      result._digits[i] += bigint::base;
      carry = 1;
    } else {
      carry = 0;
    }
  }

  result.cleanup();
  return result;
}

bool operator<(const bigint &lhs, const bigint &rhs) {
  if (lhs == rhs) {
    return false;
  }

  if (lhs.is_negative() && !rhs.is_negative()) { // -1  < 1
    return true;
  }

  if (!lhs.is_negative() && rhs.is_negative()) { // 1 > -1
    return false;
  }

  if (lhs.is_negative() && rhs.is_negative()) { // -2 < -1 <==> 2 > 1
    return (-rhs < -lhs);
  }

  if (lhs._digits.size() != rhs._digits.size()) {
    return lhs._digits.size() < rhs._digits.size();
  }

  for (size_t i = 0; i < lhs._digits.size(); ++i ){
    if (lhs._digits[i] != rhs._digits[i]) {
      return lhs._digits[i] < rhs._digits[i];
    }
  }

  return true;
}

bigint bigint::operator-() const {
  bigint my(*this);
  my._is_negative = !my._is_negative;
  return my;
}

void bigint::cleanup() {
  while (this->_digits.size() > 1 && this->_digits.back() == 0) {
    this->_digits.pop_back();
  }
}


