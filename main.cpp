#include <iostream>
#include <fstream>
#include "Abonat.h"


int main() {
    std::ifstream f("data.in");
    Agenda lista;
    int n;
    f >> n;
    for (int i = 0; i < n; i++) {
        int id;
        std::string nume, nr_telefon, id_skype, adresa_mail;
        f >> id >> nume >> nr_telefon >> id_skype >> adresa_mail;
        Abonat_Skype_Romania* abonat = new Abonat_Skype_Romania(id, nume, nr_telefon, id_skype, adresa_mail);
        lista.Add(abonat);
    }
    try {

        std::cout << *static_cast<Abonat_Skype_Romania*>(lista["mihai"]);
        std::cout << *static_cast<Abonat_Skype_Romania*>(lista["Antonietta"]);
        std::cout << *static_cast<Abonat_Skype*>(lista["Nydia"]);

    }
    catch (const char* exception){
        std::cout << exception;
    }

    Abonat_Skype* abonat = new Abonat_Skype(24, "abonattest", "072numar", "dummy");
    lista["Antonietta"]->showType();
    static_cast<Abonat_Skype*>(lista["Nydia"])->showType();
    abonat->showType();

    f.close();

}
