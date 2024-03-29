#include <cassert>
#include <cstdio>

using namespace std;

// Classes and Methods
struct Animal {
  const char *name_;
  void print_name();
};

void Animal::print_name() {
  // definition
  printf("%s\n", name_);
}

// Overloading (function and operators as well)
struct point {
  int x;
  int y;
};

point operator+(point a, point b) {
  a.x += b.x;
  a.y += b.y;
  return a;
}

int main(void) {
  Animal a;
  a.name_ = "foo";
  a.print_name();

  // References
  int x = 1;
  int *x_ptr = &x;
  *x_ptr = 2;
  assert(*x_ptr == 2);

  int &x_ref = x;
  assert(x_ref = 2);

  x = 4;
  assert(*x_ptr == 4 && x_ref == 4);

  // a reference can only be initialized once, there is no way to change where a
  // reference points!

  // testing Overloading
  point pt_1;
  pt_1.x = 1;
  pt_1.y = 2;
  point pt_2;
  pt_2.x = 1;
  pt_2.y = 2;
  point c = pt_1 + pt_2;
  printf("x = %d and y = %d\n", c.x, c.y);

  // Name Mangling
  // When a C compiler compiles a function f, it creates an object file
  // containing the name f. But in C++, the object file uses a mangled name for
  // the function that also encodes of the function’s argument types. This
  // disambiguates overloaded functions with the same name.
  // The c++filt program can demangle a name to its source representation.
  // to 'avoid' name mangling : extern "C" { int f(); }
}
