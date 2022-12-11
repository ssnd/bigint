#include <iostream>
#include "version.h"
#include "bigint/bigint.h"

enum bigintOperator {
  PLUS, MINUS
};

int run_cli() {
  std::string operation, x,y;
  bigintOperator op;
  std::cout << "enter operation" << std::endl;

  std::cin >> operation;
  if (operation.empty()) {
    std::cerr << "empty operation name" << std::endl;
    return 1;
  }

  switch (operation[0]) {
     case '-':
       op = MINUS;
       break;
     case '+':
       op = PLUS;
       break;
    default:
       std::cerr << "wrong operation name provided, '+' and '-' are supported for now" << std::endl;
       return 1;
  }

  std::cout << "enter first number:" << std::endl;
  std::cin >> x;
  std::cout << "enter second number:" << std::endl;
  std::cin >> y;

  bigint a;
  bigint b;

  try {
    a = bigint(x);
    b = bigint(y);
  } catch (const char * msg) {
    std::cerr << "exception caught while trying to read the argument" << std::endl;
    std::cerr << msg << std::endl;
    return 1;
  }


  std::cout << "result: "<< std::endl;
  if (op == PLUS) {
    std::cout << a + b << std::endl;
  } else { // op == MINUS
    std::cout << a - b << std::endl;
  }

  return 0;

}

int main() {
  std::cout << "bigint-cli, version=" << git_version() << ", revision=" << git_revision() << std::endl;
  return run_cli();
}

