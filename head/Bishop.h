#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Bishop :public Figure
{
public:
	//void CalculateAllowed(std::set<Cells> forbidden) override;
	void SetSprite(bool isWhite) override;
	Bishop() :Figure(FigureType::Bishop) {}
};
