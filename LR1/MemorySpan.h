

#ifndef MEMORYSPAN_H
#define MEMORYSPAN_H

template <typename T>
class Pointer;

template <typename T>
class MemorySpan {
private:
    T** elem;
    size_t* counter;
    size_t Nexter;
    size_t size_;
    size_t* NextElem;

public:
    MemorySpan(size_t size) : Nexter(0), size_(size) {
        elem = new T * [size];
        counter = new size_t[size];
        NextElem = new size_t[size];

        for (size_t i = 0; i < size; ++i) {
            counter[i] = 0;
            elem[i] = nullptr;
            NextElem[i] = (i < size - 1) ? (i + 1) : size;
        }
    }

    ~MemorySpan() {
        for (size_t i = 0; i < size_; ++i) {
            delete elem[i];
        }
        delete[] elem;
        delete[] counter;
        delete[] NextElem;
    }

    Pointer<T> NewPointer(T* newObj);

    T* getElement(size_t index) const {
        if (index < size_ && elem[index] != nullptr) {
            return elem[index];
        }
        throw std::out_of_range("Index out of range or element does not exist");
    }

    void deletePointer(size_t index) {
        if (index >= size_ || elem[index] == nullptr) {
            return;
        }

        if (--counter[index] == 0) {
            delete elem[index];
            elem[index] = nullptr;
            NextElem[index] = Nexter;
            Nexter = index;
        }
    }

    size_t getSize() const {
        return size_;
    }

    size_t getCounter(size_t index) const {
        if (index < size_) {
            return counter[index];
        }
        return 0;
    }

    const size_t* getCounters() const {
        return counter;
    }

    T** getElements() const {
        return elem;
    }
};

template <typename T>
class Pointer {
private:
    MemorySpan<T>& span_;
    size_t index_;

public:
    Pointer(MemorySpan<T>& span, size_t index) : span_(span), index_(index) {
        if (index_ >= span.getSize() || span.getCounter(index_) == 0) {
            throw std::out_of_range("Index out of range or element does not exist");
        }
    }

    ~Pointer() {
        span_.deletePointer(index_);
    }

    T getValue() const {
        return *(span_.getElement(index_));
    }
};

template <typename T>
Pointer<T> MemorySpan<T>::NewPointer(T* newObj) {
    for (size_t i = 0; i < size_; ++i) {
        if (elem[i] != nullptr && *elem[i] == *newObj) {
            counter[i]++;
            return Pointer<T>(*this, i);
        }
    }

    if (Nexter < size_) {
        size_t index = Nexter;
        elem[index] = newObj;
        counter[index] = 1;
        Nexter = NextElem[Nexter];
        return Pointer<T>(*this, index);
    }

    throw std::runtime_error("No free space for a new element.");
}

#endif // MEMORYSPAN_H