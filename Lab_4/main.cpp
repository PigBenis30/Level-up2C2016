//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

PolandNotate node;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

// event handler when you click button <Translate>
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	char ss, a;
	String inStr, outStr;   	OutStr = "";
	Edit2->Text = "";
	InStr = Edit1->Text;
	node.znak << '*' << '/' << '+' << '-' << '^';
	int len = InStr.Length(), k;
	for (k = 1; k <= len; k++) {
	ss = InStr[k];
		if ( ss == '(' ) node.begin = node.inStack(ss); 
		if ( ss == ')' ) {
			while ( (node.begin -> info) != '(' ) { 
				node.begin = node.outStack(&a);
				outStr += a; 
		}
		node.begin = node.outStack(&a); 
	}
		if (ss >= 'a' && ss <= 'z' ) outStr += ss;  // 
		if (node.znak.Contains(ss)) {   
			while ( node.begin != NULL && node.prior (node.begin->info) >=  node.prior (ss) ) {
				node.begin = node.outStack(&a);
				outStr += a;
			}
		node.begin = node.inStack(ss);
		}
	}

	while ( node.begin != NULL){
		node.begin = node.outStack(&a);
		outStr += a;    
	}
	Edit2->Text = OutStr;
}

//---------------------------------------------------------------------------

// event handler when you click button <Calculate>
void __fastcall TForm1::Button2Click(TObject *Sender) 
{
	char ch;
	String outStr = Edit2->Text;
    	try
	{
		for (int i = 0; i < 5; i++) {
			ch = StringGrid1->Cells[i][0][1];
			node.array[int(ch)] = StrToFloat(StringGrid1->Cells[i][1]);

		}
		Edit3->Text=FloatToStr(node.rezult(outStr));
	} catch(...)
	{
		ShowMessage("Please enter value!");
	}
}
//---------------------------------------------------------------------------

// event handler when form was created
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Edit1->Text = "(a-b)/(c+d)*e";
	Edit2->Text = "";
	char a = 'a';
	for(int i = 0; i<StringGrid1->ColCount; i++) {
		StringGrid1->Cells[i][0] = a++;
	}
}
//---------------------------------------------------------------------------

