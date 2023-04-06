#include "../include/core/List.hpp"

/**
 * ? Constructors
*/
template<typename GENERIC>
List<GENERIC>::List() {
    this->list = new GENERIC[10];
};

template<typename GENERIC>
List<GENERIC>::List(size_t size) {
    /**
     * ? If size is inferior to 2 set it to 2
    */
    if(size < 2)
        size = 2;
    this->list = new GENERIC[size];
};

/**
 * ? Destructor
*/
template<typename GENERIC>
List<GENERIC>::~List() {
    delete[] this->list;
};

template<typename GENERIC>
void List<GENERIC>::add(GENERIC element) {
    /**
     * ? If size is inferior to 2 set it to 2
    */
    if(size < 2)
        size = 2;

    this->list = new GENERIC[size];

    /**
     * If more elements in the array than the size of the array return error code
     * 1, 2, 126 – 165 and 255 have special meanings therefore we start from 1000
    */
    if(this->elements > this->size)
        exit(1000);

    /**
     * Array not full
    */
    if(this->elements < this->size)
        this->list[this->elements++] = *move;

    /**
     * Array full
    */
    if(this->elements == this->size) {
        size_t newSize = this->size * ceil(sqrt(this->size));

        // We create a new pointer array
        Move* _ = new Move[newSize];

        // We replace the values
        for(size_t x = 0; x < this->size; x++)
            _[x] = this->list[x];
        
        // We set the new size
        this->size = newSize;

        // We delete the old array
        delete[] this->list;

        // We replace the old array by the new array
        this->list = _;

        // We set the new value
        this->list[this->elements++] = *move;
    };
};