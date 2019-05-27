//
// Created by maciek on 02.04.19.
//

#include <Definitions_and_Helpers/Definitions.hpp>

std::ostream& operator <<(std::ostream& strm, MethodType methodType)
{
    if (methodType == MethodType::MethodType_Unknown)
    {
        strm << "Unknown";
    }
    else if (methodType == MethodType::MethodType_PolakRibiere)
    {
        strm << "PolakRibiere";
    }
    return strm;
}
