#include "MemorySpan.h"

#ifndef MSPTR_H
#define MSPTR_H

template <typename T>
class MsPtr {
private:
    MemorySpan<T>& span_; // Reference to the MemorySpan
    size_t index_;        // Index in the MemorySpan

public:
    // Constructor
    MsPtr(MemorySpan<T>& span, size_t index) : span_(span), index_(index) {
        if (index >= span.getSize() || span.getCounter(index) == 0) {
            throw std::out_of_range("Index out of range or element does not exist");
        }
    }

    

    // Overloading dereference operator
    T& operator*() const {
        return *(span_.getElement(index_));
    }

    // Overloading arrow operator
    T* operator->() const {
        return span_.getElement(index_);
    }

    // Overloading increment operator for pointer arithmetic
    MsPtr<T>& operator++() {
        if (index_ + 1 >= span_.getSize() || span_.getCounter(index_ + 1) == 0) {
            throw std::out_of_range("Incrementing out of bounds");
        }
        ++index_;
        return *this;
    }

    // Overloading decrement operator for pointer arithmetic
    MsPtr<T>& operator--() {
        if (index_ == 0) {
            throw std::out_of_range("Decrementing out of bounds");
        }
        --index_;
        return *this;
    }

    // Overloading addition operator for pointer arithmetic
    MsPtr<T> operator+(size_t offset) const {
        if (index_ + offset >= span_.getSize() || span_.getCounter(index_ + offset) == 0) {
            throw std::out_of_range("Adding offset out of bounds");
        }
        return MsPtr<T>(span_, index_ + offset);
    }

    // Overloading subtraction operator for pointer arithmetic
    MsPtr<T> operator-(size_t offset) const {
        if (index_ < offset) {
            throw std::out_of_range("Subtracting offset out of bounds");
        }
        return MsPtr<T>(span_, index_ - offset);
    }

    // Destructor
    ~MsPtr() {
        // No need to manage memory here, as MemorySpan handles it
    }
};
#endif