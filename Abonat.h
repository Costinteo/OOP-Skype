#pragma once

#include <string>
#include <iostream>
#include <vector>

class Agenda;

// SUPER CLASS
class Persoana {
protected:
    int id;
    std::string nume;
public:
    friend Agenda;

    Persoana(int id = 0, std::string nume = "DEFAULT");


    Persoana(const Persoana &obj);

    Persoana &operator=(const Persoana &obj);

    friend std::ostream &operator<<(std::ostream &os, const Persoana &obj);

    virtual ~Persoana(){}

    virtual void showType(){

        std::cout << "Persoana" << std::endl;

    }

};


// DERIVED CLASSES
class Abonat : public Persoana {
protected:
    std::string nr_telefon;
public:
    Abonat(int id = 0, std::string nume = "DEFAULT", std::string nr_telefon = "UNASSIGNED");

    Abonat(const Abonat &obj);

    Abonat &operator=(const Abonat &obj);

    friend std::ostream &operator<<(std::ostream &os, const Abonat &obj);

    ~Abonat(){}

    void showType(){

        std::cout << "Abonat" << std::endl;

    }

};


class Abonat_Skype : public Abonat {
protected:
    std::string id_skype;
public:
    Abonat_Skype(int id = 0, std::string nume = "DEFAULT",
                 std::string nr_telefon = "UNASSIGNED", std::string id_skype = "UNASSIGNED");

    Abonat_Skype(const Abonat_Skype &obj);

    Abonat_Skype &operator=(const Abonat_Skype &obj);

    friend std::ostream &operator<<(std::ostream &os, const Abonat_Skype &obj);

    ~Abonat_Skype(){}

    void showType(){

        std::cout << "Abonat_Skype" << std::endl;

    }

};


class Abonat_Skype_Romania : public Abonat_Skype {
protected:
    std::string adresa_mail;
public:
    Abonat_Skype_Romania(int id = 0, std::string nume = "DEFAULT",
                         std::string nr_telefon = "UNASSIGNED", std::string id_skype = "UNASSIGNED",
                         std::string adresa_mail = "UNASSIGNED");

    Abonat_Skype_Romania(const Abonat_Skype_Romania &obj);

    Abonat_Skype_Romania &operator=(const Abonat_Skype_Romania &obj);

    friend std::ostream &operator<<(std::ostream &os, const Abonat_Skype_Romania &obj);

    ~Abonat_Skype_Romania(){}

    void showType(){

        std::cout << "Abonat_Skype_Romania" << std::endl;

    }

};


class Abonat_Skype_Extern : public Abonat_Skype {
protected:
    std::string tara;
public:
    Abonat_Skype_Extern(int id = 0, std::string nume = "DEFAULT",
                        std::string nr_telefon = "UNASSIGNED", std::string id_skype = "UNASSIGNED",
                        std::string tara = "UNASSIGNED");

    Abonat_Skype_Extern(const Abonat_Skype_Extern &obj);

    Abonat_Skype_Extern &operator=(const Abonat_Skype_Extern &obj);

    friend std::ostream &operator<<(std::ostream &os, const Abonat_Skype_Extern &obj);

    ~Abonat_Skype_Extern(){}

    void showType(){

        std::cout << "Abonat_Skype_Extern" << std::endl;

    }

};

class Agenda {
private:
    std::vector<Persoana *> persoane;

public:
    void Add(Persoana *persoana) {
        persoane.push_back(persoana);
    }

    Persoana *operator[](std::string nume) {
        for (auto &pers : persoane) {
            if (pers->nume == nume) {
                return pers;
            }
        }

        throw "N-am gasit utilizatorul in lista";
    }

    ~Agenda() {
        for (auto &persoana : persoane) {
            delete persoana;
        }
    }
};