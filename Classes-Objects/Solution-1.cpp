#include <iostream>
using namespace std;

class Point
{
    double coord_x, coord_y;

public:

    Point(double coord_x, double coord_y) : coord_x(coord_x), coord_y(coord_y) {}
    double get_coord_x()const{return coord_x}
    double get_coord_y()const{return coord_y}
    void set_coord_x(double x){ x = coord_x; return x}
    void set_coord_y(double y){ y = coord_y; return y}
	    			


};

int main()
{
}
