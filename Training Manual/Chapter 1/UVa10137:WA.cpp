/* lyybsni 10137 C++ "The Trip" */

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    // Analysis: the result is the sum of Negative parts or Positive parts
    
    int people;                 // the number of the people
    while(cin >> people){
        if (people == 0) break;
        
        double sum = 0;
        double* money = new double[people];
        
        for(int i = 0; i < people; i++){
        // iteration 1: Scan all to get average
            cin >> money[i];
            sum += money[i];
        }
        
        double ave = ((int) (sum/people*100)/100.0);
        double res = 0;
        double res1 = 0;
        
        for(int i = 0; i < people; i++){
            double diff = money[i] - ave;
            if(diff < 0) res += money[i];
            else if(diff > 0) res1 += money[i];
        }
        
        cout << "$" << setprecision(2) << fixed << (res1 - res)/2 << endl;
        
        delete[] money;
    }
    
    
    return 0;
}
