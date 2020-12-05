#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm> // std::copy
#include <iomanip>
#include <iostream>
using namespace std;


template <class Type>
class Shapes_Vector
{
    /*!
    vector of doubles much like stl vector container

    NOTE: elem[n] is vector component n for all n >= 0 AND n < size_v
          size_v = the number of items stored in the vector
          space = the available storage capacity of the vector where size_v <= space
          if size_v < space there is space for (space - size_v) doubles after elem[size_v-1]
    */

    int size_v;   //! the current size of vector
    Type *elem;   //! pointer to the elements (or 0)
    int space;    //! number of elements plus number of free slots
public:
    Shapes_Vector() : size_v{0}, elem{nullptr}, space{0} {} //! default constructor

    //! alternate constructor
    /*!
     * \param s creates a vector of size s to use for shapes
     */

    explicit Shapes_Vector(int s) : size_v{s}, elem{new Type[s]}, space{s}
    {
        for (int i = 0; i < size_v; ++i)
            elem[i] = 0; //! elements are initialized
    }

    //! copy constructor
    /*!
     * \param src is the object of Shape_Vector that is getting its data copied
     */
    Shapes_Vector(const Shapes_Vector &src) : size_v{src.size_v}, elem{new Type[src.size_v]}, space{src.space}
    {
        copy(src.elem, src.elem + size_v, elem); //! copy elements - std::copy() algorithm
    }

    //! copy assignment
    /*!
     * \param src is the object of Shape_Vector that is getting its data copied
     * \return a self-reference to the Shape_Vector function call
     */
    Shapes_Vector &operator=(const Shapes_Vector &src)
    {
        Type *p = new Type[src.size_v];       //! allocate new space
        copy(src.elem, src.elem + src.size_v, p); //! copy elements - std::copy() algorithm
        delete[] elem;                            //! deallocate old space
        elem = p;                                 //! now we can reset elem
        size_v = src.size_v;
        return *this;
    }

    //! destructor
    /*!
      deletes the data that gets stored in elem
     */
    ~Shapes_Vector() {
        delete[] elem;
    }

    //! access operator
    /*!
     * \brief operator [] you can change the data inside of the vector
     * \param n is the element that you want to have return from the vector
     * \return returns reference to the nth element of vector
     */
    Type &operator[](int n) {
        return elem[n];
    }

    //! const access operator
    /*!
     * \brief operator [] Can not change data that gets returned from the member funct.
     * \param n is the element that you want to have return from the vector
     * \return returns a const reference to the nth element of vector
     */
    const Type &operator[](int n) const {
        return elem[n];
    }

    //! Getter function to get the current size of the vector (size_v)
    int size() const {
        return size_v;
    }

    //! Getter function to get the max size of the vector (space)
    int capacity() const {
        return space;
    }

    //!  make the vector have newsize number of elements
    //!  initialize each new element with the default value 0.0
    void resize(int newsize)
    {
        reserve(newsize);
        for (int i = size_v; i < newsize; ++i)
        {
            elem[i] = 0; //! initialize new elements
        }
        size_v = newsize;
    }

    //! increase vector size by one; initialize the new element with d
    void push_back(Type d)
    {
        cout << "Hi";
        if (space == 0)
            reserve(8);         //! start with space for 8 elements
        else if (size_v == space)
            reserve(2 * space); //! get more space
        elem[size_v] = d;       //! add d at end
        ++size_v;               //! increase the size (size_v is the number of elements)
    }

    //! allocattes an amount of new newalloc space in the vector class
    void reserve(int newalloc)
    {
        if (newalloc<=space)
            return; //! never decrease allocation
        Type* p = new Type[newalloc]; //! allocate new space
        for (int i=0; i<size_v; ++i)
            p[i]=elem[i]; //! copy old elements
        delete[ ] elem; //! deallocate old space
        elem = p;
        space = newalloc;
    }

    using iterator = Type *;
    using const_iterator = const Type *;

    //! begin is an iterator that points to the beginning of the container
    iterator begin()
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }
    /*! const begin is an iterator that points to the beginning of the container
        and the data cant be changed */
    const_iterator begin() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    //! end is an iterator that points to one beyond the last element
    iterator end()
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    /*! const end is an iterator that points to one beyond the last element
        of the container and the data cant be changed */
    const_iterator end() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }
    //! insert a new element val before p
    /*!
     * \param p is the spot where you want to add the new element to the vector
     * \param val is the value of Type that you wish to add to the shape class
     * \return the iterator pointer back to the calling function
     */
    iterator insert(iterator p, const Type &val)
    {
        //!make sure we have space
        if (size_v + 1 > space)
        {
            return p;
        }

        //!variables used to cycle and shift the loop correctly
        Type shiftedElement;
        Type originalElement;
        int difference;

        //!initialization
        difference = &elem[space - 1] - p;
        originalElement = *p;

        //! the place to put value
        for (int i = 0; i < difference; i++)
        {
            shiftedElement = *(p + 1); //! creates a variable for whats inside p + 1
            p = p + 1; //!incrementing p
            *p = originalElement; //! know that p = p + 1 when you set *p = originalElement you are shifting the contents of the array to the right one
            originalElement = shiftedElement;
        }

        for(int unShift = 0; unShift < difference; unShift++)
        {
            p = (p - 1);//!returns the iterator to its starting point
        }

        *p = val;//!inserts the element at the position p which was passed to the function

        size_v++;//!add 1 to size for the data you added to the list.

     return p;
    }

    //! remove element pointed to by p
    /*!
     * \brief erase deletes the data stored inside the element p
     * \param p deletes the data stored in this parameter
     * \return iterator back to the calling function
     */
    iterator erase(iterator p)
    {
        if (p == end())
            return p;
        for (iterator pos = p + 1; pos != end(); ++pos)
            *(pos - 1) = *pos; //! copy element one position to the left of p
        //delete (end() - 1);
        --size_v;
        return p;
    }

    //! setter that can change any index to type stuff
    void set(int index, const Type& stuff)
    {
        if(index < space)
            elem[index] = stuff;
    }
};

#endif //VECTOR_H


