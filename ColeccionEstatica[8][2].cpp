// EstructuraEstatica.cpp : Defines the entry point for the console application.
//

//importa las librerias
#include "StdAfx.h"
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
using namespace std;

/*esta es la estructura de los datos q poseen los Productos*/
typedef struct T_Producto {
	int Codigo;
	char Descripcion[50];
	float Precio;
	int Disponible;
	bool Activo;
} X;

const int Max = 100;
int Ultimo = 0;

void CapturarElemento(T_Producto &Pieza)
{
	system("CLS");
	cout << "Captura de una Pieza" << endl;
	cout << "" << endl;

	system("CLS");  
	cout << "Captura de una Pieza" << endl;  
	cout << "" << endl;
	cout << "CodidoProducto:";   
	cin >> Pieza.Codigo;  cout << "" << endl;
	cout << "DescripcionProducto:";   
	cin >> Pieza.Descripcion;  
	cout << "" << endl;
	cout << "PrecioProducto:";   
	cin >> Pieza.Precio;  
	cout << "" << endl;
	cout << "DisponibleProducto:";   
	cin >> Pieza.Disponible;  cout << "" << endl;
	Pieza.Activo = true;

}

void Listar(T_Producto Inventario[Max]) {
	system("CLS");
	int conta = 0;
	cout << "Listado de  Productos" << endl;
	for (int i = 0; i<Ultimo; i++) {
		if (Inventario[i].Activo) {
			cout << Inventario[i].Codigo << " " << Inventario[i].Descripcion << " " << Inventario[i].Precio << " "
				<< Inventario[i].Disponible << " " << endl;
			conta++;
			if (conta == 7) {
				cout << "-----------------------------------" << endl;
				cout << "Presione cualquier tecla para continuar..." << endl;
				system("pause");
				system("CLS");

				conta = 0;
			}
		}
	}
	system("pause");
}



int BuscarElemento(T_Producto Inventario[Max], int Cual)
{
	bool Encontro = false;
	int Cont = 0;

	while ((!Encontro) && (Cont<Ultimo))
	{
		if ((Inventario[Cont].Activo == true) && (Inventario[Cont].Codigo == Cual))
			Encontro = true;
		else
			Cont++;
	}

	if (Encontro == true)
		return Cont;
	else
		return -1;

}
void InsertarElemento(T_Producto Inventario[Max], T_Producto Unidad)
{
	Inventario[Ultimo] = Unidad;
	Ultimo++;
}

void BorrarElemento(T_Producto Inventario[Max], int Cual)
{
	int PorBorrar;
	PorBorrar = BuscarElemento(Inventario, Cual);

	if (PorBorrar != -1)
		Inventario[PorBorrar].Activo = false;

}


void main() {

	T_Producto PiezasFerreteria[Max];
	T_Producto Elemento;
	int opcion = 0;

	while (opcion<4) {

		system("cls");//limpia la pantalla
		cout << "******Menu principal******" << endl;
		cout << "1. Insertar Pieza" << endl;
		cout << "2. Listar Piezas " << endl;
		cout << "3. Borrar Piezas " << endl;
		cout << "4. Salir " << endl;
		cin >> opcion;//captura el numero introducido

		switch (opcion) {

		case 1:
			system("cls");
			CapturarElemento(Elemento);
			InsertarElemento(PiezasFerreteria, Elemento);
			break;

		case 2:
			system("cls");
			Listar(PiezasFerreteria);
			break;
		case 3:
			system("CLS");
			int CodigoEscogido;
			cout << "Digite el codigo del Producto a Borrar" << endl;
			cout << "" << endl;
			cout << "CodidoProducto:" << endl;
			cin >> CodigoEscogido;
			BorrarElemento(PiezasFerreteria, CodigoEscogido);
			break;

		}
	}
}
