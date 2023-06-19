#pragma once
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

class Entidad
{
protected:
	int x, y;
	int x1, y1;
	int dx, dy;
	int ancho, alto;
	int IDx;
public:
	Entidad()
	{
		x = y = 0;
		x1 = y1 = 0;
		dx = dy = 0;
		ancho = alto = 0;
		IDx = 0;
	}

	void SetDX(int value)
	{
		dx = value;
	}
	void SetDY(int value)
	{
		dy = value;
	}

	Rectangle Area()
	{
		return Rectangle(x, y, ancho, alto);
		return Rectangle(x1, y1, ancho, alto);
	}
	Rectangle NextArea()
	{
		return Rectangle(x + dx, y + dy, ancho, alto);
		return Rectangle(x1 + dx, y1 + dy, ancho, alto);
	}

	virtual void Mover(Graphics^ g)
	{
		x += dx;
		y += dy;
		x1 += dx;
		y1 += dy;
	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->FillRectangle(Brushes::Black, Area());
	}
};
