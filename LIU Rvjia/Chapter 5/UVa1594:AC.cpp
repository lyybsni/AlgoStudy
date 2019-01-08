/* lyybsni 1594 C++ "Ducci" */

#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int case_number;
    cin >> case_number;

    while(case_number--){
        int number;
        cin >> number;

        int temp;
        vector<int> arr;
        for(int i = 0; i < number; i++){
            cin >> temp;
            arr.push_back(temp);
        }

        set<vector<int> > s;
        bool flag = false;

        while(!s.count(arr) && !flag){
            s.insert(arr);
            flag = true;

            vector<int> temp_arr;

            for(int i = 0; i < number; i++){
                if(arr[i] != 0) flag = false;
                int diff = abs(arr[i] - arr[(i+1)%number]);
                temp_arr.push_back(diff);
//                cout << i << "th: " << diff << endl;
            }

            arr = temp_arr;
        }

        if(flag){
            cout << "ZERO" << endl;
        } else {
            cout << "LOOP" << endl;
        }
    }


    return 0;
}