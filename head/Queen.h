#pragma once
#include"Figure.h"
#include<SFML/Graphics.hpp>
class Queen:public Figure
{
public:
	void CalculateAllowed(Figures figures) override;
	 void  SetSprite(bool isWhite) override;
	 Queen():Figure(FigureType::Queen){}
};