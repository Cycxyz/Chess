#pragma once
#include"Figure.h"
#include<SFML/Graphics.hpp>
class CapturedFigureCell
{
public:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	CapturedFigureCell();
};
