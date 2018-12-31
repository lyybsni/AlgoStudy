/* lyybsni 706 C++ "LCD Display"*/

#include <iostream>
#include <stdlib.h>
using namespace std;
//                         0,1,2,3,4,5,6,7,8,9
const int level[5][10] = {{1,0,1,1,0,1,1,1,1,1},   // 0 for no, 1 for yes (for level 1,3,5)
                          {2,1,1,1,2,0,0,1,2,2},   // 0 for left, 1 for right, 2 for both (for level 2,4)
                          {0,0,1,1,1,1,1,0,1,1},
                          {2,1,0,1,1,1,2,1,2,1},
                          {1,0,1,1,0,1,1,0,1,1}};

void printHorizontal(int size, int* number, int lvl, int len) {
    string dash(size,'-');
    string null(size+2,' ');
    
    dash = " "+dash+" ";
    
    for(int i = 0; i < len; i++) {
        if (i != 0) cout << " ";
        switch (level[lvl][number[i]]){
            case 0:
                cout << null;
                break;
            case 1:
                cout << dash;
                break;
        }
    }
    
    cout << endl;
}

void printVertical(int size, int* number, int lvl, int len) {
    string null(size,' ');
    string left = "| "+null;
    string right = null+" |";
    string both = "|"+null+"|";
    
    for (int j = 0; j < size; j++){
        for (int i = 0; i < len; i++) {
            if (i != 0) cout << " ";
                switch (level[lvl][number[i]]){
                case 0:
                    cout << left;
                    break;
                case 1:
                    cout << right;
                    break;
                case 2:
                    cout << both;
            }
        }
        cout << endl;
    }
}

void printNumber(int size, int number) {
    string text = to_string(number);
    int len = (int) text.length();
    
//    cout << "Line 61: Length is " << len << endl;
    
    int* arr = new int[len];
    for(int i = len-1; i >= 0; i--) {
        arr[i] = number%10;
        number /= 10;
    }
    
    for (int i = 0; i < 5; i++) {
        if (i%2 == 0) printHorizontal(size, arr, i, len);
        else printVertical(size, arr, i, len);
    }
}

int main(){
    int size, number;       // two input variables
    while(cin >> size >> number) {
        if (size == 0 && number == 0) break;    // end condition
        printNumber(size, number);
        cout << endl;
    }
    return 0;
}
