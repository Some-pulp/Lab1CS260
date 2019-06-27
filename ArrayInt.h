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
public:
    ArrayInt();
    ArrayInt(int n);
    int getAt(int index);
    void setAt(int index, int value);
    int getSize();
    void resize(int newSize);
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
    if(index < 0 || index > size - 1)
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
void ArrayInt::resize(int newSize){

}

/*
void ArrayInt::setSize(int size){
    if(size > this->size) {
        resize(size);
        this->size = size;
    }

}
 */

//void ArrayInt::append(int value){}
//void ArrayInt::insertAt(int index, int value){}
//int ArrayInt::removeAt(int index{}

#endif /* ArrayInt_h */
