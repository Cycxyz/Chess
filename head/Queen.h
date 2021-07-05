#pragma once
#include"Figure.h"
#include<SFML/Graphics.hpp>
class Queen:public Figure
{
public:
	 void  SetSprite(bool isWhite) override;
     void  SetPosition(int x_, int y_) override;
	 Queen():Figure(FigureType::Queen){}
};