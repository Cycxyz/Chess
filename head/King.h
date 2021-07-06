#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class King :public Figure
{
public:
	//void CalculateAllowed(std::set<Cells> forbidden) override;
	void SetSprite(bool isWhite) override;
	King():Figure(FigureType::King){}
};