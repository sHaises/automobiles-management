#ifndef MASINI_H
#define MASINI_H


#include <iostream>
#include <string.h>
#include <cmath>
#include <sstream>

using namespace std;

class Masini{
protected:
    char *marca,*model,*numar_inmatriculare,*serie_sasiu;
    int pret,an_fabricatie,capacitate_motor,putere;
public:
    Masini();
    ~Masini();
    Masini(const Masini& );
    Masini& operator = (const Masini& );
    friend istream& operator >>(istream&, Masini& );
    friend ostream& operator <<(ostream&, const Masini& );
    friend bool operator == (const Masini & , const Masini& );
    friend bool operator > (const Masini&, const Masini& );
    //get
    const char* get_marca();
    const char* get_model();
    const char *get_numar();
    const char *get_serie();
    int get_an();
    int get_capacitate();
    int get_putere();
    int get_pret();
    //set
    void set_marca(const char* );
    void set_model(const char* );
    void set_serie(const char* );
    void set_numar(const char* );
    void set_pret(int );
    void set_an(int );
    void set_capacitate(int );
    void set_putere(int );


    virtual string ToString();
};

#endif // MASINI_H
