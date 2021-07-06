#pragma once
#include<SFML/Graphics.hpp>
#include <set>
#include<algorithm>
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
//Координаты вида (0,0)
struct Cells
{
	int x, y;
};
class Figure
{
public:
	Figure(FigureType type_)
	{
		type = type_;
		cell. x = 0;
		cell.y = 0;
	}
	std::set<Cells> allowed;
	Cells cell;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	FigureType type;
	//virtual void CalculateAllowed(std::set<Cells> forbidden) = 0;
	 virtual void SetSprite(bool isWhite) = 0;
	  void SetPosition(int x_, int y_);
private:
	/*void SeparateForbidden(std::set<Cells> forbidden)
	{
		for(Cells cell:forbidden)
		{
			if (allowed.count(cell))
				allowed.erase(cell);
		}
	}*/
};
