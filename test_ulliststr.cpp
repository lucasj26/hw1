#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr list;
    std::cout << "List initialized" << std::endl;
    std::cout << list.size() << std::endl;


    list.pop_back();
    list.push_front("AX");
    list.push_back("Z8");
    std::cout << "size after initial push: " << list.size() << std::endl;
    std::cout << "front: " << list.front() << std::endl;
    std::cout << "back: " << list.back() << std::endl;

    list.push_back("A");
    list.push_back("A");
    list.push_back("A");
    list.push_back("A");
    list.push_back("A");
    list.push_back("A");
    list.push_back("A");
    list.push_back("A");


    std::cout << "size after push: " << list.size() << std::endl;
    std::cout << "front: " << list.front() << std::endl;
    std::cout << "back: " << list.back() << std::endl;
    


    list.clear();
    std::cout << "Size after clear: " << list.size() << std::endl;  
}
