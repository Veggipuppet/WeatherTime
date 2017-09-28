#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;
/**
	 * @class Vector
	 * @brief  Creates a dynamic array to store any kind of data.
	 *
	 *
	 * @author Liam Goerke
	 * @version 01
	 * @date 3/06/2017 Liam Goerke
	 */

template <class T>
class Vector
{
	    public:

                /**
                * @brief  Getter function for length
                *
                * gets the variable length, returning the number of slots filled within the vector
                *
                * @return length
                */
            int listSize() const;


                /**
                * @brief  Getter function for maxSize
                *
                * gets the variable maxSize, returning the current total size of the vector
                *
                * @return maxSize
                */
            int maxListSize() const;

                /**
                * @brief  Getter function for List
                *
                * Returns what is within list at location
                *
                * @return List[location]
                */
            const T& retrieveAt(int location) const;

                /**
                * @brief  Setter function for List
                *
                * sets List[length] to element, incrementing length afterwards, calls resizeVector if vector is full
                *
                * @return void
                */
            void insertEnd(const T& element);

                /**
                * @brief  Resizes the vector
                *
                * Creates a temporary vector twice the size of the previous vector and fills it with List
                *   then deletes the old vector, changes the pointer of List to the temporary vector and makes
                *   the temporary pointer equal to null.
                *
                * @return void
                */
            void resizeVector();

                /**
                * @brief  Constructor
                *
                * Sets initial vector size to 100 and allocates memory for List
                *
                * @param initial size of vector, int
                * @return
                */
            Vector(int Size = 1000);

                /**
                * @brief  Destructor
                *
                * When Vector goes out of scopes deletes memory allocated for it
                *
                * @return
                */
            ~Vector();

                /**
                * @brief  Copy Constructor
                *
                * copies one vector into another vector
                *
                * @param address of another vector
                * @return
                */
            Vector(const Vector& otherVector);

            // overload assignment operator

    protected:

    private:
            ///array to hold the list elements
        T *List;
            ///variable to store the current length of the list
        int length;
            ///variable to store the maximum size of the list
        int maxSize;

};



template <class T>
Vector<T>::Vector(int Size)
{
    if(Size <= 0)
    {
        maxSize = 100;
    }
    else
        maxSize = Size;

    length = 0;

    List = new T[maxSize];
}

template <class T>
Vector<T>::~Vector()
{
    delete [] List;
}

template <class T>
int Vector<T>::listSize() const
{
    return length;
}

template <class T>
int Vector<T>::maxListSize() const
{
    return maxSize;
}

template <class T>
const T& Vector<T>::retrieveAt(int location) const
{
    if (location < 0 || location >= length)
        cout << "The location of the item to be retrieved is out of range" << endl;
    return List[location];
}

template <class T>
void Vector<T>::insertEnd(const T& element)
{
    if(length >= maxSize )
    {
        resizeVector();
    }

    List[length] = element; //insert element into vector
    length++; //increment list length

}

template <class T>
void Vector<T>::resizeVector()
{
    maxSize*=2;
    T* temp = new T[maxSize];

    for(int i=0; i < (maxSize/2) ; i++)
    {
        temp[i] = List[i];
    }

    delete []List;
    List = temp;
    temp = NULL;

}

template <class T>
Vector<T>::Vector(const Vector& otherVector)
{
    maxSize = otherVector.maxListSize;
    length = otherVector.listSize;

    List = new T[maxSize];

    for(int i=0; i<length; i++)
    {
        List[i] = otherVector.List[i];
    }
}

// class implementation follows with normal comments
// you fill in the rest

#endif // VECTOR_H
