//
// Created by jacki on 5/8/2024.
//

#include "ItemList.h"

ItemList::ItemList()
{

}

ItemList::ItemList(const std::vector<int> &v)
{
    setVector(v);
}

void ItemList::setVector(const std::vector<int> &v)
{
    itemVector = v;
}

int ItemList::getLargestValIndex(const std::vector<int> v)
{
    int highestIndex=0;
    for(int i=0; i<itemVector.size(); i++)
    {
        if(itemVector[i] > itemVector[highestIndex])
            highestIndex = i;
    }
    return highestIndex;
}

void ItemList::setBarsWidth(const sf::RenderWindow &window)
{
    float barWidth = (window.getSize().x)/barVector.size();
    for(auto &i: barVector)
        i.setSize({barWidth, i.getSize().y});
}

void ItemList::setBarsHeight(const sf::RenderWindow &window)
{
    float highestHeight = (window.getSize().y) * .95;
    sf::RectangleShape &tallestRect = barVector[getLargestValIndex(itemVector)];
    float highestVal = itemVector[getLargestValIndex(itemVector)];
    tallestRect.setSize({tallestRect.getSize().x, -highestHeight});
    for(int i=0; i<barVector.size(); i++)
    {
        if(i != getLargestValIndex(itemVector))
        {
            float currVal = itemVector[i];
            float ratio = currVal/highestVal;
            barVector[i].setSize({barVector[i].getSize().x
                                  , (ratio * tallestRect.getSize().y)});
        }

    }
}

void ItemList::positionBars(const sf::RenderWindow &window)
{
    for(int i=0; i<barVector.size(); i++)
    {
        barVector[i].setPosition({barVector[i].getGlobalBounds().width * i, float(window.getSize().y)});
    }
}

void ItemList::updateDraw(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);
    window.draw(*this);
    window.display();
}

void ItemList::merge(sf::RectangleShape *rects, int sizeL, int sizeR, sf::RenderWindow &window)
{
    rects[(sizeL + sizeR - 1)].setFillColor(sf::Color::Green);
    auto *tempArr = new sf::RectangleShape[sizeL + sizeR];
    int copiedToTemp = 0, copiedFirstHalf = 0, copiedSecondHalf = 0;
    int sleepTime = 0;
    while(copiedFirstHalf < sizeL && copiedSecondHalf < sizeR)//while we haven't copied everything from the arrays
    {
        sf::sleep(sf::milliseconds(sleepTime));
        if(rects[copiedFirstHalf].getSize().y > (rects + sizeL)[copiedSecondHalf].getSize().y)
        {
            tempArr[copiedToTemp].setSize(rects[copiedFirstHalf++].getSize());
//            tempArr[copiedToTemp++] = rects[copiedFirstHalf++];
//            positionBars(window);
        }
        else
        {
            tempArr[copiedToTemp].setSize((rects + sizeL)[copiedSecondHalf++].getSize());
//            tempArr[copiedToTemp++] = (rects + sizeL)[copiedSecondHalf++];
//            positionBars(window);
        }
        positionBars(window);
        (rects + copiedToTemp++)->setFillColor(sf::Color::Red);
        updateDraw(window);

//        (rects + copiedToTemp)->setFillColor(sf::Color::White);

//        if (rects[copiedFirstHalf] < (rects + sizeL)[copiedSecondHalf])
//            tempArr[copiedToTemp++] = rects[copiedFirstHalf++];
//        else
//            tempArr[copiedToTemp++] = (rects + sizeL)[copiedSecondHalf++];
//        float ratio = (float(sizeL) + float(sizeR))/3;
//        if((float)copiedToTemp > ratio)
//        {
//            for (int i = 0; i < (copiedToTemp); i++)
//            {
////        rects[i].setSize(tempArr[i].getSize());
//                sf::sleep(sf::milliseconds(sleepTime));
//                rects[i] = tempArr[i];
//                positionBars(window);
//                updateDraw(window);
//            }
//        }
    }
    while (copiedFirstHalf < sizeL)
    {
        sf::sleep(sf::milliseconds(sleepTime));
        tempArr[copiedToTemp].setSize(rects[copiedFirstHalf++].getSize());
//        tempArr[copiedToTemp++] = rects[copiedFirstHalf++];
        positionBars(window);
        (rects + copiedToTemp++)->setFillColor(sf::Color::Red);
        updateDraw(window);
//        (rects + copiedToTemp)->setFillColor(sf::Color::White);
    }
//        tempArr[copiedToTemp++] = rects[copiedFirstHalf++];

    while (copiedSecondHalf < sizeR)
    {
        sf::sleep(sf::milliseconds(sleepTime));
        tempArr[copiedToTemp].setSize((rects + sizeL)[copiedSecondHalf++].getSize());
//        tempArr[copiedToTemp++] = (rects + sizeL)[copiedSecondHalf++];
        positionBars(window);
        (rects + copiedToTemp++)->setFillColor(sf::Color::Red);
        updateDraw(window);

//        (rects + copiedToTemp)->setFillColor(sf::Color::White);
    }
//        tempArr[copiedToTemp++] = (rects + sizeL)[copiedSecondHalf++];

    for (int i = 0; i < (sizeL + sizeR); i++)
    {
//        rects[i].setSize(tempArr[i].getSize());
        sf::sleep(sf::milliseconds(sleepTime));
        rects[i] = tempArr[i];
        positionBars(window);
        updateDraw(window);
    }
//    positionBars(window);
//    updateDraw(window);
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

void ItemList::mergeSort(sf::RectangleShape *rects, int size, sf::RenderWindow &window)
{
    int sizeL, sizeR;
    if(size > 1)
    {
        sizeL = size / 2;
        sizeR = size - sizeL;
        mergeSort(rects, sizeL, window);
        mergeSort(rects + sizeL, sizeR, window);
        merge(rects, sizeL, sizeR, window);
        updateDraw(window);
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

void ItemList::initBars(const sf::RenderWindow &window)
{
    sf::RectangleShape bar;
    for(int i=0; i<itemVector.size(); i++)
    {
        barVector.push_back(bar);
    }
    for(auto &i: barVector)
    {
        i.setFillColor(sf::Color::White);
    }
    setBarsWidth(window);
    setBarsHeight(window);
    positionBars(window);
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for(auto &i:barVector)
    {
        window.draw(i);
    }
}

void ItemList::mergeSort(sf::RenderWindow &window)
{
    mergeSort(&barVector[0], (int)barVector.size(), window);
    positionBars(window);
}
