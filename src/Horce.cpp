#include "Horce.h"
#include <functional>
void Horce::SetSprite(bool _isWhite)
{
	isWhite = _isWhite;
    currentPosition.x = 0;
    currentPosition.y = 0;
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
        int i = findFigure(x, y, figures);
		if (i == -1) figure->allowed.insert(Cell{ x,y });
		else
			if (!(figures[i].get()->isWhite == figure->isWhite))
			{
				figure->allowed.insert(Cell{ x,y });
			}
	}
};
void Horce::CalculateAllowed(Figures figures)
{
    int x = currentPosition.x, y = currentPosition.y;
	x += 2; y++;
	F(figures, this, x, y, x < 8, y < 8);
    x =currentPosition.x+2; y=currentPosition.y-1;
	F(figures, this, x, y, x<8, y>-1);
    x = currentPosition.x - 2; y = currentPosition.y + 1;
	F(figures, this, x, y, x>-1, y<8);
    x = currentPosition.x - 2; y = currentPosition.y - 1;
	F(figures, this, x, y, x>-1, y>-1);
    x =currentPosition.x+1; y=currentPosition.y+2;
	F(figures, this, x, y, x < 8, y < 8);
    x =currentPosition.x+1; y=currentPosition.y-2;
	F(figures, this, x, y, x<8, y>-1);
    x = currentPosition.x - 1; y = currentPosition.y + 2;
	F(figures, this, x, y, x>-1, y<8);
    x = currentPosition.x - 1; y = currentPosition.y - 2;
	F(figures, this, x, y, x>-1, y>-1);
}
