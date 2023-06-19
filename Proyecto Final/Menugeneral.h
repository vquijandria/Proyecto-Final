#pragma once
#include "JuegoNormal.h"
#include "Reglasform.h"

namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Menugeneral
	/// </summary>
	public ref class Menugeneral : public System::Windows::Forms::Form
	{
	public:
		Menugeneral(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Menugeneral()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Jugar;
	protected:
	private: System::Windows::Forms::Button^ Reglas;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Menugeneral::typeid));
			this->Jugar = (gcnew System::Windows::Forms::Button());
			this->Reglas = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Jugar
			// 
			this->Jugar->Location = System::Drawing::Point(373, 207);
			this->Jugar->Name = L"Jugar";
			this->Jugar->Size = System::Drawing::Size(100, 40);
			this->Jugar->TabIndex = 0;
			this->Jugar->Text = L"Jugar";
			this->Jugar->UseVisualStyleBackColor = true;
			this->Jugar->Click += gcnew System::EventHandler(this, &Menugeneral::Jugar_Click);
			// 
			// Reglas
			// 
			this->Reglas->Location = System::Drawing::Point(373, 302);
			this->Reglas->Name = L"Reglas";
			this->Reglas->Size = System::Drawing::Size(100, 34);
			this->Reglas->TabIndex = 1;
			this->Reglas->Text = L"Reglas";
			this->Reglas->UseVisualStyleBackColor = true;
			this->Reglas->Click += gcnew System::EventHandler(this, &Menugeneral::Reglas_Click);
			// 
			// Menugeneral
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(784, 411);
			this->Controls->Add(this->Reglas);
			this->Controls->Add(this->Jugar);
			this->Name = L"Menugeneral";
			this->Text = L"Menugeneral";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Jugar_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		JuegoNormal^ Formulariojuego = gcnew JuegoNormal();
		Formulariojuego->ShowDialog();
	}
	private: System::Void Reglas_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Reglasform^ Formularioreglas = gcnew Reglasform();
		Formularioreglas->ShowDialog();
	}
	};
}
