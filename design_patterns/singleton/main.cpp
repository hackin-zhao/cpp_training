#include "singleton.hpp"
#include <string>

struct A
{
    A(const std::string &) { std::cout << "lvalue" << std::endl; }
    A(const std::string &&x) { std::cout << "rvalue" << std::endl; }

    void fun() { std::cout << "fun" << std::endl; }
};

int main(int argc, char const *argv[])
{
    std::string test = "test";

    Singleton<A>::NewInstance(test);
    Singleton<A>::GetInstance()->fun();
    Singleton<A>::DeleteInstance();

    return 0;
}
