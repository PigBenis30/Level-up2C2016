#include<vcl.h>
//---------------------------------------------------------------------------

#ifndef opzH

struct Stack{
	char info;
	Stack* next;
};

class Poland{
	public:
	double array[201];
	Stack* begin;
	Set <char, 0, 255> znak;

	Poland()
	{
		begin = NULL;
	}

	int prior(char);
	Stack* inStack(char);
	Stack* outStack(char*);
	double rezult(String);
	~Poland();


};

#define opzH
//---------------------------------------------------------------------------
#endif
