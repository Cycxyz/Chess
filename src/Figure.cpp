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