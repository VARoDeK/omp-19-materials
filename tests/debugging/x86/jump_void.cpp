#include <cstdlib>
#include <iostream>

#include <boost/context/fiber.hpp>

namespace ctx = boost::context;

ctx::fiber f1( ctx::fiber && f) {
    std::cout << "f1: entered first time" << std::endl;
    f = std::move( f).resume();
    std::cout << "f1: entered second time" << std::endl;
    return std::move( f);
}

int main() {
    ctx::fiber f{ f1 };
    f = std::move( f).resume();
    std::cout << "f1: returned first time" << std::endl;
    f = std::move( f).resume();
    std::cout << "f1: returned second time" << std::endl;
    std::cout << "main: done" << std::endl;
    return EXIT_SUCCESS;
}
