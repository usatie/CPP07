#include <iomanip>
#include <iostream>

#include "iter.hpp"

#define RESET "\033[m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define BOLD "\033[1m"

// print title in green color surrounded by '='
void printTitle(std::string const &title) {
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
void printSubtitle(std::string const &subtitle) {
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

// Print functions
template <typename T>
void print_T(T v) {
  std::cout << v << " ";
}
template <typename T>
void print_const_T(const T v) {
  std::cout << v << " ";
}
template <typename T>
void print_ref_T(T &v) {
  std::cout << v << " ";
}
template <typename T>
void print_const_ref_T(const T &v) {
  std::cout << v << " ";
}

void print_int(int i) { std::cout << i << " "; }
void print_const_int(int const i) { std::cout << i << " "; }
void print_ref_int(int &i) { std::cout << i << " "; }
void print_const_ref_int(int const &i) { std::cout << i << " "; }

/* ===========================================================================*/
/*                               Primitive types                              */
/* ===========================================================================*/
// Test int array with concrete functions
void test_int_array() {
  printTitle("Test T = int");
  {
    int array[] = {0, 1, 2, 3, 4};
    printSubtitle("Test function takes T");
    ::iter(array, 5, print_int);
    std::cout << std::endl;
    printSubtitle("Test function takes T const");
    ::iter(array, 5, print_const_int);
    std::cout << std::endl;
    printSubtitle("Test function takes T &");
    ::iter(array, 5, print_ref_int);
    std::cout << std::endl;
    printSubtitle("Test function takes T const &");
    ::iter(array, 5, print_const_ref_int);
    std::cout << std::endl;
  }
}

// Test char array with template functions
void test_char_array_template() {
  printTitle("Test T = char");
  {
    char array[] = {'a', 'b', 'c', 'd', 'e'};
    printSubtitle("Test function takes T");
    ::iter(array, 5, print_T<char>);
    std::cout << std::endl;
    printSubtitle("Test function takes T const");
    ::iter(array, 5, print_const_T<char>);
    std::cout << std::endl;
    printSubtitle("Test function takes T &");
    ::iter(array, 5, print_ref_T<char>);
    std::cout << std::endl;
    printSubtitle("Test function takes T const &");
    ::iter(array, 5, print_const_ref_T<char>);
    std::cout << std::endl;
  }
}

// Test const char* array with template functions
void test_const_char_array_template() {
  printTitle("Test T = char const *");
  {
    char const *array[] = {"a", "bb", "ccc", "dddd", "eeeee"};
    printSubtitle("Test function takes T");
    ::iter(array, 5, print_T<const char *>);
    std::cout << std::endl;
    printSubtitle("Test function takes T const");
    ::iter(array, 5, print_const_T<const char *>);
    std::cout << std::endl;
    printSubtitle("Test function takes T &");
    ::iter(array, 5, print_ref_T<const char *>);
    std::cout << std::endl;
    printSubtitle("Test function takes T const &");
    ::iter(array, 5, print_const_ref_T<const char *>);
    std::cout << std::endl;
  }
}

/* ===========================================================================*/
/*                               Test with template                           */
/* ===========================================================================*/
// Test int array with template functions
void test_int_array_template() {
  printTitle("Test int array");
  {
    int array[] = {0, 1, 2, 3, 4};
    printSubtitle("Test function takes int");
    ::iter(array, 5, print_T<int>);
    std::cout << std::endl;
    printSubtitle("Test function takes int const");
    ::iter(array, 5, print_const_T<int>);
    std::cout << std::endl;
    printSubtitle("Test function takes int &");
    ::iter(array, 5, print_ref_T<int>);
    std::cout << std::endl;
    printSubtitle("Test function takes int const &");
    ::iter(array, 5, print_const_ref_T<int>);
    std::cout << std::endl;
  }
}

// Test const int array with template functions
void test_const_int_array_template() {
  printTitle("Test const int array");
  {
    int const array[] = {0, 1, 2, 3, 4};
    printSubtitle("Test function takes int");
    ::iter(array, 5, print_T<const int>);
    std::cout << std::endl;
    printSubtitle("Test function takes int const");
    ::iter(array, 5, print_const_T<const int>);
    std::cout << std::endl;
    printSubtitle("Test function takes int &");
    ::iter(array, 5, print_ref_T<const int>);
    std::cout << std::endl;
    printSubtitle("Test function takes int const &");
    ::iter(array, 5, print_const_ref_T<const int>);
    std::cout << std::endl;
  }
}

// Test const array of int with template functions
void test_const_array_of_int_template() {
  printTitle("Test const array of int");
  {
    int array[] = {0, 1, 2, 3, 4};
    int *const const_array = array;
    printSubtitle("Test function takes int");
    ::iter(const_array, 5, print_T<int>);
    std::cout << std::endl;
    printSubtitle("Test function takes int const");
    ::iter(const_array, 5, print_const_T<int>);
    std::cout << std::endl;
    printSubtitle("Test function takes int &");
    ::iter(const_array, 5, print_ref_T<int>);
    std::cout << std::endl;
    printSubtitle("Test function takes int const &");
    ::iter(const_array, 5, print_const_ref_T<int>);
    std::cout << std::endl;
  }
}

// Test const array of const int with template functions
void test_const_array_of_const_int_template() {
  printTitle("Test const array of const int");
  {
    int array[] = {0, 1, 2, 3, 4};
    int const *const const_array = array;
    printSubtitle("Test function takes const int");
    ::iter(const_array, 5, print_T<const int>);
    std::cout << std::endl;
    printSubtitle("Test function takes const const int");
    ::iter(const_array, 5, print_const_T<const int>);
    std::cout << std::endl;
    printSubtitle("Test function takes const int &");
    ::iter(const_array, 5, print_ref_T<const int>);
    std::cout << std::endl;
    printSubtitle("Test function takes const int & const");
    ::iter(const_array, 5, print_const_ref_T<const int>);
    std::cout << std::endl;
  }
}

int main(void) {
  // Test with concrete function
  test_int_array();

  // Test (T/const T/T &/const T &) functions
  test_char_array_template();
  test_const_char_array_template();
  test_int_array_template();
  test_const_int_array_template();
  test_const_array_of_int_template();
  test_const_array_of_const_int_template();
  return 0;
}
