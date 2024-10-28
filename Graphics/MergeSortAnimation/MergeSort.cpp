//
// Created by jacki on 5/2/2024.
//

#include "MergeSort.h"

void MergeSort::merge(sf::RectangleShape *rects, int sizeL, int sizeR, sf::RenderWindow &window)
{
    auto *tempArr = new sf::RectangleShape[sizeL + sizeR];
    int copiedToTemp = 0, copiedFirstHalf = 0, copiedSecondHalf = 0;
    while(copiedFirstHalf < sizeL && copiedSecondHalf < sizeR)//while we haven't copied everything from the arrays
    {
        if(rects[copiedFirstHalf].getSize().y < (rects + sizeL)[copiedFirstHalf].getSize().y)
            tempArr[copiedToTemp++].setSize(rects[copiedFirstHalf++].getSize());
        else
            tempArr[copiedToTemp++].setSize((rects + sizeL)[copiedSecondHalf++].getSize());
//        if (rects[copiedFirstHalf] < (rects + sizeL)[copiedSecondHalf])
//            tempArr[copiedToTemp++] = rects[copiedFirstHalf++];
//        else
//            tempArr[copiedToTemp++] = (rects + sizeL)[copiedSecondHalf++];

    }
    while (copiedFirstHalf < sizeL)
        tempArr[copiedToTemp++].setSize(rects[copiedFirstHalf++].getSize());
//        tempArr[copiedToTemp++] = rects[copiedFirstHalf++];

    while (copiedSecondHalf < sizeR)
        tempArr[copiedToTemp++].setSize((rects + sizeL)[copiedSecondHalf++].getSize());
//        tempArr[copiedToTemp++] = (rects + sizeL)[copiedSecondHalf++];

    for (int i = 0; i < (sizeL + sizeR); i++)
        rects[i] = tempArr[i];
    delete[] tempArr;
//Merge Function
//merge(data[], n1, n2)
//int *temp; //holds the sorted array
//copied = 0 //keep track of how many elements were copied to temp
//copied1 = 0 //keep track of how many elements were copied from the first half
//copied2 = 0 // keep track of how many elements were copied from second half
//dynamically create array of size n1 + n2

//if data[copied1] < data[copied2]
//temp[copied++] = data[copied1++]
//put the remaining values in the temp
//while(copied1 < n2)
//do stuff
//while(copied2 < n2)
//do stuff
//copy everything from temp back to data
//delete temp
}

void MergeSort::mergeSort(sf::RectangleShape *rects, int size, sf::RenderWindow &window)
{
    int sizeL, sizeR;
    if(size > 1)
    {
        sizeL = size / 2;
        sizeR = size - sizeL;
        mergeSort(rects, sizeL, window);
        mergeSort(rects + sizeL, sizeR, window);
        merge(rects, sizeL, sizeR, window);
    }
//Merge Sort function
//mergeSort(data[], n)
//n1: left side size
//n2: right side size
//if(n > 1)
//n1 = n/2;
//n2 = n - n1;
//mergeSort(data[], n1)
//mergeSort(data + n1, n2)
//merge(data, n1, n2)
}
