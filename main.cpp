#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class punto{
    float x;
    float y;
public:
    punto(float a, float b):x{a},y{b}{}
     double distancia(punto* b){
        return sqrt(pow(x-b->x,2)+pow(y-b->y,2));
    }
};
int main() {
    int i,j,cant_vec;
    double x,y;
    while(cin >> cant_vec) {
        if (cant_vec == 0) { return 0; }
        else {
            vector<double> distancias;
            punto **puntos;
            puntos = new punto *[cant_vec];
            for (i = 0; i < cant_vec; i++) {
                cin >> x >> y;
                puntos[i] = new punto(x, y);
            }
            if (cant_vec == 1) {
                cout << "INFINITY" << endl;

            } else {
                for (i = 0; i < cant_vec; i++) {
                    for (j = i + 1; j < cant_vec; j++) {
                        double a = puntos[i]->distancia(puntos[j]);
                        distancias.push_back(a);
                    }
                }
                auto result = min_element(distancias.begin(), distancias.end());
                auto menor = distancias[distance(distancias.begin(), result)];
                if (menor >= 10000) {
                    cout << "INFINITY" << endl;
                } else {
                    cout << fixed;
                    cout << setprecision(4) << menor << endl;
                }

                distancias.clear();

            }
        }
    }
}
