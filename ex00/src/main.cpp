#include <iomanip>
#include <iostream>

#include "whatever.hpp"

#define RESET "\033[m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BOLD "\033[1m"

// print title in green color surrounded by '='
void printTitle(std::string const& title) {
  // set color to green
  std::cout << GREEN << BOLD;
  // print '='
  std::cout << std::setfill('=') << std::setw(80) << "" << std::endl;
  // print title at the center
  std::cout << std::setfill(' ') << std::setw(40 - title.length() / 2) << ""
            << title << std::endl;
  // print '='
  std::cout << std::setfill('=') << std::setw(80) << "" << std::endl;
  // reset color
  std::cout << RESET << std::setfill(' ') << std::setw(0);
}

// print test subtitle in white color surrounded by '-'
void printSubtitle(std::string const& subtitle) {
  // print '-'
  std::cout << std::setfill('-') << std::setw(80) << "" << std::endl;
  // print subtitle at the center
  std::cout << std::setfill(' ') << std::setw(40 - subtitle.length() / 2) << ""
            << subtitle << std::endl;
  // print '-'
  std::cout << std::setfill('-') << std::setw(80) << "" << std::endl;
  // reset color
  std::cout << RESET << std::setfill(' ') << std::setw(0);
}

void test_from_subject() {
  printTitle("Test from sunject pdf");
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

void test_swap() {
  printTitle("Test swap");
  // Test int
  {
    printSubtitle("int");
    int a = 2;
    int b = 3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
  }
  // Test float
  {
    printSubtitle("float");
    float a = 2.2;
    float b = 3.3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
  }
  // Test char
  {
    printSubtitle("char");
    char a = 'a';
    char b = 'b';
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
  }
  // Test string
  {
    printSubtitle("string");
    std::string a = "string1";
    std::string b = "string2";
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
  }
}

void test_min() {
  printTitle("Test min");
  // Test int
  {
    printSubtitle("int");
    int a = 2;
    int b = 3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  }
  // Test float
  {
    printSubtitle("float");
    float a = 2.2;
    float b = 3.3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  }
  // Test char
  {
    printSubtitle("char");
    char a = 'a';
    char b = 'b';
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  }
  // Test string
  {
    printSubtitle("string");
    std::string a = "string1";
    std::string b = "string2";
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  }
}

void test_max() {
  printTitle("Test max");
  // Test int
  {
    printSubtitle("int");
    int a = 2;
    int b = 3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  }
  // Test float
  {
    printSubtitle("float");
    float a = 2.2;
    float b = 3.3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  }
  // Test char
  {
    printSubtitle("char");
    char a = 'a';
    char b = 'b';
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  }
  // Test string
  {
    printSubtitle("string");
    std::string a = "string1";
    std::string b = "string2";
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  }
}

int main(void) {
  test_swap();
  test_min();
  test_max();
  test_from_subject();
  return 0;
}
