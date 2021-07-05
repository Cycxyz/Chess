﻿#include <SFML/Graphics.hpp>
#include "Pawn.h"
#include"King.h"
#include"Queen.h"
#include"rook.h"
#include"Bishop.h"
#include"Horce.h"
#include <vector>
#include <iostream>
#include <set>
#include"CapturedFigure.h"
#include<memory>
using namespace std;
#define Figures  vector<shared_ptr<Figure>>&

struct Cells
{
    int x, y;
};

class BoardConfigurator
{
public: 
    sf::Texture texture;
    sf::Sprite sprite;
    BoardConfigurator()
    {
            texture.loadFromFile("../images/board.png");
            texture.setRepeated(1);
            sprite.setTexture(texture);
            sprite.setRotation(90);
            sprite.setPosition(800, 0);
            sprite.setTextureRect(sf::IntRect(0, 0, 800, 800));
    }
};

void InitFigures(Figures figures)
{
    for (int j = 0; j < 2; j++)
    {
    for (int i = 0; i < 8; i++)
    {
        figures[j*16+i] = make_shared<Pawn>();
        figures[j*16+i]->SetSprite(j);
        figures[j * 16+i]->SetPosition(i, 1+j*5);
    }
        figures[j * 16 + 11] = make_shared<Rook>();
        figures[j * 16 + 11]->SetSprite(j);
        figures[j * 16 + 11]->SetPosition(0, j*7);
        figures[j * 16 + 10] = make_shared<Rook>();
        figures[j * 16 + 10]->SetSprite(j);
        figures[j * 16 + 10]->SetPosition(7, j*7);
        figures[j * 16 + 8] = make_shared<Horce>();
        figures[j * 16 + 8]->SetSprite(j);
        figures[j * 16 + 8]->SetPosition(1, j*7);
        figures[j * 16 + 9] = make_shared<Horce>();
        figures[j * 16 + 9]->SetSprite(j);
        figures[j * 16 + 9]->SetPosition(6, j*7);
        figures[j * 16 + 12] = make_shared<Bishop>();
        figures[j * 16+12]->SetSprite(j);
        figures[j * 16+12]->SetPosition(2, j*7);
        figures[j * 16+13] = make_shared<Bishop>();
        figures[j * 16+13]->SetSprite(j);
        figures[j * 16+13]->SetPosition(5, j*7);
        figures[j * 16+14] = make_shared<Queen>();
        figures[j * 16+14]->SetSprite(j);
        figures[j * 16+14]->SetPosition(3, j*7);
        figures[j * 16+15] = make_shared<King>();
        figures[j * 16+15]->SetSprite(j);
        figures[j * 16+15]->SetPosition(4, j*7);
    }
}

void InitExtraFigures(Figures figures)
{
    for (int i = 0; i < 2; i++)
    {
        figures[0+i*6] = make_shared<King>();
        figures[0+i*6]->SetSprite(i);
        figures[0+i*6]->SetPosition(8+i, 0);
        figures[1+i*6] = make_shared<Queen>();
        figures[1+i*6]->SetSprite(i);
        figures[1+i*6]->SetPosition(8+i, 1);
        figures[2+i*6] = make_shared<Bishop>();
        figures[2+i*6]->SetSprite(i);
        figures[2+i*6]->SetPosition(8+i, 2);
        figures[3+i*6] = make_shared<Horce>();
        figures[3+i*6]->SetSprite(i);
        figures[3+i*6]->SetPosition(8+i, 3);
        figures[4+i*6] = make_shared<Rook>();
        figures[4+i*6]->SetSprite(i);
        figures[4+i*6]->SetPosition(8+i, 4);
        figures[5+i*6] = make_shared<Pawn>();
        figures[5+i*6]->SetSprite(i);
        figures[5+i*6]->SetPosition(8+i, 5);
    }
}

void Draw(sf::RenderWindow& window, BoardConfigurator board, Figures figures, CapturedFigureCell Cell, Figures extraFigures)
{
window.clear(sf::Color::Blue);
    window.draw(board.sprite);
    window.draw(Cell.sprite);
    for (int i = 0; i < 12; i++)
        window.draw(extraFigures[i]->sprite);
    for (int i = 0; i < figures.size(); i++)
        window.draw(figures[i]->sprite);
    window.display();
}

int FindFigure(int x, int y, Figures figures)
{
    for (int i = 0; i < figures.size(); i++)
    {
        if (figures[i]->x == x && figures[i]->y == y) return i;
    }
    return -1;
}

//Двигает фигуру на указанное место или поднимает, фигура выделена
void MoveFigure(sf::Event event, shared_ptr<Figure>& Capturedfigure, Figures figures, CapturedFigureCell& Cell)
{
    int x = event.mouseButton.x / 100;
    int y = event.mouseButton.y / 100;
    if (!(x == Capturedfigure->x && y == Capturedfigure->y)) //если фигура выделена и нажато на другом поле
    {
        int index = FindFigure(x, y, figures);
        if (index != -1) figures.erase(figures.begin() + index);
        Cell.sprite.setPosition(-100, -100);
        Capturedfigure->SetPosition(x, y);
        Capturedfigure = NULL;
    }
}
shared_ptr<Figure> ParseFigure(shared_ptr<Figure> figure)
{
    switch (figure->type)
    {
    case FigureType::Bishop:
        return make_shared<Bishop>();
    case FigureType::King:
        return make_shared<King>();
    case FigureType::Queen:
        return make_shared<Queen>();
    case FigureType::Pawn:
        return make_shared<Pawn>();
    case FigureType::Rook:
        return make_shared<Rook>();
    default:
        return make_shared<Horce>();
    }
}

int main()
{
    set<Cells> forbidden;
    vector< shared_ptr<Figure> >extraFigures(12);
    CapturedFigureCell Cell;
    vector< shared_ptr<Figure>>figures;
    BoardConfigurator boardcfg;
   // InitFigures(figures);
    InitExtraFigures(extraFigures);
    sf::RenderWindow window(sf::VideoMode(1000, 800), "May be chess");
    shared_ptr<Figure> Capturedfigure;
    bool isFigureCaptured = 0, wasFigureGiven=0, isWhiteTurn=1;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }

            else
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    
                    if (Capturedfigure!=NULL) //если фигура уже выделена, то необходимо или сделать ход или поднять 
                    {
                        MoveFigure(event, Capturedfigure, figures, Cell);
                        if (Capturedfigure == NULL) wasFigureGiven = 0;
                        else isFigureCaptured = 1;
                    }
                    else
                    {
                        int x = event.mouseButton.x / 100;
                        int y = event.mouseButton.y / 100;
                        int i = FindFigure(x, y, figures);
                            //Если на нажатом поле есть фигура, выделить её
                        if(i!=-1)
                        {
                                Capturedfigure = figures[i];
                                swap(figures[i], figures[figures.size() - 1]);
                                Cell.sprite.setPosition(x * 100, y * 100);
                            }
                        else
                        {
                            i = FindFigure(x, y, extraFigures);
                            //Вдруг нажали на доп фигуры? Создать новую в том месте и выделить!
                            if (i != -1)
                            {
                                figures.push_back(ParseFigure(extraFigures[i]));
                                Capturedfigure = figures[figures.size() - 1];
                                Capturedfigure->sprite = extraFigures[i]->sprite;
                                Capturedfigure->SetPosition(extraFigures[i]->x, extraFigures[i]->y);
                                Cell.sprite.setPosition(Capturedfigure->x*100, Capturedfigure->y*100);
                            }
                            else Capturedfigure = NULL;
                        }
                        if (Capturedfigure != NULL) //костыль
                        {
                            isFigureCaptured = 1;
                            event.mouseMove.x = event.mouseButton.x;
                            event.mouseMove.y = event.mouseButton.y;
                        }
                    }
                }
            }

            else
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if(event.mouseButton.button==sf::Mouse::Left)
                { 
                    if(Capturedfigure!=NULL)
                    { 
                      //Переместить и зачистить если отпущена кнопка на поле отличном от начального
                            int x = event.mouseButton.x / 100;
                            int y = event.mouseButton.y / 100;
                            if (!(x == Capturedfigure->x && y == Capturedfigure->y))
                            {
                                wasFigureGiven = 0;
                                isFigureCaptured = 0;
                                Cell.sprite.setPosition(-100, -100);
                                int index = FindFigure(x, y, figures);
                                if (index != -1) figures.erase(figures.begin() + index);
                                Capturedfigure->SetPosition(x, y);
                                Capturedfigure = NULL;
                            }
                            //Если до этого фигура была выделена, зачистить. Вернуть с гулянок
                            else if (wasFigureGiven)
                            {
                                Cell.sprite.setPosition(-100, -100);
                                wasFigureGiven = 0;
                                isFigureCaptured = 0;
                                Capturedfigure->SetPosition(x, y);
                                Capturedfigure = NULL;
                            }
                            //Если не была, сказать, что её отпустили и указать, что уже была взята. Вернуть с гулянок
                            else
                            {
                                Capturedfigure->SetPosition(x, y);
                                wasFigureGiven = 1;
                                isFigureCaptured = 0;
                            }
                    }
                }

            }

            else
            if (event.type = sf::Event::MouseMoved)
            {
                if (isFigureCaptured) 
                    Capturedfigure->sprite.setPosition(event.mouseMove.x-50, event.mouseMove.y-50);
            }
        }
        Draw(window, boardcfg, figures, Cell, extraFigures);
    }
    return 0;
}