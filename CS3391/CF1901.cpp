/* lyybsni C++ Goodbye 2018 A */

#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    
    int min = a;
    b -= 1;
    c -= 2;
    if(min > b) min = b;
    if(min > c) min = c;
    
    cout << 3*min+3 << endl;
    
    return 0;
}
