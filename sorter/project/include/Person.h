#pragma once
#include <iostream>
#include <ranges>
#include "PersonAttribute.h"

class Person
{
public:
    Person()  { }

    void print(std::ostream& out, PersonAttribute attribute) // При увеличении числа аттрибутов можно использовать std::tuple
    {                                                        // и std::index_seqence       
        switch(attribute)
        {
            case PersonAttribute::Name:
                out << name_ << ": " << surname_ << " " << phoneNumber_;
                break;
            case PersonAttribute::Surname:
                out << surname_ << ": " << name_ << " " << phoneNumber_;
                break;
            case PersonAttribute::PhoneNumber:
                out << phoneNumber_ << ": " << surname_ << " " << name_;
                break;
        }
    }

    static void orderBy(std::vector<Person>& persons, PersonAttribute attribute)
    {        
        switch(attribute)
        {
            case PersonAttribute::Name:
                std::ranges::sort(persons, {}, &Person::name_);
                break;

             case PersonAttribute::Surname:
                std::ranges::sort(persons, {}, &Person::surname_);
                break;
                
             case PersonAttribute::PhoneNumber:
                std::ranges::sort(persons, {}, &Person::phoneNumber_);
                break;
        } 
    }
    
    friend std::istream& operator >> (std::istream& in, Person& p);

private:

    std::string name_;

    std::string surname_;

    uint32_t phoneNumber_;
};


std::istream& operator >> (std::istream& in, Person& p)
{
    in >> p.surname_  >> p.name_  >> p.phoneNumber_;
    p.name_.pop_back(); // Удаляем ':'
    return in;
}