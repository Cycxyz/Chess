#pragma once
#include<SFML/Graphics.hpp>
#include "Figure.h"
class King :public Figure
{
public:
	void SetSprite(bool isWhite) override;
	void SetPosition(int x_, int y_) override;
	King():Figure(FigureType::King){}
};