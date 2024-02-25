#include <iostream>
#include <algorithm>
#define Nmax 200005
using namespace std;

int n, q, pos, val;
int V[Nmax];

struct Arbore{
    int lazy, value;
    int mini;
}A[Nmax * 3];

void Propagate(int node){
    int add = A[node].lazy;

    A[node * 2].lazy += add;
    A[node * 2 + 1].lazy += add;
    A[node].lazy = 0;

    A[node * 2].value += add;
    A[node * 2 + 1].value += add;
}
pair<int, int> Find_Minimum(int st, int dr, int node){
    if(st != dr)
        Propagate(node);

    if(st == dr)
        return {st, A[node].value};
    
    int mid = (st + dr) / 2;

    if(A[node * 2].value == A[1].value)
        return Find_Minimum(st, mid, node * 2);
    else return Find_Minimum(mid + 1, dr, node * 2 + 1);

}
void Update(int st, int dr, int a, int b, int val, int node){
    if(st != dr)
        Propagate(node);

    if(st >= a && dr <= b){
        A[node].lazy += val;
        A[node].value += val;
        return;
    }
    int mid = (st + dr) / 2;

    if(mid >= a)
        Update(st, mid, a, b, val, node * 2);
    if(mid < b)
        Update(mid + 1, dr, a, b, val, node * 2 + 1);

    A[node].value = max(A[node * 2].value, A[node * 2 + 1].value);
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; ++i)
        cin >> V[i];

    cin >> q;

    for(int i = 2; i <= n; i++){
        int st = V[i - 1], dr = V[i];

        if(st < dr)
            Update(1, 200000, st, dr, 1, 1);
        else Update(1, 200000, dr, st, 1, 1);
    
        if(i != 2)
            Update(1, 200000, st, st, -1, 1);

    }


    for(int i = 1; i <= q; ++i){
        cin >> pos >> val;

        int st = V[pos - 1];
        int init = V[pos];
        int fin = val;

        if(pos > 1){
            if(st < init)
                Update(1, 200000, st, init , -1, 1);
            else Update(1, 200000, init, st, -1, 1);

            if(st < val)
                Update(1, 200000, st, val, 1, 1);
            else Update(1, 200000, val, st, 1, 1);
        }
        st = V[pos + 1];

        if(pos < n){
            if(st < init)
                Update(1, 200000, st, init, -1, 1);
            else Update(1, 200000, init, st, -1, 1);

            if(st < val)
                Update(1, 200000, st, val, 1, 1);
            else Update(1, 200000, val, st, 1, 1);
        }

        if(pos < n && pos > 1)
            Update(1, 200000, init, init, 1, 1),
            Update(1, 200000, val, val, -1, 1);

        V[pos] = val;

        pair <int, int> p;
        p = Find_Minimum(1, 200000, 1);
        cout << p.first << " " << p.second << "\n";
    }
}
