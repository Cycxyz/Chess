#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Horce : public Figure
{
public:
	void CalculateAllowed(Figures figures) override;
	void  SetSprite(bool isWhite) override;
	Horce():Figure(FigureType::Horce){}
};
