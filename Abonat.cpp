#include "Abonat.h"

Persoana::Persoana(int id, std::string nume) {

    this->id = id;
    this->nume = nume;

}

Persoana::Persoana(const Persoana &obj) {
    *this = obj;
}

Persoana &Persoana::operator=(const Persoana &obj) {
    this->id = obj.id;
    this->nume = obj.nume;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Persoana &obj) {
    os << "ID:" << obj.id;
    os << std::endl;
    os << "NUME:" << obj.nume;
    os << std::endl;
    return os;
}


Abonat &Abonat::operator=(const Abonat &obj) {
    this->nr_telefon = obj.nr_telefon;
    Persoana::operator=(obj);
    return *this;
}

Abonat::Abonat(const Abonat &obj) {
    *this = obj;
}

Abonat::Abonat(int id, std::string nume, std::string nr_telefon) : Persoana(id, nume) {

    this->nr_telefon = nr_telefon;

}

std::ostream &operator<<(std::ostream &os, const Abonat &obj) {
    os << static_cast<const Persoana &> (obj);
    os << "NR_TELEFON:" << obj.nr_telefon;
    os << std::endl;
    return os;

}


Abonat_Skype::Abonat_Skype(int id, std::string nume, std::string nr_telefon, std::string id_skype) : Abonat(id, nume,
                                                                                                            nr_telefon) {

    this->id_skype = id_skype;

}

Abonat_Skype::Abonat_Skype(const Abonat_Skype &obj) {
    *this = obj;
}

Abonat_Skype &Abonat_Skype::operator=(const Abonat_Skype &obj) {
    this->id_skype = obj.id_skype;
    Abonat::operator=(obj);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Abonat_Skype &obj) {
    os << static_cast<const Abonat &> (obj);
    os << "ID_SKYPE:" << obj.id_skype;
    os << std::endl;
    return os;
}

Abonat_Skype_Romania::Abonat_Skype_Romania(int id, std::string nume, std::string nr_telefon, std::string id_skype,
                                           std::string adresa_mail) : Abonat_Skype(id, nume, nr_telefon, id_skype) {

    this->adresa_mail = adresa_mail;

}

Abonat_Skype_Romania::Abonat_Skype_Romania(const Abonat_Skype_Romania &obj) {
    *this = obj;
}

Abonat_Skype_Romania &Abonat_Skype_Romania::operator=(const Abonat_Skype_Romania &obj) {
    this->adresa_mail = obj.adresa_mail;
    Abonat_Skype::operator=(obj);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Abonat_Skype_Romania &obj) {
    os << static_cast<const Abonat_Skype &> (obj);
    os << "ADRESA_MAIL:" << obj.adresa_mail;
    os << std::endl;
    return os;
}

Abonat_Skype_Extern::Abonat_Skype_Extern(int id, std::string nume, std::string nr_telefon, std::string id_skype,
                                         std::string tara) : Abonat_Skype(id, nume, nr_telefon, id_skype) {

    this->tara = tara;

}

Abonat_Skype_Extern::Abonat_Skype_Extern(const Abonat_Skype_Extern &obj) {
    *this = obj;
}

Abonat_Skype_Extern &Abonat_Skype_Extern::operator=(const Abonat_Skype_Extern &obj) {
    this->tara = obj.tara;
    Abonat_Skype::operator=(obj);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Abonat_Skype_Extern &obj) {
    os << static_cast<const Abonat_Skype &> (obj);
    os << "TARA:" << obj.tara;
    os << std::endl;
    return os;
}
