#include <iostream>

class Wektor
{
public:
    Wektor(int n_wek)
    {
        dlugosc   = n_wek;
        pojemnosc = n_wek;
        vector    = new double[dlugosc];
        for (int i = 0; i < dlugosc; i++)
            vector[i] = 0;
    }

    ~Wektor() { delete[] vector; }

    void dlugosc_wek() { std::cout << "Dlugosc wektora wynosi " << dlugosc << std::endl; }

    int getDlugosc() { return dlugosc; }
    int getPojemnosc() { return pojemnosc; }

    void print()
    {
        std::cout << "Obecna zawartosc wektora [";
        for (int i = 0; i < dlugosc; ++i) {
            std::cout << vector[i];
            if (i < (dlugosc - 1))
                std::cout << ", ";
        }
        std::cout << "]\n" << std::endl;
    }

    void ZmienDlugosc(int nowe_n)
    {
        if (nowe_n <= pojemnosc) {
            for (int i = nowe_n; i < pojemnosc; i++)
                vector[i] = 0;
            dlugosc = nowe_n;
        }
        else if (nowe_n > pojemnosc) {
            double* temp = new double[nowe_n];
            for (int i = 0; i < dlugosc; i++)
                temp[i] = vector[i];
            for (int i = dlugosc; i < nowe_n; i++)
                temp[i] = 0.0;

            vector = temp;
            delete[] temp;

            dlugosc   = nowe_n;
            pojemnosc = dlugosc;
        }
    }

    double& operator[](int n)
    {
        if (n > dlugosc) {
            ZmienDlugosc(n);
            return vector[n];
        }
        else
            return vector[n];
    }

private:
    double* vector;
    int     dlugosc;
    int     pojemnosc;
};

int main()
{
    Wektor wek{4};
    wek.dlugosc_wek();

    std::cout << "Przypisanie wartosci do elementu spoza zakresu wektora" << std::endl;
    wek[6] = 7.5;
    wek.dlugosc_wek();

    std::cout << "Ostatnia linijka kodu." << std::endl;
}