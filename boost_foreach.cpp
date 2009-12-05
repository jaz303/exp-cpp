#include <string>
#include <iostream>
#include <boost/foreach.hpp>

#define foreach         BOOST_FOREACH
#define reverse_foreach BOOST_REVERSE_FOREACH

int main(int argc, char* argv[]) {
    
    // how the hell does this work?
    int a[3] = {1,2,3};
    foreach(int i, a) {
        std::cout << i << "\n";
    }
    
    std::string my_str = "abc";
    foreach(char c, my_str) {
        std::cout << c << "\n";
    }
    
    return 0;
}