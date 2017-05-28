//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

MyTable table;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

// event handler when you click button <add element>
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	try
	{
		table.push(StrToInt(Edit1->Text));
	} catch (...)
	{
		 ShowMessage("Enter integer value");
		 Edit1->Clear();
	}
}
//---------------------------------------------------------------------------

// event handler when you click button <Show hash-table>
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Memo1->Clear();
	table.show(Memo1);
}
//---------------------------------------------------------------------------

// event handler when you click button <find>
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Memo1->Clear();
	table.search(StrToInt(Edit2->Text), Memo1);
}
//---------------------------------------------------------------------------

// event handler when you click button <less than average key>
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	ShowMessage(IntToStr(table.countNoMoreThanAverage()) + " elements of table which have key less than average value!");
}
//---------------------------------------------------------------------------

