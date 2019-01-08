/* lyybsni 10082 C++ "WERTYU" */

#include <iostream>
#include <string>
using namespace std;

int main(){
    const string reverse = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    
    string input;
    while(getline(cin, input)){
    
        string output = "";
        for(char tempChar: input){
            int loc = (int) reverse.find(tempChar);
            if(loc != -1)
                output = output + reverse.at(loc-1);
            else output = output + tempChar;
        }
        
        cout << output << endl;
    }
    
    return 0;
}
