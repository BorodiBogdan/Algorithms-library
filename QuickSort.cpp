#include <iostream>
#include <cmath>
#include <queue>
#define Nmax 100001
#define RUP ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TOT return 0;
using namespace std;

int n;
int v[Nmax], s[Nmax];

void QuickSort(int v[], int st, int dr)
{
    if(st < dr)
    {
        //pivotul este inițial v[st]
        int m = (st + dr) / 2;

        int i = st , j = dr, d = 0;
        while(i < j)
        {
            if(v[i] > v[j])
            {
                int aux = v[i]; 
                v[i] = v[j];
                v[j] = aux;
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        QuickSort(v, st , i - 1);
        QuickSort(v, i + 1 , dr);
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    QuickSort(v, 1, n);

    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
}
