//
// Created by jacki on 12/5/2023.
//

#include "Game.h"

Game::Game()
{
    turnNum=1;
    font.loadFromFile("OpenSans-Bold.ttf");
    turnCount.setCharacterSize(30);
    turnCount.setFillColor(sf::Color::Black);
    turnCount.setFont(font);
    turnCount.setPosition(320,0);
    turnCount.setString("Turn: " + std::to_string(turnNum));
}

void Game::run()
{

}

void Game::loadPlayer(Player &p)
{
    players.push_back(&p);
}

void Game::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    for(int i=0; i<players.size(); i++)
        players[i]->eventHandler(window, event);
    if(players[0]->checkReady() && players[1]->checkReady())
    {
        actionsHappen();
        turnCount.setString("Turn: " + std::to_string(turnNum));
    }
    if(players[0]->getCharacter().currentHealth == 0 || players[1]->getCharacter().currentHealth == 0)
    {
        turnCount.setPosition(285, 0);
        turnCount.setString("Game Over");
    }
}

void Game::update()
{
    for(int i=0; i<players.size(); i++)
        players[i]->update();
}

void Game::actionsHappen()
{
    for(int i=0; i<players.size(); i++)
    {
        if(players[i]->getActionChoice() == GUARD)
            players[i]->guard();
    }
    switch(players[0]->getActionChoice())
    {
        case BASICATTACK:
            players[1]->reduceHealth(players[0]->attack(), false);
            break;
        case GUARD:
            break;
        case BRACE:
            players[0]->charBrace();
            break;
        case STAB:
            players[1]->reduceHealth(players[0]->stab(), true);
            break;
    }
    switch(players[1]->getActionChoice())
    {
        case BASICATTACK:
            players[0]->reduceHealth(players[1]->attack(), false);
            break;
        case GUARD:
            break;
        case BRACE:
            players[1]->charBrace();
            break;
        case STAB:
            players[0]->reduceHealth(players[1]->stab(), true);
            break;
    }
    for(int i=0; i<players.size(); i++)
    {
        players[i]->zeroGuardStacks();
        players[i]->unReady();
    }
    turnNum++;
}

void Game::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    for(int i=0; i<players.size(); i++)
        window.draw(*players[i]);
    window.draw(turnCount);
}
