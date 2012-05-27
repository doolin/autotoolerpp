/*
 * Compile for now with
 * g++ -o getsome main.cpp autotoolerpp.cpp  -I../include
 */

#include <iostream>
#include "autotoolerpp.h"

int
main(int argc, char ** argv) {

  std::cout << get_some() << std::endl;
  return 0;
}
