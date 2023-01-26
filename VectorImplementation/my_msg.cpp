#include <iostream>

#include "my_msg.h"

using namespace std;

const char* MyMsg::mess_arr[] = {
	"ERROR: Memory allocation failed",
	"ERROR: Memory copy failed",
	"ERROR: Failed to open file",
	"WARNING: Array is full. Reallocating memory and increasing array size by 1",
	"WARNING: Array is empty",
	"WARNING: Unknown operation",
	"WARNING: Invalid index",
	"WARNING: Vector not initialized",
	"WARNING: Item not found",
	"WARNING: Vector already initialized",
	"WARNING: Your current vector data will be deleted"
};

void MyMsg::mess(MESSAGE mes) {
	cout << mess_arr[mes] << endl;
	if (mess_arr[mes][0] == 'E') {
		system("pause");
		exit(0);
	}
}