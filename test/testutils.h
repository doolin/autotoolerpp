//#define PATENT_TESTUTILS_H
//#ifndef PATENT_TESTUTILS_H

#include <algorithm>
#include <functional>
#include <string>

#include <cppunit/TestCase.h>

#include "colortest.h"

#define DESCCOLOR COLOR45
#define PASSCOLOR COLOR119
#define FAILCOLOR COLOR124
#define PENDINGCOLOR COLOR166

#define INDENT0 ""
#define INDENT2 "  "
#define INDENT4 "     "
#define INDENT6 "       "


typedef const std::string Description;
typedef void (*Describer)(const char *, const char *);

void describe_test(const char * indent, const std::string & description);
void describe_pass(const char * indent, const char * description);
void describe_fail(const char * indent, const char * description);
void describe_pending(const char * indent, const char * description);

//#define DO_SPEC [](Description d)->bool
#define DO_SPEC []()->bool
#define DO_SPEC_THIS [this](Description d)->bool
#define DO_SPEC_HANDLE [&](Description d)->bool

class Spec {

public:

  //void it (Description desc, std::function<bool(Description)> test) {
  void it (Description desc, std::function<bool()> test) {

    Describer d;
    try {
      //CPPUNIT_ASSERT(test(desc));
      CPPUNIT_ASSERT(test());
      d = describe_pass;
    } catch (CppUnit::Exception e) {
      d = describe_fail;
    }
    d(INDENT2, desc.c_str());
  }

  //void xit (Description desc, std::function<bool(Description)> test) {
  /* Avoid unused parameter warning, don't care about legal c syntax, obviously. */
  void xit (Description desc, std::function<bool()> /* test */) {
    describe_pending(INDENT4, desc.c_str());
  }

};

class TestUtils {
};

//#endif // PATENT_TESTUTILS_H
