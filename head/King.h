#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class King :public Figure
{
public:
	void CalculateAllowed(Figures figures) override;
	void SetSprite(bool isWhite) override;
	King():Figure(FigureType::King){}
};