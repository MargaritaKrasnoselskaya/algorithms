#include<stdio.h>
#include<string.h>

#include <iostream>
#include <cstdlib>

typedef long long big;
using namespace std;

static const big base = 263;
static const big hashnum = 1000000007;
big mt(big a, big b){
    return (a*b)%hashnum;
}
big ad(big a, big b)
{
    return (a+b)%hashnum;
}
big de(big a, big b)
{
    if (a>b)
        return (a-b)%hashnum;
    else
        return (a%hashnum+hashnum-b%hashnum)%hashnum;
}
big getPow(size_t len)
{
    big res=1;
    if (len==0) return 1;
    if (len==1) return base%hashnum;
   for (size_t i = 0; i < len; i++)
        res = mt(res, base);
    return res;
}
big myhash(string word, long first,long last)
{
    big res=0; big tmpRes = 0;
    unsigned int asc; long j=last-1-first; big pow;
    for (size_t i=first; i<last; ++i)
    {
        asc = ((unsigned int)word[i]);//%hashnum;
        res= res+asc;
        if (res>=hashnum) res = res-hashnum;
        /*
        pow = getPow(j);
        tmpRes = mt((big)asc, pow);
        res = ad(res, tmpRes);
        j--;*/
    }
    return res;
}

void search(string ptr, string txt)
{
    size_t ptrlen = ptr.length();
    if (ptrlen==0) return;
    size_t txtlen = txt.length();
    if(txtlen==0) return;
    if (txtlen<ptrlen) return;
    if (ptrlen==txtlen)
    {
        for (size_t i=0; i<txtlen; i++)
         {
             if (txt[i]!=ptr[i]) return;
         }
        cout<<"0"; return;
    }
    size_t diff = txtlen-ptrlen;
     long i, j;
    big ptrhash = myhash(ptr, 0, ptrlen);
    big txthash = myhash(txt, 0, ptrlen);
    big pow = getPow(ptrlen-1);
    big hashtmp, asc, asc1;
    int yes=0;
     for (long i = 0; i <= diff+1; i++)
    {
        asc1=(big)(unsigned int)txt[i+ptrlen];
        asc = (big)(unsigned int)txt[i];
        if ( ptrhash == txthash )
        {
            yes = 1;
             for (long j = 0; j < ptrlen; j++)
            {
                if (txt[i+j] != ptr[j])
                 {  yes =0; break; }
            }
            if (yes == 1)
                cout<<i<<" ";
        }
        if ( i <= diff)
        {
            txthash = asc1+txthash-asc;
            if (txthash>=hashnum) txthash = txthash-hashnum;
            if (txthash<0) txthash = txthash +hashnum;
            /*
            hashtmp =mt(asc, pow);
            big tmptmp = hashtmp; big tmp=txthash;
            hashtmp =de(txthash, hashtmp);
            txthash = ad(mt(base, hashtmp), asc1);
            */
        }
    }
}
int main()
{
    string source;
    string strtofind;
    cin>>strtofind;
    cin>>source;
    search(strtofind, source);
     return 0;
}
