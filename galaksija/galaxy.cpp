#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
    freopen("galaxy4.in","r",stdin);
    freopen("galaxy4.out","w",stdout);

    int zbir[1005]={}, i, j, n, m, prijenos=0, maxcif=0;
    char broj[1005]={};

    cin >> n;
    for (i=0; i<n; i++)
    {
        cin >> broj;
        m=strlen(broj);
        for (j=0; j<m; j++)
        {
            zbir[j]+=int(broj[m-j-1])-48 + prijenos;
            prijenos = zbir[j]/10;
            zbir[j] = zbir[j]%10;
        }
        j=m;
        while (prijenos!=0)
        {
            zbir[j]+=prijenos;
            prijenos=zbir[j]/10;
            zbir[j]=zbir[j]%10;
            j++;
        }
        if (j>maxcif) maxcif=j;
    }

    for (i=maxcif-1; i>=0; i--) cout << zbir[i];
    cout << endl;

    return 0;
}
