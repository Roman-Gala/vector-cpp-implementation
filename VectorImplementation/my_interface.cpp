#include <iostream>

#include "my_interface.h"

using namespace std;

// ------ FIND FUNCTION ------
template <typename T, typename K>
T* my_find(T* st, T* end, K key) {
	if (st && end) {
		T* retval;
		end++;
		for (st; st < end; st++) {
			if (*st == key) {
				retval = st;
				return retval;
			}
		}
	}
	return NULL;
}

// ------ STATIC MEMBER DEFINITION ------
const char* MyInterface::inter_arr[] = {
	"Initialize vector",
	"Push element",
	"Pop element",
	"Erase element",
	"Modify element",
	"Find element",
	"Display last element",
	"Display vector",
	"Clear vector",
	"Save vector to binary file",
	"Load vector from binary file",
	"Exit"
};

// ------ CONSTRUCTOR, DESTRUCTOR ------
MyInterface::MyInterface() {
	run = true;
	vector = NULL;
}

MyInterface::~MyInterface() {
	if (vector) {
		delete vector;
	}
	vector = NULL;
}

// ------ PRIVATE METHODS ------
bool MyInterface::is_init() {
	if (!vector) {
		msg.mess(msg.WAR_INIT);
		return false;
	}
	return true;
}

// ------ INTERFACE FUNCTIONS ------
void MyInterface::menu() {
	cout << endl;
	for (int i = 0; i < INTER_TOTAL; i++) {
		cout << "  " << i + 1 << ". \t" << inter_arr[i] << endl;
	}
}

void MyInterface::init() {
	if (vector) {
		msg.mess(msg.WAR_IS_INIT);
		return;
	}
	size_t size;
	cout << "Vector size: ";
	cin >> size;
	vector = new MyVect<MyNode>(size);                     // TYPE
	if (!vector) {
		msg.mess(msg.ERR_ALLOC);
	}
	cout << "Vector initialized with size: " << size << endl;
}

void MyInterface::push() {
	if (!is_init()) {
		init();
	}
	MyNode elem;
	cout << "Push\n";                                    // TYPE
	elem.node_init();
	vector->push(elem);
}

void MyInterface::pop() {
	if (!is_init()) {
		return;
	}
	MyNode* elem;                                          // TYPE
	elem = vector->pop();
	if (elem) {
		cout << "Popped\n" << *elem << endl;
	}
}

void MyInterface::erase() {
	if (!is_init()) {
		return;
	}
	MyNode crit;                                         // TYPE
	cout << "Erase criteria\n";
	crit.node_init();
	vector->erase(crit);
}

void MyInterface::clear() {
	if (!is_init()) {
		return;
	}
	vector->clear_all();
}

void MyInterface::find_elem() {
	if (!is_init()) {
		return;
	}
	int elem;
	cout << "Search criteria (number): ";                            // TYPE
	cin >> elem;
	int count = 0;
	MyNode* fd = my_find(vector->get_first(), vector->get_last(), elem);
	if (!fd) {
		msg.mess(msg.WAR_FIND);
	}
	while (fd) {
		count++;
		cout << count << '.' << "Element found\n" << *fd << endl;
		fd++;
		if (fd == vector->get_last()) {
			break;
		}
		fd = my_find(fd, vector->get_last(), elem);
	}
}

void MyInterface::save() {
	if (!is_init()) {
		return;
	}
	string file_name;
	cout << "File name: ";
	cin >> file_name;
	ofstream fl(file_name, ios::binary);

	if (!fl.is_open()) {
		msg.mess(msg.ERR_FILE_OPEN);
	}

	fl << *vector;
	cout << "Saved vector to file.\n";
	fl.close();
}

void MyInterface::load() {
	if (!is_init()) {
		cout << "Initializing vector...\n";
		vector = new MyVect<MyNode>(1);                     // TYPE
		if (!vector) {
			msg.mess(msg.ERR_ALLOC);
		}
		cout << "Vector initialized." << endl;
	}
	string file_name;
	msg.mess(msg.WAR_LOST_DATA);
	cout << "Do you want to continue? (y/n): ";
	char ans;
	cin >> ans;
	if (ans != 'y') {
		return;
	}
	cout << "File name : ";
	cin >> file_name;
	ifstream fl(file_name, ios::binary);

	if (!fl.is_open()) {
		msg.mess(msg.ERR_FILE_OPEN);
	}

	fl >> *vector;
	cout << "Loaded vector from file\n";
	fl.close();
}

void MyInterface::exit_intr() {
	run = false;
}

void MyInterface::default_intr() {
	msg.mess(msg.WAR_UNKNOWN);
}

void MyInterface::disp_last() {
	if (!is_init()) {
		return;
	}
	MyNode* last = vector->get_last();                      // TYPE
	if (!last) {
		msg.mess(msg.WAR_EMPTY);
		return;
	}
	cout << "Last element\n" << *last << endl;
}

void MyInterface::disp_vect() {
	if (!is_init()) {
		return;
	}
	if (!vector->get_last()) {
		msg.mess(msg.WAR_EMPTY);
		return;
	}
	cout << *vector;
}

void MyInterface::modify() {
	if (!is_init()) {
		return;
	}
	MyNode elem;
	cout << "Search criteria\n";                            // TYPE
	elem.node_init();
	int count = 0;
	MyNode* fd = my_find(vector->get_first(), vector->get_last(), elem);
	if (!fd) {
		msg.mess(msg.WAR_FIND);
	}
	else {
		cout << "Element found: " << *fd << endl;
	}
	fd->node_init();
}