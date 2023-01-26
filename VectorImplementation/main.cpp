#pragma warning(disable: 4996)

#include <iostream>

#include "my_interface.h"

using namespace std;

int main() {
	MyInterface inter;
	int operation;

	while (inter.run) {
		inter.menu();
		cout << "\nOperation: ";
		cin >> operation;
		cout << endl;
		operation--;
		switch (operation) {
		case inter.INTER_INIT:
			inter.init();
			break;
		case inter.INTER_PUSH:
			inter.push();
			break;
		case inter.INTER_POP:
			inter.pop();
			break;
		case inter.INTER_ERASE:
			inter.erase();
			break;
		case inter.INTER_CLEAR:
			inter.clear();
			break;
		case inter.INTER_FIND:
			inter.find_elem();
			break;
		case inter.INTER_SAVE:
			inter.save();
			break;
		case inter.INTER_LOAD:
			inter.load();
			break;
		case inter.INTER_EXIT:
			inter.exit_intr();
			break;
		case inter.INTER_DISP_LAST:
			inter.disp_last();
			break;
		case inter.INTER_DISP_VECT:
			inter.disp_vect();
			break;
		case inter.INTER_MODIFY:
			inter.modify();
			break;
		default:
			inter.default_intr();
			break;
		}
		cout << endl;
		system("pause");
		system("cls");
	}

	return 0;
}