#include <cstring> // for strcpy
#include <iostream>
using namespace std;

class Animal {
public:
  static int count_animals_;
  Animal(int age, const char *name);
  void set_name(const char *name);
  void print_name();
  Animal(const Animal &other);

private:
  char *name_;
  int age_;
};

int Animal::count_animals_ = 0;

Animal::Animal(int age, const char *name) : age_(age) {
  name_ = new char[strlen(name) + 1];
  strcpy(name_, name);
  count_animals_++;
}

Animal::Animal(const Animal &other) {
  this->age_ = other.age_;
  this->name_ = other.name_;
  count_animals_++;
}

void Animal::set_name(const char *name) {
  delete[] name_;
  name_ = new char[strlen(name) + 1];
  strcpy(name_, name);
}

void Animal::print_name() { std::cout << "Name: " << name_ << std::endl; }

int32_t main() {
  Animal a(44, "Hello Kitty");
  a.set_name("Surfing Hello Kitty");
  a.print_name(); // Output: Name: Surfing Hello Kitty
  cout << a.count_animals_ << endl;
  Animal b(a);
  cout << b.count_animals_ << endl;
  return 0;
}
