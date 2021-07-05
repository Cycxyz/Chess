#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Pawn:public Figure
{
public: 
    void SetSprite(bool isWhite) override;
	void SetPosition(int x_, int y_) override;
	Pawn() :Figure(FigureType::Pawn) {}
};