#include <iostream>
using namespace std;

double lagrange(double p, const double* x, const double* y, double wezly);

int main() {

    double p;
    int wezly;

    cout<<"Podaj ilość węzłów: ";
    cin>>wezly;
    double x[wezly];
    double y[wezly];
    cout<<"Podaj x:"<<endl;
    for(int i = 0; i< wezly; i++){
        cout<<"Podaj wartość x"<<i+1<<": ";
        cin>>x[i];
    }

    cout<<"Podaj y:"<<endl;
    for(int i = 0; i< wezly; i++){
        cout<<"Podaj wartość y"<<i+1<<": ";
        cin>>y[i];
    }
    cout<<"Podaj punkt: ";
    cin>>p;

    for(int i = 0; i< wezly-1; i++){
        if(x[i] >= x[i + 1]){
            return 100;
        }
    }

    if(!(p>=x[0] && p<=x[wezly-1])){
        return 101;
    }

    cout<<"Wynik to: "<<lagrange(p, x, y, wezly)<<endl;
    return 0;
}



/* Funkcja lagrange() stosująca algorytm Lagrange do oblicznia przybliżonej wartości wielomianu w punkcjie

 Wymagane jest aby tablica x-ów była posortowana rosnąco, oraz wartość p mieściła się między największym a najmniejszym x-em.

*/
double lagrange(double p, const double* x, const double* y, double wezly){
    double suma = 0;
    for(int i = 0; i<wezly; i++){
        double l = 1;
        for(int j = 0; j<wezly; j++){
            if(j != i) {
                l *= (p - x[j]) / (x[i] - x[j]);
            }
        }
        suma += y[i]*l;
    }
    return suma;
}