#ifndef HEADER_H
#define HEADER_H

#include <string>

void generateHeader(const std::string &programName)
{
    int headerLength = programName.length() + 8;
    std::cout << std::endl;
    std::cout << std::string(headerLength, '*') << std::endl;
    std::cout << "**  " << programName << "  **" << std::endl;
    std::cout << std::string(headerLength, '*') << std::endl
              << std::endl;
}

#endif
