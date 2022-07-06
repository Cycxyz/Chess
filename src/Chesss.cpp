#include <SFML/Graphics.hpp>
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
    figures.resize(32);
    for (int j = 0; j < 2; j++)
    {
    for (int i = 0; i < 8; i++)
    {
        figures[j*16+i] = make_shared<Pawn>();
        figures[j*16+i]->SetSprite(j);
        figures[j * 16 + i]->direction = (j) ? -1 : 1;
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

//void InitFigures(Figures figures)
//{
//    figures.resize(4);
//    figures[0] = make_shared<King>();
//    figures[0]->SetSprite(0);
//    figures[0]->SetPosition(4, 0);
//    figures[1] = make_shared<King>();
//    figures[1]->SetSprite(1);
//    figures[1]->SetPosition(4, 7);
//    figures[2] = make_shared<Pawn>();
//    figures[2]->SetSprite(1);
//    figures[2]->direction = -1;
//    figures[2]->SetPosition(6, 1);
//    figures[3] = make_shared<Rook>();
//    figures[3]->SetSprite(0);
//    figures[3]->SetPosition(1, 1);
//}

//void InitExtraFigures(Figures figures)
//{
// figures.resize(12);
//    for (int i = 0; i < 2; i++)
//    {
//        figures[0+i*6] = make_shared<King>();
//        figures[0+i*6]->SetSprite(i);
//        figures[0+i*6]->SetPosition(8+i, 0);
//        figures[1+i*6] = make_shared<Queen>();
//        figures[1+i*6]->SetSprite(i);
//        figures[1+i*6]->SetPosition(8+i, 1);
//        figures[2+i*6] = make_shared<Bishop>();
//        figures[2+i*6]->SetSprite(i);
//        figures[2+i*6]->SetPosition(8+i, 2);
//        figures[3+i*6] = make_shared<Horce>();
//        figures[3+i*6]->SetSprite(i);
//        figures[3+i*6]->SetPosition(8+i, 3);
//        figures[4+i*6] = make_shared<Rook>();
//        figures[4+i*6]->SetSprite(i);
//        figures[4+i*6]->SetPosition(8+i, 4);
//        figures[5+i*6] = make_shared<Pawn>();
//        figures[5+i*6]->SetSprite(i);
//        figures[5+i*6]->SetPosition(8+i, 5);
//    }
//}
class Move
{
public:
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    Move(Cells cell)
    {
        image.loadFromFile("../images/move.png");
        auto pixel = image.getPixel(0, 0);
        image.createMaskFromColor(pixel);
        texture.loadFromImage(image);
        texture.setSmooth(1);
        sprite.setTexture(texture);
        sprite.setPosition(cell.x * 100, cell.y * 100);
    }
};
void Draw(sf::RenderWindow& window, BoardConfigurator board, Figures figures, CapturedFigureCell Cell, Figures extraFigures, vector<Move> move)
{
window.clear(sf::Color::Blue);
    window.draw(board.sprite);
    window.draw(Cell.sprite);
    for (int i = 0; i < extraFigures.size(); i++)
        window.draw(extraFigures[i]->sprite);
    for (int i = 0; i < figures.size(); i++)
        window.draw(figures[i]->sprite);
    for (int i = 0; i < move.size(); i++)
        window.draw(move[i].sprite);
    window.display();
}



//Двигает фигуру на указанное место или поднимает, фигура выделена
void MoveFigure(sf::Event event, shared_ptr<Figure>& Capturedfigure, Figures figures, CapturedFigureCell& Cell)
{
    int x = event.mouseButton.x / 100;
    int y = event.mouseButton.y / 100;
    if ((x < 0 || y < 0 || x>7 || y>7))
    {
        Cell.sprite.setPosition(-100, -100);
        Capturedfigure->SetPosition(Capturedfigure->cell.x, Capturedfigure->cell.y);
        Capturedfigure = NULL;
    }
    else
    if (!(x == Capturedfigure->cell.x && y == Capturedfigure->cell.y)) //если фигура выделена и нажато на другом поле
    {
        
        if (Capturedfigure->allowed.count(Cells{ x,y }) == 1)
        {
            if (Cells{ x,y } == Capturedfigure->CastlingR)
            {
                figures[FindFigure(7, Capturedfigure->cell.y, figures)]->SetPosition(5, Capturedfigure->cell.y);
            }
            else if (Cells{ x,y } == Capturedfigure->CastlingL)
            {
                figures[FindFigure(0, Capturedfigure->cell.y, figures)]->SetPosition(3, Capturedfigure->cell.y);
            }
            else if (Capturedfigure->type == FigureType::Pawn &&
                (Capturedfigure->direction == 1 && y == 7 ||
                    Capturedfigure->direction == -1 && y == 0))
            {
                 int i= FindFigure(Capturedfigure->cell.x, Capturedfigure->cell.y, figures);
                figures[i]= make_shared<Queen>();
                figures[i]->SetSprite(Capturedfigure->isWhite);
                figures[i]->SetPosition(Capturedfigure->cell.x, Capturedfigure->cell.y);
                Capturedfigure = figures[i];
            }
            else
            {
                int index = FindFigure(x, y, figures);
                if (index != -1) figures.erase(figures.begin() + index);
            }
                Capturedfigure->SetPosition(x, y);
                Capturedfigure->MadeMove = 1;
        }
            Cell.sprite.setPosition(-100, -100);
            Capturedfigure.get()->allowed.clear();
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
    //cout << sizeof(Bishop);
    vector<Move> move;
    set<Cells> forbidden;
    vector< shared_ptr<Figure> >extraFigures;
    CapturedFigureCell Cell;
    vector< shared_ptr<Figure>>figures;
    BoardConfigurator boardcfg;
    InitFigures(figures);
    //InitExtraFigures(extraFigures);
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
                        if (Capturedfigure == NULL)
                        {
                            wasFigureGiven = 0;
                            move.clear();
                        }
                        else isFigureCaptured = 1;
                    }
                    else
                    {
                        int x = event.mouseButton.x / 100;
                        int y = event.mouseButton.y / 100;
                        int i = FindFigure(x, y, figures);
                            //Если на нажатом поле есть фигура, выделить её и показать ходы
                        if (i != -1)
                        {
                            Capturedfigure = figures[i];
                            swap(figures[i], figures[figures.size() - 1]);
                            Cell.sprite.setPosition(x * 100, y * 100);
                            Capturedfigure.get()->CalculateAllowedForbidden(figures);
                            for (Cells cell : Capturedfigure.get()->allowed)
                            {
                                move.push_back(cell);
                            }
                        }
                        else Capturedfigure = NULL;
                       /* {
                            i = FindFigure(x, y, extraFigures);
                            //Вдруг нажали на доп фигуры? Создать новую в том месте и выделить!
                            if (i != -1)
                            {
                                figures.push_back(ParseFigure(extraFigures[i]));
                                Capturedfigure = figures[figures.size() - 1];
                                Capturedfigure.get()->SetSprite(extraFigures[i].get()->isWhite);
                                Capturedfigure->SetPosition(extraFigures[i]->cell.x, extraFigures[i]->cell.y);
                                Cell.sprite.setPosition(Capturedfigure->cell.x*100, Capturedfigure->cell.y*100);
                            }
                            else Capturedfigure = NULL;
                        }*/
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
                            int x = event.mouseButton.x / 100;
                            int y = event.mouseButton.y / 100;
                            //Если отпущена кнопка вне игрового поля
                            if (((x < 0 || y < 0 || x>7 || y>7)) && isFigureCaptured)
                            {
                                    wasFigureGiven = 0;
                                    isFigureCaptured = 0;
                                    Cell.sprite.setPosition(-100, -100);
                                    Capturedfigure->SetPosition(Capturedfigure->cell.x, Capturedfigure->cell.y);
                                    Capturedfigure->allowed.clear(); 
                                    Capturedfigure = NULL; 
                                    move.clear();
                            }
                            else
                      //Переместить и зачистить если отпущена кнопка на поле отличном от начального 
                            if (!(x == Capturedfigure->cell.x && y == Capturedfigure->cell.y))
                            {
                                if (Capturedfigure->allowed.count(Cells{ x,y }) == 1)
                                {
                                    if (Cells{ x,y } == Capturedfigure->CastlingL)
                                    {
                                        figures[FindFigure(0, Capturedfigure->cell.y, figures)]->SetPosition(3, Capturedfigure->cell.y);
                                    }
                                    else if (Cells{ x,y } == Capturedfigure->CastlingR)
                                    {
                                    figures[FindFigure(7, Capturedfigure->cell.y, figures)]->SetPosition(5, Capturedfigure->cell.y);
                                    }
                                    else if (Capturedfigure->type == FigureType::Pawn &&
                                        (Capturedfigure->direction == 1 && y == 7 ||
                                            Capturedfigure->direction == -1 && y == 0))
                                    {
                                        int i = FindFigure(Capturedfigure->cell.x, Capturedfigure->cell.y, figures);
                                        figures[i] = make_shared<Queen>();
                                        figures[i]->SetSprite(Capturedfigure->isWhite);
                                        figures[i]->SetPosition(Capturedfigure->cell.x, Capturedfigure->cell.y);
                                        Capturedfigure = figures[i];
                                    }
                                    else
                                    {
                                        int index = FindFigure(x, y, figures);
                                        if (index != -1) figures.erase(figures.begin() + index);
                                    }
                                    Capturedfigure->SetPosition(x, y);
                                    Capturedfigure->MadeMove = 1;
                                    Cell.sprite.setPosition(-100, -100);
                                }
                                else
                                {
                                    Cell.sprite.setPosition(-100, -100);
                                    Capturedfigure->SetPosition(Capturedfigure->cell.x, Capturedfigure->cell.y);
                                }
                                Capturedfigure->allowed.clear();
                                Capturedfigure = NULL;
                                wasFigureGiven = 0;
                                isFigureCaptured = 0;
                                move.clear();

                            }
                            //Если до этого фигура была выделена, зачистить. Вернуть с гулянок
                            else if (wasFigureGiven)
                            {
                                Cell.sprite.setPosition(-100, -100);
                                wasFigureGiven = 0;
                                isFigureCaptured = 0;
                                Capturedfigure->SetPosition(x, y);
                                Capturedfigure->allowed.clear();
                                Capturedfigure = NULL;
                                move.clear();
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
        Draw(window, boardcfg, figures, Cell, extraFigures, move);
    }
    return 0;
}