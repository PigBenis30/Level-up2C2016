#include <vcl.h>

class Train
{
	public:
	// constructor without initialization parameters
	Train(){}
	// function wich draw train
	void showTrain(TCanvas *Canvas)
	{
		Canvas->Pen->Color = clBlue;
		Canvas->Brush->Color = clRed;
		Canvas->FillRect(Rect(100, 300, 500, 370));
		Canvas->Brush->Color = clBlack;
		Canvas->Rectangle(100, 230, 500, 300);
		Canvas->Rectangle(100, 180, 250, 320);
		Canvas->Rectangle(500, 330, 590, 370);
		Canvas->Rectangle(450, 200, 480, 230);
		Canvas->Brush->Color = clMaroon;
		Canvas->Ellipse(130, 340, 200, 410);
		Canvas->Ellipse(210, 340, 280, 410);
		Canvas->Ellipse(130, 340, 200, 410);
		Canvas->Ellipse(290, 340, 360, 410);
		Canvas->Ellipse(370, 340, 440, 410);
		Canvas->Ellipse(510, 350, 570, 410);
		Canvas->MoveTo(450, 200);
		Canvas->LineTo(435, 180);
		Canvas->LineTo(495, 180);
		Canvas->LineTo(480, 200);
	}
	// destructor
	~Train(){}
};

class SmokeTrain : public Train
{
	public:
	// constructor without initialization parameters
	SmokeTrain(){}
	// function which produce smoke from train
	void produceSmoke(TCanvas *Canvas)
	{
		int y1 = 120, y2 = 180;
		while (y1 > 0){
			Canvas->FillRect(Rect(455, y1, 475, y2));
			Sleep(1000);
			y1-=40;
			removeSmoke(Canvas, y1, y2);
			y2-=40;
		}
		Canvas->FillRect(Rect(455, 120, 475, 180));
	}
	// function, which remove smoke from train
	void removeSmoke(TCanvas *Canvas, int y1, int y2)
	{
		Canvas->Brush->Color = clWhite;
		Canvas->FillRect(Rect(455, y1, 475, y2));
		Canvas->Brush->Color = clGray;
	}
	//destructor
	~SmokeTrain(){};
};
