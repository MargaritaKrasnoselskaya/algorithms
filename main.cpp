#include <iostream>
#include <queue>
#include <list>
#include <vector>

typedef unsigned long long big;
using namespace std;
static unsigned long N;//num of lines
struct node
{
    big value;
    long leftChild;
    long rightChild;
    long parent;
    node(big val, long l, long r, long p=-1){value = val; leftChild=l; rightChild=r; parent = p;}
};
vector<node> tree;
static long rot=-1;
void printPreorder()
{
       list<long> waitlist1;
    while (grt>=0)
    {
        cout<<tree[grt].value<<" ";
        if(tree[grt].leftChild>=0)
        {
            if (tree[grt].rightChild>=0)
            {
                waitlist1.push_front(tree[grt].rightChild);
        //        cout<<"put "<<tree[grt].rightChild<<"\n";
            }
            grt = tree[grt].leftChild;
        }
        else
        {
            if (tree[grt].rightChild>=0)
            {
                grt = tree[grt].rightChild;
            }
            else
            {
                if (waitlist1.size()>0)
                {
                    grt = waitlist1.front();
                    waitlist1.pop_front();
                }
                else
                    grt = -1;
            }
        }
    }
}
void printinOrder()
{
   list<long> waitlist0; long bignum=1000000;
    while (grt>=0)
    {
 //       cout<<tree[grt].value<<" ";
        if(tree[grt].leftChild>=0 && tree[grt].leftChild < bignum)
        {
            waitlist0.push_front(grt);
            grt = tree[grt].leftChild;
        }
        else
        {
            cout<<tree[grt].value<<" ";
            //ware parent!
            if (grt!=rot)
            {
                 tree[tree[grt].parent].leftChild = tree[tree[grt].parent].leftChild + bignum; /*now there is no link */
            }
            if (tree[grt].rightChild>=0)
            {
                grt = tree[grt].rightChild;
            }
            else
            {
                if (waitlist1.size()>0)
                {
                    grt = waitlist1.front();
                    cout<<tree[grt].value<<" ";
                    waitlist1.pop_front();
                }
                else
                    grt = -1;
            }
        }
    }
}
int main()
{
     cin>>N;
     if (N==0) return -2;
    big key; signed long lindex, rindex;
    long i;

    for(i=0; i<N; i++)
        tree.push_back(node(0, -1, -1, -1));
     for (i=0; i<N; i++)
    {
        cin>>key; cin>>lindex; cin>>rindex;
       //
        lindex = lindex; rindex= rindex;
        tree[i].value = key;
        tree[i].leftChild=lindex;
        tree[i].rightChild = rindex;
        if (lindex>=0) {tree[lindex].parent = i;
        }
        if (rindex>=0) {tree[rindex].parent = i;
        }
    }
    //find the root
    for(i=0; i<N; i++)
       { if (tree[i].parent==-1) { rot = i; break; }}
    //find the smallest element
    long grt = rot;
    return 0;
}
