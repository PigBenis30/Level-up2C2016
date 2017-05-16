//---------------------------------------------------------------------------

#pragma hdrstop

#include "Station.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Bus::addFirstBus(int number, int hourDeparture, int minuteDeparture, int hourArrive, int minuteArrive, String destination, String type)
{
	head_ = new Element;
	first_ = head_;
	head_->number = number;
	head_->hourDeparture = hourDeparture;
	head_->minuteDeparture = minuteDeparture;
	head_->hourArrive = hourArrive;
	head_->minuteArrive = minuteArrive;
	head_->destination = destination;
	head_->type = type;
	first_ = head_;
}

void Bus::addNextBus(int number, int hourDeparture, int minuteDeparture, int hourArrive, int minuteArrive, String destination, String type)
{
	head_->next = new Element;
	head_ = head_->next;
	head_->number = number;
	head_->hourDeparture = hourDeparture;
	head_->minuteDeparture = minuteDeparture;
	head_->hourArrive = hourArrive;
	head_->minuteArrive = minuteArrive;
	head_->destination = destination;
	head_->type = type;
 }

void Bus::endList()
{
	head_->next = NULL;
}

void Bus::showBus(TMemo* Memo1)
{
	Element* temp = first_;
	Memo1->Clear();
	while (temp != NULL && temp->type != ""){
		Memo1->Lines->Add(IntToStr(temp->number) + " " + temp->type + " " + temp->destination + " "
		 + IntToStr(temp->hourDeparture) + ":" + IntToStr(temp->minuteDeparture) + " "
		 + IntToStr(temp->hourArrive) + ":" + IntToStr(temp->minuteArrive));
		temp = temp->next;
	}
}

void Bus::comeToPlace(TMemo* Memo1, String place)
{
	Element* temp = first_;
	int i = 0;
	Memo1->Clear();
	while (temp != NULL){
		if (temp->destination == place){
			Memo1->Lines->Add(IntToStr(temp->number) + " " + temp->type + " " + temp->destination + " "
			+ IntToStr(temp->hourDeparture) + ":" + IntToStr(temp->minuteDeparture) + " "
			+ IntToStr(temp->hourArrive) + ":" + IntToStr(temp->minuteArrive));
			i++;
		}
		temp = temp->next;
	}
	if (i == NULL)
		ShowMessage("Äî çàäàííîãî ïóíêòà àâòîáóñû íå õîäÿò!");
}

void Bus::comeToPlaceAndInTime(TMemo* Memo1, String place, int hour, int minute)
{
	Element* temp = first_;
	int i = 0;
	Memo1->Clear();
	while (temp != NULL){
		if (temp->destination == place){
			if (temp->hourArrive*60 + temp->minuteArrive <= hour*60 + minute){
				Memo1->Lines->Add(IntToStr(temp->number) + " " + temp->type + " " + temp->destination
				 + " " + IntToStr(temp->hourDeparture) + ":" + IntToStr(temp->minuteDeparture) + " "
				 + IntToStr(temp->hourArrive) + ":" + IntToStr(temp->minuteArrive));
				 i++;
			}

		}
		temp = temp->next;
	}
	if (i == NULL)
		ShowMessage("Äî çàäàííîãî ïóíêòà àâòîáóñû íå õîäÿò èëè íå óñïåâàþò äî çàäàííîãî âðåìåíè!");
}


Bus::~Bus()
{
	while (!head_) {
		Element* temp = head_->next;
		delete head_;
		head_ = temp;
	}
}

