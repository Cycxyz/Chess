#include "Horce.h"
void Horce::SetSprite(bool isWhite)
{
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
