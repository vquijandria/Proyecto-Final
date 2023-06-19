#pragma once
#include "Jugador.h"
#include "Obstaculo.h"
#include "Meta.h"

ref class ControladorJuego
{
private:
	Jugador* objJugador;
	Obstaculos* obstaculos;
	Metas* meta;

	Bitmap^ imgTransparente30x45;
	Bitmap^ imgJugador;
	Bitmap^ imgMeta;
	Graphics^ canvas;

public:
	ControladorJuego()
	{
		imgTransparente30x45 = gcnew Bitmap("img/transparente30x45.png");
		imgJugador = gcnew Bitmap("img/jugador.png");
		imgMeta = gcnew Bitmap("img/trol.png");
		//fondo = gcnew Bitmap(gcnew System::String("img/Normal.png"));

		objJugador = new Jugador(imgJugador);
		obstaculos = new Obstaculos(1, objJugador->Area(), imgTransparente30x45);
		meta = new Metas(1, objJugador->Area(), imgMeta);

	}
	~ControladorJuego()
	{
		delete objJugador, obstaculos, meta;
		delete imgTransparente30x45, imgMeta;
	}

	void MovimientoJugador(bool accion, Keys tecla)
	{
		int v = 3;

		if (accion == true)
		{
			if (tecla == Keys::W)
			{
				objJugador->SetDY(-v);
				objJugador->SetAccion(CaminarArriba);
			}
			else if (tecla == Keys::S)
			{
				objJugador->SetDY(v);
				objJugador->SetAccion(CaminarAbajo);
			}
			else if (tecla == Keys::A)
			{
				objJugador->SetDX(-v);
				objJugador->SetAccion(CaminarIzquierda);
			}
			else if (tecla == Keys::D)
			{
				objJugador->SetDX(v);
				objJugador->SetAccion(CaminarDerecha);
			}
		}
		else
		{
			if (tecla == Keys::W)
				objJugador->SetDY(0);
			else if (tecla == Keys::S)
				objJugador->SetDY(0);
			else if (tecla == Keys::A)
				objJugador->SetDX(0);
			else if (tecla == Keys::D)
				objJugador->SetDX(0);
		}
	}
	bool Llegar(Graphics^ g)
	{
		if (meta->Colision(objJugador->NextArea()) == true)
			objJugador->Mover(g);

		meta->Mover(g);
		return 0;
	}
	void Mover(Graphics^ g)
	{
		if (obstaculos->Colision(objJugador->NextArea()) == false)
			objJugador->Mover(g);

		obstaculos->Mover(g);
	}
	void Mostrar(Graphics^ g)
	{
		objJugador->Mostrar(g, imgJugador);
		obstaculos->Mostrar(g, imgTransparente30x45);
		meta->Mostrar(g, imgMeta);
	}
};