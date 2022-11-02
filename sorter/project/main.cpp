#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <filesystem>
#include <fstream>

#include "Person.h"
#include "UserDialog.h"

void printSorted(PersonAttribute attribute, 
                        std::filesystem::path const& sortableFilePath, 
                            std::ostream& sortedStream)
{
    std::ifstream sortableStream(sortableFilePath.c_str());
    std::vector<Person> persons;
    Person p;
    while(sortableStream >> p)
        persons.emplace_back(p);

    Person::orderBy(persons, attribute);

    sortedStream << "\n";
    for(auto& p: persons)
    {
        p.print(sortedStream, attribute);
        sortedStream << "\n";
    }
    sortableStream.close();
}

int main(int argc, char** argv)
{
    try
    {
        UserDialog userDialog(std::cin, std::cout);
        
        auto sortableFilePath = userDialog.getFilePath(); 
        auto attribute = userDialog.getSortingAttribute();

        printSorted(attribute, sortableFilePath, std::cout);
    }
    catch(const std::exception& e)
    {
        std::cerr <<"Fatal error!\n" << e.what() << '\n';
    }

    return 0;
}
