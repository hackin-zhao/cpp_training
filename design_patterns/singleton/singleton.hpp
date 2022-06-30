#if !defined(_SINGLETON_HPP_)
#define _SINGLETON_HPP_

#include <iostream>

template <typename T>
class Singleton final
{
public:
    template <typename... Args>
    static T *NewInstance(Args &&...args)
    {
        if (instance_ == nullptr)
            instance_ = new T(std::forward<Args>(args)...);

        return instance_;
    }

    static T *GetInstance()
    {
        if (instance_ == nullptr)
        {
            throw std::logic_error("instance not init");
        }

        return instance_;
    }

    static void DeleteInstance()
    {
        delete instance_;
        instance_ = nullptr;
    }

private:
    Singleton(/* args */);
    ~Singleton();

private:
    static T *instance_;
};

template <class T>
T *Singleton<T>::instance_ = nullptr;

#endif // _SINGLETON_HPP_
