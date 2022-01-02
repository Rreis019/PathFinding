#pragma once
template <typename T>
class CSingleton
{
public:
    static T& Get()
    {
        static T instance;
        return instance;
    }
protected:
    CSingleton() {}
    ~CSingleton() {}
public:
    CSingleton(const &MySingleton  ) = delete;
    CSingleton& operator=(const &CSingleton ) = delete;
};