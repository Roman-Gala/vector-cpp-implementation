#include <iostream>
#include <fstream>

#include "my_msg.h"

using namespace std;

template <typename T>
class MyVect {
private:
	T* data_ptr;                                        // Data pointer
	size_t size;                                       // Array size
	int last;                                         // Last array index in use
	MyMsg msg;

public:
	MyVect(size_t siz);                                 // Parametrized constructor
	MyVect() : data_ptr(NULL), size(0), last(-1) {}    // Default constructor
	~MyVect();                                        // Destructor

	// Getters
	T* get_first() { if (last != -1) return &data_ptr[0]; return NULL; }
	T* get_last() { if (last != -1) return &data_ptr[last]; return NULL; }

	// Vector functions
	void push(const T& elem);
	T* pop();
	void erase(const T& elem);
	void clear_all();

	// Operator overloading
	T& operator [] (const int index);
	friend ostream& operator << <>(ostream& strm, const MyVect<T>& vec);
	friend ofstream& operator << <>(ofstream& strm, const MyVect<T>& vec);
	friend ifstream& operator >> <>(ifstream& strm, MyVect<T>& vec);

private:
	void realloc_v();
	void alloc(size_t siz);
	void dealloc();
};


// ------ OPERATOR OVERLOADING ------
template <typename T>
T& MyVect<T>::operator [] (const int index) {
	if (index >= 0 && index <= last && last != -1) {
		return &data_ptr[index];
	}
	else {
		msg.mess(msg.WAR_INDEX);
		return NULL;
	}
}

template <typename T>
ostream& operator << <>(ostream& strm, const MyVect<T>& vec) {
	for (int i = 0; i <= vec.last; i++) {
		strm << "[" << i << "] " << vec.data_ptr[i] << endl;
	}
	return strm;
}

template <typename T>
ofstream& operator << <>(ofstream& strm, const MyVect<T>& vec) {
	strm.write(reinterpret_cast<const char*>(&vec.last), static_cast<streamsize>(sizeof(int)));
	for (int i = 0; i <= vec.last; i++) {
		strm << vec.data_ptr[i];
	}
	return strm;
}

template <typename T>
ifstream& operator >> <>(ifstream& strm, MyVect<T>& vec) {
	int siz;
	strm.read(reinterpret_cast<char*>(&siz), static_cast<streamsize>(sizeof(int)));
	if (strm.bad() || strm.fail()) {
		vec.msg.mess(vec.msg.ERR_FILE_OPEN);
	}
	vec.alloc(siz + 2);
	vec.last = siz;

	for (int i = 0; i <= siz; i++) {
		strm >> vec.data_ptr[i];
		if (strm.bad() || strm.fail()) {
			vec.msg.mess(vec.msg.ERR_FILE_OPEN);
		}
	}
	return strm;
}


// ------ CONSTRUCTOR AND DESTRUCTOR ------
template <typename T>
MyVect<T>::MyVect(size_t siz) {
	alloc(siz);
	last = -1;
}

template <typename T>
MyVect<T>::~MyVect() {
	delete[] data_ptr;
	data_ptr = NULL;
}

// ------ VECTOR FUNCTIONS ------
template <typename T>
void MyVect<T>::push(const T& elem) {
	last++;
	if (last + 1 == size) {
		msg.mess(msg.WAR_FULL);
		realloc_v();
	}
	data_ptr[last] = elem;
}

template <typename T>
T* MyVect<T>::pop() {
	if (last == -1) {
		msg.mess(msg.WAR_EMPTY);
		return NULL;
	}
	last--;
	return &data_ptr[last + 1];
}

template <typename T>
void MyVect<T>::erase(const T& elem) {
	if (last < 0) {
		msg.mess(msg.WAR_EMPTY);
		return;
	}
	int i = 0;
	for (i; i <= last; i++) {
		if (data_ptr[i] == elem) {
			break;
		}
	}
	if (i > last) {
		msg.mess(msg.WAR_FIND);
		return;
	}
	for (i; i < last; i++) {
		data_ptr[i] = data_ptr[i + 1];
	}
	last--;
	cout << "Erased\n" << elem << endl;
}

template <typename T>
void MyVect<T>::clear_all() {
	if (last != -1) {
		delete[] data_ptr;
		data_ptr = new T[size];
		last = -1;
		cout << "Vector cleared.\n";
	}
}

// ------ PRIVATE METHODS ------
template <typename T>
void MyVect<T>::realloc_v() {
	T* temp_ptr = NULL;
	size++;
	temp_ptr = (T*)realloc((void*)data_ptr, size * sizeof(T));
	if (!temp_ptr) {
		msg.mess(msg.ERR_ALLOC);
	}
	data_ptr = temp_ptr;
	temp_ptr = NULL;
}

template <typename T>
void MyVect<T>::alloc(size_t siz) {
	if (data_ptr) {
		dealloc();
	}
	try {
		data_ptr = new T[siz];
	}
	catch (bad_alloc) {
		msg.mess(msg.ERR_ALLOC);
	}
	size = siz;
	last = siz - 2;
}

template <typename T>
void MyVect<T>::dealloc() {
	if (data_ptr) {
		delete[] data_ptr;
	}
	data_ptr = NULL;
	last = -1;
}