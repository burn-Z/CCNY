#include <iostream>

#include "point.hpp"

using namespace std;

int main() {
	point p0;
	point p1(3,6);
	point p2(-1,-3);
	pair <double,double> P(6,3);
	pair <double,double> Q(0,0);

	point a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
//////////////////////////////////////////////////////////////////
	cout << "p0 = ";
	p0.print();

	cout << "p1 = ";
	p1.print();

	cout << "p2 = ";
	p2.print();

	cout << "P = (" << P.first << "," << P.second << ")" << endl;
	cout << "Q = (" << Q.first << "," << Q.second << ")" << endl;

	cout << "================================" << endl;
	cout << "Arithmetic Operators" << endl;
///////////////////////////////////////////////////////////////////
	a = p1 + p2;
	b = P + p2;
	c = p1 + P;

	cout << "p1 + p2 = ";
	a.print();

	cout << "(" << P.first << "," << P.second << ") + p2 = ";
	b.print();

	cout << "p1 + (" << P.first << "," << P.second << ") = ";
	c.print();
	cout << endl;
///////////////////////////////////////////////////////////////////
	d = p2 - p1;
	e = P - p2;
	f = p1 - P;

	cout << "p2 - p1 = ";
	d.print();

	cout << "(" << P.first << "," << P.second << ") - p2 = ";
	e.print();

	cout << "p1 - (" << P.first << "," << P.second << ") = ";
	f.print();
	cout << endl;
///////////////////////////////////////////////////////////////////
	g = p1 * p2;
	h = P * p2;
	i = p1 * P;

	cout << "p1 * p2 = ";
	g.print();

	cout << "(" << P.first << "," << P.second << ") * p2 = ";
	h.print();

	cout << "p1 * (" << P.first << "," << P.second << ") = ";
	i.print();
	cout << endl;
///////////////////////////////////////////////////////////////////
	j = p1 / p2;
	k = p1 / Q;
	l = P / p2;

	cout << "p1 / p2 = ";
	j.print();

	cout << "p1 / (" << Q.first << "," << Q.second << ") = ";
	k.print();

	cout << "(" << P.first << "," << P.second << ") / p2 = ";
	l.print();
///////////////////////////////////////////////////////////////////
	cout << "================================" << endl;
	cout << "Comparison Operators" << endl;
//////////////////////////////////////////////////////////////////
	cout << "p1 == p2\t" << (p1==p2) << endl;
	cout << "p0 == (" << Q.first << "," << Q.second << ")\t"
		 << (p0==Q) << endl;
	cout << "(" << P.first << "," << P.second << ") == p2\t"
		 << (P==p2) << endl;
	cout << endl;
//////////////////////////////////////////////////////////////////
	cout << "p1 != p2\t" << (p1!=p2) << endl;
	cout << "p0 != (" << Q.first << "," << Q.second << ")\t"
		 << (p0!=Q) << endl;
	cout << "(" << P.first << "," << P.second << ") != p2\t"
		 << (P!=p2) << endl;
	cout << endl;
//////////////////////////////////////////////////////////////////
	cout << "p1 < p2 \t" << (p1<p2) << endl;
	cout << "p0 < (" << Q.first << "," << Q.second << ")\t"
		 << (p0<Q) << endl;
	cout << "(" << P.first << "," << P.second << ") < p2\t"
		 << (P<p2) << endl;
	cout << endl;
//////////////////////////////////////////////////////////////////
	cout << "p1 > p2 \t" << (p1>p2) << endl;
	cout << "p0 > (" << Q.first << "," << Q.second << ")\t"
		 << (p0>Q) << endl;
	cout << "(" << P.first << "," << P.second << ") > p2\t"
		 << (P>p2) << endl;
	cout << endl;
//////////////////////////////////////////////////////////////////
	cout << "p1 >= p2\t" << (p1>=p2) << endl;
	cout << "p0 >= (" << Q.first << "," << Q.second << ")\t"
		 << (p0>=Q) << endl;
	cout << "(" << P.first << "," << P.second << ") >= p2\t"
		 << (P>=p2) << endl;
	cout << endl;
//////////////////////////////////////////////////////////////////
	cout << "p1 <= p2\t" << (p1<=p2) << endl;
	cout << "p0 <= (" << Q.first << "," << Q.second << ")\t"
		 << (p0<=Q) << endl;
	cout << "(" << P.first << "," << P.second << ") <= p2\t"
		 << (P<=p2) << endl;
///////////////////////////////////////////////////////////////////
	cout << "================================" << endl;
	cout << "Increment Operators" << endl;
//////////////////////////////////////////////////////////////////
	point pi(3,4);
	point ip(1,2);

	cout << "pi = ";
	pi.print();

	cout << "ip = ";
	ip.print();

	m = pi++;
	n = ++ip;

	cout << "\npi++ = ";
	m.print();

	cout << "++ip = ";
	n.print();
//////////////////////////////////////////////////////////////////
	cout << "================================" << endl;
	cout << "Decriment Operators" << endl;
//////////////////////////////////////////////////////////////////
	point pd(2,3);
	point dp(6,-1);

	cout << "pd = ";
	pd.print();

	cout << "dp = ";
	dp.print();

	o = pd--;
	p = --dp;

	cout << "\npd-- = ";
	o.print();

	cout << "--dp = ";
	p.print();

	return 0;
}