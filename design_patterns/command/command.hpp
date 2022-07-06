#if !defined(_COMMAND_HPP_)
#define _COMMAND_HPP_

#include <functional>
#include <type_traits>

template <typename R = void>
struct CommCommand
{
private:
    std::function<R()> f_;

public:
    template <class F, class... Args,
              class = typename std::enable_if<!std::is_member_function_pointer<F>::value>::type>
    void Warp(F &&f, Args &&...args)
    {
        f_ = [&]
        { return f(args...); };
    }

    template <class Re, class C, class... DArgs, class P, class... Args>
    void Warp(Re (C::*f)(DArgs...) const, P &&p, Args &&...args)
    {
        f_ = [&, f]
        { return (p->*f)(args...); };
    }

    template <class Re, class C, class... DArgs, class P, class... Args>
    void Warp(Re (C::*f)(DArgs...), P &&p, Args &&...args)
    {
        f_ = [&, f]
        { return (p->*f)(args...); };
    }

    R execute()
    {
        return f_();
    }
};

#endif // _COMMAND_HPP_
