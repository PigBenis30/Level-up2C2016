//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm2 *Form2;

EllipseObject ellipse;
RectangleObject rectangle;
PolygonObject polygon;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner): TForm(Owner)
{
	RadioButton4->Checked = true;
}
//---------------------------------------------------------------------------
// event handler when you click on <Нарисовать>
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	anEllipse.hideEllipse(Canvas);
	if (RadioButton1->Checked == true) {
		ellipse.showEllipse(Canvas, StrToInt(Edit1->Text), StrToInt(Edit2->Text), StrToInt(Edit3->Text), StrToInt(Edit4->Text));
		Edit8->Text = FloatToStr(ellipse.computeArea());
		Edit9->Text = IntToStr(ellipse.computePerimetr());
	}

	 if (RadioButton2->Checked == true) {
		rectangle.showRectangle(Canvas, StrToInt(Edit1->Text), StrToInt(Edit2->Text), StrToInt(Edit3->Text), StrToInt(Edit4->Text));
		Edit8->Text = FloatToStr(rectangle.computeArea());
		Edit9->Text = IntToStr(rectangle.computePerimetr());
	}

	if (RadioButton3->Checked == true) {
		 polygon.showPolygon(Canvas, StrToInt(Edit1->Text), StrToInt(Edit2->Text), StrToInt(Edit10->Text), StrToInt(Edit7->Text));
		 Edit8->Text = FloatToStr(polygon.computeArea());
		 Edit9->Text = IntToStr(polygon.computePerimetr());
	}
}
//---------------------------------------------------------------------------
// event handler when you click on <Очистить>
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	ellipse.hideEllipse(Canvas);
}
// event handler when you click on <Переместить>
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	if (RadioButton1->Checked == true) {
		ellipse.moveEllipse(Canvas, StrToInt(Edit5->Text), StrToInt(Edit6->Text));
	}

	if (RadioButton2->Checked == true) {
		rectangle.moveRectangle(Canvas, StrToInt(Edit5->Text), StrToInt(Edit6->Text));
	}

	if (RadioButton3->Checked == true) {
		polygon.movePolygon(Canvas, StrToInt(Edit5->Text), StrToInt(Edit6->Text));
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
			ellipse.scaleEllipse(Canvas, StrToInt(Edit11->Text), true);
		if (RadioButton5->Checked == true)
			ellipse.scaleEllipse(Canvas, StrToInt(Edit11->Text), false);
	}

	if (RadioButton3->Checked == true) {
		if (RadioButton4->Checked == true)
			polygon.scalePolygon(Canvas, StrToInt(Edit11->Text), true);
		if (RadioButton5->Checked == true)
			polygon.scalePolygon(Canvas, StrToInt(Edit11->Text), false);
	}

	if (RadioButton2->Checked == true) {
		if (RadioButton4->Checked == true)
			rectangle.scaleRectangle(Canvas, StrToInt(Edit11->Text), true);
		if (RadioButton5->Checked == true)
			rectangle.scaleRectangle(Canvas, StrToInt(Edit11->Text), false);
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
		rectangle.rotateRectangle(Canvas, StrToInt(Edit12->Text));
	}
}
//---------------------------------------------------------------------------


