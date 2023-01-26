#include <iostream>

#include "my_coord.h"

using namespace std;

class MyNode : public MyCoord {
private:
	int number;                                                        // Vertex number
	char name[512];                                                   // Vertex name

public:
	// Constructors
	MyNode(int num, const char* st, double xx, double yy);             // Parametrized constructor
	MyNode(const MyNode& obj);                                        // Copy constructor
	MyNode();                                                        // Default constructor

	// Inteface functions
	void node_init();

	// Operator overloading
	MyNode& operator = (const MyNode& obj);
	bool operator == (const MyNode& obj) const;
	bool operator == (const int num) const;
	friend ostream& operator << (ostream& strm, const MyNode& obj);
	friend istream& operator >> (istream& strm, MyNode& obj);
	friend ofstream& operator << (ofstream& strm, const MyNode& obj);
	friend ifstream& operator >> (ifstream& strm, MyNode& obj);
};