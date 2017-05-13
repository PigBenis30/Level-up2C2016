#include <vcl.h>
 // class Polygon
class PolygonObject
{
	protected:
	int x, y, r, n;

	public:
	// constructor without initialization parameters
	PolygonObject() {}
	// функция, рисующая многоугольник с заданными коордиатами
	void ShowPolygon(TCanvas *Canvas, int xp, int yp, int rp, int np)
	 {
		int xi, yi;
		x = xp;
		y = yp;
		r = rp;
		n = np;
		if (n == 0)
			return;
		else{
		xi = x + r * cos(2 * M_PI / n);
		yi = y + r * sin(2 * M_PI / n);
		Canvas->MoveTo(xi, yi);
		
		Canvas->Pen->Color=clRed;
		
		for (int i = 0; i <= n; i++) {
			xi = x + r * cos(2 * M_PI * i / n);
			yi = y + r * sin(2 * M_PI * i / n);
			Canvas->LineTo(xi, yi);
		}
		}
	 }
	 // функция, стирающая эмногоугольник
	 void HidePolygon(TCanvas *Canvas)
	 {
		Canvas->Pen->Color=clWhite;
		Canvas->Rectangle(0, 0, 600, 800);
	 }
	 // функция, двигающая многоугольник в задданные координаты
	 void MovePolygon(TCanvas *Canvas, int xn, int yn)
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
			HidePolygon(Canvas);
			x = xe;
			y = ye;
			ShowPolygon(Canvas, x, y, r, n);
			Sleep(10);
			}
	 }
	 // функция масштабирования многоугольника
	 void ScalePolygon(TCanvas *Canvas, int xn, bool isIncrease)
	 {
		for (int Count = 1; Count <= xn; Count++){
			HidePolygon(Canvas);
			if (isIncrease)
				ShowPolygon(Canvas, x, y, r + 1, n);
			else
				ShowPolygon(Canvas, x, y, r - 1, n);
			Sleep(30);
			if (r <= 0){
				ShowMessage("Фигура испарилась");
				return;
			}
		}
	 }
	 // функция, высчитывающая площадь многоугольника
	 int AreaPolygon()
	 {
		if (n == 0)
			return 0;
		else
			return n / 2 * r * r * sin(2 * M_PI / n);
	 }
	 // функция, высчитывающая периметр многоугольника
	 int PerimetrPolygon()
	 {  if (n == 0)
			return 0;
		else {
			int a = 2 * r * sin(M_PI / n);
			return a * n;
		}
	 }
	 // деструктор
	 ~PolygonObject(){}
};
