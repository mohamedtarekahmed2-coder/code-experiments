#include <iostream>
#include <vector>
using ll = long long;
#define nl cout << '\n'
using namespace std;

class Shape
{
protected:
	int color;

public:
	Shape(int color) : color(color) {}
	virtual ~Shape() {}
	int getColor()
	{
		return color;
	}
	void setColor(int color)
	{
		this->color = color;
	}
	virtual float getArea() = 0;
	virtual void print() = 0;
};

class Rectangle : public Shape
{
private:
	float length;
	float width;

public:
	Rectangle(int color, float length, float width) : Shape(color), length(length), width(width) {}
	float getLength()
	{
		return length;
	}
	void setLength(float length)
	{
		this->length = length;
	}
	float getWidth()
	{
		return width;
	}
	void setWidth(float width)
	{
		this->width = width;
	}
	void print() override
	{
		cout << color << ' ' << length << ' ' << width << '\n';
	}
	float getArea ()override
	{
		return length * width;
	}
};

class Square : public Shape
{
private:
	float side;

public:
	Square(int color, float side) : Shape(color), side(side) {}
	void print() override
	{
		cout << color << ' ' << side << '\n';
	}
	float getSide()
	{
		return side;
	}
	void setSide(float side)
	{
		this->side = side;
	}
	float getArea () override
	{
		return side * side;
	}
};

int main()
{
	Rectangle rec(2, 2, 2);
	Shape *shape_ptr = &rec;
	shape_ptr->print();
	cout << shape_ptr->getArea() << '\n';

	Square sq(3, 3);
	shape_ptr = &sq;
	shape_ptr->print();
	cout << shape_ptr->getArea() << '\n';
	return 0;
}
