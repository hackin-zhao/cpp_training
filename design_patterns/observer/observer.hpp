#if !defined(_OBSERVER_HPP_)
#define _OBSERVER_HPP_

#include <iostream>
#include <string>
#include <functional>
#include <map>

class NonCopyable
{
protected:
    NonCopyable() = default;
    NonCopyable(const NonCopyable &) = delete;
    NonCopyable &operator=(const NonCopyable &) = delete;
    ~NonCopyable() = default;
};

template <typename Func>
class Events : public NonCopyable
{
private:
    template <typename F>
    int Assign(F &&f)
    {
        int k = observer_id_++;
        connections_.emplace(k, std::forward<F>(f));
        return k;
    }

public:
    Events() = default;
    ~Events() = default;

    int Connect(Func &&f)
    {
        return Assign(f);
    }

    int Connect(const Func &f)
    {
        return Assign(f);
    }

    void Disconnect(int key)
    {
        connections_.erase(key);
    }

    template <typename... Args>
    void Notify(Args &&...args)
    {
        for (auto &it : connections_)
        {
            it.second(std::forward<Args>(args)...);
        }
    }

private:
    int observer_id_ = 0;
    std::map<int, Func> connections_;
};

#endif // _OBSERVER_HPP_
