//
//  ArrayInt.h
//  Lab1CS260
//
//  Created by Peter ODonnell on 6/27/19.
//  Copyright © 2019 Peter ODonnell. All rights reserved.
//

#ifndef ArrayInt_h
#define ArrayInt_h

#include <stdexcept>

const int DEFAULT = 10;

class ArrayInt{
private:
    int* arr;
    int size = 10;
    int counter = 0;
    bool isFull = false;
public:
    ArrayInt();
    ArrayInt(int n);
    int getAt(int index);
    void setAt(int index, int value);
    int getSize();
    void resize();
    void setSize(int size);
    void append(int value);
    void insertAt(int index, int value);
    int removeAt(int index);

};

ArrayInt::ArrayInt(){
    size = DEFAULT;
    arr = new int[size];
}
ArrayInt::ArrayInt(int n){
    size = n;
    arr = new int[size];
}

int ArrayInt::getAt(int index){
    if(index < 0 || index > size-1)
        throw std::out_of_range("Out of range");

    return arr[index];
}

void ArrayInt::setAt(int index, int value){
    if(index < 0 || index > size)
        throw std::out_of_range("Out of range");

    arr[index] = value;
}

int ArrayInt::getSize(){return size;}

//copy contents of old into new
//Note: resize is for append when the array is full, double the size
void ArrayInt::resize(){
    int* newArr = new int[size * 2];
    size *= 2;
    arr = newArr;
    delete[] newArr;

}

//if newer size is greater, resize, update size
//Note: setSize is for whatever size is required
void ArrayInt::setSize(int size){
    if(size > this->size) {
       int* tmp = new int[size];
       arr = tmp;
       delete[] tmp;
    }
}

/*
Add value at next available index
If array is full, resize to size * 2 and copy values.

Next location is:
 -0 if no items added
 -the next location if only appends have been done
 -if setAt() is called, one larger than the largest index used for setAt()
 */

void ArrayInt::append(int value){
    if(isFull)
        resize();
}
//void ArrayInt::insertAt(int index, int value){}
//int ArrayInt::removeAt(int index{}

#endif /* ArrayInt_h */
