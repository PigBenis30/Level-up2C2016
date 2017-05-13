//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Ellipse.h"
#include "Rectangle.h"
#include "Polygon.h"
#include <Data.DB.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button2;
	TGroupBox *GroupBox1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TGroupBox *GroupBox2;
	TLabel *Label2;
	TLabel *Label1;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label4;
	TLabel *Label3;
	TEdit *Edit3;
	TEdit *Edit4;
	TGroupBox *GroupBox3;
	TLabel *Label8;
	TEdit *Edit7;
	TGroupBox *GroupBox4;
	TLabel *Label6;
	TEdit *Edit5;
	TEdit *Edit6;
	TButton *Button3;
	TLabel *Label7;
	TGroupBox *GroupBox5;
	TEdit *Edit8;
	TLabel *Label5;
	TEdit *Edit9;
	TButton *Button1;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *Edit10;
	TGroupBox *GroupBox6;
	TRadioButton *RadioButton4;
	TRadioButton *RadioButton5;
	TEdit *Edit11;
	TLabel *Label11;
	TButton *Button4;
	TGroupBox *GroupBox7;
	TButton *Button5;
	TEdit *Edit12;
	TLabel *Label12;
	TGroupBox *GroupBox8;
	TButton *Button6;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall RadioButton3Click(TObject *Sender);
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
