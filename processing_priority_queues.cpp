#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
typedef long long big;
using namespace std;
static vector<big> arr;
static long arsize;
static vector<long> leftres, rightres;
struct proc {
    long thnum;
    big beginZeit;
    big endzeit;
    proc(long th, big bz, big ez)
    {
        thnum = th;
        beginZeit = bz;
        endzeit = ez;
    }
};
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=true)
    {reverse=revparam;}
  bool operator() (const proc& lhs, const proc &rhs) const
  {
    if (lhs.endzeit == rhs.endzeit) return (lhs.thnum > rhs.thnum);
    return (lhs.endzeit > rhs.endzeit);
  }
};

typedef priority_queue<proc, vector<proc>,mycomparison> mypq_type;

int main()
{
    long num, thnum, cnt; big val;
    mypq_type processing;
    cin>>thnum;cin>>num;
    for (cnt=0; cnt<num; cnt++)
    {
        cin>>val;
        arr.push_back(val);
    }
    if (thnum>=num)
    {
        //drucken den Result und abrechnen
        for (int i=0; i<num-1; i++)
            cout<<i<<" 0\n";
        cout<<num-1<<" 0";
        return 0;
    }
    arsize = arr.size(); long thr; big ezeit, bzeit;
    cout<<"0 0";
    processing.push(proc(0, 0, arr[0]));
    for (cnt=1; cnt<min(thnum, num); cnt++)
    {
        processing.push(proc(cnt, 0, arr[cnt]));
        cout<<"\n"<<cnt<<" "<<0;
    }
    while(!processing.empty())
    {
        thr = processing.top().thnum; bzeit = processing.top().beginZeit; ezeit = processing.top().endzeit;
        processing.pop();
        if(cnt<arsize)
        {
            cout<<"\n"<<thr<<" "<<ezeit;//gedruckt
            processing.push(proc(thr, ezeit, ezeit+arr[cnt]));
            cnt++;
        }
    }
    return 0;
}
