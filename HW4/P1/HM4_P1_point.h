#ifndef POINT_H
#define POINT_H

class point {
private:
	double x;
	double y;
public:
	point(double X=0, double Y=0): x(X), y(Y) {}
	void setX(double x) { this->x=x; }
	double getX() const { return this->x;}
	void setY(double y) { this->y=y; }
	double getY() const { return this->y;}
	friend std::istream& operator>>(std::istream&, point&);
	friend std::ostream& operator<<(std::ostream&, const point&);
};

#endif