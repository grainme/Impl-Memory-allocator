#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

class Shape {
public:
  Shape(int width, int height);
  virtual int get_area(); // virtual means that this is meant to be overriden
  virtual void print_name() = 0; // = 0 must be overriden to be called

protected: // same thing as private but reusable by derived classes
  int width_;
  int height_;
};

class Square : public Shape {
public:
  using Shape::Shape;
  int get_area() override;
  void print_name() override;
};

Shape::Shape(int width, int height) : height_(height), width_(width) {}

int Shape::get_area() { return height_ * width_; }

int Square::get_area() { return this->width_ * this->height_; }

void Square::print_name() { cout << "Hey I am a Square!" << endl; }

int32_t main(void) {
  Square a(5, 5);
  assert(a.get_area() == 25);
  a.print_name();
  return 0;
}
