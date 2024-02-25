//problem link: https://www.pbinfo.ro/probleme/508/cautare-binara
#include <iostream>
using namespace std;

int Cautare_Binara(int st, int dr, int V[], int valoare){
    if(st > dr)
        return 0;

    int mij = (st + dr) / 2;

    if(V[mij] == valoare)
        return 1;
    
    if(V[mij] >= valoare)
        return Cautare_Binara(st, mij - 1, V, valoare);
    else return Cautare_Binara(mij + 1, dr, V, valoare);
}
int n, m;
int x[25001], y[200001];

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i)
        cin >> x[i];

    cin >> m;

    for(int i = 1; i <= m; ++i)
        cin >> y[i];

    for(int i = 1; i <= m; ++i)
        if(Cautare_Binara(1, n, x, y[i]) == 1)
            cout << 1 << " ";
        else cout << 0 << " ";


    return 0;
}
