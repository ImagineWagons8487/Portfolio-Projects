//
// Created by jacki on 5/8/2024.
//

#ifndef _SFMLTEMPLATE_ITEMLIST_H
#define _SFMLTEMPLATE_ITEMLIST_H
#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"
class ItemList : public sf::Drawable
{
private:
    std::vector<int> itemVector;
    std::vector<sf::RectangleShape> barVector;
    int getLargestValIndex(const std::vector<int> v);
    void setBarsWidth(const sf::RenderWindow& window);
    void setBarsHeight(const sf::RenderWindow& window);
    void positionBars(const sf::RenderWindow& window);
    void updateDraw(sf::RenderWindow& window);
    void merge(sf::RectangleShape* rects, int sizeL, int sizeR, sf::RenderWindow& window);
    void mergeSort(sf::RectangleShape* rects, int size, sf::RenderWindow& window);
public:
    ItemList();
    ItemList(const std::vector<int>& v);
    void setVector(const std::vector<int>& v);
    void initBars(const sf::RenderWindow &window);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void mergeSort(sf::RenderWindow &window);
};


#endif //_SFMLTEMPLATE_ITEMLIST_H
