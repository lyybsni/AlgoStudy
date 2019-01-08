#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class base{
public:
    int time;
    base(){};
    base(int time):time(time){};
};

class left_b:public base{
public:
    int time;
    left_b(int time):time(time){};
};

class right_b:public base{
public:
    int time;
    right_b(int time):time(time){};
};

int comp(const base& base1, const base& base2){
    return base1.time - base2.time;
}

int main(){
    
    int case_number;
    cin >> case_number;
    
    while(case_number--){
        int car_number;
        cin >> car_number;
        
        list<base> master;
        
        int str, end;
        while(car_number--){
            cin >> str >> end;
            master.push_back(left_b(str));
            master.push_back(right_b(end));
        }
        
        sort(master.begin(), master.end(), comp);
        
        
        
    }
    
    return 0;
}
