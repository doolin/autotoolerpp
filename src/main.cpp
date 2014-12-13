/* Compile for now with
 * g++ -o getsome main.cpp autotoolerpp.cpp  -I../include
 */

#include <iostream>
#include "autotoolerpp.h"

// http://www.embedded-bits.co.uk/2009/gcc-compiler-warnings/
// https://github.com/ndim/freemcan/blob/f6348add31479b17ad7c7eec0acaf1f100843e84/include/compiler.h#L44

/** Rename Unused Parameter */
#define _UP(x) unused_p__ ## x

/** Mark Unused Parameter */
#define UP(x) _UP(x) __attribute__((unused))

int
main(int __attribute__((unused))argc, char ** UP(argv)) {

  std::cout << get_some() << std::endl;
  return 0;
}
