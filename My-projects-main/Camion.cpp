#include "Camion.h"
#include "Masini.h"

#include <iostream>
#include <string.h>
#include <cmath>
#define setCol(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x)
#include <windows.h>

using namespace std;

int Camion::get_masa_utila() const
{
    return masa_utila;
}

void Camion::set_masa_utila(int masa)
{
    masa_utila = masa;
}

string Camion::ToString()
{
    stringstream os;
    os << "\n";
    os << "\n";
    setCol(0x0a);
    os << "MarcaCamion: ";
    setCol(0x0f);
    os << marca;
    os << "\n";
    setCol(0x0a);
    os << "Modelul: ";
    setCol(0x0f);
    os << model;
    os << "\n";
    setCol(0x0a);
    os << "Seria sasiului: ";
    setCol(0x0f);
    os << serie_sasiu;
    os << "\n";
    setCol(0x0a);
    os << "Puterea: ";
    setCol(0x0f);
    os << putere;
    os << "\n";
    setCol(0x0a);
    os << "Anul fabricatiei: ";
    setCol(0x0f);
    os << an_fabricatie;
    os << "\n";
    setCol(0x0a);
    os << "Capacitatea motorului: ";
    setCol(0x0f);
    os << capacitate_motor;
    os << "\n";
    setCol(0x0a);
    os << "Masa utila: ";
    setCol(0x0f);
    os << masa_utila;
    os << "\n";
    setCol(0x0a);
    os << "Pretul: ";
    setCol(0x0f);
    os << pret;
    os << "\n";
    setCol(0x0a);
    os << "Numarul de inmatriculare: ";
    setCol(0x0f);
    os << numar_inmatriculare;
    os << endl;
    return os.str();
}

istream& operator >> (istream& is, Camion& t)
{
    cout << "\n";
    setCol(0x0a);
    cout << "Introduceti marca: ";
    setCol(0x0f);
    is.getline(t.marca, 100);
    cout << "\n";
    setCol(0x0a);
    cout << "Introduceti modelul: ";
    setCol(0x0f);
    is.getline(t.model, 100);
    cout << "\n";
    setCol(0x0a);
    cout << "Introduceti seria sasiului: ";
    setCol(0x0f);
    is.getline(t.serie_sasiu, 100);
    cout << "\n";
    setCol(0x0a);
    cout << "Introduceti puterea: ";
    setCol(0x0f);
    is >> t.putere;
    cout << "\n";
    setCol(0x0a);
    cout << "Introduceti anul fabricatiei: ";
    setCol(0x0f);
    is >> t.an_fabricatie;
    cout << "\n";
    setCol(0x0a);
    cout << "Introduceti capacitatea motorului: ";
    setCol(0x0f);;
    is >> t.capacitate_motor;
    cout << "\n";
    cout << "Introduceti masa utila: ";
    setCol(0x0f);;
    is >> t.masa_utila;
    cout << "\n";
    setCol(0x0a);
    cout << "Introduceti pretul: ";
    setCol(0x0f);;
    is >> t.pret;
    cout << "\n";
    setCol(0x0a);
    cout << "Introduceti numarul de inmatriculare: ";
    setCol(0x0f);
    is.ignore();
    is.getline(t.numar_inmatriculare, 100);
    
    return is;
}
ostream& operator << (ostream& os, const Camion& t)
{
    os << "\n";
    os << "\n";
    setCol(0x0a);
    os << "Marca: ";
    setCol(0x0f);
    os << t.marca;
    os << "\n";
    setCol(0x0a);
    os << "Modelul: ";
    setCol(0x0f);
    os << t.model;
    os << "\n";
    setCol(0x0a);
    os << "Seria sasiului: ";
    setCol(0x0f);
    os << t.serie_sasiu;
    os << "\n";
    setCol(0x0a);
    os << "Puterea: ";
    setCol(0x0f);
    os << t.putere;
    os << "\n";
    setCol(0x0a);
    os << "Anul fabricatiei: ";
    setCol(0x0f);
    os << t.an_fabricatie;
    os << "\n";
    setCol(0x0a);
    os << "Capacitatea motorului: ";
    setCol(0x0f);
    os << t.capacitate_motor;
    os << "\n";
    setCol(0x0a);
    os << "Masa utila: ";
    setCol(0x0f);
    os << t.masa_utila;
    os << "\n";
    setCol(0x0a);
    os << "Pretul: ";
    setCol(0x0f);
    os << t.pret;
    os << "\n";
    setCol(0x0a);
    os << "Numarul de inmatriculare: ";
    setCol(0x0f);
    os << t.numar_inmatriculare;
    os << endl;
    return os;
}