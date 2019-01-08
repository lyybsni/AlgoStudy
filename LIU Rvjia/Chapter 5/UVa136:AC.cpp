/* lyybsni 136 C++ "Ugly Number" */

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;

priority_queue<LL, vector<LL>, greater<LL> > pq;
set<LL> s;

void in(LL x, int para){
    LL x2 = x*para;
    if(!s.count(x2)){
        s.insert(x2);
        pq.push(x2);
    }
}

int main(){

    pq.push(1);
    s.insert(1);

    for(int i = 1; ;i++){
        LL x = pq.top(); pq.pop();
        if(i == 1500){
            cout << "The 1500'th ugly number is " << x << endl;
            return 0;
        }

        in(x, 2);
        in(x, 3);
        in(x, 5);
    }

    return 0;
}