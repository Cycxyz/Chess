#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Pawn:public Figure
{
public: 
	void calculateAllowed(Figures figure) override;
	//void CalculateAllowedForbidden(Figures figures) override;
    void setSprite(bool isWhite) override;
	Pawn() :Figure(FigureType::Pawn) {}
};