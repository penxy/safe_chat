#ifndef __SINGLE_MODEL_H
#define __SINGLE_MODEL_H

#include <type_traits>
/**
 * @brief single model
*/
template<typename T>
class Singleton{
public:
    static T& get_inst() noexcept(std::is_nothrow_constructible<T>::value){
        static T instance;
        return instance;
    }
    virtual ~Singleton() = default;
    Singleton(const Singleton&)=delete;
    Singleton& operator =(const Singleton&)=delete;
protected:
    Singleton() = default;
};
/*

class node : public Singleton<node> {
    friend class Singleton<node>;
public:
    node (const node&) = delete;
    node& operator = (const node&) = delete;
protected:
    node() = default;
};
*/


#endif