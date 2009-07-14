#include <iostream>

using namespace std;

class A {
public:
    A() { cout << "constructing A" << endl; }
    A(const A& a) { cout << "copying A, shouldn't see me" << endl; }
    virtual ~A() {}
    virtual void foo() { cout << "A speaks!" << endl; }
};

class B : public A {
public:
    B() { cout << "constructing B" << endl; }
    B(const B& b) : A(b) { cout << "copying B, shouldn't see me" << endl; }
    void foo() { cout << "B speaks!" << endl; }
};

class C : public B {
public:
    C() { cout << "constructing C" << endl; }
    C(const C& c) : B(c) { cout << "copying C, shouldn't see me" << endl; }
    void foo() { cout << "C speaks!" << endl; }
};

void foo(A &arg) {

    arg.foo();
    
    A &other = arg;
    other.foo();

}

int main(int argc, char* argv[]) {
    A* thing = new C();
    foo(*thing);
    delete thing;
}
