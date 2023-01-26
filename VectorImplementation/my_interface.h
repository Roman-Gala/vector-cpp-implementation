#include <iostream>

#include "my_vect.h"
#include "my_node.h"

using namespace std;

class MyInterface {
public:
	enum INTERFACE {
		INTER_INIT,
		INTER_PUSH,
		INTER_POP,
		INTER_ERASE,
		INTER_MODIFY,
		INTER_FIND,
		INTER_DISP_LAST,
		INTER_DISP_VECT,
		INTER_CLEAR,
		INTER_SAVE,
		INTER_LOAD,
		INTER_EXIT,
		INTER_TOTAL
	};

	static const char* inter_arr[INTER_TOTAL];
	MyMsg msg;

private:
	MyVect<MyNode>* vector;                                // TYPE

public:
	bool run;

public:
	// Constructor, destructor
	MyInterface();
	~MyInterface();

	// Interface functions
	void menu();
	void init();
	void push();
	void pop();
	void erase();
	void clear();
	void find_elem();
	void save();
	void load();
	void modify();
	void exit_intr();
	void default_intr();
	void disp_last();
	void disp_vect();

private:
	// Private methods
	bool is_init();
};

// ------ FIND FUNCTION ------
template <typename T, typename K>
T* my_find(T* st, T* end, K key);