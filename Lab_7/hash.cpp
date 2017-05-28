//---------------------------------------------------------------------------

#pragma hdrstop

#include "hash.h"
 Table::~Table()
 {
	for (int i = 0; i < SIZE; i++){
		hashTable[i].nElements = NULL;
		hashTable[i].info = NULL;
		while (hashTable[i].next != NULL){
			Stack* temp = hashTable[i].next->next;
			delete (hashTable[i].next);
			(hashTable[i].next) = NULL;
			hashTable[i].next = temp;
		}
		hashTable[i].next = NULL;
	}
	delete[] hashTable;
	hashTable = NULL;
 }

 int Table::hash(int info)
 {
	 if (info < 0)
			info = - info;
	 return info%SIZE;
 }

 void Table::push(int info)
 {
	int key = hash(info);
	if (hashTable[key].nElements == NULL){
		hashTable[key].info = info;
		hashTable[key].nElements++;
		return;
	}
	if (hashTable[key].info == info) {
		hashTable[key].nElements++;
		return;
	}
	if (hashTable[key].next == NULL) {
		hashTable[key].next = new Stack;
		hashTable[key].next->next = NULL;
		hashTable[key].next->info = info;
		hashTable[key].next->nElements = 1;
		return;
	}
	if (hashTable[key].next->info == info) {
		hashTable[key].next->nElements++;
		return;
	}
	Stack* temp = hashTable[key].next;
	while (temp->next) {
		if (temp->next->info == info) {
			temp->next->nElements++;
			return;
		}
		temp = temp->next;
	}
	temp->next = new Stack;
	temp->next->info = info;
	temp->next->nElements = 1;
	temp->next->next = NULL;
 }

 void Table::search(int key, TMemo* Memo)
 {
	int count = 0;
	if (hashTable[key].nElements != 0){
		Memo->Lines->Add(IntToStr(hashTable[key].info) + " (" + IntToStr(hashTable[key].nElements) + ") ");
		count++;
	}
	Stack* temp = hashTable[key].next;
	while(temp){
		Memo->Lines->Add(IntToStr(temp->info) + " (" + IntToStr(temp->nElements) + ") ");
		temp = temp->next;
		count++;
	}
	if (count == NULL) Memo->Lines->Add("No elements with key " + IntToStr(key));
 }

void Table::show(TMemo* Memo)
 {
	 int key = NULL;
	 String string = "";
	 for ( ;key < SIZE; key++){
		string += "Ключ " + IntToStr(key) + ": ";
		if (hashTable[key].nElements != NULL){
			string += IntToStr(hashTable[key].info)
			+ " (" + IntToStr(hashTable[key].nElements) + ") ";
			Stack* temp = hashTable[key].next;
			while (temp) {
				string += IntToStr(temp->info) + " (" + IntToStr(temp->nElements) + ") ";
				temp = temp->next;
			}
		}
		else string += "No elements! ";
		Memo->Lines->Add(string);
		string = "";
	 }
 }

 int MyTable::averageValue()
 {
	int averageKey = 0;
	int count = 0;
	 for (int i = 0; i < SIZE; i++){
		if (hashTable[i].nElements != 0){
			averageKey += i;
			count += hashTable[i].nElements;
		}
		Stack* temp = hashTable[i].next;
		while (temp != NULL){
			if (temp->nElements != 0){
				averageKey += i;
				count += temp->nElements;
				temp = temp->next;
			}
		}
	}
	return (!count) ? NULL : averageKey / count;
 }

 int MyTable::countNoMoreThanAverage()
 {
	int averageKey = averageValue();
	int count = 0;
	for (int i = 0; i <= averageKey; i++){
		count += hashTable[i].nElements;
		Stack* temp = hashTable[i].next;
		while (temp != NULL){
			count += temp->nElements;
			temp = temp->next;
		}
	}
	return count;
 }
//---------------------------------------------------------------------------
#pragma package(smart_init)
