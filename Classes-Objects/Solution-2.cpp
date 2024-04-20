#include <iostream>
#include <cmath>
using namespace std;

class Point{
	double coord_x,coord_y;

public:
	Point(double coord_x, double coord_y):coord_x(coord_x), coord_y(coord_y){}

double distance(const Point &other)const{
	double p,q;

	p= coord_x - other.coord_x
	
	q= coord_y - other.coord_y
	
	return sqrt((p*p)-(q*q))

}


};



int main(){



}
