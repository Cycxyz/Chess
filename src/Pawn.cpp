#include "Pawn.h"
		void Pawn::SetSprite(bool _isWhite)
		{
			isWhite = _isWhite;
            currentPosition.x = 0;
            currentPosition.y = 0;
			sf::Vector2i pos;
				pos.x = 750;
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
		void Pawn::CalculateAllowed(Figures figures)
		{
                int x = currentPosition.x, y = currentPosition.y+direction;
                int i = findFigure(x, y, figures);
				if (i == -1)
				{
					allowed.insert(Cell{ x,y });
					y+=direction;
					if (!madeMove)
					{
                         i = findFigure(x, y, figures);
						if (i == -1)
						{
							allowed.insert(Cell{ x,y });
						}
					}
				}
                y = currentPosition.y+direction;
				x--;
                i = findFigure(x, y, figures);
				if (i != -1 && !(figures[i].get()->isWhite == isWhite))
					allowed.insert(Cell{x, y });
				x += 2;
                i = findFigure(x, y, figures);
				if (i != -1 && !(figures[i].get()->isWhite == isWhite))
					allowed.insert(Cell{ x, y });
		}
		
