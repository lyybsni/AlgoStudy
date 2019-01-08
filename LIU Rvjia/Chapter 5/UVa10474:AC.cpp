/* lyybsni 10474 C++ "Where is the Marble "*/

/* Analysis:
 * Time Complexity O(size log size + size * query)
 * Space Complexity O(size)
 */


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> ls;

    int size, query;
    int count = 1;
    while(cin >> size >> query){
        // ending condition
        if(size == 0 && query == 0) return 0;

        int temp;       /* input variable */

        int tempSize = size;
        while(tempSize--) {
            cin >> temp;
            pq.push(temp);
        }

        for(int i = 0; i < size; i++){
            ls.push_back(pq.top());
            pq.pop();
        }

        int tempQuery = query;

        cout << "CASE# " << count++ << ":" << endl;

        while(tempQuery--){
            cin >> temp;
            vector<int>::iterator it = find(ls.begin(), ls.end(), temp);
            if(it != ls.end()){
                cout << temp << " found at " << (distance(ls.begin(), it) + 1);
            } else {
                cout << temp << " not found" ;
            }
            cout << endl;

        }

        ls.clear();
    }

    return 0;
}