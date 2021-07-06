#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Horce : public Figure
{
public:
	//void CalculateAllowed(std::set<Cells> forbidden) override;
	void  SetSprite(bool isWhite) override;
	Horce():Figure(FigureType::Horce){}
};
