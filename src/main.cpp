/*
 * Compile for now with
 * g++ -o getsome main.cpp autotoolerpp.cpp  -I../include
 */

#include <iostream>
#include "autotoolerpp.h"

/** Rename Unused Parameter */
#define _UP(x) unused_p__ ## x

/** Mark Unused Parameter */
#define UP(x) _UP(x) __attribute__((unused))

int
main(int __attribute__((unused))argc, char ** UP(argv)) {

  std::cout << get_some() << std::endl;
  return 0;
}
