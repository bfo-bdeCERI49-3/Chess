#pragma once

#include <stddef.h>
#include <math.h>

template<typename GENERIC>
class List {
    private:
        GENERIC list { nullptr }; // Actual list of pointers
        size_t size { 0 };        // Size of array
        size_t elements { 0 };    // Elements in array

    public:

        /**
         * ? Constructors
        */
        List(size_t);
        List();

        /**
         * ? Destructor
        */
        ~List();

        /**
         * ? Adds an element to the list
         * @return void
        */
        void add(GENERIC);

        /**
         * ? Returns the size of the array
         * @return size_t
        */
        inline size_t getSize() { return this->size; };

        /**
         * ? Returns the elements in the array
         * @return size_t
        */
        inline size_t getElements() { return this->elements; };
};