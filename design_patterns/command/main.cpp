#include "command.hpp"
#include <string>
#include <iostream>

struct STA
{
    int a;
    int operator()() { return a; }
    int operator()(int n) { return a + n; }
    int triple() { return a * 3; }
    int triple1(int n) const { return a * 3 + n; }
    const int triple2(int n) const { return a * 3 + n; }

    void triple3() { std::cout << "triple3" << std::endl; }
};

int add_one(int n)
{
    std::cout << "add_one" << std::endl;
    return n + 1;
}

void TestWrap()
{
    CommCommand<int> cmd;
    cmd.Warp(add_one, 0);
    cmd.Warp([](int n)
             {
                std::cout << "lambda" << std::endl;
                return n + 1; },
             1);

    STA t = {10};
    int x = 3;

    // CommCommand<STA> cmd1;
    // cmd1.Warp(&STA::triple, &t);
    // cmd1.execute();

    cmd.Warp(&STA::triple, &t);
    std::cout << cmd.execute() << std::endl;
}

int main(int argc, char const *argv[])
{
    TestWrap();

    return 0;
}
