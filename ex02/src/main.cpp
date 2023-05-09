#include <iomanip>
#include <iostream>

#include "Array.hpp"

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

// Test with int
void testArrayInt() {
  printTitle("Test int array");

  printSubtitle("Constructors");
  Array<int> a1;
  Array<int> a2(5);
  Array<int> a3(a2);
  Array<int> a4(0);

  printSubtitle("Accessors");
  std::cout << "a1.size() = " << a1.size() << std::endl;
  std::cout << "a2.size() = " << a2.size() << std::endl;
  std::cout << "a3.size() = " << a3.size() << std::endl;

  printSubtitle("Operators");
  for (unsigned int i = 0; i < a2.size(); i++) {
    a2[i] = i;
    std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
  }
  for (unsigned int i = 0; i < a3.size(); i++) {
    a3[i] = i * 2;
    std::cout << "a3[" << i << "] = " << a3[i] << std::endl;
  }
  {
    const Array<int> a5 = a2;
    for (unsigned int i = 0; i < a5.size(); i++) {
      std::cout << "a5[" << i << "] = " << a5[i] << std::endl;
    }
  }

  printSubtitle("Copy");
  a1 = a2;
  for (unsigned int i = 0; i < a1.size(); i++) {
    std::cout << "a1[" << i << "] = " << a1[i] << std::endl;
  }

  printSubtitle("Output");
  std::cout << "a1 = " << a1 << std::endl;
  std::cout << "a2 = " << a2 << std::endl;
  std::cout << "a3 = " << a3 << std::endl;
  std::cout << "a4 = " << a4 << std::endl;

  printSubtitle("Exceptions");
  try {
    std::cout << "a1[0]: " << a1[0] << std::endl;
    std::cout << "a1[1]: " << a1[1] << std::endl;
    std::cout << "a1[2]: " << a1[2] << std::endl;
    std::cout << "a1[3]: " << a1[3] << std::endl;
    std::cout << "a1[4]: " << a1[4] << std::endl;
    std::cout << "a1[5]: " << a1[5] << std::endl;
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  try {
    std::cout << "a1[0] = 0;" << std::endl;
    a1[0] = 0;
    std::cout << "a1[1] = 1;" << std::endl;
    a1[1] = 1;
    std::cout << "a1[2] = 2;" << std::endl;
    a1[2] = 2;
    std::cout << "a1[3] = 3;" << std::endl;
    a1[3] = 3;
    std::cout << "a1[4] = 4;" << std::endl;
    a1[4] = 4;
    std::cout << "a1[5] = 5;" << std::endl;
    a1[5] = 5;
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

// Tests with string
void testArrayString() {
  printTitle("Test string array");

  printSubtitle("Constructors");
  Array<std::string> a1;
  Array<std::string> a2(5);
  Array<std::string> a3(a2);
  Array<std::string> a4(0);

  printSubtitle("Accessors");
  std::cout << "a1.size() = " << a1.size() << std::endl;
  std::cout << "a2.size() = " << a2.size() << std::endl;
  std::cout << "a3.size() = " << a3.size() << std::endl;

  printSubtitle("Operators");
  for (unsigned int i = 0; i < a2.size(); i++) {
    a2[i] = "Hello" + std::to_string(i);
    std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
  }
  for (unsigned int i = 0; i < a3.size(); i++) {
    a3[i] = "World" + std::to_string(i);
    std::cout << "a3[" << i << "] = " << a3[i] << std::endl;
  }
  {
    const Array<std::string> a5 = a2;
    for (unsigned int i = 0; i < a5.size(); i++) {
      std::cout << "a5[" << i << "] = " << a5[i] << std::endl;
    }
  }

  printSubtitle("Copy");
  a1 = a2;
  for (unsigned int i = 0; i < a1.size(); i++) {
    std::cout << "a1[" << i << "] = " << a1[i] << std::endl;
  }

  printSubtitle("Output");
  std::cout << "a1 = " << a1 << std::endl;
  std::cout << "a2 = " << a2 << std::endl;
  std::cout << "a3 = " << a3 << std::endl;
  std::cout << "a4 = " << a4 << std::endl;

  printSubtitle("Exceptions []");
  try {
    std::cout << "a1[0]: " << a1[0] << std::endl;
    std::cout << "a1[1]: " << a1[1] << std::endl;
    std::cout << "a1[2]: " << a1[2] << std::endl;
    std::cout << "a1[3]: " << a1[3] << std::endl;
    std::cout << "a1[4]: " << a1[4] << std::endl;
    std::cout << "a1[5]: " << a1[5] << std::endl;
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  printSubtitle("Exceptions []");
  try {
    std::cout << "a1[0] = \"HELLO0\";" << std::endl;
    a1[0] = "HELLO0";
    std::cout << "a1[1] = \"HELLO1\";" << std::endl;
    a1[1] = "HELLO1";
    std::cout << "a1[2] = \"HELLO2\";" << std::endl;
    a1[2] = "HELLO2";
    std::cout << "a1[3] = \"HELLO3\";" << std::endl;
    a1[3] = "HELLO3";
    std::cout << "a1[4] = \"HELLO4\";" << std::endl;
    a1[4] = "HELLO4";
    std::cout << "a1[5] = \"HELLO5\";" << std::endl;
    a1[5] = "HELLO5";
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

// Test const array with int
void testConstArrayInt() {
  printTitle("Test const array of int");

  printSubtitle("Constructors");
  const Array<int> a1;
  const Array<int> a2(5);
  const Array<int> a3(a2);
  const Array<int> a4(0);

  printSubtitle("Accessors");
  std::cout << "a1.size() = " << a1.size() << std::endl;
  std::cout << "a2.size() = " << a2.size() << std::endl;
  std::cout << "a3.size() = " << a3.size() << std::endl;

  printSubtitle("Operators");
  /* Compile error
  for (unsigned int i = 0; i < a2.size(); i++) {
    a2[i] = i;
    std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
  }
  for (unsigned int i = 0; i < a3.size(); i++) {
    a3[i] = i * 2;
    std::cout << "a3[" << i << "] = " << a3[i] << std::endl;
  }
  */
  {
    const Array<int> a5 = a2;
    for (unsigned int i = 0; i < a5.size(); i++) {
      std::cout << "a5[" << i << "] = " << a5[i] << std::endl;
    }
  }

  /* Compile error
  printSubtitle("Copy");
  a1 = a2;
  for (unsigned int i = 0; i < a1.size(); i++) {
    std::cout << "a1[" << i << "] = " << a1[i] << std::endl;
  }
  */

  printSubtitle("Output");
  std::cout << "a1 = " << a1 << std::endl;
  std::cout << "a2 = " << a2 << std::endl;
  std::cout << "a3 = " << a3 << std::endl;
  std::cout << "a4 = " << a4 << std::endl;

  printSubtitle("Exceptions");
  try {
    std::cout << "a1[0]: " << a1[0] << std::endl;
    std::cout << "a1[1]: " << a1[1] << std::endl;
    std::cout << "a1[2]: " << a1[2] << std::endl;
    std::cout << "a1[3]: " << a1[3] << std::endl;
    std::cout << "a1[4]: " << a1[4] << std::endl;
    std::cout << "a1[5]: " << a1[5] << std::endl;
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  /* compile error
  try {
    std::cout << "a1[0] = 0;" << std::endl;
    a1[0] = 0;
    std::cout << "a1[1] = 1;" << std::endl;
    a1[1] = 1;
    std::cout << "a1[2] = 2;" << std::endl;
    a1[2] = 2;
    std::cout << "a1[3] = 3;" << std::endl;
    a1[3] = 3;
    std::cout << "a1[4] = 4;" << std::endl;
    a1[4] = 4;
    std::cout << "a1[5] = 5;" << std::endl;
    a1[5] = 5;
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
  */
}


// Test array with const char *
void testArrayConstCharPointer() {
  printTitle("Test array of const char *");

  printSubtitle("Constructors");
  const char * a[] = {"hello", "world", "42", "!", "welcome"} ;
  const char * b[] = {"HELLO", "WORLD", "42", "!", "WELCOME"} ;
  Array<const char *> a1;
  Array<const char *> a2(5);
  Array<const char *> a3(a2);
  Array<const char *> a4(0);

  printSubtitle("Accessors");
  std::cout << "a1.size() = " << a1.size() << std::endl;
  std::cout << "a2.size() = " << a2.size() << std::endl;
  std::cout << "a3.size() = " << a3.size() << std::endl;

  printSubtitle("Operators");
  for (unsigned int i = 0; i < a2.size(); i++) {
    a2[i] = a[i];
    std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
  }
  for (unsigned int i = 0; i < a3.size(); i++) {
    a3[i] = b[i];
    std::cout << "a3[" << i << "] = " << a3[i] << std::endl;
  }
  {
    const Array<const char *> a5 = a2;
    for (unsigned int i = 0; i < a5.size(); i++) {
      std::cout << "a5[" << i << "] = " << a5[i] << std::endl;
    }
  }

  printSubtitle("Copy");
  a1 = a2;
  for (unsigned int i = 0; i < a1.size(); i++) {
    std::cout << "a1[" << i << "] = " << a1[i] << std::endl;
  }

  printSubtitle("Output");
  std::cout << "a1 = " << a1 << std::endl;
  std::cout << "a2 = " << a2 << std::endl;
  std::cout << "a3 = " << a3 << std::endl;
  std::cout << "a4 = " << a4 << std::endl;

  printSubtitle("Exceptions");
  try {
    std::cout << "a1[0]: " << a1[0] << std::endl;
    std::cout << "a1[1]: " << a1[1] << std::endl;
    std::cout << "a1[2]: " << a1[2] << std::endl;
    std::cout << "a1[3]: " << a1[3] << std::endl;
    std::cout << "a1[4]: " << a1[4] << std::endl;
    std::cout << "a1[5]: " << a1[5] << std::endl;
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  try {
    std::cout << "a1[0] = \"hello\";" << std::endl;
    a1[0] = "hello";
    std::cout << "a1[1] = \"world\";" << std::endl;
    a1[1] = "world";
    std::cout << "a1[2] = \"HELLO\";" << std::endl;
    a1[2] = "HELLO";
    std::cout << "a1[3] = \"WORLD\";" << std::endl;
    a1[3] = "WORLD";
    std::cout << "a1[4] = \"42\";" << std::endl;
    a1[4] = "42";
    std::cout << "a1[5] = \"!\";" << std::endl;
    a1[5] = "!";
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

int main(void) {
  testArrayInt();
  testArrayString();
  testConstArrayInt();
  testArrayConstCharPointer();
  return 0;
}
