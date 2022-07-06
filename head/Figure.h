#pragma once
#include<SFML/Graphics.hpp>
#include <set>
#include<algorithm>
#include<memory>
#include<vector>


enum class FigureType
{
    Figure,
    Bishop,
    Rook,
    King,
    Queen,
    Pawn,
    Horce
};

struct Cell
{
    int x, y;
};

bool operator==(const Cell &lhs, const Cell &rhs);
bool operator<(const Cell& lhs, const Cell& rhs);


class Figure;
using Figures = std::vector<std::shared_ptr<Figure>>;

class Figure
{
  public:
    Figure(FigureType aType) : type(aType)
    {
        type = aType;
        currentPosition.x = -1;
        currentPosition.y = -1;
        madeMove = 0;
        castlingL = Cell{-1, -1};
        castlingR = Cell{-1, -1};
        direction = 0;
    }
    void setPosition(int xPos, int yPos);
    Cell getPosition() const { return currentPosition; }
    bool isWhite() const { return fIsWhite; }
    const std::set<Cell> getAllowedPositions() { return allowed; }
    void markMoved() { madeMove = true; }
    const sf::Sprite& getSprite() { return sprite; }
    int direction;
    Cell castlingR;
    Cell castlingL;
    FigureType type;
    virtual void calculateAllowed(Figures &figures);
    virtual void calculateAllowedForbidden(Figures &figures);
    virtual void setSprite(bool isWhite) = 0;

  protected:
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
    bool madeMove = 0;
    std::set<Cell> allowed;
    Cell currentPosition;
    bool fIsWhite;

  private:
    void separateForbidden();
};

int findFigure(int x, int y, const Figures& figures);
