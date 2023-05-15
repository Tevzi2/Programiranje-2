#pragma once

#include <ReferenceCounter.hpp>

template<typename T>
class SmartPointer
{
public:
        SmartPointer() :raw(nullptr), ref_counter(nullptr) {}

        template<typename... Args>
        explicit SmartPointer(Args... args)
            :raw(new T(args...)), ref_counter(new ReferenceCounter())
        {
            (*ref_counter)++;
        }

        SmartPointer(SmartPointer& copy)
            :raw(copy.raw), ref_counter(copy.ref_counter)
        {
            (*ref_counter)++;
        }

        ~SmartPointer()
        {
            --(*ref_counter);

            if(!ref_counter->getCount())
            {
                delete raw;
                delete ref_counter;
            }
        }

        uint32_t useCount()
        {
            return ref_counter->getCount();
        }

        SmartPointer<T>& operator=(const SmartPointer<T>& other)
        {
            if(this == &other)
                return *this;

            if(ref_counter != nullptr && raw != other.raw)
            {
                --(*ref_counter);

                if(!ref_counter->getCount())
                {
                    delete raw;
                    delete ref_counter;
                }
            }

            ref_counter = other.ref_counter;
            raw = other.raw;
            (*ref_counter)++;

            return *this;
        }

        T* operator->()
        {
            return raw;
        }

        T& operator*()
        {
            return *raw;
        }

        template<typename F>
        bool operator==(SmartPointer<F>& othr)
        {
            return raw == othr.raw;
        }


        bool operator==(std::nullptr_t othr)
        {
            return (raw == nullptr);
        }

        template<typename F>
        bool operator!=(SmartPointer<F>& othr)
        {
            return raw != othr.raw;
        }

        bool operator!=(std::nullptr_t othr)
        {
            return (raw != nullptr);
        }

    private:
        ReferenceCounter* ref_counter = nullptr;
        T* raw = nullptr;
};