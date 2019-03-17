//
// Created by maciek on 16.03.19.
//

#ifndef SOLVER_OPTIONAL_HPP
#define SOLVER_OPTIONAL_HPP

#include <bits/unique_ptr.h>

template<class Type>
class Optional
{
public:
    Optional() = default;

    explicit Optional(const Type& anOptional);
    explicit operator bool();
    Type get() const;
    Optional& operator =(const Type&);
private:
    std::unique_ptr<Type> _optional;
};

template<class Type>
Optional<Type>::operator bool()
{
    return _optional != nullptr;
}

template<class Type>
Optional<Type>::Optional(const Type& anOptional)
{
    _optional = std::make_unique<Type>(anOptional);
}

template<class Type>
Optional<Type>& Optional<Type>::operator =(const Type& arg)
{
    _optional = std::make_unique<Type>(arg);
    return *this;
}

template<class Type>
Type Optional<Type>::get() const
{
    return *_optional;
}

#endif //SOLVER_OPTIONAL_HPP
