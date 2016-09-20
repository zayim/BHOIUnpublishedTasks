#include <iostream>
#include <ctime>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
    srand(time(0));
    freopen("zbir10.in","w",stdout);

    int n=1000,i,j,m;

    cout << n << endl;
    for (i=0; i<n; i++)
    {
        m=1000;//m=1+rand()%1000;
        cout << (1+rand()%9);
        for (j=1; j<m; j++) cout << rand()%10;
        cout << endl;
    }

    return 0;
}
