#include <vcl.h>
 // class Polygon
class Polygon
{
	protected:
	int x_, y_, radius_, nSides_;

	public:
	// constructor without initialization parameters
	Polygon() {}
	// func which draw polygon
	void showPolygon(TCanvas *Canvas, int xp, int yp, int rp, int np)
	 {
		int xi, yi;
		x_ = xp;
		y_ = yp;
		radius_ = rp;
		nSides_ = np;
		if (np == 0)
			return;
		else{
		xi = x_ + radius * cos(2 * M_PI / nSides_);
		yi = y_ + radius * sin(2 * M_PI / nSides_);
		Canvas->MoveTo(xi, yi);
		
		Canvas->Pen->Color=clRed;
		
		for (int i = 0; i <= nSides_; i++) {
			xi = x_ + radius * cos(2 * M_PI * i / nSides_);
			yi = y_ + radius * sin(2 * M_PI * i / nSides_);
			Canvas->LineTo(xi, yi);
		}
		}
	 }
	 // func which hide polygon from screen
	 void hidePolygon(TCanvas *Canvas)
	 {
		Canvas->Pen->Color=clWhite;
		Canvas->Rectangle(0, 0, 600, 800);
	 }
	 // func which move polygon on specified coordinates
	 void movePolygon(TCanvas *Canvas, int xn, int yn)
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
			hidePolygon(Canvas);
			x_ = xe;
			y_ = ye;
			showPolygon(Canvas, x_, y_, radius_, nSides_);
			Sleep(10);
			}
	 }
	 // func which scale polygon
	 void scalePolygon(TCanvas *Canvas, int xn, bool isIncrease)
	 {
		for (int Count = 1; Count <= xn; Count++){
			hidePolygon(Canvas);
			if (isIncrease)
				showPolygon(Canvas, x_, y_, radius_ + 1, nSides_);
			else
				showPolygon(Canvas, x_, y_, radius_ - 1, nSides_);
			Sleep(30);
			if (radius_ <= 0){
				ShowMessage("Фигура испарилась!");
				return;
			}
		}
	 }
	 // func which find polygon area
	 int computeArea()
	 {
		if (nSides_ == 0)
			return 0;
		else
			return nSides_ / 2 * radius_ * radius_ * sin(2 * M_PI / nSides_);
	 }
	 // func which find polygon perimetr
	 int computePerimetr()
	 {  if (nSides_ == 0)
			return 0;
		else {
			int temp = 2 * radius_ * sin(M_PI / nSides_);
			return temp * nSides_;
		}
	 }
	 // destructor
	 ~PolygonObject(){}
};
