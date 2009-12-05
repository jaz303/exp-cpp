#include <iostream>
#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/intrusive_ptr.hpp>

class Foo {
public:
    ~Foo() { std::cout << "byebye\n"; }
    void greet() { std::cout << "hello!\n"; }
};

void scoped_ptr() {
    // The primary reason to use scoped_ptr rather than auto_ptr is
    // to let readers of your code know that you intend "resource
    // acquisition is initialization" to be applied only for the
    // current scope, and have no intent to transfer ownership.
    // 
    // A secondary reason to use scoped_ptr is to prevent a later
    // maintenance programmer from adding a function that transfers
    // ownership by returning the auto_ptr, because the maintenance
    // programmer saw auto_ptr, and assumed ownership could safely
    // be transferred.
    
    std::cout << "\nscoped ptr\n";
    
    boost::scoped_ptr<Foo> a(new Foo());
    boost::scoped_ptr<Foo> b(new Foo());
    b.reset();
    
    boost::scoped_ptr<Foo> c;
    // c = a; - won't compile as assignment is private
    
    a->greet();
}

void scoped_array() {
    std::cout << "\nscoped array\n";
    
    boost::scoped_array<Foo> d(new Foo[10]);
}

void shared_ptr() {
    std::cout << "\nshared ptr\n";
    
    boost::shared_ptr<Foo> e(new Foo);
    boost::shared_ptr<Foo> f(e);
    
    if (e == f) {
        std::cout << "equal!\n";
    }
}

int main(int argc, char* argv[]) {
    scoped_ptr();
    scoped_array();
    shared_ptr();
    
    return 0;
}
