#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Horce : public Figure
{
public:
	void calculateAllowed(Figures figures) override;
	void  setSprite(bool isWhite) override;
	Horce():Figure(FigureType::Horce){}
};
