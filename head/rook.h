#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Rook :public Figure
{
public:
	void CalculateAllowed(Figures figures) override;
	void SetSprite(bool isWhite) override;
	Rook() :Figure(FigureType::Rook){}
};