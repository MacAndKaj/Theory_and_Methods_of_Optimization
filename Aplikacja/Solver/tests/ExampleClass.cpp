//
// Created by maciek on 06.03.19.
//

#include "ExampleClass.hpp"


ExampleClass::ExampleClass()
{
}

ExampleClass::~ExampleClass()
{
}

unsigned int ExampleClass::getFive(bool failTest) const
{
    return failTest ? 0 : 5;
}

