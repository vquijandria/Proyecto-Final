#pragma once
#include "Juego.h"

namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class JuegoNormal : public System::Windows::Forms::Form
	{
		ControladorJuego^ juego;
	public:
		JuegoNormal(void)
		{
			InitializeComponent();
			juego = gcnew ControladorJuego();
			fondo = gcnew Bitmap(gcnew System::String("img/Normal.png"));
		}

	protected:
		~JuegoNormal()
		{
			if (components)
			{
				delete components;
			}
			delete juego;
		}
	private: System::Windows::Forms::Timer^ clock;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Bitmap^ fondo;
		Jugador* objJugador;
		Obstaculos* obstaculos;
		Metas* meta;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// clock
			// 
			this->clock->Enabled = true;
			this->clock->Interval = 40;
			this->clock->Tick += gcnew System::EventHandler(this, &JuegoNormal::clock_Tick);
			// 
			// JuegoNormal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 501);
			this->Name = L"JuegoNormal";
			this->Text = L"JuegoNormal";
			this->Load += gcnew System::EventHandler(this, &JuegoNormal::JuegoNormal_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoNormal::JuegoNormal_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &JuegoNormal::JuegoNormal_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void JuegoNormal_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void clock_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);

		bf->Graphics->DrawImage(fondo, 0, 0, Rectangle(0, 0, 1000, 500), GraphicsUnit::Pixel);

		if (juego->Llegar(bf->Graphics))
		{
			clock->Enabled = false;
			MessageBox::Show("Pasas al siguiente nivel");
		}
		/*if (meta->Colision(objJugador->NextArea()) == true)
		{
			clock->Enabled = false;
			MessageBox::Show("Pasas al siguiente nivel");
		}   */
		juego->Mover(bf->Graphics);
		juego->Mostrar(bf->Graphics);

		bf->Render(g);
	}
	private: System::Void JuegoNormal_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		juego->MovimientoJugador(true, e->KeyCode);
		if (e->KeyCode == Keys::Escape) this->Close();	
	}
	private: System::Void JuegoNormal_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
	{
		juego->MovimientoJugador(false, e->KeyCode);
	}
	};
}
