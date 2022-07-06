#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

class Base
{
  private:
  public:
    Base(/* args */) = default;
    ~Base() = default;

    virtual void print()
    {
        std::cout << "base" << std::endl;
    };

    int a;
};

class A : public Base
{
  private:
  public:
    A(/* args */) = default;
    ~A() = default;

    virtual void print()
    {
        std::cout << "A" << std::endl;
    };

    int a = 1;
};

class B : public Base
{
  private:
  public:
    B(/* args */) = default;
    ~B() = default;

    virtual void print()
    {
        std::cout << "B" << std::endl;
    };

    int b = 2;
};

class C : public Base
{
  private:
  public:
    C(/* args */) = default;
    ~C() = default;

    virtual void print()
    {
        std::cout << "C" << std::endl;
    };

    int c = 3;
};

int main(int argc, char const *argv[])
{
    using BasePtr = std::shared_ptr<Base>;
    std::vector<BasePtr> vec_bases;
    std::shared_ptr<A> a_ptr = std::make_shared<A>();
    std::shared_ptr<B> b_ptr = std::make_shared<B>();
    std::shared_ptr<C> c_ptr = std::make_shared<C>();

    vec_bases.push_back(a_ptr);
    vec_bases.push_back(b_ptr);
    vec_bases.push_back(c_ptr);

    for (size_t i = 0; i < vec_bases.size(); i++)
    {
        vec_bases[i]->print();
    }

    std::shared_ptr<A> aa_ptr = std::dynamic_pointer_cast<A>(vec_bases[0]);
    std::cout << aa_ptr->a << std::endl;

    std::shared_ptr<B> bb_ptr = std::dynamic_pointer_cast<B>(vec_bases[1]);
    std::cout << bb_ptr->b << std::endl;

    std::shared_ptr<C> cc_ptr = std::dynamic_pointer_cast<C>(vec_bases[2]);
    std::cout << cc_ptr->c << std::endl;

    return 0;
}

// hello world
