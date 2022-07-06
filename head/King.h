#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class King :public Figure
{
public:
	void calculateAllowed(Figures figures) override;
	void setSprite(bool isWhite) override;
	King():Figure(FigureType::King){}
};