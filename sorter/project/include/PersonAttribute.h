#pragma once
#include <iostream>
#include <exception>

enum class PersonAttribute
{
    Name,
    Surname,
    PhoneNumber
};

PersonAttribute createPersonAttribute(int code)
{
    switch(code)
    {
        case 1:
            return PersonAttribute::Name;
        case 2:
            return PersonAttribute::Surname;
        case 3:
            return PersonAttribute::PhoneNumber;
        default:
            throw std::runtime_error("No such attribute");
    }
}

