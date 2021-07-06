#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Bishop :public Figure
{
public:
	void CalculateAllowed(Figures figures) override;
	void SetSprite(bool isWhite) override;
	Bishop() :Figure(FigureType::Bishop) {}
};
