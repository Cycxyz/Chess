#include "Figure.h"
#include<cmath>

bool operator==(const Cell &lhs, const Cell &rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator<(const Cell &lhs, const Cell &rhs)
{
    return pow(2, lhs.x + 8) + pow(2, lhs.y) < pow(2, lhs.x + 8) + pow(2, lhs.y);
}
void Figure::setPosition(int xPos, int yPos)
{
    currentPosition.x = xPos;
    currentPosition.y = yPos;
    sprite.setPosition(currentPosition.x * 100, currentPosition.y * 100);
}
void Figure::separateForbidden()
{
	//for (Cells cell : forbidden)
	//{
	//	if (allowed.count(cell))
	//		allowed.erase(cell);
	//}
}
void Figure::calculateAllowed(Figures& figures)
{
	;
}
int findFigure(int x, int y, const Figures& figures)
{
	for (int i = 0; i < figures.size(); i++)
	{
        if (figures[i]->getPosition() == Cell { x, y }) {
            return i;
        }
	}
	return -1;
}
void Figure::calculateAllowedForbidden(Figures& figures)
{
    if (type == FigureType::King) {
        allowed.insert(Cell{ currentPosition.x, currentPosition.y });
    }
    std::shared_ptr<Figure> king;
    for (int i = 0; i < figures.size(); i++) {
        if (figures[i]->type == FigureType::King && figures[i]->isWhite() == fIsWhite) {
            king = figures[i];
        }
    }
    calculateAllowed(figures);

    Cell oldPosition = currentPosition;
    auto it = allowed.begin();
    while (it != allowed.end())
    {
        setPosition(it->x, it->y);
        for (int i = 0; i < figures.size(); i++)
        {
            if (figures[i]->currentPosition == currentPosition) {
                swap(figures[i], figures[figures.size() - 1]);
                break;
            }
        }
        bool isKingInDanger = false;
        for (int i = 0; !isKingInDanger && i < figures.size(); i++)
        {
            if (!(figures[i]->currentPosition == currentPosition))
            {
                if (figures[i]->isWhite() != isWhite())
                {
                    figures[i]->calculateAllowed(figures);
                    if (figures[i]->allowed.count(king->currentPosition) == 1)
                    {
                        allowed.erase(it++);
                        isKingInDanger = true;
                    }
                    figures[i]->allowed.clear();
                }
            }
        }
        if (!isKingInDanger) {
            it++;
        }
    }
        this->setPosition(oldPosition.x, oldPosition.y);
		if (FigureType::King == type)
		{
            if (!(allowed.count(Cell{ currentPosition.x, currentPosition.y }) &&
                allowed.count(Cell{ currentPosition.x + 1 , currentPosition.y }) &&
                allowed.count(Cell{ currentPosition.x + 2, currentPosition.y })))
                allowed.erase(Cell{ currentPosition.x + 2, currentPosition.y });
            if (!(allowed.count(Cell{ currentPosition.x, currentPosition.y }) &&
                allowed.count(Cell{ currentPosition.x - 1 , currentPosition.y }) &&
                allowed.count(Cell{ currentPosition.x - 2, currentPosition.y })))
                allowed.erase(Cell{ currentPosition.x - 2, currentPosition.y });
		}
        if (allowed.count(Cell{currentPosition.x, currentPosition.y}) == 1)
            allowed.erase(Cell{currentPosition.x, currentPosition.y});
}
