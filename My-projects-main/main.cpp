#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <string>
#include <cmath>
#include <windows.h>
#include "Masini.h"
#include "Camion.h"
#define setCol(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x)

using namespace std;

vector<Masini*> tablou_masini(100);
int Last_Car = -1;

void Meniu_Principal();
void ScriereInFisier();

void Interschimbare(Masini &m1, Masini &m2)
{
    Masini aux;

    aux.set_marca(m1.get_marca());
    aux.set_model(m1.get_model());
    aux.set_serie(m1.get_serie());
    aux.set_putere(m1.get_putere());
    aux.set_an(m1.get_an());
    aux.set_capacitate(m1.get_capacitate());
    aux.set_pret(m1.get_pret());
    aux.set_numar(m1.get_numar());

    m1.set_marca(m2.get_marca());
    m1.set_model(m2.get_model());
    m1.set_serie(m2.get_serie());
    m1.set_putere(m2.get_putere());
    m1.set_an(m2.get_an());
    m1.set_capacitate(m2.get_capacitate());
    m1.set_pret(m2.get_pret());
    m1.set_numar(m2.get_numar());

    m2.set_marca(aux.get_marca());
    m2.set_model(aux.get_model());
    m2.set_serie(aux.get_serie());
    m2.set_putere(aux.get_putere());
    m2.set_an(aux.get_an());
    m2.set_capacitate(aux.get_capacitate());
    m2.set_pret(aux.get_pret());
    m2.set_numar(aux.get_numar());
}

void Copiere(Masini &sursa, Masini &destinatie)
{
    destinatie.set_marca(sursa.get_marca());
    destinatie.set_model(sursa.get_model());
    destinatie.set_serie(sursa.get_serie());
    destinatie.set_putere(sursa.get_putere());
    destinatie.set_an(sursa.get_an());
    destinatie.set_capacitate(sursa.get_capacitate());
    destinatie.set_pret(sursa.get_pret());
    destinatie.set_numar(sursa.get_numar());
}

void DeplasareLaDreapta(int capat)
{
    int i;
    Masini aux;
    aux.set_marca(tablou_masini[Last_Car]->get_marca());
    aux.set_model(tablou_masini[Last_Car]->get_model());
    aux.set_serie(tablou_masini[Last_Car]->get_serie());
    aux.set_putere(tablou_masini[Last_Car]->get_putere());
    aux.set_an(tablou_masini[Last_Car]->get_an());
    aux.set_capacitate(tablou_masini[Last_Car]->get_capacitate());
    aux.set_pret(tablou_masini[Last_Car]->get_pret());
    aux.set_numar(tablou_masini[Last_Car]->get_numar());
    i = Last_Car;
    while(i > capat)
    {
        Copiere(*(tablou_masini[i-1]), *(tablou_masini[i]));
        i--;
    }
    Interschimbare(aux, *(tablou_masini[capat]));

}

void OrdonareDupaModificare()
{
    int ultima_masina = Last_Car;
    for (int i = 0; i < ultima_masina; i++)
    {
        if (strcmp(tablou_masini[ultima_masina]->get_marca(), tablou_masini[i]->get_marca()) < 0)
        {
            DeplasareLaDreapta(i);
        }
        else if (strcmp(tablou_masini[ultima_masina]->get_marca(), tablou_masini[i]->get_marca()) == 0 && strcmp(tablou_masini[ultima_masina]->get_model(), tablou_masini[i]->get_model()) < 0)
        {
            DeplasareLaDreapta(i);
        }
    }
}

void Adaugare_Masina()
{
    Last_Car++;
    tablou_masini[Last_Car] = new Masini();
    cin.ignore();
    cin >> *(tablou_masini[Last_Car]);
    OrdonareDupaModificare();
    ScriereInFisier();
    Meniu_Principal();
}

void Adaugare_Camion()
{
    Last_Car++;
    tablou_masini[Last_Car] = new Camion();
    cin.ignore();
    cin >> *(tablou_masini[Last_Car]);
    OrdonareDupaModificare();
    ScriereInFisier();
    Meniu_Principal();
}

void Adaugare_()
{
    Last_Car++;
    tablou_masini[Last_Car] = new Masini();
    cin.ignore();
    cin >> *(tablou_masini[Last_Car]);
    OrdonareDupaModificare();
    ScriereInFisier();
    Meniu_Principal();
}

void Stergere_Masina()
{
    char serie[30];
    int i = 0;
    cout << "\n";
    setCol(0x0b);
    cout << "Introduceti seria sasiului masinii pe care doriti sa o stergeti: ";
    setCol(0x0f);
    cin.ignore();
    cin.getline(serie, 30);
    if (Last_Car > -1)
    {
        while (strcmp(serie, tablou_masini[i]->get_serie()) != 0 && i <= Last_Car)
        {
            i++;
        }
        if (i <= Last_Car)
        {
            while (i < Last_Car)
            {
                //deplasarea la stanga de la masina de sters + 1
                Copiere(*(tablou_masini[i + 1]), *(tablou_masini[i]));
                i++;
            }
            Last_Car--;
            setCol(0x0a);
            cout << "Stergerea a fost facuta cu succes!";
            setCol(0x0f);
            cout << "\n";
            ScriereInFisier();
            Meniu_Principal();
        }
        else
        {
            setCol(0x0c);
            cout << "Nu exista masina cu seria introdusa!";
            setCol(0x0f);
            cout << "\n";
            Meniu_Principal();
        }
    }
    else
    {
        cout << "\n";
        setCol(0x0c);
        cout << "Momentan nu exista masini in lista!";
        setCol(0x0f);
        cout << "\n";
        Meniu_Principal();
    }
}

void Actualizare_Masina()
{
    char serie[30];
    char aux[50];
    char selectie;
    int i, aux2;
    cout << "\n";
    setCol(0x0a);
    cout << "Introduceti seria masinii pe care doriti sa o actualizati: ";
    setCol(0x0f);
    cout << "\n";
    cin.ignore();
    cin.getline(serie, 30);
    if (Last_Car > -1)
    {
        i = 0;
        while (strcmp(serie, tablou_masini[i]->get_serie()) != 0 && i <= Last_Car)
        {
            i++;
        }
        if (i <= Last_Car)
        {
            cout << "\n";
            setCol(0x0a);
            cout << "Masina cautata este: ";
            setCol(0x0f);
            cout << "\n";
            cout << *(tablou_masini[i]);
            cout << "\nIntroduceti cifra corespunzatoare modificarii pe care doriti sa o faceti: \n";
            cout << "1. Marca\n2. Modelul\n3. Seria Sasiului\n4. Puterea\n5. Anul fabricatiei\n6. Capacitatea motorului\n7. Pretul\n8. Numarul de inmatriculare\n9. Vreau sa revin in meniul principal\nIntroduceti alegerea: ";
            cin >> selectie;
            switch (selectie)
            {
            case '1':
                cout << "\nIntroduceti noua marca: ";
                cin.ignore();
                cin.getline(aux, 50);
                tablou_masini[i]->set_marca(aux);
                cout << "\n";
                setCol(0x0a);
                cout << "Modificarea a fost facuta cu succes!";
                setCol(0x0f);
                cout << "\n";
                OrdonareDupaModificare();
                ScriereInFisier();
                break;
            case '2':
                cout << "\nIntroduceti noul model: ";
                cin.ignore();
                cin.getline(aux, 50);
                tablou_masini[i]->set_model(aux);
                cout << "\n";
                setCol(0x0a);
                cout << "Modificarea a fost facuta cu succes!";
                setCol(0x0f);
                cout << "\n";
                OrdonareDupaModificare();
                ScriereInFisier();
                break;
            case '3':
                cout << "\nIntroduceti noua serie de sasiu: ";
                cin.ignore();
                cin.getline(aux, 50);
                tablou_masini[i]->set_serie(aux);
                cout << "\n";
                setCol(0x0a);
                cout << "Modificarea a fost facuta cu succes!";
                setCol(0x0f);
                cout << "\n";
                ScriereInFisier();
                break;
            case '4':
                cout << "\nIntroduceti noua putere: ";
                cin >> aux2;
                tablou_masini[i]->set_putere(aux2);
                cout << "\n";
                setCol(0x0a);
                cout << "Modificarea a fost facuta cu succes!";
                setCol(0x0f);
                cout << "\n";
                ScriereInFisier();
                break;
            case '5':
                cout << "\nIntroduceti noul an de fabricatie: ";
                cin >> aux2;
                tablou_masini[i]->set_an(aux2);
                cout << "\n";
                setCol(0x0a);
                cout << "Modificarea a fost facuta cu succes!";
                setCol(0x0f);
                cout << "\n";
                ScriereInFisier();
                break;
            case '6':
                cout << "\nIntroduceti noua capacitate a motorului: ";
                cin >> aux2;
                tablou_masini[i]->set_capacitate(aux2);
                cout << "\n";
                setCol(0x0a);
                cout << "Modificarea a fost facuta cu succes!";
                setCol(0x0f);
                cout << "\n";
                ScriereInFisier();
                break;
            case '7':
                cout << "\nIntroduceti noul pret: ";
                cin >> aux2;
                tablou_masini[i]->set_pret(aux2);
                cout << "\n";
                setCol(0x0a);
                cout << "Modificarea a fost facuta cu succes!";
                setCol(0x0f);
                cout << "\n";
                ScriereInFisier();
                break;
            case '8':
                cout << "\nIntroduceti noul numar de inmatriculare: ";
                cin.ignore();
                cin.getline(aux, 50);
                tablou_masini[i]->set_numar(aux);
                cout << "\n";
                setCol(0x0a);
                cout << "Modificarea a fost facuta cu succes!";
                setCol(0x0f);
                cout << "\n";
                ScriereInFisier();
                break;
            case '9':
                break;
            default:
                cout << "\n";
                setCol(0x0c);
                cout << "Cifra introdusa nu este corecta!";
                setCol(0x0f);
                cout << "\n";
                break;
            }
            Meniu_Principal();
        }
        else
        {
            cout << "\n";
            setCol(0x0c);
            cout << "Masina cu seria introdusa nu exista!";
            setCol(0x0f);
            cout << "\n";
        }
    }
    else
    {
        cout << "\n";
        setCol(0x0c);
        cout << "Nu exista masini in momentul de fata!";
        setCol(0x0f);
        cout << "\n";

    }
}

void Cautare_Masina()
{
    char serie[30];
    char selectie;
    int i;
    if (Last_Car > -1)
    {
        i = 0;
        cout << "\n";
        setCol(0x0b);
        cout << "Introduceti seria masinii cautate: ";
        setCol(0x0f);
        cin.ignore();
        cin.getline(serie, 30);
        while (strcmp(serie, tablou_masini[i]->get_serie()) != 0 && i < Last_Car)
        {
            i++;
        }
        if (i < Last_Car || (i == Last_Car && strcmp(serie, tablou_masini[i]->get_serie()) == 0))
        {
            cout << "\n";
            setCol(0x0a);
            cout << "Masina cautata este: ";
            setCol(0x0f);
            cout << *(tablou_masini[i]);
            Meniu_Principal();
        }
        else
        {

            cout << "\n";
            setCol(0x0c);
            cout << "Nu exista masina cu seria introdusa!!";
            setCol(0x0f);
            cout << "\n";
            cout << "Daca doriti sa reveniti la meniul principal, introduceti 0\nDaca doriti sa vedeti toate masinile cu marca cautat, introduceti 1\nAlegere: ";
            cin >> selectie;
            if (selectie == '0')
            {
                Meniu_Principal();
            }
            else if (selectie == '1')
            {
                cout << "\nIntroduceti marca: ";
                cin.ignore();
                cin.getline(serie, 30); //folosesc tot tabloul de la serie, nu are rost sa mai iau altul, ca tot nu mai conteaza seria acum
                for (i = 0; i <= Last_Car; i++)
                {
                    if (strcmp(tablou_masini[i]->get_marca(), serie) == 0)
                    {
                        cout << *(tablou_masini[i]);
                    }
                }
                Meniu_Principal();
            }
            else
            {
                cout << "\n";
                setCol(0x0c);
                cout << "Cifra introdusa este gresita!";
                setCol(0x0f);
                cout << "\n";
                Meniu_Principal();
            }
        }
    }
    else
    {
        cout << "\n";
        setCol(0x0c);
        cout << "Nu exista masini in momentul de fata!";
        setCol(0x0f);
        cout << "\n";
    }
}

template <class T>
void print_Masina(T masina)
{
    cout << masina.ToString();
}

void Afisare_Masini()
{
    if (Last_Car > -1)
    {
        for (int i = 0; i <= Last_Car; i++)
        {
            print_Masina(*(tablou_masini[i]));
        }
    }
    else
    {

        cout << "\n";
        setCol(0x0c);
        cout << "Nu exista masini in momentul de fata!";
        setCol(0x0f);
        cout << "\n";
    }
    Meniu_Principal();
}

void Meniu_Principal()
{
    char selectie;
    cout << "\n";
    setCol(0x0a);
    cout << "Buna ziua!";
    setCol(0x0f);
    cout << "\n";
    cout << "\n";
    setCol(0x0b);
    cout << "1. Doresc sa adaug o masina";
    setCol(0x0f);
    cout << "\n";
    setCol(0x0b);
    cout << "2. Doresc sa sterg o masina";
    setCol(0x0f);
    cout << "\n";
    setCol(0x0b);
    cout << "3. Doresc sa actualizez o masina";
    setCol(0x0b);
    cout << "\n";
    setCol(0x0b);
    cout << "4. Doresc sa caut o masina";
    setCol(0x0b);
    cout << "\n";
    setCol(0x0b);
    cout << "5. Doresc sa vad toate masinile";
    setCol(0x0f);
    cout << "\n";
    setCol(0x0b);
    cout << "6. Doresc sa adaug un camion";
    setCol(0x0b);
    cout << "\n";
    setCol(0x0b);
    cout << "7. Doresc sa printez tot parcul auto";
    setCol(0x0b);
    cout << "\n";
    setCol(0x0b);
    cout << "0. Doresc sa parasesc programul";
    setCol(0x0f);
    cout << "\n";
    cout << "\n";
    setCol(0x0b);
    cout << "Introduceti optiunea aleasa: ";
    setCol(0x0f);

    //cout << "\nBuna ziua!\n\n" << "1. Doresc sa adaug o masina\n" << "2. Doresc sa sterg o masina\n" << "3. Doresc sa actualizez o masina\n" << "4. Doresc sa caut o masina\n" << "5. Doresc sa vad toate masinile\n" << "0. Doresc sa parasesc aplicatia\n" << "\nIntroduceti optiunea: ";
    cin >> selectie;
    switch(selectie)
    {
    case '0':
        setCol(0x0b);
        cout << "O zi buna";;
        setCol(0x0f);
        break;
    case '1':
        Adaugare_Masina();
        break;
    case '2':
        Stergere_Masina();
        break;
    case '3':
        Actualizare_Masina();
        break;
    case '4':
        Cautare_Masina();
        break;
    case '5':
        Afisare_Masini();
        break;
    case '6':
        Adaugare_Camion();
        break;
    default:
        cout << "Cifra introdusa nu este corecta!\nDaca doriti sa reincercati, introduceti orice cifra\nDaca doriti sa parasiti aplicatia, introduceti 0\n";
        cin.ignore();
        cin >> selectie;
        if (selectie == '0')
        {
            setCol(0x0b);
            cout << "O zi buna";;
            setCol(0x0f);
        }
        else
        {
            Meniu_Principal();
        }
    }
}

void CitireDinFisier()
{
    ifstream Fisier("date.txt");
    string informatii;
    char *propozitie, *auxiliar;
    if (Fisier.is_open())
    {
        while (getline(Fisier, informatii))
        {

            propozitie = &informatii[0];
            if (strlen(propozitie) > 0)
            {
                Last_Car++;

                tablou_masini[Last_Car] = new Masini();

                auxiliar = strtok(propozitie, " ");
                tablou_masini[Last_Car]->set_marca(auxiliar);

                auxiliar = strtok(NULL, " ");
                tablou_masini[Last_Car]->set_model(auxiliar);

                auxiliar = strtok(NULL, " ");
                tablou_masini[Last_Car]->set_serie(auxiliar);

                auxiliar = strtok(NULL, " ");
                tablou_masini[Last_Car]->set_putere(atoi(auxiliar));

                auxiliar = strtok(NULL, " ");
                tablou_masini[Last_Car]->set_an(atoi(auxiliar));

                auxiliar = strtok(NULL, " ");
                tablou_masini[Last_Car]->set_capacitate(atoi(auxiliar));;

                auxiliar = strtok(NULL, " ");
                tablou_masini[Last_Car]->set_pret(atoi(auxiliar));

                auxiliar = strtok(NULL, " ");
                tablou_masini[Last_Car]->set_numar(auxiliar);
            }
        }

        Fisier.close();
    }

        
}

void ScriereInFisier()
{
    ofstream Fisier("date.txt");

    for (int i = 0; i <= Last_Car; i++)
    {
        Fisier << tablou_masini[i]->get_marca() << ' ';
        Fisier << tablou_masini[i]->get_model() << ' ';
        Fisier << tablou_masini[i]->get_serie() << ' ';
        Fisier << tablou_masini[i]->get_putere() << ' ';
        Fisier << tablou_masini[i]->get_an() << ' ';
        Fisier << tablou_masini[i]->get_capacitate() << ' ';
        Fisier << tablou_masini[i]->get_pret() << ' ';
        Fisier << tablou_masini[i]->get_numar() << "\n";
    }
    Fisier.close();
}


int main()
{
    CitireDinFisier();
    Meniu_Principal();

}
