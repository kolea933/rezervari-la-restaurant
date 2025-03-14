#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>

using namespace std;

// Clasa de bază Rezervare
class Rezervare {
protected:
    string numeClient;
    string dataOra;
    int nrPersoane;

public:
    Rezervare(string nume, string data, int persoane)
        : numeClient(nume), dataOra(data), nrPersoane(persoane) {}

    virtual ~Rezervare() {}

    virtual int calculeazaDurata() const {
        return 2; // Durată standard 2 ore
    }

    virtual double calculeazaPret() const = 0;

    virtual string getTipRezervare() const = 0;

    virtual void afiseazaDetalii() const {
        cout << "Tip: " << getTipRezervare()
             << ", Client: " << numeClient
             << ", Data/Ora: " << dataOra
             << ", Nr. persoane: " << nrPersoane
             << ", Pret total: " << calculeazaPret() << " lei" << endl;
    }
};

// Rezervare Zilnica
class RezervareZilnica : public Rezervare {
public:
    RezervareZilnica(string nume, string data, int persoane)
        : Rezervare(nume, data, persoane) {}

    double calculeazaPret() const override {
        if (nrPersoane <= 2) return 50;
        return 50 + (nrPersoane - 2) * 20;
    }

    string getTipRezervare() const override {
        return "Zilnica";
    }
};

// Rezervare Eveniment Special
class RezervareEvenimentSpecial : public Rezervare {
public:
    RezervareEvenimentSpecial(string nume, string data, int persoane)
        : Rezervare(nume, data, persoane) {}

    int calculeazaDurata() const override {
        return 4; // Mai lung pentru evenimente speciale
    }

    double calculeazaPret() const override {
        double pret = 200; // Tarif fix
        if (calculeazaDurata() > 3) {
            pret += (calculeazaDurata() - 3) * 50; // Taxe suplimentare
        }
        return pret;
    }

    string getTipRezervare() const override {
        return "EvenimentSpecial";
    }
};

// Rezervare Grup Mare
class RezervareGrupMare : public Rezervare {
public:
    RezervareGrupMare(string nume, string data, int persoane)
        : Rezervare(nume, data, persoane) {}

    double calculeazaPret() const override {
        if (nrPersoane <= 20) return 500;
        return 500 + (nrPersoane - 20) * 10;
    }

    string getTipRezervare() const override {
        return "GrupMare";
    }
};

// Rezervare VIP
class RezervareVIP : public Rezervare {
public:
    RezervareVIP(string nume, string data, int persoane)
        : Rezervare(nume, data, persoane) {}

    double calculeazaPret() const override {
        double pret = 1000;
        if (nrPersoane > 5)
            pret += (nrPersoane - 5) * 100; // Extra costuri pentru facilități
        return pret;
    }

    string getTipRezervare() const override {
        return "VIP";
    }
};

// Citire rezervări din fișier
void citesteRezervari(const string& numeFisier, vector<shared_ptr<Rezervare>>& rezervari) {
    ifstream fin(numeFisier);
    if (!fin.is_open()) {
        cerr << "Eroare la deschiderea fișierului " << numeFisier << endl;
        return;
    }

    string linie;
    while (getline(fin, linie)) {
        stringstream ss(linie);
        string tip, nume, data;
        int persoane;

        ss >> tip >> nume >> data >> persoane;

        if (tip == "RezervareZilnica")
            rezervari.push_back(make_shared<RezervareZilnica>(nume, data, persoane));
        else if (tip == "RezervareEvenimentSpecial")
            rezervari.push_back(make_shared<RezervareEvenimentSpecial>(nume, data, persoane));
        else if (tip == "RezervareGrupMare")
            rezervari.push_back(make_shared<RezervareGrupMare>(nume, data, persoane));
        else if (tip == "RezervareVIP")
            rezervari.push_back(make_shared<RezervareVIP>(nume, data, persoane));
        else
            cerr << "Tip necunoscut de rezervare: " << tip << endl;
    }

    fin.close();
}

// Afișare rezervări
void afiseazaRezervari(const vector<shared_ptr<Rezervare>>& rezervari) {
    for (const auto& rezervare : rezervari) {
        rezervare->afiseazaDetalii();
    }
}

// Funcția principală
int main() {
    vector<shared_ptr<Rezervare>> rezervari;
    citesteRezervari("rezervari.txt", rezervari);
    afiseazaRezervari(rezervari);
    return 0;
}
