#include <iostream>
#include <cmath>
#include <queue>
#define Nmax 100001
#define RUP ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TOT return 0;
using namespace std;

int n;
int v[Nmax], s[Nmax];

void MergeSort(int v[], int st, int dr)
{
    if (st < dr)
    {
        int mij = (st + dr) / 2;

        MergeSort(v, st, mij);
        MergeSort(v, mij + 1, dr);

        int i = st, j = mij + 1, k = 0;

        while (i <= mij && j <= dr)
            if (v[i] < v[j])
                s[++k] = v[i++];
            else
                s[++k] = v[j++];
        while (i <= mij)
            s[++k] = v[i++];
        while (j <= dr)
            s[++k] = v[j++];
        for (i = st, j = 1; i <= dr; i++, j++)
            v[i] = s[j];
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> v[i];
    
    MergeSort(v, 1, n);

    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
}
