#include <vcl.h>
 // class Ellipsñ
class EllipseObject
{
	protected:
	int x, y, a, b;

	public:
	// constructor without initialization parameters
	EllipseObject() {}
	// func which draw ellipse on screen
	void ShowEllipse(TCanvas *Canvas, int xe, int ye, int ae, int be)
	 {
		x = xe;
		y = ye;
		a = ae;
		b = be;
		Canvas->Pen->Color=clRed;
		Canvas->Ellipse(x - a, y - b, x + a, y + b);
	 }
	 // func which hide ellipse
	 void HideEllipse(TCanvas *Canvas)
	 {
		Canvas->Pen->Color=clWhite;
		Canvas->Rectangle(0, 0, 600, 800);
	 }
	 // func which move ellipse on specified coordinates 
	 void MoveEllipse(TCanvas *Canvas, int xn, int yn)
	 {
		int xe = x, ye = y;
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

			HideEllipse(Canvas);
			x = xe;
			y = ye;
			ShowEllipse(Canvas, x, y, a, b);
			Sleep(10);
		}
	 }
	 // func fich 
	 void ScaleEllipse(TCanvas *Canvas, int xn, bool isIncrease)
	 {
		for (int Count = 1; Count<=xn; Count++){
			HideEllipse(Canvas);
			if (isIncrease)
				ShowEllipse(Canvas, x, y, a + 1, b + 1);
			else
				ShowEllipse(Canvas, x, y, a - 1, b - 1);
			Sleep(30);
			if (a <= 0 || b <= 0){
				ShowMessage("Ôèãóðà èñïàðèëàñü");
				return;
			}
		}
	 }
	 // func which find ellipse area
	 int AreaEllipse()
	 {
		 return a * b * M_PI;
	 }
	 // func which find ellipse perimetr
	 int PerimetrEllipse()
	 {
		if ((a+b) == 0)
			return 0;
		else
			return 4 * (M_PI * a * b + (a - b)) / (a + b);
	 }
	 // destructor
	 ~EllipseObject(){}
};
