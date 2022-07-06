#include "King.h"
void King::SetSprite(bool _isWhite)
{
	isWhite = _isWhite;
    currentPosition.x = 0;
    currentPosition.y = 0;
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
        int i = findFigure(x, y, figures);
		if (i == -1)
		{
			king->allowed.insert(Cell{ x,y });
		}
		else if (figures[i].get()->isWhite != king->isWhite)
			king->allowed.insert(Cell{x, y});
	}
}
void King::CalculateAllowed(Figures  figures)
{
    int x = currentPosition.x - 1, y = currentPosition.y;
	F(x, y, this, figures, x > -1, y > -1);
    x = currentPosition.x + 1;
	F(x, y, this, figures, x < 8, y>-1);
    x = currentPosition.x;
    y = currentPosition.y - 1;
	F(x, y, this, figures, x < 8, y>-1);
    y = currentPosition.y + 1;
	F(x, y, this, figures, x < 8, y < 8);
    x = currentPosition.x + 1;
    y = currentPosition.y + 1;
	F(x, y, this, figures, x < 8, y < 8);
    x = currentPosition.x - 1;
	F(x, y, this, figures, x > -1, y < 8);
    y = currentPosition.y - 1;
	F(x, y, this, figures, x > -1, y > -1);
    x = currentPosition.x + 1;
	F(x, y, this, figures, x<8, y>-1);
    x = currentPosition.x + 2; y = currentPosition.y;
    int i = findFigure(currentPosition.x + 3, currentPosition.y, figures);
	if (!madeMove &&
        allowed.count(Cell{ currentPosition.x + 1, currentPosition.y }) == 1 &&
		i != -1 &&
		figures[i]->type == FigureType::Rook &&
		figures[i]->isWhite == isWhite &&
		!figures[i]->madeMove &&
        findFigure(x, y, figures) == -1 &&
        findFigure(currentPosition.x + 1, currentPosition.y, figures) == -1)
	{
		allowed.insert(Cell{ x,y });
		castlingR = Cell{ x,y };
	}
    x = currentPosition.x - 2; y = currentPosition.y;
    i = findFigure(currentPosition.x - 4, currentPosition.y, figures);
	if (!madeMove &&
        allowed.count(Cell{ currentPosition.x -1, y }) == 1 &&
		i != -1 &&
		figures[i]->type == FigureType::Rook &&
		figures[i]->isWhite == isWhite &&
		!figures[i]->madeMove &&
        findFigure(x, y, figures) == -1 &&
        findFigure(currentPosition.x - 1, currentPosition.y, figures) == -1 &&
        findFigure(currentPosition.x - 3, currentPosition.y, figures)==-1)
	{
		allowed.insert(Cell{ x,y });
		castlingL = Cell{ x,y };
	}
}
