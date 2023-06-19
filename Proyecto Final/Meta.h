#pragma once
#include "Entidad.h"

class Meta : public Entidad
{

public:
	Meta(Bitmap^ img)
	{
		x = 600;
		y = 200;
		ancho = img->Width;
		alto = img->Height;
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->DrawImage(img, Area());
		g->DrawRectangle(Pens::Black, Area());
	}
};

class Metas
{
private:
	vector<Meta*> metas;

public:
	Metas(int n, Rectangle obj, Bitmap^ img)
	{
		for (int i = 0; i < n; i++)
		{
			Meta* obs = new Meta(img);
			if (obs->Area().IntersectsWith(obj) == false && Colision(obs->Area()) == false)
				metas.push_back(obs);
			else
			{
				delete obs;
				i--;
			}
		}
	}
	~Metas()
	{
		for (int i = 0; i < metas.size(); i++)
			delete metas.at(i);
	}

	bool Colision(Rectangle obj)
	{
		for each (Meta * obs in metas)
		{
			if (obs->NextArea().IntersectsWith(obj))
				return true;
		}
		return false;
	}

	void Mover(Graphics^ g)
	{
		for each (Meta * obs in metas)
		{
			obs->Mover(g);
		}
	}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		for (Meta* obs : metas)
		{
			obs->Mostrar(g, img);
		}
	}

};