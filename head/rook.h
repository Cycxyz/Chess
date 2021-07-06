#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Rook :public Figure
{
public:
	//void CalculateAllowed(std::set<Cells> forbidden) override;
	void SetSprite(bool isWhite) override;
	Rook() :Figure(FigureType::Rook){}
};