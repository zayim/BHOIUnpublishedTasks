#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
/*
Ova funkcija ima zadatak da pretvori binarni broj u decimalni. Ukoliko pretvaramo parametar neke instrukcije u decimalni
broj, onda on ima samo 29 cifara u binarnom zapisu (instukcija cijela ima 32 cifre, ali prve tri su rezervisane za kod instrukcije).
Kao parametar saljemo duzinu cijelog niza kao i informaciju o tome koji dio niza zapravo trebamo pretvoriti u decimalni broj.
*/
int bin_to_dec(bool niz[], int brojCifara=29, int duzinaNiza=32)
{
    int broj=0,i,stepen=1,tmp=duzinaNiza-brojCifara+1;
    for (i=duzinaNiza-1; i>=tmp; i--)
    {
        broj+=stepen*niz[i];
        stepen*=2;
    }

    if (niz[duzinaNiza-brojCifara]) broj=-broj;

    return broj;
}
/*
Ova funkcija prepisuje decimalno zadani broj u binarni zapis i smjesta taj binarni zapis u prvi parametar. Naravno, po konvenciji, prva cifra nam
predstavlja znak broja.
*/
void upisi(bool odrediste[], int broj)
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
/*
Funckija koja ispituje da li data instrukcija predstavlja kraj programa.
*/
bool kraj (bool niz[], int duzinaNiza=32)
{
    for (int i=0; i<duzinaNiza; i++) if (!niz[i]) return false;
    return true;
}
/*
Funkcija koja nam vraæa kod instrukcije, tj. iz cijelog niza od 32 elementa, izdvaja samo prva 3 elementa i pretvara ih u decimalni zapis.
To nam je potrebno jer je cijela instrukcija duga 32 bita, ali samo prva 3 bita nam kazuju o kojoj je instrukciji rijec.
*/
int kodInstrukcije(bool niz[], int duzinaInstrukcije=3, int duzinaNiza=32)
{
    int broj=0,stepen=1,i;
    for (i=duzinaInstrukcije-1; i>=0; i--)
    {
        broj+=stepen*niz[i];
        stepen*=2;
    }

    return broj;
}
int main()
{
    freopen("asm.in","r",stdin);
    freopen("asm.out","w",stdout);
    int i,j,m,n,param,instrukcija,registar=0,rb;
    bool memorija[10000][32];
    char tmp[32];
    bool a[32];

    cin >> n;
    for (i=0; i<n; i++)
    {
        for (j=0; j<32; j++)
        {
            cin >> tmp[j];
            if (tmp[j]=='1') memorija[i][j]=true;
            else memorija[i][j]=false;
        }
    }

    i=0;
    while(!kraj(memorija[i]))
    {
        instrukcija=kodInstrukcije(memorija[i]);
        param=bin_to_dec(memorija[i],29);

        i++;
        if (instrukcija==0) registar = bin_to_dec(memorija[abs(param)-1]); // LOAD
        else if (instrukcija==1) upisi(memorija[abs(param)-1],registar); // STORE
        else if (instrukcija==2) registar+=bin_to_dec(memorija[abs(param)-1]); // ADD
        else if (instrukcija==3 && registar<0) i=abs(param)-1; // BNEG

    }

    for (i=0; i<n; i++)
    {
        for (j=0; j<32; j++) cout << memorija[i][j];
        cout << endl;
    }

    return 0;
}
