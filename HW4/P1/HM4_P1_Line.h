#ifndef LINE_H
#define LINE_H

class point;
class Line {
private:
	point* p1;
	point* p2;
	double m;   // slope
	double len;   // length
public:
	Line();
	Line(double x1, double y1, double x2, double y2);
	Line(const Line&);
	~Line();
	Line& operator=(const Line&);
	void setVertex1(point);
	point getVertex1() const {	return *p1;	}
	void setVertex2(point);
	point getVertex2() const {	return *p2;	}
	double getSlope() const {	return this->m;	}
	double getLength() const {	return this->len;	}
	bool parallel(const Line&, const Line&);
	friend bool operator<(const Line&, const Line&);
	friend bool operator==(const Line&, const Line&);
	friend bool operator>(const Line&, const Line&);
	friend std::istream& operator>>(std::istream&, Line&);
	friend std::ostream& operator<<(std::ostream&, const Line&);
};

#endif