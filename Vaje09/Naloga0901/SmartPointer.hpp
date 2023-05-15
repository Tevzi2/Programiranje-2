#pragma once

template<typename T>
class SmartPointer
{
    public:
        template<typename... Args>
        explicit SmartPointer(Args... args)
        {
            raw = new T(args...);
        }

        ~SmartPointer()
        {
            delete raw;
        }

        T* operator->()
        {
            return raw;
        }

        T& operator*()
        {
            return *raw;
        }

    private:
        T* raw;
};