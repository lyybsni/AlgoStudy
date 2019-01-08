/* lyybsni 10815 C++ "Andy's First Dictionary" */

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <set>
using namespace std;

string transform(string& str){
    string temp = "";
    for(char mychar: str){
        if( mychar <= 'Z' && mychar >= 'A'){
            mychar = mychar + 'a' - 'A';
        }
        if ( mychar <= 'z' && mychar >= 'a' ){
            temp += mychar;
        } else {
            temp += ' ';
        }
    }
    return temp;
}

int main() {
    set<string> str;
    string temp;

//    for(int i = 0; i < 10; i++){
    while(cin >> temp){
        cin >> temp;
        stringstream ss(transform(temp));
        while(ss >> temp) str.insert(temp);
    }

    for(string mystr: str){
        cout << mystr << endl;
    }

    return 0;
}