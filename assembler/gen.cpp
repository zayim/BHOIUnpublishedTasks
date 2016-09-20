#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
void upisi(bool odrediste[], int broj)
{
    if (broj<0) odrediste[3]=1;
    else odrediste[3]=0;
    broj=abs(broj);
    int i=31;
    while (broj>0)
    {
        odrediste[i]=broj%2;
        broj/=2;
        i--;
    }
    for (int j=4; j<=i; j++) odrediste[j]=0;
}
void upisi2(bool odrediste[], int broj)
{
    if (broj<0) odrediste[0]=1;
    else odrediste[0]=0;
    broj=abs(broj);
    int i=31;
    while (broj>0)
    {
        odrediste[i]=broj%2;
        broj/=2;
        i--;
    }
    for (int j=1; j<=i; j++) odrediste[j]=0;
}
bool ima_li(vector<int> &v, int broj)
{
    int duzina=v.size(),i;

    for (i=0; i<duzina; i++) if (v[i]==broj) return true;
    return false;
}
int main()
{
    freopen("asm1.in","w",stdout);
    srand(time(0));
    int i,j,n=10,instrukcija,param;
    //n=21 + rand()%1080;
    int kraj=20 + rand()%(n-20);
    kraj=5;
    bool memorija[1000][32]={};
    vector <int> instrukcije;

    for (i=0; i<32; i++) memorija[kraj][i]=1;

    for (i=0; i<kraj; i++)
    {
        instrukcija=rand()%4;
        param = kraj + 2 + rand()%(n-kraj-2);

        memorija[i][0]=0;
        if (instrukcija==0) { memorija[i][1]=memorija[i][2]=0; }
        else if (instrukcija==1) { memorija[i][1]=0; memorija[i][2]=1; }
        else if (instrukcija==2) { memorija[i][1]=1; memorija[i][2]=0; }
        else if (instrukcija==3)
        {
            memorija[i][1]=memorija[i][2]=1;
            instrukcije.push_back(param);
        }
        upisi(memorija[i],param);
    }
    for (i=kraj+1; i<n; i++)
    {
        if (!ima_li(instrukcije,i))
        {
            param=1+rand()%n;
            bool znak=rand()%2;
            if (znak) param=-param;
            upisi2(memorija[i],param);
        }
        else
        {
            instrukcija=rand()%3;
            param = kraj + 2 + rand()%(n-kraj-2);
            while (ima_li(instrukcije,param)) param = param = kraj + 2 + rand()%(n-kraj-2);

            memorija[i][0]=0;
            if (instrukcija==0) { memorija[i][1]=memorija[i][2]=0; }
            else if (instrukcija==1) { memorija[i][1]=0; memorija[i][2]=1; }
            else if (instrukcija==2) { memorija[i][1]=1; memorija[i][2]=0; }
            upisi(memorija[i],param);
        }
    }

    cout << n << endl;
    for (i=0; i<n; i++)
    {
        for (j=0; j<32; j++) cout << memorija[i][j];
        cout << endl;

    }

    return 0;
}
