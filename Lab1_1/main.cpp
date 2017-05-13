//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm2 *Form2;

EllipseObject AEllipse;
RectangleObject ARectangle;
PolygonObject APolygon;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner): TForm(Owner)
{
	RadioButton4->Checked = true;
}
//---------------------------------------------------------------------------
// event handler when you click on <Нарисовать>
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	AEllipse.HideEllipse(Canvas);
	if (RadioButton1->Checked == true) {
		AEllipse.ShowEllipse(Canvas, StrToInt(Edit1->Text), StrToInt(Edit2->Text), StrToInt(Edit3->Text), StrToInt(Edit4->Text));
		Edit8->Text = FloatToStr(AEllipse.AreaEllipse());
		Edit9->Text = IntToStr(AEllipse.PerimetrEllipse());
	}

	 if (RadioButton2->Checked == true) {
		ARectangle.ShowRectangle(Canvas, StrToInt(Edit1->Text), StrToInt(Edit2->Text), StrToInt(Edit3->Text), StrToInt(Edit4->Text));
		Edit8->Text = FloatToStr(ARectangle.AreaRectangle());
		Edit9->Text = IntToStr(ARectangle.PerimetrRectangle());
	}

	if (RadioButton3->Checked == true) {
		 APolygon.ShowPolygon(Canvas, StrToInt(Edit1->Text), StrToInt(Edit2->Text), StrToInt(Edit10->Text), StrToInt(Edit7->Text));
		 Edit8->Text = FloatToStr(APolygon.AreaPolygon());
		 Edit9->Text = IntToStr(APolygon.PerimetrPolygon());
	}
}
//---------------------------------------------------------------------------
// event handler when you click on <Очистить>
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	AEllipse.HideEllipse(Canvas);
}
// event handler when you click on <Переместить>
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	if (RadioButton1->Checked == true) {
		AEllipse.MoveEllipse(Canvas, StrToInt(Edit5->Text), StrToInt(Edit6->Text));
	}

	if (RadioButton2->Checked == true) {
		ARectangle.MoveRectangle(Canvas, StrToInt(Edit5->Text), StrToInt(Edit6->Text));
	}

	if (RadioButton3->Checked == true) {
		APolygon.MovePolygon(Canvas, StrToInt(Edit5->Text), StrToInt(Edit6->Text));
	}
}
//---------------------------------------------------------------------------
// event handler when you click on RadioButton <Многоугольник>
void __fastcall TForm2::RadioButton3Click(TObject *Sender)
{
	GroupBox7->Enabled = false;
	Edit7->Enabled = true;
	Edit10->Enabled = true;
}
//---------------------------------------------------------------------------
// event handler when you click on RadioButton <Эллипс>
void __fastcall TForm2::RadioButton1Click(TObject *Sender)
{
	GroupBox7->Enabled = false;
	Edit7->Enabled = false;
	Edit10->Enabled = false;
}
//---------------------------------------------------------------------------
// event handler when you click on RadioButton <Прямоугольник>
void __fastcall TForm2::RadioButton2Click(TObject *Sender)
{
	GroupBox7->Enabled = true;
	Edit7->Enabled = false;
	Edit10->Enabled = false;
}
//---------------------------------------------------------------------------
/// event handler when you click on <Масштабировать>
void __fastcall TForm2::Button4Click(TObject *Sender)
{
	if (RadioButton1->Checked == true) {
		if (RadioButton4->Checked == true)
			AEllipse.ScaleEllipse(Canvas, StrToInt(Edit11->Text), true);
		if (RadioButton5->Checked == true)
			AEllipse.ScaleEllipse(Canvas, StrToInt(Edit11->Text), false);
	}

	if (RadioButton3->Checked == true) {
		if (RadioButton4->Checked == true)
			APolygon.ScalePolygon(Canvas, StrToInt(Edit11->Text), true);
		if (RadioButton5->Checked == true)
			APolygon.ScalePolygon(Canvas, StrToInt(Edit11->Text), false);
	}

	if (RadioButton2->Checked == true) {
		if (RadioButton4->Checked == true)
			ARectangle.ScaleRectangle(Canvas, StrToInt(Edit11->Text), true);
		if (RadioButton5->Checked == true)
			ARectangle.ScaleRectangle(Canvas, StrToInt(Edit11->Text), false);
	}
}
//---------------------------------------------------------------------------
// event handler when you click on <Выход>
void __fastcall TForm2::Button6Click(TObject *Sender)
{
	Form2->Close();
}
//---------------------------------------------------------------------------
// event handler when you click on <Поворот>
void __fastcall TForm2::Button5Click(TObject *Sender)
{
	if (RadioButton2->Checked == true) {
		ARectangle.RotateRectangle(Canvas, StrToInt(Edit12->Text));
	}
}
//---------------------------------------------------------------------------


