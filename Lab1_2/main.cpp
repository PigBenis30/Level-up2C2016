//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

DoSmoke ATrain;

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	ATrain.ShowTrain(Canvas);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Canvas->Brush->Color = clGray;
	ATrain.ProduceSmoke(Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    ATrain.RemoveSmoke(Canvas, 120, 180);
}
//---------------------------------------------------------------------------

