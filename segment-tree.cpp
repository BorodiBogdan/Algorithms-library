//https://www.pbinfo.ro/probleme/3526/stringquery
#include <iostream>
#include <cmath>
#include <queue>
#include <climits>
using namespace std;

int n, op, q, poz1, poz2;
string Sir;
char c;
char S[5000001];
int P[60];
int A[20000001];

inline void Build_Tree(int st, int dr, int node){
    if(st == dr){
        int poz = S[st - 1] - 'a';

        A[node] = P[poz];
        return;
    }
    int mid = (st + dr) / 2;

    Build_Tree(st, mid, node * 2);
    Build_Tree(mid + 1, dr, node * 2 + 1);
    A[node] = A[node * 2] | A[node * 2 + 1];
}
inline void Update(int st, int dr, int poz, int val, int node){
    if(st == dr){
        A[node] = P[val];
        return;
    }
    int mid = (st + dr) / 2;

    if(mid >= poz)
        Update(st, mid, poz, val, node * 2);
    else Update(mid + 1, dr, poz, val, node * 2 + 1);

    A[node] = A[node * 2] | A[node * 2 + 1];
}
inline int Query(int st, int dr, int a, int b, int node){
    if(st >= a && dr <= b)
        return A[node];

    int p1 = 0;
    int p2 = p1;
    int mid = (st + dr) / 2;

    if(mid >= a)
        p1 = Query(st, mid, a, b, node * 2);
    if(mid + 1 <= b)
        p2 = Query(mid + 1, dr, a, b, node * 2 + 1);

    return p1 | p2;
}
int main(){
    ios::sync_with_stdio(nullptr);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cin.get();
    cin >> S;

    for(int i = 0; i <= 27; ++i)
        P[i] = 1LL << i;

    Build_Tree(1, n, 1);

    cin >> q;

    for(int i = 1; i <= q; ++i){
        cin >> op;

        if(op == 1){
            cin >> poz1 >> c;
            int poz = c - 'a';
            Update(1, n, poz1, poz, 1);
        }
        else {
            cin >> poz1 >> poz2;

            int rez = Query(1, n, poz1, poz2, 1);

            cout << __builtin_popcountl(rez) <<"\n";
        }
    }
    return 0;
}
