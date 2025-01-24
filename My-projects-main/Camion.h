#pragma once
#include "Masini.h"
#include <sstream>

using namespace std;

class Camion : public Masini
{
    int masa_utila;
public:
    Camion(){}

    int get_masa_utila() const;
    void set_masa_utila(int masa);

    friend istream& operator >>(istream&, Camion& );
    friend ostream& operator <<(ostream&, const Camion& );

    string ToString();

};