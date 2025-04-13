#ifndef _POINT_HPP_
#define _POINT_HPP_

class Point
{
public:
	Point() = default;
	Point(int x, int y) : x(x), y(y) {}
	Point(const Point&) = default;
	~Point() = default;
	int x = 0;
	int y = 0;
};

#endif // _POINT_HPP_
