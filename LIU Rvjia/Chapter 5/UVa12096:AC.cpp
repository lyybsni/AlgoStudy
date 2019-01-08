/* lyybsni 12096 C++ "Stack" */

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x, x.begin())

using namespace std;

map<set<int>, int> dict;
vector<set<int> > setCache;

int findId(set<int> myset){
    int id;
    if(!dict.count(myset)){
        setCache.push_back(myset);
        id = setCache.size()-1;
        dict[myset] = id;
        return id;
    } else {
        return dict[myset];
    }
}

void print(stack<int> mystack){
//    int size = mystack.size();
//    cout << "The size is: " << size << endl;
//    for(int i = 0; i < size; i++){
        cout << setCache[mystack.top()].size() << endl;
//        mystack.pop();
//    }
//    cout << "***" << endl;
}

void testing(stack<int> mystack){
    stack<int> copy = mystack;
    for(int i = 0; i < mystack.size(); i++){
        cout << setCache[copy.top()].size() << "\t";
        copy.pop();
    }
    cout << endl;
}

int main(){

    int case_number;
    cin >> case_number;

    while(case_number --){
        stack<int> mystack;

        int operation_number;
        cin >> operation_number;

        string op;
        while(operation_number --){
            cin >> op;

            set<int> ele1, ele2, res;
            switch(op[0]){
                case 'A':
                    ele1 = setCache[mystack.top()]; mystack.pop();
                    ele2 = setCache[mystack.top()]; mystack.pop();
                    ele2.insert(findId(ele1));
                    mystack.push(findId(ele2));
                    break;
                case 'U':
                    ele1 = setCache[mystack.top()]; mystack.pop();
                    ele2 = setCache[mystack.top()]; mystack.pop();
                    set_union(ALL(ele1), ALL(ele2), INS(res));
                    mystack.push(findId(res));
                    break;
                case 'I':
                    ele1 = setCache[mystack.top()]; mystack.pop();
                    ele2 = setCache[mystack.top()]; mystack.pop();
                    set_intersection(ALL(ele1), ALL(ele2), INS(res));
                    mystack.push(findId(res));
                    break;
                case 'P':
                    mystack.push(findId(set<int>()));
//                    testing(mystack);
                    break;
                case 'D':
//                    cout << "Before D the size is " << mystack.size() << endl;
                    mystack.push(mystack.top());
//                    cout << "After D the size is " << mystack.size() << endl;
                    break;
            }
            print(mystack);
        }
        cout << "***" << endl;
    }

    return 0;
}
