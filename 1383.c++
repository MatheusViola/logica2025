#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool contemNumerosDe1a9(const vector<int>& v) {
    set<int> s(v.begin(), v.end());
    if (s.size() != 9) return false;
    for (int i = 1; i <= 9; ++i)
        if (s.count(i) == 0) return false;
    return true;
}

bool verificarSudoku(const vector<vector<int>>& matriz) {
    for (int i = 0; i < 9; ++i)
        if (!contemNumerosDe1a9(matriz[i]))
            return false;

    for (int j = 0; j < 9; ++j) {
        vector<int> coluna;
        for (int i = 0; i < 9; ++i)
            coluna.push_back(matriz[i][j]);
        if (!contemNumerosDe1a9(coluna))
            return false;
    }

    for (int bloco_i = 0; bloco_i < 3; ++bloco_i) {
        for (int bloco_j = 0; bloco_j < 3; ++bloco_j) {
            vector<int> bloco;
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    bloco.push_back(matriz[bloco_i * 3 + i][bloco_j * 3 + j]);
            if (!contemNumerosDe1a9(bloco))
                return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    for (int instancia = 1; instancia <= n; ++instancia) {
        vector<vector<int>> matriz(9, vector<int>(9));
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                cin >> matriz[i][j];

        cout << "Instancia " << instancia << endl;
        if (verificarSudoku(matriz))
            cout << "SIM" << endl;
        else
            cout << "NAO" << endl;
        cout << endl;
    }

    return 0;
}
