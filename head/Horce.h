#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Horce : public Figure
{
public:
	void  SetSprite(bool isWhite) override;
	void  SetPosition(int x_, int y_) override;
	Horce():Figure(FigureType::Horce){}
};
