#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm> // std::copy
#include <iomanip>
#include <iostream>
using namespace std;


template <class Type>
class Shapes_Vector
{
    /*
    vector of doubles much like stl vector container

    NOTE: elem[n] is vector component n for all n >= 0 AND n < size_v
          size_v = the number of items stored in the vector
          space = the available storage capacity of the vector where size_v <= space
          if size_v < space there is space for (space - size_v) doubles after elem[size_v-1]
    */

    int size_v;   // the size
    Type *elem; // pointer to the elements (or 0)
    int space;    // number of elements plus number of free slots
public:
    Shapes_Vector() : size_v{0}, elem{nullptr}, space{0} {} // default constructor

    explicit Shapes_Vector(int s) : size_v{s}, elem{new Type[s]}, space{s} // alternate constructor
    {
        for (int i = 0; i < size_v; ++i)
            elem[i] = 0; // elements are initialized
    }

    Shapes_Vector(const Shapes_Vector &src) : size_v{src.size_v}, elem{new Type[src.size_v]}, space{src.space} // copy constructor
    {
        copy(src.elem, src.elem + size_v, elem); // copy elements - std::copy() algorithm
    }

    Shapes_Vector &operator=(const Shapes_Vector &src) // copy assignment
    {
        Type *p = new Type[src.size_v];       // allocate new space
        copy(src.elem, src.elem + src.size_v, p); // copy elements - std::copy() algorithm
        delete[] elem;                            // deallocate old space
        elem = p;                                 // now we can reset elem
        size_v = src.size_v;
        return *this;  // return a self-reference
    }

    ~Shapes_Vector() {
        delete[] elem; // destructor
    }

    Type &operator[](int n) {
        return elem[n]; // access: return reference
    }

    const Type &operator[](int n) const {
        return elem[n];
    }

    int size() const {
        return size_v;
    }

    int capacity() const {
        return space;
    }

    void resize(int newsize) // growth
    // make the vector have newsize elements
    // initialize each new element with the default value 0.0
    {
        reserve(newsize);
        for (int i = size_v; i < newsize; ++i)
        {
            elem[i] = 0; // initialize new elements
        }
        size_v = newsize;
    }

    void push_back(Type d)
    // increase vector size by one; initialize the new element with d
    {
        if (space == 0)
            reserve(8);         // start with space for 8 elements
        else if (size_v == space)
            reserve(2 * space); // get more space
        elem[size_v] = d;       // add d at end
        ++size_v;               // increase the size (size_v is the number of elements)
    }

    void reserve(int newalloc)
    {
        if (newalloc<=space)
            return; // never decrease allocation
        double* p = new double[newalloc]; // allocate new space
        for (int i=0; i<size_v; ++i)
            p[i]=elem[i]; // copy old elements
        delete[ ] elem; // deallocate old space
        elem = p;
        space = newalloc;
    }

    using iterator = Type *;
    using const_iterator = const Type *;

    iterator begin() // points to first element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    const_iterator begin() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    iterator end() // points to one beyond the last element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    const_iterator end() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    iterator insert(iterator p, const double &val) // insert a new element val before p
    {
        //make sure we have space
        if (size_v + 1 > space)
        {
            return p;
        }

        //variables used to cycle and shift the loop correctly
        Type shiftedElement;
        Type originalElement;
        int difference;

        //initialization
        difference = &elem[space - 1] - p;
        originalElement = *p;

        //Help for this https://codereview.stackexchange.com/questions/154008/custom-stl-vector-in-c
        // the place to put value
        for (int i = 0; i < difference; i++)
        {
            shiftedElement = *(p + 1); // creates a variable for whats inside p + 1
            p = p + 1; //incrementing p
            *p = originalElement; // know the p = p + 1 when you set *p = originalElement you are shifting the contents of the array to the right one
            originalElement = shiftedElement;
        }

        for(int unShift = 0; unShift < difference; unShift++)
        {
            p = (p - 1);//returns the iterator to its starting point
        }

        *p = val;//inserts the element at the position p which was passed to the function

        size_v++;//add 1 to size for the data you added to the list.

     return p;
    }

    iterator erase(iterator p) // remove element pointed to by p
    {
        if (p == end())
            return p;
        for (iterator pos = p + 1; pos != end(); ++pos)
            *(pos - 1) = *pos; // copy element one position to the left
        delete (end() - 1);
        --size_v;
        return p;
    }


    void set(int index, const Type& stuff)
    {
        if(index < space)
            elem[index] = stuff;
    }
};

#endif //VECTOR_H


