#include <vcl.h>
// class Rectangle
class RectangleObject
{
	 private:
	 int x, y, a, b;

	 public:
	 // constructor without initialization parameters
	 RectangleObject() {}
	 // функция, рисующая прямоугольник с заданными коордиатами
	  void ShowRectangle(TCanvas *Canvas, int xr, int yr, int ar, int br)
	 {
		x = xr;
		y = yr;
		a = ar;
		b = br;
		Canvas->Pen->Color=clRed;
		Canvas->Rectangle(x - a, y - b, x + a, y + b);
	 }
	 // функция, стирающая прямогоугольник
	 void HideRectangle(TCanvas *Canvas)
	 {
		Canvas->Pen->Color=clWhite;
		Canvas->Rectangle(0, 0, 600, 800);
	 }
	  // функция, двигающая прямоугольник в задданные координаты
	 void MoveRectangle(TCanvas *Canvas, int xn, int yn)
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

			HideRectangle(Canvas);
			x = xe;
			y = ye;
			ShowRectangle(Canvas, x, y, a, b);
			Sleep(10);
			}
	 }
	 // функция масштабирования прямоугольника
	 void ScaleRectangle(TCanvas *Canvas, int xs, bool isIncrease)
	 {
		for (int Count = 1; Count <= xs; Count++){
			HideRectangle(Canvas);
			if (isIncrease){
				ShowRectangle(Canvas, x, y, a + 1, b + 1);
			}
			else
				ShowRectangle(Canvas, x, y, a - 1, b - 1);
			Sleep(30);
			if (a <= 0 || b <= 0){
				ShowMessage("Фигура испарилась");
				return;
			}
		}
	 }
	 // функция отрисовки прямоугольника при повороте	
	 void ShowRotateRectangle(TCanvas *Canvas,int x1_new, int x2_new, int x3_new, int x4_new, int y1_new, int y2_new, int y3_new, int y4_new)
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
	 // функция расчета новых координат прямоугольника при повороте
	 void RotateCalculate(int gr, int x1_old, int x2_old, int x3_old, int x4_old, int y1_old, int y2_old,
	  int y3_old, int y4_old, int xo, int yo, int *x1_new, int *x2_new, int *x3_new, int *x4_new,
	   int *y1_new, int *y2_new, int *y3_new, int *y4_new)
	 {
		if (gr > 360)
			gr = gr - 360;
		double sina = sin(gr * (M_PI / 180));
		double cosa = cos(gr * (M_PI / 180));
		*x1_new = ((x1_old - xo) * cosa - (y1_old - yo) * sina) + xo; // расчет новых  координат
		*y1_new = ((x1_old - xo) * sina + (y1_old - yo) * cosa) + yo;

		*x2_new = ((x2_old - xo) * cosa - (y2_old - yo) * sina) + xo;
		*y2_new = ((x2_old - xo) * sina + (y2_old - yo) * cosa) + yo;

		*x3_new = ((x3_old - xo) * cosa - (y3_old - yo) * sina) + xo;
		*y3_new = ((x3_old - xo) * sina + (y3_old - yo) * cosa) + yo;

		*x4_new = ((x4_old - xo) * cosa - (y4_old - yo) * sina) + xo;
		*y4_new = ((x4_old - xo) * sina + (y4_old - yo) * cosa) + yo;
	 }
	 // функция поворота прямоугольника на заданный градус
	 void RotateRectangle(TCanvas *Canvas, int xRotate)
	 {
		int Degree = xRotate;
		for (int TempDegree = 0; TempDegree <= Degree; TempDegree++){
			HideRectangle(Canvas);
			int width = 2*a, height = 2*b; //ширина и высота прям-ка
			int x1 = x - a, y1 = x - b; //координаты верхнего левого угла
			int x1_old = x1, x1_new;
			int x2_old = x1 + width, x2_new;
			int x3_old = x1 + width, x3_new;
			int x4_old = x1, x4_new;
			int y1_old = y1, y1_new;
			int y2_old = y1, y2_new;
			int y3_old = y1 + height, y3_new;
			int y4_old = y1 + height, y4_new;
			int xo = x1+(width/2);
			int yo = y1+(height/2);
			RotateCalculate(TempDegree, x1_old, x2_old, x3_old, x4_old, y1_old, y2_old, y3_old, y4_old, xo, yo,
			&x1_new, &x2_new, &x3_new, &x4_new, &y1_new, &y2_new, &y3_new, &y4_new);
			ShowRotateRectangle(Canvas,x1_new, x2_new, x3_new, x4_new, y1_new, y2_new, y3_new, y4_new);
			Sleep(50);
		}
	 }
	 // функция, высчитывающая площадь прямоугольника
	 int AreaRectangle()
	 {
		 return a * b;
	 }
	 // функция, высчитывающая периметр прямоугольника
	 int PerimetrRectangle()
	 {
		 return 2 * (a + b);
	 }
	 // деструктор
	 ~RectangleObject(){}
};


