//
// Created by jacki on 5/2/2024.
//

#ifndef NOTES_HASHTABLES_MERGESORT_H
#define NOTES_HASHTABLES_MERGESORT_H
#include "ItemList.h"

class MergeSort
{
private:
    static void merge(sf::RectangleShape *rects, int sizeL, int sizeR, sf::RenderWindow &window);
public:
    static void mergeSort(sf::RectangleShape *rects, int size, sf::RenderWindow &window);
};





#endif //NOTES_HASHTABLES_MERGESORT_H
