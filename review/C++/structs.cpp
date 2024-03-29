#include <cassert>
#include <cstdio>

static unsigned int nbr_animals = 0;

struct Animal {
  int age_;
  const char *name_;
  // constructor && desctructor
  Animal(const char *name, int age);
  ~Animal();
  // deactivate copy constructor (we often use this on kernel)
  // otherwise a copy constructor is made automatically
  Animal(const Animal &other) = delete;
  // methods
  void print_name();
};

Animal::Animal(const char *name, int age) : name_(name), age_(age) {
  nbr_animals++;
}

Animal::~Animal() { nbr_animals--; }

void Animal::print_name() {
  // definition
  fprintf(stdout, "%s\n", name_);
}

int main() {
  assert(nbr_animals == 0);
  Animal a("foo", 10);
  assert(nbr_animals == 1);
  if (true) {
    Animal b("bar", 18);
    assert(nbr_animals == 2);
    // desctructor will work here!
  }
  assert(nbr_animals == 1);
  Animal c(a);
  printf("%s\n", c.name_);
  return 0;
}
