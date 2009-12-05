#include <memory>
#include <iostream>

class Foo {
public:
    ~Foo() { std::cout << "go bye bye\n"; }
    void greet() { std::cout << "hello!\n"; }
};

int main(int argc, char* argv[]) {
  
    std::auto_ptr<Foo> a(new Foo());
    std::auto_ptr<Foo> b;
    
    b = a;
    
    b->greet();
    
    std::cout << a.get() << "\n"; // NULL
    std::cout << b.get() << "\n"; // not null
  
    return 0;
}