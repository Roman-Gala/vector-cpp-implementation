#include <iostream>

using namespace std;

class MyCoord {
protected:
	double x;
	double y;

public:
	MyCoord(double xx, double yy) { x = xx; y = yy; }
	MyCoord() { x = 0; y = 0; }
};