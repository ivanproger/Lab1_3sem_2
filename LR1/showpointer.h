
#ifndef SHOWPOINTER_H
#define SHOWPOINTER_H

#include <iostream>
#include "MemorySpan.h" 

template <typename T>
void showPointer(const MemorySpan<T>& span) {
    const size_t* counters = span.getCounters();
    T** elements = span.getElements();
    for (size_t i = 0; i < span.getSize(); ++i) {
        if (elements[i] != nullptr) {
            std::cout << "elem[" << i << "] = " << *elements[i] 
                << ", counter = " << counters[i] 
                << ", address = " << elements[i] << std::endl; 
        }
        else {
            std::cout << "elem[" << i << "] = nullptr, counter = " << counters[i] << std::endl;
        }
    }
}

#endif // SHOWPOINTER_H