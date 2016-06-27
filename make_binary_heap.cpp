#include <iostream>
#include <cstdlib>
#include <vector>
typedef long long big;
using namespace std;
static vector<big> arr;
static long arsize;
static vector<long> leftres, rightres;
void siftDown(long it)
 {
    long left, j;
    while (2*it + 1 < arsize)
    {
        long left = 2*it+1;            // left — левый сын
        j = left;
        if (left+1 < arsize && arr[left+1] < arr[left])
            j = left+1;
        if (arr[it] <= arr[j])
            break;
        leftres.push_back(it);
        rightres.push_back(j);
        swap(arr[it], arr[j]);
        it = j;
    }
    return;
}

void heapify()
{
    long i;
    if (arsize%2==1)
        i = (arsize+1)/2;
    else i = arsize/2;
    for (; i>=0; i--)
        siftDown(i);
 }
int main()
{
    long num; big val;
    cin>>num;
    for (long j=0; j<num; j++)
    { cin>>val; arr.push_back(val);}
    arsize = arr.size();
    heapify();
    long lsize = leftres.size();
    if (lsize>0)
    {
        printf("%u\n", lsize);
        for(long k = 0; k<lsize-1; k++)
            printf("%u %u\n", leftres.at(k), rightres.at(k));
        printf("%u %u", leftres.at(lsize-1), rightres.at(lsize-1));
    }
    else printf("0");
    return 0;
}
