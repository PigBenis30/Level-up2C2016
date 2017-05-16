#include <vcl.h>
//---------------------------------------------------------------------------

#ifndef StationH

using namespace std;

struct Element{
	 int number, hourDeparture, minuteDeparture, hourArrive, minuteArrive;
	 String destination;
	 String type;
	 Element* next;
};

class Bus{
	Element* head_;
	Element* first_;
	public:

	// constructor
	Bus(){
		head_ = NULL;
		first_ = head_;
	}

	// method which add first element in list
	void addFirstBus(int number, int hourDeparture, int minuteDeparture, int hourArrive, int minuteArrive, String destination, String type);

	// method which add new element in list
	void addNextBus(int number, int hourDeparture, int minuteDeparture, int hourArrive, int minuteArrive, String destination, String type);

	// method which show list on screen
	void showBus(TMemo* Memo1);

	// func which define end of list
	void endList();

	// method which show bus which go to some destination
	void comeToPlace(TMemo* Memo1, String place);

	//method which show bus which go to some destination and in time
	void comeToPlaceAndInTime(TMemo* Memo1, String place, int hour, int minute);

	void checkBusInRoad();


	// destructor
	~Bus();
};
#define StationH
//---------------------------------------------------------------------------
#endif

