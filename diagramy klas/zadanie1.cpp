#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

class IPolaczenie {
    public:
        virtual list<string> pobierzSzczegoly() = 0;
        virtual void drukuj() = 0;
};


class Wyszukiwanie {
    private:
        string przystanekPoczatkowy;
        string przystanekKoncowy;
        time_t data;
        int liczbaPrzesiadek;

    public:
        Wyszukiwanie(string przystanekPoczatkowy, string przystanekKoncowy, time_t data, int liczbaPrzesiadek) {
            this -> przystanekPoczatkowy = przystanekPoczatkowy;
            this -> przystanekKoncowy = przystanekKoncowy;
            this -> data = data;
            this -> liczbaPrzesiadek = liczbaPrzesiadek;
        }
        list<IPolaczenie> szukajPolaczenia();
};

class Wydruk {
    public:
        static void drukujPolaczenie(Polaczenie p);
};

class Polaczenie {
    private:
        time_t czasOdjazdu;
        time_t czasPrzyjazdu;
        string miejscePrzyjazdu;
        string miejsceOdjazdu;

    public:
        Polaczenie(time_t czasOdjazdu, time_t czasPrzyjazdu, string miejscePrzyjazdu, string miejsceOdjazdu) {
            this -> czasOdjazdu = czasOdjazdu;
            this -> czasPrzyjazdu = czasPrzyjazdu;
            this -> miejscePrzyjazdu = miejscePrzyjazdu;
            this -> miejsceOdjazdu = miejsceOdjazdu;
        }
        list<string> pobierzSzczegoly();
        void drukuj() {
            Wydruk::drukujPolaczenie(*this);
        }
};


class MiejscePrzesiadki {
    private:
        string miejscowosc;
        int peronPrzyjazdu;
        int peronOdjazdu;
    public:
        MiejscePrzesiadki(string miejscowosc, int peronPrzyjazdu, int peronOdjazdu) {
            this -> miejscowosc = miejscowosc;
            this -> peronPrzyjazdu = peronPrzyjazdu;
            this -> peronOdjazdu = peronOdjazdu;
        }
};

class PolaczenieBezposrednie:Polaczenie {
    private:
        float dlugoscTrasy;
        float prowizorycznaCenaBiletu;
    public:
        PolaczenieBezposrednie(time_t czasOdjazdu, time_t czasPrzyjazdu, string miejscePrzyjazdu, string miejsceOdjazdu, float dlugoscTrasy, float prowizorycznaCenaBiletu):Polaczenie(czasOdjazdu, czasPrzyjazdu, miejscePrzyjazdu, miejsceOdjazdu) {
            this -> dlugoscTrasy = dlugoscTrasy;
            this -> prowizorycznaCenaBiletu = prowizorycznaCenaBiletu;
        }
        list<string> pobierzSzczegoly();
        void drukuj() {
            Wydruk::drukujPolaczenie(*this);
        }
};

class PolaczeniePosrednie:Polaczenie {
    private:
        MiejscePrzesiadki miejsceP;
        time_t czasPrzesiadki;
    public:
        PolaczeniePosrednie(time_t czasOdjazdu, time_t czasPrzyjazdu, string miejscePrzyjazdu, string miejsceOdjazdu, MiejscePrzesiadki miejsceP, time_t czasPrzesiadki):Polaczenie(czasOdjazdu, czasPrzyjazdu, miejscePrzyjazdu, miejsceOdjazdu) {
            this -> miejsceP = miejsceP;
            this -> czasPrzesiadki = czasPrzesiadki;
        }
        list<string> pobierzSzczegoly();
        void drukuj() {
            Wydruk::drukujPolaczenie(*this);
        }
};




int main() {
    printf("Hello World");
    return 0;
}
