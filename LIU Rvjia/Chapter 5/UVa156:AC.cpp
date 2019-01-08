/* lyybsni 156 C++ "Ananagram" */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, vector<string>> dictionary;

string preprocessing(string mystr){
    string temp = mystr;
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] <= 'Z' && temp[i] >= 'A'){
            temp[i] = temp[i] + ('a' - 'A');
        }
    }
    sort(temp.begin(), temp.end());
    return temp;
}

void print(){
    vector<string> result;
    map<string, vector<string> >::iterator it = dictionary.begin();
    for(; it != dictionary.end(); it++){
        vector<string> temp = it->second;
        if(temp.size() == 1){
            result.push_back(temp.back());
        }
    }

    sort(result.begin(), result.end());
    for(string item: result){
        cout << item << endl;
    }

}

int main(){

    string temp;

    while(cin >> temp){
        if(temp == "#") break;
        else{
            string result = preprocessing(temp);
            if(!dictionary.count(result)){
                vector<string> vc;
                vc.push_back(temp);
                dictionary[result] = vc;
            } else {
                dictionary[result].push_back(temp);
            }
        }
    }
    print();
    return 0;
}