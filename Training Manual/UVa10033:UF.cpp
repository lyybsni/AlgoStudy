/* lyybsni 10033 C++ "Intepreter" */

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    
    int reg[10];          // initialize as all 0s
    memset(reg, 0, sizeof(int)*10);
    
    int ram[1000];
    memset(ram, 0, sizeof(int)*1000);
    
    
    int curr = 0;
    int dir;
    int c, d, n;
    while(cin >> dir) {
        c = dir/100;
        d = (dir/10)%10;
        n = dir%10;
        switch (c) {
            case 1:
                //halt
                cout << curr << endl;
                break;
            case 2:
                reg[d] = n;
                break;
            case 3:
                reg[d] += n;
                break;
            case 4:
                reg[d] *= n;
                break;
            case 5:
                reg[d] = reg[n];
                break;
            case 6:
                reg[d] += reg[n];
                break;
            case 7:
                reg[d] *= reg[n];
                break;
            case 8:
                reg[d] = ram[n];
                break;
            case 9:
                ram[d] = reg[n];
                break;
            case 0:
                if(ram[d] < 100 || ram[d] < 10 || ram[d]%10 == 0 || (ram[d]/10)%10 == 0) break;
                curr = ram[d];
                break;
        }
    }
    
    return 0;
}
