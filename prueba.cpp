
#include <vector>
#include <iostream>
#incl
using namespace std;
int main() {
    // Declarar una lista de listas utilizando std::vector
    vector<vector< Personaje>> matrix;
    vector<int> vector  = {1, 2, 3};
    
    matrix.push_back(v);
    matrix.push_back({4, 5, 6});
    matrix.push_back({7, 8, 9});

    // Acceder a los elementos de la lista de listas
    int elemento = matrix[0][1];  // Acceder al elemento de la primera lista en la posición 1

    // Imprimir los elementos de la lista de listas
    for (const auto& lista : matrix) {
        for (int elemento : lista) {
            cout << elemento << " ";
        }
        cout << endl;
    }

    return 0;
}
