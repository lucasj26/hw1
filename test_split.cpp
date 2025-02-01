/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{
     Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, new Node(6, new Node(7, new Node(8, nullptr))))))));
     Node* read = head;
     while (read!= nullptr){
        std::cout << read->value << " -> ";
        read = read->next;
     }
     std::cout << std::endl;

     Node* evens = nullptr;
     Node* odds = nullptr;

     split(head, evens, odds);


     Node* read2 = evens;
     while (read2!= nullptr){
        std::cout << read2->value << " -> ";
        read2 = read2->next;
     }
     std::cout << std::endl;

     Node* read3 = odds;
     while (read3!= nullptr){
        std::cout << read3->value << " -> ";
        read3 = read3->next;
     }
     std::cout << std::endl;

}
