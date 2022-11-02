#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>

#include "PersonAttribute.h"

class UserDialog
{
public:
    UserDialog(std::istream& in, std::ostream& out): userIn_(in),
                                                     userOut_(out)
    {
    }

    std::filesystem::path getFilePath()
    {
        std::filesystem::path filePath;
        userOut_ << "Еnter the sortable file path:\n";
        while(! std::filesystem::exists(filePath))
        {
            userIn_ >> filePath;
            if(!std::filesystem::exists(filePath))
                userOut_ << filePath.c_str() << ": No such file or directory. Try again.\n";
        }
        return filePath;
    }

    PersonAttribute getSortingAttribute()
    {
        userOut_ <<  "Enter the comprassion attribute (1-3):\n"
            <<  "1. Name\n"
            <<  "2. Surname\n"
            <<  "3. Phone number\n";

        int code = -1;
        while(code < 1 || 3 < code)
        {
            userIn_ >> code;
            if(code  < 1 || 3 < code)
                userOut_<<"No such atrribute. Try again.\n";
        }
        return createPersonAttribute(code);
    }

private:

    std::istream& userIn_;

    std::ostream& userOut_;
};


