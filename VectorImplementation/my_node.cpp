#pragma warning(disable:4996)

#include <iostream>
#include <fstream>

#include "my_node.h"

using namespace std;

// ------ CONSTRUCTORS ------
MyNode::MyNode(int num, const char* st, double xx, double yy) : MyCoord(xx, yy) {
	number = num;
	strcpy(name, st);
}

MyNode::MyNode(const MyNode& obj) : MyCoord(obj.x, obj.y) {
	number = obj.number;
	strcpy(name, obj.name);
}

MyNode::MyNode() {
	number = 0;
	char abc[4] = "abc";
	strcpy(name, abc);
}

// ------ OPERATOR OVERLOADING ------
MyNode& MyNode::operator = (const MyNode& obj) {
	x = obj.x;
	y = obj.y;
	number = obj.number;
	strcpy(name, obj.name);
	return *this;
}

bool MyNode::operator == (const MyNode& obj) const {
	if (x == obj.x && y == obj.y && number == obj.number) {
		return strcmp(name, obj.name) == 0;
	}
	return false;
}

bool MyNode::operator == (const int num) const {
	if (number == num) {
		return true;
	}
	return false;
}

ostream& operator << (ostream& strm, const MyNode& obj) {
	strm << "Name: " << obj.name << " Number: " << obj.number << " x = " << obj.x << " y = " << obj.y << endl;
	return strm;
}

istream& operator >> (istream& strm, MyNode& obj) {
	strm >> obj.name >> obj.number >> obj.x >> obj.y;
	return strm;
}

ofstream& operator << (ofstream& strm, const MyNode& obj) {
	strm.write(reinterpret_cast<const char*>(&obj), static_cast<streamsize>(sizeof(MyNode)));
	return strm;
}

ifstream& operator >> (ifstream& strm, MyNode& obj) {
	strm.read(reinterpret_cast<char*>(&obj), static_cast<streamsize>(sizeof(MyNode)));
	return strm;
}

// ------ INTERFACE FUNCTIONS ------
void MyNode::node_init() {
	cout << "Name: ";
	cin >> name;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	cout << "Number: ";
	cin >> number;
}