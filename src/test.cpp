#include <bits/stdc++.h>
using namespace std;

struct foo {
  double n;
  char c;
};

int main(void) {
  // diff between sizeof and allignof
  cout << "double : " << (size_t)sizeof(double) << " "
       << (size_t)alignof(double) << endl;
  cout << "char : " << (size_t)sizeof(char) << endl;
  cout << "size of foo : " << (size_t)sizeof(foo) << endl;
  cout << "align requirement : " << (size_t)alignof(foo) << endl;
  cout << 4 % 8 << endl;
  cout << alignof(std::max_align_t) << endl;
}
