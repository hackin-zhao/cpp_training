
#include <functional>
#include <iostream>

#include "observer.hpp"

struct A
{
    int a, b;

    void print(int a, int b) { std::cout << "A: " << a << ", " << b << std::endl; }
};

void print(int a, int b) { std::cout << "fun: " << a << ", " << b << std::endl; }

int main(int argc, char const *argv[])
{
    Events<std::function<void(int, int)>> myevents;

    auto key = myevents.Connect(print);

    A t;

    auto lambda_key = myevents.Connect([&t](int a, int b)
                                       {t.a = a; t.b = b; });

    auto f = std::bind(&A::print, &t, std::placeholders::_1, std::placeholders::_2);
    myevents.Connect(f);

    myevents.Notify(1, 2);

    myevents.Disconnect(key);
    myevents.Disconnect(lambda_key);

    return 0;
}
