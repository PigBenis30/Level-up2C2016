//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Station.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label9;
	TLabel *Label10;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TLabel *Label3;
	TLabel *Label6;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TGroupBox *GroupBox3;
	TEdit *Edit5;
	TEdit *Edit7;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TButton *Button1;
	TMemo *Memo1;
	TGroupBox *GroupBox4;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TComboBox *ComboBox1;
	TEdit *Edit6;
	TGroupBox *GroupBox5;
	TEdit *Edit8;
	TLabel *Label1;
	TEdit *Edit9;
	TLabel *Label7;
	TLabel *Label8;
	TGroupBox *GroupBox6;
	TEdit *Edit10;
	TEdit *Edit11;
	TLabel *Label11;
	TLabel *Label12;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall ComboBox1Select(TObject *Sender);
	void __fastcall Edit6Change(TObject *Sender);
	void __fastcall Edit9Change(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall Edit4Change(TObject *Sender);
	void __fastcall Edit10Change(TObject *Sender);
	void __fastcall Edit11Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
