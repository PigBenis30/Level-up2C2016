#include <vcl.h>
 // class Ellipsс
class EllipseObject
{
	protected:
	int x, y, a, b;

	public:
	// constructor without initialization parameters
	EllipseObject() {}
	// функция, рисующая эллипс с заданными коордиатами
	void ShowEllipse(TCanvas *Canvas, int xe, int ye, int ae, int be)
	 {
		x = xe;
		y = ye;
		a = ae;
		b = be;
		Canvas->Pen->Color=clRed;
		Canvas->Ellipse(x - a, y - b, x + a, y + b);
	 }
	 // функция, стирающая эллипс
	 void HideEllipse(TCanvas *Canvas)
	 {
		Canvas->Pen->Color=clWhite;
		Canvas->Rectangle(0, 0, 600, 800);
	 }
	 // функция, двигающая эллипс в задданные координаты
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
	 // функция масштабирования эллипса
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
				ShowMessage("Фигура испарилась");
				return;
			}
		}
	 }
	 // угол поворота при вращении
	 void RotateDegree(HANDLE dc,float Degree)
	 {

	 }
	//функция вращения эллипса с заданным углом. контекст.
	 void RotateEllipse(float Degree,HDC dc)
	 {

	 }
	 // функция, высчитывающая площадь эллипса
	 int AreaEllipse()
	 {
		 return a * b * M_PI;
	 }
	 // функция, высчитывающая периметр эллипса
	 int PerimetrEllipse()
	 {
		if ((a+b) == 0)
			return 0;
		else
			return 4 * (M_PI * a * b + (a - b)) / (a + b);
	 }
	 // деструктор
	 ~EllipseObject(){}
};
