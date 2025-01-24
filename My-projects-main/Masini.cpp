#include "Masini.h"

#include <bits/stdc++.h>
#include <string.h>
#include <cmath>
#define setCol(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x)
#include <windows.h>
#include <sstream>

using namespace std;


Masini::Masini()
{
    this->marca = new char[100];
    this->model = new char[100];
    this->numar_inmatriculare = new char[100];
    this->serie_sasiu = new char[100];

}

Masini::~Masini()
{
    if (model != NULL)
        delete [] model;
    if (marca != NULL)
        delete [] marca;
    if (numar_inmatriculare != NULL)
        delete [] numar_inmatriculare;
    if (serie_sasiu != NULL)
        delete[] serie_sasiu;

}

Masini::Masini(const Masini& t)
{
    this->model = new char[strlen(t.model) + 1];
    this->marca = new char[strlen(t.marca) + 1];
    this->numar_inmatriculare = new char[strlen(t.numar_inmatriculare) + 1];
    this->serie_sasiu = new char[strlen(t.serie_sasiu)+1];
    this->pret = t.pret;
    this->putere = t.putere;
    this -> an_fabricatie = t.an_fabricatie;
    this -> capacitate_motor = t.capacitate_motor;
    strcpy(this->model, t.model);
    strcpy(this->marca, t.marca);
    strcpy(this->numar_inmatriculare, t.numar_inmatriculare);
    strcpy(this ->serie_sasiu,t.serie_sasiu);
}

Masini& Masini::operator=(const Masini& t)
{
    if (&t == this)
        return *this;
    else
    {
        this->pret = t.pret;
        this->an_fabricatie = t.an_fabricatie;
        this->putere = t.putere;
        this->capacitate_motor = t.capacitate_motor;
        strcpy(this->model, t.model);
        strcpy(this->marca, t.marca);
        strcpy(this->numar_inmatriculare, t.numar_inmatriculare);
        strcpy(this ->serie_sasiu,t.serie_sasiu);
        return *this;
    }
}

istream& operator >> (istream& is, Masini& t)
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
ostream& operator << (ostream& os, const Masini& t)
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

string Masini::ToString()
{
    stringstream os;
    os << "\n";
    os << "\n";
    setCol(0x0a);
    os << "Marca: ";
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


bool operator ==(const Masini& t1, const Masini& t2)
{
    if (strcmp(t1.marca, t2.marca) == 0)
        return true;
    else
        return false;
}

bool operator >(const Masini& t1, const Masini& t2)
{
    if (strcmp(t1.model, t2.model) > 0)
        return true;
    else
        return false;
}
//get
int Masini::get_pret()
{
    return this->pret;
}
const char* Masini::get_marca()
{
    return this->marca;
}
const char* Masini::get_model()
{
    return this->model;
}
const char* Masini::get_numar() {
    return this->numar_inmatriculare;
}
const char *Masini::get_serie() {
    return this->serie_sasiu;
}
int Masini::get_putere() {
    return this->putere;
}
int Masini ::get_an() {
    return this->an_fabricatie;
}
int Masini ::get_capacitate() {
    return this->capacitate_motor;
}
//set
void Masini::set_marca(const char* marca)
{
    if (this->marca != NULL)
        delete [] this->marca;
    this->marca = new char[strlen(marca) + 1];
    strcpy(this->marca, marca);
}
void Masini::set_model(const char* model)
{
    if (this->model != NULL)
        delete [] this->model;
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
}
void Masini::set_serie(const char* serie)
{
    if (this->serie_sasiu != NULL)
        delete [] this->serie_sasiu;
    this->serie_sasiu = new char[strlen(serie) + 1];
    strcpy(this->serie_sasiu, serie);
}
void Masini::set_numar(const char* numar)
{
    if (this->numar_inmatriculare != NULL)
        delete [] this->numar_inmatriculare;
    this->numar_inmatriculare = new char[strlen(numar) + 1];
    strcpy(this->numar_inmatriculare, numar);
}
void Masini::set_pret(int pret)
{
    this->pret = pret;
}
void Masini::set_putere(int putere)
{
    this->putere = putere;
}
void Masini::set_capacitate(int capacitate)
{
    this->capacitate_motor = capacitate;
}
void Masini::set_an(int an)
{
    this->an_fabricatie = an;
}
