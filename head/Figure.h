#pragma once
#include<SFML/Graphics.hpp>
enum class FigureType
{
	Figure,
	Bishop,
	Rook,
	King,
	Queen,
	Pawn,
	Horce
};
class Figure
{
public:
	Figure(FigureType type_)
	{
		type = type_;
		x = 0;
		y = 0;
	}
	int x;
	int y;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	FigureType type;
	 virtual void SetSprite(bool isWhite) = 0;
	 virtual void SetPosition(int x_, int y_)=0;
};
