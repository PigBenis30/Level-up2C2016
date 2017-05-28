#include <vcl.h>
//---------------------------------------------------------------------------

#ifndef hashH

#define SIZE 10

struct Stack{
	Stack* next;
	int info;
	int nElements;
};

class Table{
	public:
	Stack* hashTable;
	Table()
	{
		hashTable = new Stack[SIZE];
		for (int i = 0; i < SIZE; i++){
			hashTable[i].next = NULL;
			hashTable[i].nElements = NULL;
			hashTable[i].info = NULL;
		}
	}

	// hash-func
	int hash(int info);

	// hash-table methods:
	// add element in table
	void push(int info);

	// find elements with specified key in hash-table
	void search(int key, TMemo* Memo);

	// show hash-table
	void show(TMemo* Memo);

	// delete elements from hash-table
	~Table();

};

class MyTable: public Table{

	public:
	// to count the number of elements has hash-table with random keys does not exceed the average value
	//  all keys

	// to count average value of keys in table
	int averageValue();

	// method which show count how many elements have key which no more than average key
	int countNoMoreThanAverage();
};
#define hashH
//---------------------------------------------------------------------------
#endif
