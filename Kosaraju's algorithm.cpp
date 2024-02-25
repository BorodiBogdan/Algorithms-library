//https://www.pbinfo.ro/probleme/583/tare-conexitate
#include <bits/stdc++.h>

using namespace std;

const int dim = 105;
int n, m, nct, P[dim], PT[dim];
vector<int> V[dim], VT[dim];
stack<int> S;

int DF(int v)
{
    P[v] = 1;
    for(auto i : V[v])
        if(!P[i])
            DF(i);
    S.push(v);
}

void DFT(int v, int c)
{
    PT[v] = c;
    for(auto i : VT[v])
        if(!PT[i])
            DFT(i, c);
}

int main()
{
    cin >> n >> m;
    for(int x = 1; x <= m; x ++)
    {
        int i, j;
        cin >> i >> j;
        V[i].push_back(j);
        VT[j].push_back(i);
    }
    for(int i = 1; i <= n; i ++)
        if(!P[i])
            DF(i);
    while(!S.empty())
    {
        int v = S.top();
        S.pop();
        if(!PT[v])
        {
            nct ++;
            DFT(v, nct);
        }
    }
    cout << nct << endl;
    return 0;
}
