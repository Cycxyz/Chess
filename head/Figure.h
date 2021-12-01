#pragma once
#include<SFML/Graphics.hpp>
#include <set>
#include<algorithm>
#include<memory>
#include<vector>


enum class FigureType
{
	Figure,
	Bishop,
	Rook,
	King,
	Queen,
	Pawn,
	Horce
};
//Координаты вида (0,0)
struct Cells
{
	int x, y;
};
bool operator==(const Cells& c1, const Cells& c2);
bool operator<(Cells c1, Cells c2);
class Figure
{
public:
	Figure(FigureType type_)
	{
		type = type_;
		cell. x = -1;
		cell.y = -1;
		MadeMove = 0;
		CastlingL = Cells{ -1,-1 };
		CastlingR = Cells{ -1,-1 };
		direction = 0;
	}
	std::set<Cells> allowed;
	Cells cell;
	bool MadeMove=0;
	bool isWhite;
	int direction;
	Cells CastlingR;
	Cells CastlingL;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	FigureType type;
	virtual void CalculateAllowed(std::vector<std::shared_ptr<Figure>>& figures);
	virtual void CalculateAllowedForbidden(std::vector<std::shared_ptr<Figure>>& figures);
	 virtual void SetSprite(bool isWhite) = 0;
	  void SetPosition(int x_, int y_);
private:
	void SeparateForbidden();
};
#define Figures  std::vector<std::shared_ptr<Figure>>&
int FindFigure(int x, int y, Figures figures);