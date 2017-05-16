//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Poland node;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

// event handler when you click button <Перевести>
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	char ss, a;
	String InStr, OutStr;   // Входная и выходная строки
	OutStr = "";
	Edit2->Text = "";
	InStr = Edit1->Text;
	node.znak << '*' << '/' << '+' << '-' << '^';
	int len = InStr.Length(), k;
	for (k = 1; k <= len; k++) {
	ss = InStr[k];
		if ( ss == '(' ) node.begin = node.inStack(ss); // Открывающую скобку записываем в стек
		if ( ss == ')' ) {
			while ( (node.begin -> info) != '(' ) { //Считываем элемент из стека
				node.begin = node.outStack(&a);// Выталкиваем из стека все знаки операций до //открывающей скобки
				OutStr += a; // Записываем в строку
		}
		node.begin = node.outStack(&a); // Удаляем из стека скобку «(»
	}
		if (ss >= 'a' && ss <= 'z' ) OutStr += ss;  // Букву (операнд) заносим в выходную строку
		if (node.znak.Contains(ss)) {   // Если знак операции, то переписываем из стека в выходную строку все операции с большим или равным приоритетом
			while ( node.begin != NULL && node.prior (node.begin->info) >=  node.prior (ss) ) {
				node.begin = node.outStack(&a);
				OutStr += a;
			}
		node.begin = node.inStack(ss);
		}
	}

	while ( node.begin != NULL){
		node.begin = node.outStack(&a);
		OutStr += a;     // Если стек не пуст, переписываем все операции в выходную строку
	}
	Edit2->Text = OutStr;
}

//---------------------------------------------------------------------------

// event handler when you click button <Посчитать>
void __fastcall TForm1::Button2Click(TObject *Sender) // функция готова
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
			ShowMessage("Неправильный ввод");
	}
}
//---------------------------------------------------------------------------

// event handler when form created

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

