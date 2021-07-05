#include "CapturedFigure.h"
CapturedFigureCell::CapturedFigureCell()
{
	image.loadFromFile("../images/CapturedFigure.png");
	auto pixel = image.getPixel(0, 0);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(-100, -100);
	int r = pixel.r;
	int g = pixel.g;
	int b = pixel.b;
	sprite.setColor(sf::Color(r, g, b, 128));
}