//---------------------------------------------------------------------------

#pragma hdrstop

#include "opz.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Poland::~PolandNotate()
{
	while(begin != NULL){
		Stack* temp = begin->next;
		delete begin;
		begin = temp;
	}
}

Stack* PolandNotate::inStack(char in) // begin = InStack(begin, a);
{
	Stack* temp = new Stack;
	temp->info = in;
	temp->next = begin;
	return temp;
}

Stack* PolandNotate::outStack(char* out) // begin = OutStack(begin, &a);
{
	Stack *t = begin;
	*out = begin -> info;
	begin = begin -> next;
	delete t;
	return begin;
}

int PolandNotate::prior(char a)
{
	switch (a) {
		case '^': return 4;
		case '*': case '/': return 3;
		case '-': case '+': return 2;
		case '(': return 1;
	}
	return 0;
}

double PolandNotate::rezult(String str)
{
	char ch, ch1, ch2;
	double op1, op2, rez;
	znak<<'*'<<'/'<<'+'<<'-'<<'^';
	char chr = 'z' + 1;
	for(int i = 1; i <= str.Length(); i++){
		ch = str[i];
		if (!znak.Contains(ch)) begin = inStack(ch);
		else{
			begin = outStack(&ch1);
			begin = outStack(&ch2);
			op1 = array[int (ch1)];
			op2 = array[int (ch2)];
			switch (ch){
			case '+' : rez=op2+op1; break;
			case '-' : rez=op2-op1; break;
			case '*' : rez=op2*op1; break;
			case '/' : rez=op2/op1; break;
			case '^' : rez=pow(op2,op1); break;
			}
		array[int (chr)] = rez;
		begin = inStack(chr);
		chr++;
		}
	}
	return rez;
}



