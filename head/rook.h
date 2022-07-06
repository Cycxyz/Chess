#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Rook :public Figure
{
public:
	void calculateAllowed(Figures figures) override;
	void setSprite(bool isWhite) override;
	Rook() :Figure(FigureType::Rook){}
};