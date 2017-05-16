#include<vcl.h>
//---------------------------------------------------------------------------

#ifndef opzH

struct Stack{
	char info;
	Stack* next;
};

class PolandNotate{
	public:
	double array[201];
	Stack* begin;
	Set <char, 0, 255> znak;
	
	//constructor
	PolandNotate()
	{
		begin = NULL;
	}
	
	// method which define priority of operation
	int prior(char);
	
	// method which push in stack
	Stack* inStack(char);
	
	// method which gets element form stack
	Stack* outStack(char*);
	
	// mathod which calculate result
	double rezult(String);
	
	// destructor
	~PolandNotate();


};

#define opzH
//---------------------------------------------------------------------------
#endif
