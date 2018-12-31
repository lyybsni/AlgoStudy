/* lyybsni 10142 C++ "Australian Voting" */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    
    int case_number;
    cin >> case_number;
    
    for(int i = 0; i < case_number; i++){
        
        int person;
        cin >> person;
        
        string* people = new string[person];
        int*** voting = new int**[person];
        
        for(int i = 0; i < person; i++){
            voting[i] = new int*[person];
            for(int j = 0; j < person; j++){
                voting[i][j] = new int[person];
                memset(voting[i][j],0,sizeof(int)*person);
            }
        }
        
        for(int i = 0; i < person; i++){
            cin >> people[i];
        }
        
        string line;
        while(getline(cin, line)){
            istringstream stream(line);
            int prev, curr;
            stream >> prev;
            voting[prev][0]++;
            
            for(int i = 1; i < person; i++){
                cin >> curr;
                voting[curr][i]++;
            }
            
        }
    
    }
    return 0;
}
