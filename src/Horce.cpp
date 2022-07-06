#include "Horce.h"
#include <functional>
void Horce::SetSprite(bool _isWhite)
{
	isWhite = _isWhite;
	cell.x = 0;
	cell.y = 0;
	sf::Vector2i pos;
	pos.x = 450;
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
void F(Figures figures, Figure* figure, int x, int y, bool ar1, bool ar2)
{
	if (ar1 && ar2)
	{
		int i = FindFigure(x, y, figures);
		if (i == -1) figure->allowed.insert(Cells{ x,y });
		else
			if (!(figures[i].get()->isWhite == figure->isWhite))
			{
				figure->allowed.insert(Cells{ x,y });
			}
	}
};
void Horce::CalculateAllowed(Figures figures)
{
	int x = cell.x, y = cell.y;
	x += 2; y++;
	F(figures, this, x, y, x < 8, y < 8);
	x =cell.x+2; y=cell.y-1;
	F(figures, this, x, y, x<8, y>-1);
	x = cell.x - 2; y = cell.y + 1;
	F(figures, this, x, y, x>-1, y<8);
	x = cell.x - 2; y = cell.y - 1;
	F(figures, this, x, y, x>-1, y>-1);
	x =cell.x+1; y=cell.y+2;
	F(figures, this, x, y, x < 8, y < 8);
	x =cell.x+1; y=cell.y-2;
	F(figures, this, x, y, x<8, y>-1);
	x = cell.x - 1; y = cell.y + 2;
	F(figures, this, x, y, x>-1, y<8);
	x = cell.x - 1; y = cell.y - 2;
	F(figures, this, x, y, x>-1, y>-1);
}
