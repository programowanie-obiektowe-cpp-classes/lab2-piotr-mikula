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

    double& operator[](int n) { return vector[n]; }

private:
    double* vector;
    int     dlugosc;
    int     pojemnosc;
};

int main()
{
    Wektor wek{4};
    std::cout << "Przypisanie wek[0] = 42" << std::endl;
    wek[0] = 42;
    std::cout << "Sprawdzenie: wek[0] = " << wek[0] << std::endl;

    std::cout << "\nPrzypisanie a = wek[0]" << std::endl;
    double a = wek[0];
    std::cout << "Sprawdzenie: a = " << a << std::endl;
    std::cout << "a++" << std::endl;
    a++;
    std::cout << "Sprawdzenie: a = " << a << ", wek[0] = " << wek[0] << std::endl;

    std::cout << "Ostatnia linijka kodu." << std::endl;
}