// #include <iostream>

class Base
{
  public:
    Base() = default;
    ~Base() = default;

    void Func()
    {
    }

    virtual void test(){};

    int a;
    int b;
    int c;
};

class Base1
{
  private:
    /* data */
  public:
    Base1(/* args */) = default;
    ~Base1() = default;

    virtual void test2(){};
};

class Test : public Base, public Base1
{
  private:
    int a;
    int b;
    int c;

  public:
    Test(/* args */) = default;
    ~Test() = default;

    // virtual void test(){};
    // virtual void test3(){};
};

int main()
{
    Test a;
    return 0;
}

// 使用clang -Xclang -fdump-record-layouts -stdlib=libc++ -c model.cc查看
// g++ -fdump-lang-class model.cc后查看生成的文件
