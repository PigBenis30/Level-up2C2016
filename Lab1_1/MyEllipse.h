#include <vcl.h>
 // class Ellipsñ
class Ellipse
{
	protected:
	int x_, y_, aAxis_, bAxis_;

	public:
	// constructor without initialization parameters
	Ellipse() {}
	// func which draw ellipse on screen
	void showEllipse(TCanvas *Canvas, int xe, int ye, int ae, int be)
	 {
		x_ = xe;
		y_ = ye;
		aAxis_ = ae;
		bAxis_ = be;
		Canvas->Pen->Color=clRed;
		Canvas->Ellipse(x_ - aAxis_, y_ - bAxis_, x_ + aAxis_, y_ + bAxis_);
	 }
	 // func which hide ellipse
	 void hideEllipse(TCanvas *Canvas)
	 {
		Canvas->Pen->Color=clWhite;
		Canvas->Rectangle(0, 0, 600, 800);
	 }
	 // func which move ellipse on specified coordinates 
	 void moveEllipse(TCanvas *Canvas, int xn, int yn)
	 {
		int xe = x_, ye = y_;
		bool isAvaible = true;

		while(isAvaible) {
			isAvaible = false;
			if (xn - xe > 0 && xe != xn) {
				xe++;
				isAvaible = true;
			}
			if (xn - xe < 0 && xe != xn) {
				xe--;
				isAvaible = true;
			}
			if (yn - ye > 0 && ye != yn) {
				ye++;
				isAvaible = true;
			}
			if (yn - ye < 0 && ye != yn) {
				ye--;
				isAvaible = true;
			}

			hideEllipse(Canvas);
			x_ = xe;
			y_ = ye;
			showEllipse(Canvas, x_, y_, aAxis_, bAxis_);
			Sleep(10);
		}
	 }
	 // func which scale ellipse 
	 void scaleEllipse(TCanvas *Canvas, int xn, bool isIncrease)
	 {
		for (int Count = 1; Count <= xn; Count++){
			hideEllipse(Canvas);
			if (isIncrease)
				ShowEllipse(Canvas, x_, y_, aAxis_ + 1, bAxis_ + 1);
			else
				ShowEllipse(Canvas, x_, y_, aAxis_ - 1, bAxis_ - 1);
			Sleep(30);
			if (aAxis_ <= 0 || bAxis_ <= 0){
				ShowMessage("Фигура испарилась");
				return;
			}
		}
	 }
	 // func which find ellipse area
	 int computeArea()
	 {
		 return aAxis_ * bAxis_ * M_PI;
	 }
	 // func which find ellipse perimetr
	 int computePerimetr()
	 {
		if (( aAxis_ + bAxis_) == 0)
			return 0;
		else
			return 4 * (M_PI * aAxis_ * bAxis_ + (aAxis_ - bAxis_)) / (aAxis_ + bAxis_);
	 }
	 // destructor
	 ~Ellipse(){}
};
