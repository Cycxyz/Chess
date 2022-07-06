#include "King.h"
void King::SetSprite(bool _isWhite)
{
	isWhite = _isWhite;
	cell.x = 0;
	cell.y = 0;
	sf::Vector2i pos;
	pos.x = 0;
	if (isWhite)
	{
		pos.y = 0;
	}
	else
		pos.y = 150;
	image.loadFromFile("../images/Chess.png");
	auto pixel = image.getPixel(0, 0);
	image.createMaskFromColor(pixel);
	texture.loadFromImage(image, sf::IntRect(pos, sf::Vector2i(150, 150)));
	texture.setSmooth(1);
	sprite.setTexture(texture);
	float scale = 2 / 3.0;
	sprite.setScale(scale, scale);
}
void F(int x, int y, Figure* king, Figures figures, bool arg1, bool arg2)
{
	if (arg1 && arg2)
	{
		int i = FindFigure(x, y, figures);
		if (i == -1)
		{
			king->allowed.insert(Cells{ x,y });
		}
		else if (figures[i].get()->isWhite != king->isWhite)
			king->allowed.insert(Cells{x, y});
	}
}
void King::CalculateAllowed(Figures  figures)
{
	int x = cell.x-1, y = cell.y;
	F(x, y, this, figures, x > -1, y>-1);
	x = cell.x + 1;
	F(x, y, this, figures, x < 8, y>-1);
	x = cell.x;
	y = cell.y-1;
	F(x, y, this, figures, x < 8, y>-1);
	y = cell.y + 1;
	F(x, y, this, figures, x < 8, y<8);
	x = cell.x + 1;
	y = cell.y + 1;
	F(x, y, this, figures, x < 8, y < 8);
	x = cell.x - 1;
	F(x, y, this, figures, x > -1, y < 8);
	y = cell.y - 1;
	F(x, y, this, figures, x > -1, y > -1);
	x = cell.x + 1;
	F(x, y, this, figures, x<8, y>-1);
}
