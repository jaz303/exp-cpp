#include <iostream>

using namespace std;

class A {
public:
    A() {}
    A(const A& a) { cout << "copy A" << endl; }
    virtual A* clone() { return new A(*this); }
};

class B : public A {
public:
    B() {}
    B(const B& b) : A(b) { cout << "copy B" << endl; }
    B* clone() { return new B(*this); }
};

void foo(A& ref) {
    cout << "enter foo, expecting both A & B's copy constructors to be called:" << endl;
    A* o1 = ref.clone();
    cout << "exit foo" << endl;
}

void bar(A& ref) {
    cout << "enter bar, expecting only A's copy constructor to be called" << endl;
    A other = ref;
    cout << "exit bar" << endl;
}

void baz(A val) {
    cout << "enter baz, expecting only A's copy constructor to be called" << endl;
    A other = val;
    cout << "exit baz" << endl;
}

int main() {

  B bleem;
  
  foo(bleem);
  cout << endl;
  
  bar(bleem);
  cout << endl;
  
  baz(bleem);
  
  return 0;
  
}