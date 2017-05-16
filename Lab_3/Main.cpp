//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Bus allBuses;
Bus busesInRoad;
Bus busesInPark;
int currentHour, currentMinute;
int nBusesInRoad = 0, nBusesInPark = 0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	RadioButton1->Checked = true;
}
//---------------------------------------------------------------------------

// event handler when you click button <Exit>
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Form1->Close();
}
//---------------------------------------------------------------------------

// event handler when you click button <show timetable>
void __fastcall TForm1::Button3Click(TObject *Sender)
{

	if (ComboBox1->ItemIndex == -1 ||ComboBox1->ItemIndex == 0){
		allBuses.showBus(Form1->Memo1);
	}
	if (ComboBox1->ItemIndex == 1){
		int hour, minute;
		try
		{
			hour = StrToInt(Edit6->Text);
			minute = StrToInt(Edit9->Text);
		} catch(...)
		{
			hour = - 5;
			ShowMessage("Please enter value!");
		}
		if (hour != -5){
			allBuses.comeToPlaceAndInTime(Memo1, Edit8->Text, hour, minute);
		}
	}
	if (ComboBox1->ItemIndex == 2)
		allBuses.comeToPlace(Memo1, Edit8->Text);
	if (ComboBox1->ItemIndex == 4) {
		if (nBusesInRoad != 0)
			busesInRoad.showBus(Memo1);
		else
			Memo1->Text = "There aren't buses in road!";
	}
	if (ComboBox1->ItemIndex == 3){
		if (nBusesInPark != 0)
			busesInPark.showBus(Memo1);
		else
			Memo1->Text = "There no buses in park!";
	}

}
//---------------------------------------------------------------------------

// event handler when you click button <Add first>
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int Time[4], number;
	try
	{
		number = StrToInt(Edit5->Text);
		Time[0] = StrToInt(Edit1->Text);
		Time[1] = StrToInt(Edit2->Text);
		Time[2] = StrToInt(Edit3->Text);
		Time[3] = StrToInt(Edit4->Text);
		currentHour = StrToInt(Edit10->Text);
		currentMinute = StrToInt(Edit11->Text);
	} catch(...)
	{
		ShowMessage("Please enter a value!");
		number = -5;
	}
	if (number != -5){
		String typeBus;
		if (RadioButton1->Checked == true)
			typeBus = "City transport";
		if (RadioButton2->Checked == true)
			typeBus = "Suburban";
		if (RadioButton3->Checked == true)
			typeBus = "Intercity";
		allBuses.addFirstBus(number, Time[0], Time[1], Time[2], Time[3], Edit7->Text, typeBus);
		if (Time[0]*60 + Time[1] <= currentHour*60 + currentMinute
		 && currentHour*60 + currentMinute <= Time[2]*60 + Time[3]){
			busesInRoad.addFirstBus(number, Time[0], Time[1], Time[2], Time[3], Edit7->Text, typeBus);
			nBusesInRoad++;
		 }
		 else{
			busesInPark.addFirstBus(number, Time[0], Time[1], Time[2], Time[3], Edit7->Text, typeBus);
			nBusesInPark++;
		 }
		Button2->Enabled = false;
		Button4->Enabled = true;
		Button5->Enabled = true;
	}
}
//---------------------------------------------------------------------------

// event handler when you click button <Add next>
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int Time[4], number;
	try
	{
		number = StrToInt(Edit5->Text);
		Time[0] = StrToInt(Edit1->Text);
		Time[1] = StrToInt(Edit2->Text);
		Time[2] = StrToInt(Edit3->Text);
		Time[3] = StrToInt(Edit4->Text);
	} catch(...)
	{
		ShowMessage("Please enter a value!");
		number = -5;
	}
	if (number != -5){
		String typeBus;
		if (RadioButton1->Checked == true)
			typeBus = "City transport";
		if (RadioButton2->Checked == true)
			typeBus = "Suburban";
		if (RadioButton3->Checked == true)
			typeBus = "Intercity";
		allBuses.addNextBus(number, Time[0], Time[1], Time[2], Time[3], Edit7->Text, typeBus);
		if (Time[0]*60 + Time[1] <= currentHour*60 + currentMinute
		 && currentHour*60 + currentMinute <= Time[2]*60 + Time[3]){
			if(nBusesInRoad == 0){
				busesInRoad.addFirstBus(number, Time[0], Time[1], Time[2], Time[3], Edit7->Text, typeBus);
				nBusesInRoad++;
			}
			else{
				busesInRoad.addNextBus(number, Time[0], Time[1], Time[2], Time[3], Edit7->Text, typeBus);
				nBusesInRoad++;
			}
		 }
		 else{
			if(nBusesInPark == 0){
				busesInPark.addFirstBus(number, Time[0], Time[1], Time[2], Time[3], Edit7->Text, typeBus);
				nBusesInPark++;
			}
			else{
				busesInPark.addNextBus(number, Time[0], Time[1], Time[2], Time[3], Edit7->Text, typeBus);
				nBusesInPark++;
			}
		 }
		GroupBox5->Enabled = false;
		Button5->Enabled = true;
	}
}
//---------------------------------------------------------------------------

// event handler when you click button <End list>
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	allBuses.endList();
	try
	{
		busesInRoad.endList();
	} catch(...)
	{
		busesInRoad.addFirstBus(0, 0, 0, 0, 0, "", "");
		busesInRoad.endList();
	}
	try
	{
		busesInPark.endList();
	} catch(...)
	{
		busesInPark.addFirstBus(0, 0, 0, 0, 0, "", "");
		busesInPark.endList();
	}
	GroupBox5->Enabled = true;
	Button5->Enabled = false;
}
//---------------------------------------------------------------------------
// äîáàâèòü çàïîëíåíèå äâóõ ñïèñêîâ.

// event handler when you choose item in combobox
void __fastcall TForm1::ComboBox1Select(TObject *Sender)
{

	if (ComboBox1->ItemIndex == 1 || ComboBox1->ItemIndex == 2){
		Edit8->Enabled = true;
		if (ComboBox1->ItemIndex == 1){
			Edit6->Enabled = true;
			Edit9->Enabled = true;
		}
		else{
			Edit6->Enabled = false;
			Edit9->Enabled = false;
		}
	}
	else {
		Edit6->Enabled = false;
		Edit8->Enabled = false;
		Edit9->Enabled = false;
	}
	if (ComboBox1->ItemIndex == 3 || ComboBox1->ItemIndex == 4){
		GroupBox6->Enabled = true;
	}
	else
		GroupBox6->Enabled = false;
}
//---------------------------------------------------------------------------

// event handler when you change edit 6
void __fastcall TForm1::Edit6Change(TObject *Sender)
{
	try
	{
		if (StrToInt(Edit6->Text) >= 24){
			ShowMessage("Please enter right hour value!");
			Edit6->Clear();
		}
	} catch(...){}
}
//---------------------------------------------------------------------------

// event handler when you change edit 9
void __fastcall TForm1::Edit9Change(TObject *Sender)
{
	try
	{
		if (StrToInt(Edit9->Text) >= 60){
			ShowMessage("Please enter right minute value!");
			Edit9->Clear();
		}
	}catch(...){}
}
//---------------------------------------------------------------------------

// event handler when you change edit 1
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
	try
	{
		if (StrToInt(Edit1->Text) >= 24){
			ShowMessage("Please enter right hour value!");
			Edit1->Clear();
		}
	} catch(...){}
}
//---------------------------------------------------------------------------

// event handler when you change edit 2
void __fastcall TForm1::Edit2Change(TObject *Sender)
{
	try
	{
		if (StrToInt(Edit2->Text) >= 60){
			ShowMessage("Please enter right minute value!");
			Edit2->Clear();
		}
	}catch(...){}
}
//---------------------------------------------------------------------------

// event handler when you change edit 3
void __fastcall TForm1::Edit3Change(TObject *Sender)
{
	try
	{
		if (StrToInt(Edit3->Text) >= 24){
			ShowMessage("Please enter right hour value!");
			Edit3->Clear();
		}
	} catch(...){}
}
//---------------------------------------------------------------------------

// event handler when you change edit 4
void __fastcall TForm1::Edit4Change(TObject *Sender)
{
	try
	{
		if (StrToInt(Edit4->Text) >= 60){
			ShowMessage("Please enter right minute value!");
			Edit4->Clear();
		}
	}catch(...){}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit10Change(TObject *Sender)
{
	try
	{
		if (StrToInt(Edit10->Text) >= 24){
			ShowMessage("Please enter right hour value!");
			Edit10->Clear();
		}
	} catch(...){}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit11Change(TObject *Sender)
{
	try
	{
		if (StrToInt(Edit11->Text) >= 60){
			ShowMessage("Please enter right minute value!");
			Edit11->Clear();
		}
	}catch(...){}
}
//---------------------------------------------------------------------------

