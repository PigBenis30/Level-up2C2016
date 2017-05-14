#include <vcl.h>
// class Rectangle
class Rectangle
{
	 private:
	 int x_, y_, aAxis_, bAxis_;

	 public:
	 // constructor without initialization parameters
	 Rectangle() {}
	 // func which draw rectangle on screen
	  void showRectangle(TCanvas *Canvas, int xr, int yr, int ar, int br)
	 {
		x_ = xr;
		y_ = yr;
		aAxis_ = ar;
		bAxis_ = br;
		Canvas->Pen->Color=clRed;
		Canvas->Rectangle(x_ - aAxis_, y_ - bAxis_, x_ + aAxis_, y_ + bAxis_);
	 }
	 // func which hide rectangle from screen
	 void hideRectangle(TCanvas *Canvas)
	 {
		Canvas->Pen->Color=clWhite;
		Canvas->Rectangle(0, 0, 600, 800);
	 }
	  // func which move rectangle on specified coordinates 
	 void moveRectangle(TCanvas *Canvas, int xn, int yn)
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

			hideRectangle(Canvas);
			x = xe;
			y = ye;
			showRectangle(Canvas, x_, y_, aAxis_, bAxis_);
			Sleep(10);
			}
	 }
	 // func which scale rectangle
	 void scaleRectangle(TCanvas *Canvas, int xs, bool isIncrease)
	 {
		for (int i = 1; i <= xs; i++){
			HideRectangle(Canvas);
			if (isIncrease){
				showRectangle(Canvas, x_, y_, aAxis_ + 1, bAxis_ + 1);
			}
			else
				showRectangle(Canvas, x_, y_, aAxis_ - 1, bAxis_ - 1);
			Sleep(30);
			if (aAxis_ <= 0 || bAxis_ <= 0){
				ShowMessage("Фигура испарилась");
				return;
			}
		}
	 }
	 // func which show rotate rectangle	
	 void showRotateRectangle(TCanvas *Canvas,int x1_new, int x2_new, int x3_new, int x4_new, int y1_new, int y2_new, int y3_new, int y4_new)
	 {
		Canvas->Pen->Color = clRed;
		Canvas->MoveTo(x1_new,y1_new);
		Canvas->LineTo(x2_new, y2_new);
		Canvas->MoveTo(x2_new,y2_new);
		Canvas->LineTo(x3_new, y3_new);
		Canvas->MoveTo(x3_new,y3_new);
		Canvas->LineTo(x4_new, y4_new);
		Canvas->MoveTo(x4_new,y4_new);
		Canvas->LineTo(x1_new, y1_new);
	 }
	 // func which calculate new coordinates of rotate rectangle
	 void rotateCalculate(int degree, int x1_old, int x2_old, int x3_old, int x4_old, int y1_old, int y2_old,
	  int y3_old, int y4_old, int xo, int yo, int *x1_new, int *x2_new, int *x3_new, int *x4_new,
	   int *y1_new, int *y2_new, int *y3_new, int *y4_new)
	 {
		if (degree > 360)
			degree = degree - 360;
		double sina = sin(degree * (M_PI / 180));
		double cosa = cos(degree * (M_PI / 180));
		*x1_new = ((x1_old - xo) * cosa - (y1_old - yo) * sina) + xo; 
		*y1_new = ((x1_old - xo) * sina + (y1_old - yo) * cosa) + yo;

		*x2_new = ((x2_old - xo) * cosa - (y2_old - yo) * sina) + xo;
		*y2_new = ((x2_old - xo) * sina + (y2_old - yo) * cosa) + yo;

		*x3_new = ((x3_old - xo) * cosa - (y3_old - yo) * sina) + xo;
		*y3_new = ((x3_old - xo) * sina + (y3_old - yo) * cosa) + yo;

		*x4_new = ((x4_old - xo) * cosa - (y4_old - yo) * sina) + xo;
		*y4_new = ((x4_old - xo) * sina + (y4_old - yo) * cosa) + yo;
	 }
	 // func which rotate rectangle
	 void rotateRectangle(TCanvas *Canvas, int xRotate)
	 {
		int degree = xRotate;
		for (int tempDegree = 0; tempDegree <= degree; tempDegree++){
			hideRectangle(Canvas);
			int width = 2 * aAxis_, height = 2 * bAxis_; 
			int x1 = x_ - aAxis_, y1 = x_ - bAxis_; 
			int x1_old = x1, x1_new;
			int x2_old = x1 + width, x2_new;
			int x3_old = x1 + width, x3_new;
			int x4_old = x1, x4_new;
			int y1_old = y1, y1_new;
			int y2_old = y1, y2_new;
			int y3_old = y1 + height, y3_new;
			int y4_old = y1 + height, y4_new;
			int xo = x1 + (width/2);
			int yo = y1 + (height/2);
			rotateCalculate(tempDegree, x1_old, x2_old, x3_old, x4_old, y1_old, y2_old, y3_old, y4_old, xo, yo,
			&x1_new, &x2_new, &x3_new, &x4_new, &y1_new, &y2_new, &y3_new, &y4_new);
			showRotateRectangle(Canvas,x1_new, x2_new, x3_new, x4_new, y1_new, y2_new, y3_new, y4_new);
			Sleep(50);
		}
	 }
	 // func which find rectangle area
	 int computeArea()
	 {
		 return aAxis_ * bAxis_;
	 }
	 // func which find rectangle perimetr
	 int computePerimetr()
	 {
		 return 2 * (aAxis_ + bAxis_);
	 }
	 // destructor
	 ~Rectangle(){}
};


