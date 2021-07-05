#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class Bishop :public Figure
{
public:
	void SetSprite(bool isWhite) override;
	void SetPosition(int x_, int y_) override;
	Bishop() :Figure(FigureType::Bishop) {}
};
