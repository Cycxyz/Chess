#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Pawn:public Figure
{
public: 
	//void CalculateAllowed(std::set<Cells> forbidden) override;
    void SetSprite(bool isWhite) override;
	Pawn() :Figure(FigureType::Pawn) {}
};