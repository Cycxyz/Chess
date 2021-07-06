#include "rook.h"
void Rook::SetSprite(bool _isWhite)
{
	isWhite = _isWhite;
	cell.x = 0;
	cell.y = 0;
	sf::Vector2i pos;
	pos.x = 600;
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
void Rook::CalculateAllowed(Figures figures)
{
	int x = cell.x + 1, y = cell.y;
	while (x < 8)
	{
		int i = FindFigure(x, y, figures);
		if (i == -1)
			allowed.insert(Cells{ x,y });
		else if (!(figures[i].get()->isWhite == isWhite))
		{
			allowed.insert(Cells{ x,y });
			break;
		}
		else break;
		x++;
	}
	x = cell.x - 1;
	while (x > -1)
	{
		int i = FindFigure(x, y, figures);
		if (i == -1)
			allowed.insert(Cells{ x,y });
		else if (!(figures[i].get()->isWhite == isWhite))
		{
			allowed.insert(Cells{ x,y });
			break;
		}
		else break;
		x--;
	}
	x = cell.x;
	y = cell.y + 1;
	while (y < 8)
	{
		int i = FindFigure(x, y, figures);
		if (i == -1)
			allowed.insert(Cells{ x,y });
		else if (!(figures[i].get()->isWhite == isWhite))
		{
			allowed.insert(Cells{ x,y });
			break;
		}
		else break;
		y++;
	}
	y = cell.y - 1;
	while (y > -1)
	{
		int i = FindFigure(x, y, figures);
		if (i == -1)
			allowed.insert(Cells{ x,y });
		else if (!(figures[i].get()->isWhite == isWhite))
		{
			allowed.insert(Cells{ x,y });
			break;
		}
		else break;
		y--;
	}
}