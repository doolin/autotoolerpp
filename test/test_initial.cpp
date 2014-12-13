#include <string>

#include <cppunit/TestCase.h>
#include "./testutils.h"

#include <autotoolerpp.h>


using std::string;

class Initial {
public:
  Initial(void) : value(1) {}
  int value;
};



class InitialTest : public CppUnit::TestCase {

public:
  InitialTest( std::string name ) : CppUnit::TestCase( name ) {}


  void test_getsome() {

    Spec spec;
    spec.it("Testing getsome", DO_SPEC {
      return (string("some") == get_some());
    });
  }

  void runTest() {
    test_getsome();
  }
};

void
test_initial() {

  InitialTest * it = new InitialTest(std::string("initial test"));
  it->runTest();
  delete it;
}


int
main(int argc, char ** argv) {

  test_initial();
  return 0;
}
