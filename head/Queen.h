#pragma once
#include"Figure.h"
#include<SFML/Graphics.hpp>
class Queen:public Figure
{
public:
	void calculateAllowed(Figures figures) override;
	 void  setSprite(bool isWhite) override;
	 Queen():Figure(FigureType::Queen){}
};