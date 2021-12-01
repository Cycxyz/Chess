#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Pawn:public Figure
{
public: 
	void CalculateAllowed(Figures figure) override;
	//void CalculateAllowedForbidden(Figures figures) override;
    void SetSprite(bool isWhite) override;
	Pawn() :Figure(FigureType::Pawn) {}
};