#include <fstream>
using namespace std;

ifstream cin("easyquery.in");
ofstream cout("easyquery.out");

long long V[100001];
long long R[100001] = {0};

int main()
{
    long long n , t , c , x , y , p;

    cin >> n;

    for(int i = 1 ; i <= n ; i++)
        cin >> V[i];

    cin >> t;

    for(int i = 1 ; i <= t ; i++)
    {
        cin >> c >> x >> y >> p;

        if(c == 1)
        {
            R[x] = R[x] + p;
            R[y + 1] = R[y + 1] - p;
        }
        if(c == 2)
        {
            R[x] = R[x] - p;
            R[y + 1] = R[y + 1] + p;
        }

    }
    for(int i = 1 ; i <= n ; i++)
        {
            R[i] = R[i - 1] + R[i];
            V[i] = V[i] + R[i];
        }
    for(int i = 1 ; i <= n ; i++)
        cout << V[i] << " ";
}
