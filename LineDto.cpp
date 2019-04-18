class LineDto
{
public:
	LineDto() :firstX(0), firstY(0), secondX(0), secondY(0) {};
	LineDto(int x1, int y1, int x2, int y2) :firstX(x1+20), firstY(y1 + 20), secondX(x2 + 20), secondY(y2 + 20) {};
	int firstX;
	int secondX;
	int firstY;
	int secondY;
private:

};
