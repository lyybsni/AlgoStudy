/* lyybsni C++ Goodbye 2018*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int number;
    cin >> number;
    
    vector<int> vt(number);
    vector<int> res;
    
    for(int i = 1; i <= number; i++){
        for(int k = 1; k <= number; k++){
            bool res = false;
            for(int j = 0; j < number; j++){
                if((i + j*number - 1) % k == 0){
                    vt[k-1] += i;
                    res = true;
                }
                 if(res) break;
            }
        }
    }

    
    sort(vt.begin(), vt.end());
    
    for(int it: vt){
        if(res.empty() || res.back() != it) {
            if(it != 0)
                res.push_back(it);
        }
    }
    
    for(int it: res){
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}
