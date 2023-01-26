#include <iostream>

using namespace std;

class MyMsg {
public:
	enum MESSAGE {
		ERR_ALLOC,
		ERR_COPY,
		ERR_FILE_OPEN,
		WAR_FULL,
		WAR_EMPTY,
		WAR_UNKNOWN,
		WAR_INDEX,
		WAR_INIT,
		WAR_FIND,
		WAR_IS_INIT,
		WAR_LOST_DATA,
		TOTAL
	};

	static const char* mess_arr[TOTAL];

public:
	void mess(MESSAGE mes);
};