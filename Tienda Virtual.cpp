// Tienda Virtual.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include<cstdlib>
#include <stdio.h>
#include<stdlib.h> // esto por la libreria conio.h
#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include <windows.h>
using namespace std;
void clientes();
void buscarcliente();
void inventario();
void facturacion();
void salir();
void menu();

void gotoxy(short x, short y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//Variables Globales
char nom[20], ape[20], dir[20], telf[13], des[20], a;
int auxcc, cc, cod, auxcod, cant, i = 11, j;
float cost, pre, iva, m, st, sst, tt;
bool encontrado = false;
char auxclient[10];

int main() {
    menu();
    return 0;
    system("PAUSE");
}
void menu() {
    int opcion = 0;
    do {
        system("COLOR F");
        system("cls");
        cout << "\n\n\n";
        cout << "                         ***************************************" << endl;
        cout << "                         *     RESTAURANTE: LOS ALTOS     *" << endl;
        cout << "                         ***************************************\n\n" << endl;
        cout << " 1. CLIENTES\n" << endl;
        cout << " 2. BUSCAR CLIENTE\n" << endl;
        cout << " 3. QUIERE RECOMENDAR UN PRODUCTO AL RESTAURANTE\n" << endl;
        cout << " 4. PEDIR UNA ORDEN\n" << endl;
        cout << " 5. SALIR\n" << endl;


        cout << " ELIJA UNA OPCION: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            clientes();
            break;
        case 2:
            buscarcliente();
            break;
        case 3:
            inventario();
            break;
        case 4:
            facturacion();
            break;
        case 5:
            salir();
            break;
        default:
            cout << "¡OPCION INCORRECTA!" << endl;
        }
    } while (opcion != 5 && !GetAsyncKeyState(27));
}//Fin funcion menu
void clientes() {
    system("cls");
    ofstream escritura;
    ifstream consulta;
    bool repetido = false;
    escritura.open("clientes.txt", ios::out | ios::app);
    consulta.open("clientes.txt", ios::in);
    if (escritura.is_open() && consulta.is_open()) {
        cout << "\t\t\t\t************************************************************\n";
        cout << "\t\t\t\t*                         CLIENTES                         *\n";
        cout << "\t\t\t\t************************************************************\n\n";
        cout << "\t\tINGRESE LA CEDULA DE CIUDADANIA: ";
        cin >> auxcc;
        consulta >> cc;
        while (!consulta.eof()) {
            consulta >> nom >> ape >> dir >> telf;
            if (cc == auxcc) {
                system("cls");
                system("COLOR 4");
                cout << "\n\n\n\n\n\n\n\n\n\n";
                cout << "\t\t\t\t*************************************************************\n";
                cout << "\t\t\t\t*                     YA EXISTE CLIENTE                     *\n";
                cout << "\t\t\t\t*************************************************************\n";
                cout << "\n\n\n\n\n\n";
                system("PAUSE");
                repetido = true;
                break;
            }
            consulta >> cc;
        }
        if (repetido == false) {
            system("cls");
            cout << "NOMBRE: ";
            cin >> nom;
            cout << "APELLIDO: ";
            cin >> ape;
            cout << "DIRECCION: ";
            cin >> dir;
            cout << "TELEFONO: ";
            cin >> telf;
            escritura << auxcc << " " << nom << " " << ape << " " << dir << " " << telf << endl;
            system("cls");
            system("COLOR A");
            cout << "Registro Ageragado" << endl;
            system("PAUSE");
        }

    }
    else {
        system("cls");
        system("COLOR 4");
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t**************************************************************\n";
        cout << "\t\t\t\t*   Error, el Archivo No se Pudo Abrir o No ha sido Creado   *\n";
        cout << "\t\t\t\t**************************************************************\n";
        cout << "\n\n\n\n\n\n";
        system("PAUSE");
    }
    escritura.close();
    consulta.close();
}//Fin funcion CLIENTES
void buscarcliente() {
    system("cls");
    ifstream lectura;//Creamos la variable de tipo lectura
    lectura.open("clientes.txt", ios::out | ios::in);//Abrimos el archivo
    //validando la apertura del archivo
    encontrado = false;
    if (lectura.is_open()) {
        cout << "\t\t\t\t************************************************************\n";
        cout << "\t\t\t\t*                      BUSCAR CLIENTES                     *\n";
        cout << "\t\t\t\t************************************************************\n\n";
        cout << "CEDULA DE CIUDADANIA: ";
        cin >> auxcc;
        lectura >> cc;//lectura adelantada

        while (!lectura.eof()) {
            lectura >> nom >> ape >> dir >> telf;//leyendo los campos del registro, Comparar cada registro para ver si es encontrado
            if (auxcc == cc) {
                system("cls");
                cout << "\t\t\t\t************************************************************\n";
                cout << "\t\t\t\t*                      BUSCAR CLIENTES                     *\n";
                cout << "\t\t\t\t************************************************************\n\n";
                cout << "\n\n\n";
                cout << "\t\t\t\t------------------------------------------------------------\n";
                cout << "\t\t\t\tCEDULA DE CIUDADANIA:\t\t" << cc << endl;
                cout << "\t\t\t\tNOMBRE:\t\t\t\t" << nom << endl;
                cout << "\t\t\t\tAPELLIDO:\t\t\t" << ape << endl;
                cout << "\t\t\t\tDIRECCION:\t\t\t" << dir << endl;
                cout << "\t\t\t\tTELEFONO:\t\t\t" << telf << endl;
                cout << "\t\t\t\t------------------------------------------------------------\n";
                encontrado = true;
                cout << "\n\n\n\n\n\n";
                system("PAUSE");
            }

            lectura >> cc;//lectura adelantada
        }
        if (encontrado == false) {
            system("cls");
            system("COLOR 4");
            cout << "\n\n\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t*************************************************************\n";
            cout << "\t\t\t\t*                   No Existe Tal Registros                 *\n";
            cout << "\t\t\t\t*************************************************************\n";
            cout << "\n\n\n\n\n\n";
            system("PAUSE");
            cout << " " << auxcc << endl;
        }
    }
    else {
        system("cls");
        system("COLOR 4");
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t*************************************************************\n";
        cout << "\t\t\t\t*    No se pudo Abrir el Archivo, aun no ha sido Creado     *\n";
        cout << "\t\t\t\t*************************************************************\n";
        cout << "\n\n\n\n\n\n";
        system("PAUSE");
    }
    //cerrando el archivo
    lectura.close();
}//fin de funcion BUSCAR
void inventario() {
    system("cls");
    ofstream escritura;
    ifstream consulta;
    bool repetido = false;
    escritura.open("inventario.txt", ios::out | ios::app);
    consulta.open("inventario.txt", ios::in);
    if (escritura.is_open() && consulta.is_open()) {
        cout << "\t\t\t\t************************************************************\n";
        cout << "\t\t\t\t* RECOMENDAR COMIDA  (INVENTARIO DE COMIDAS RECOMENDADAS) *\n";
        cout << "\t\t\t\t************************************************************\n\n";
        cout << "\t\tINGRESE EL CODIGO DEL PRODUCTO: ";
        cin >> auxcod;
        consulta >> cod;
        while (!consulta.eof()) {
            consulta >> des >> cost >> pre >> iva;
            if (cod == auxcod) {
                system("cls");
                system("COLOR 4");
                cout << "\n\n\n\n\n\n\n\n\n\n";
                cout << "\t\t\t\t*************************************************************\n";
                cout << "\t\t\t\t*                    YA EXISTE EL PRODUCTO                  *\n";
                cout << "\t\t\t\t*************************************************************\n";
                cout << "\n\n\n\n\n\n";
                system("PAUSE");
                repetido = true;
                break;
            }
            consulta >> cod;
        }
        if (repetido == false) {
            system("cls");
            cout << "DESCRIPCION: ";
            cin >> des;
            cout << "COSTO: ";
            cin >> cost;
            cout << "PRECIO: ";
            cin >> pre;
            cout << "IVA: ";
            cin >> iva;
            escritura << auxcod << " " << des << " " << cost << " " << pre << " " << iva << endl;
            system("cls");
            system("COLOR A");
            cout << "Producto Ageragado Satisfactorimente" << endl;
            system("PAUSE");
        }

    }
    else {
        system("cls");
        system("COLOR 4");
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t**************************************************************\n";
        cout << "\t\t\t\t*   Error, el Archivo No se Pudo Abrir o No ha sido Creado   *\n";
        cout << "\t\t\t\t**************************************************************\n";
        cout << "\n\n\n\n\n\n";
        system("PAUSE");
    }
    escritura.close();
    consulta.close();
}//Fin funcion CLIENTES
void facturacion() {
    system("cls");
    int num = 0;
    int suma = 0;
    ofstream escritura;
    ifstream consulta1;
    ifstream consulta2;
    bool repetido = false;
    escritura.open("ventas.txt", ios::out | ios::app);
    consulta1.open("clientes.txt", ios::in);
    consulta2.open("inventario.txt", ios::in);
    if (escritura.is_open() && consulta1.is_open() && consulta2.is_open()) {
        cout << "\t\t\t\t***********************************************************\n";
        cout << "\t\t\t\t*                       PEDIDO ORDEN                       *\n";
        cout << "\t\t\t\t***********************************************************\n\n";
        cout << "\t\tINGRESE LA CEDULA DE CIUDADANIA: ";
        cin >> auxcc;
        consulta1 >> cc;
        while (!consulta1.eof()) {
            consulta1 >> nom >> ape >> dir >> telf;
            if (cc == auxcc) {
                system("cls");
                gotoxy(0, 0);
                cout << "***********************";
                gotoxy(0, 1);
                cout << "* Gracias *";
                gotoxy(0, 2);
                cout << "***********************";
                gotoxy(1, 4);
                cout << " RAZON SOCIAL: " << nom << " " << ape << endl;
                gotoxy(1, 5);
                cout << " DIRECCION: " << dir;
                gotoxy(1, 6);
                cout << " TELEFONO: " << telf;
                gotoxy(0, 8);
                cout << "-----------------------------------------------------------------------------------------------------------------";
                gotoxy(0, 9);
                cout << " INGRESASTE AL SISTEMA DE PEDIDOS  |\n";
                gotoxy(0, 10);
                cout << "-----------------------------------------------------------------------------------------------------------------\n";
                gotoxy(1, 11);
                int almuerzo;
                int almuerzoQty;
                int refrescos;
                int refrescosQty;
                double hamburguesa = 25.00;
                double Spaghetti = 30.00;
                double Pollo = 75.00;
                double CantidadDeVentahamburguesa = 0;
                double CantidadDeVentaSpaghetti = 0;
                double CantidadDeVentaPollo = 0;
                double Cocacola = 15.75;
                double it = 20.50;
                double CantidadDeVentaCocacola = 0;
                double CantidadDeVentaIt = 0;
                double cash;
                double total = 0;
                double subtotal = 0;
                double iva;


                cout << "\n\t RESTAURANTE: LOS ALTOS\t\n\n";
                cout << "\t\t =Almuerzo= \t\n\n";

                cout << " [1] hamburguesa..............Dolares 25.00\n [2] Spaghetti...........Dolares 30.00 \n [3] Pollo w/ arroz.....Dolares 75.00\n\n";

                cout << "Cuales seran sus almuerzos: ";
                cin >> almuerzo;
                cout << "Cuantos?: ";
                cin >> almuerzoQty;

                cout << "\t\t =Bebidas= \t\t\n\n";

                cout << " [1] Cocacola................Dolares 15.75\n [2] Jugo de fruta............Dolares 20.50\n\n";
                cout << "Cual va a ser sus refrescos: ";
                cin >> refrescos;
                cout << "Cuantos?: ";
                cin >> refrescosQty;

                cout << "\n\t      =Elemento ordenado=\t\t\n\n";

                switch (almuerzo)
                {
                case 1:
                    cout << " hamburguesa..............Dolares 25.00 X " << almuerzoQty << " = " << almuerzoQty * hamburguesa << "\n";
                    CantidadDeVentahamburguesa = almuerzoQty * hamburguesa;
                    break;

                case 2:
                    cout << " Spaghetti...........Dolares 30.00 X " << almuerzoQty << " = " << almuerzoQty * Spaghetti << "\n";
                    CantidadDeVentaSpaghetti = almuerzoQty * Spaghetti;
                    break;

                case 3:   cout << " Pollo y/ arroz.....Dolares 75.00 X " << almuerzoQty << " = " << almuerzoQty * Pollo << "\n";
                    CantidadDeVentaPollo = almuerzoQty * Pollo;
                    break;

                }
                {
                    switch (refrescos)
                    {
                    case 1:
                        cout << " Cocacola................Dolares 15.75 X " << refrescosQty << " = " << refrescosQty * Cocacola << "\n\n";
                        CantidadDeVentaCocacola = refrescosQty * Cocacola;
                        break;

                    case 2:
                        cout << " Jugo de fruta............Dolares 20.50 X " << refrescosQty << " = " << refrescosQty * it << "\n\n";
                        CantidadDeVentaIt = refrescosQty * it;
                        break;
                    }


                    subtotal = 0;
                    subtotal = subtotal + CantidadDeVentahamburguesa + CantidadDeVentaSpaghetti + CantidadDeVentaPollo + CantidadDeVentaCocacola + CantidadDeVentaIt;
                    iva = CantidadDeVentahamburguesa * CantidadDeVentaSpaghetti * CantidadDeVentaPollo * CantidadDeVentaCocacola * CantidadDeVentaIt * 0.13 / 100;
                    total = subtotal + iva;

                    cout << "//////////////////////////FACTURA//////////////////////////" << endl;
                    cout << "////////               LOS ALTOS              " << endl;
                    cout << "Total a pagar es (con iva): " << total << "\n";

                    cout << "Efectivo: ";
                    cin >> cash;
                    cout << "Cambio: " << cash - total << "\n\n";


                    cout << "Disfruta tu comida!\n\n\n";
                    cout << "\n\n\t-----------------------\n";
                    cout << "\t  Por Caleb Lackwood Mejia y Josue Lackwood Mejia";
                    cout << "\n\tTecnicas de programacion\n";
                    cout << "\t-----------------------\n";


                }



                cout << "-----------------------------------------------------------------------------------------------------------------\n";
                consulta2 >> cod;




                system("PAUSE");
                repetido = true;
                break;
            }
            consulta1 >> cc;
        }
        if (repetido == false) {
            system("cls");
               cout<<"NOMBRE: ";
               cin>>nom;
               cout<<"APELLIDO: ";
               cin>>ape;
               cout<<"DIRECCION: ";
               cin>>dir;
               cout<<"TELEFONO: ";
               cin>>telf;


               escritura<<auxcc<<" "<<nom<<" "<<ape<<" "<<dir<<" "<<telf<<endl;
               system("cls");
               system("COLOR A");
               cout<<"Registro Ageragado"<<endl;
               system("PAUSE");
        }

    }
    else {
        system("cls");
        system("COLOR 4");
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t**************************************************************\n";
        cout << "\t\t\t\t*   Error, el Archivo No se Pudo Abrir o No ha sido Creado   *\n";
        cout << "\t\t\t\t**************************************************************\n";
        cout << "\n\n\n\n\n\n";
        system("PAUSE");
    }
    escritura.close();
    consulta1.close();
    consulta2.close();
}//Fin funcion FACTURACION

void salir() {
    system("cls");
    system("COLOR 2");
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t************************************************************\n";
    cout << "\t\t\t\t*              ¡GRACIAS POR USAR EL PROGRAMA!              *\n";
    cout << "\t\t\t\t************************************************************\n";
    cout << "\n\n\n\n\n\n";
    system("PAUSE");


}
