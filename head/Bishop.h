#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Bishop :public Figure
{
  public:
    void calculateAllowed(Figures &figures) override;
    void setSprite(bool isWhite) override;
    Bishop() : Figure(FigureType::Bishop)
    {
    }

  private:
    void calculateInDirection();
};
