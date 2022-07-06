#include "Queen.h"
void Queen::SetSprite(bool _isWhite)
{
	isWhite = _isWhite;
    currentPosition.x = 0;
    currentPosition.y = 0;
	sf::Vector2i pos;
	pos.x = 150;
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
void Queen::CalculateAllowed(Figures figures)
{
    int x = currentPosition.x + 1, y = currentPosition.y + 1;
	while (x < 8 && y < 8)
	{
        int i = findFigure(x, y, figures);
		if (i == -1) allowed.insert(Cell{ x,y });
		else
			if (!(figures[i].get()->isWhite == isWhite))
			{
				allowed.insert(Cell{ x,y });
				break;
			}
			else break;
		x++; y++;
	}
    x = currentPosition.x + 1; y = currentPosition.y - 1;
	while (x<8 && y>-1)
	{
        int i = findFigure(x, y, figures);
		if (i == -1)
			allowed.insert(Cell{ x,y });
		else if (!(figures[i].get()->isWhite == isWhite))
		{
			allowed.insert(Cell{ x,y });
			break;
		}
		else break;
		x++; y--;
	}
    x = currentPosition.x - 1; y = currentPosition.y - 1;
	while (x > -1 && y > -1)
	{
        int i = findFigure(x, y, figures);
		if (i == -1) allowed.insert(Cell{ x,y });
		else if (!(figures[i].get()->isWhite == isWhite))
		{
			allowed.insert(Cell{ x,y });
			break;
		}
		else break;
		x--; y--;
	}
    x = currentPosition.x - 1; y = currentPosition.y + 1;
	while (x > -1 && y < 8)
	{
        int i = findFigure(x, y, figures);
		if (i == -1) allowed.insert(Cell{ x,y });
		else if (!(figures[i].get()->isWhite == isWhite))
		{
			allowed.insert(Cell{ x,y });
			break;
		}
		else break;
		x--; y++;
	}
    x = currentPosition.x + 1, y = currentPosition.y;
	while (x < 8)
	{
        int i = findFigure(x, y, figures);
		if (i == -1)
			allowed.insert(Cell{ x,y });
		else if (!(figures[i].get()->isWhite == isWhite))
		{
			allowed.insert(Cell{ x,y });
			break;
		}
		else break;
		x++;
	}
    x = currentPosition.x - 1;
	while (x > -1)
	{
        int i = findFigure(x, y, figures);
		if (i == -1)
			allowed.insert(Cell{ x,y });
		else if (!(figures[i].get()->isWhite == isWhite))
		{
			allowed.insert(Cell{ x,y });
			break;
		}
		else break;
		x--;
	}
    x = currentPosition.x;
    y = currentPosition.y + 1;
	while (y < 8)
	{
        int i = findFigure(x, y, figures);
		if (i == -1)
			allowed.insert(Cell{ x,y });
		else if (!(figures[i].get()->isWhite == isWhite))
		{
			allowed.insert(Cell{ x,y });
			break;
		}
		else break;
		y++;
	}
    y = currentPosition.y - 1;
	while (y > -1)
	{
        int i = findFigure(x, y, figures);
		if (i == -1)
			allowed.insert(Cell{ x,y });
		else if (!(figures[i].get()->isWhite == isWhite))
		{
			allowed.insert(Cell{ x,y });
			break;
		}
		else break;
		y--;
	}
	
}
