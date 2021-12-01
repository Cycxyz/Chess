#include "Figure.h"
#include<cmath>
bool operator==(const Cells& c1, const Cells& c2)
{
	return c1.x==c2.x&&c1.y==c2.y;
}
bool operator<(Cells c1, Cells c2)
{
	return pow(2, c1.x+8) + pow(2, c1.y) < pow(2, c2.x + 8) + pow(2, c2.y);
}
void Figure::SetPosition(int x_, int y_)
{
	cell.x = x_;
	cell.y = y_;
	sprite.setPosition(cell.x * 100, cell.y * 100);
}
void Figure::SeparateForbidden()
{
	//for (Cells cell : forbidden)
	//{
	//	if (allowed.count(cell))
	//		allowed.erase(cell);
	//}
}
void Figure::CalculateAllowed(Figures figures)
{
	;
}
int FindFigure(int x, int y, Figures figures)
{
	for (int i = 0; i < figures.size(); i++)
	{
		if (figures[i]->cell.x == x && figures[i]->cell.y == y) return i;
	}
	return -1;
}
void Figure::CalculateAllowedForbidden(Figures figures)
{
	if (type == FigureType::King) allowed.insert(Cells{ cell.x, cell.y });
		Figure* king;
		for (int i = 0; i < figures.size(); i++)
			if (figures[i]->type == FigureType::King && figures[i]->isWhite == isWhite)
				king = figures[i].get();
		this->CalculateAllowed(figures);

		//std::tuple<Cells, FigureType, bool> fig;
			Cells remember = this->cell;
		auto it = allowed.begin();
		while (it != allowed.end())
		{
			bool flag = false;
			this->SetPosition(it->x, it->y);
			for (int i = 0; i < figures.size(); i++)
			{
				if (figures[i]->cell == cell) swap(figures[i], figures[figures.size() - 1]);
			}
			for (int i = 0; i < figures.size(); i++)
			{
				if (!(figures[i]->cell == cell))
				{
					auto type = figures[i]->type;
					if (figures[i]->isWhite != isWhite/* && (type == FigureType::Bishop || type == FigureType::Queen || type == FigureType::Rook)*/)
					{
						figures[i]->CalculateAllowed(figures);
						if (figures[i]->allowed.count(king->cell) == 1)
						{
							allowed.erase(it++);
							flag = 1;
						}
						figures[i]->allowed.clear();
						if (flag) break;
					}
				}
			}
			if (!flag) it++;
		}
		this->SetPosition(remember.x, remember.y);
		if (FigureType::King == type)
		{
			if (!(allowed.count(Cells{ cell.x, cell.y }) &&
				allowed.count(Cells{ cell.x + 1 , cell.y }) &&
				allowed.count(Cells{ cell.x + 2, cell.y })))
				allowed.erase(Cells{ cell.x + 2, cell.y });
			if (!(allowed.count(Cells{ cell.x, cell.y }) &&
				allowed.count(Cells{ cell.x - 1 , cell.y }) &&
				allowed.count(Cells{ cell.x - 2, cell.y })))
				allowed.erase(Cells{ cell.x - 2, cell.y });
		}
		if (allowed.count(Cells{ cell.x, cell.y }) == 1) allowed.erase(Cells{ cell.x, cell.y });
	}
