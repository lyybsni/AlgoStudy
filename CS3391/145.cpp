/* lyybsni 145 C++ "Gound Tele" */

#define MIN_IN_A_DAY 1440
#define MORNING 8
#define NOON 18
#define NIGHT 22

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int day_time(int hr, int mn){
    if(hr >= NOON){
        hr = NOON;
        mn = 0;
    }
    return (hr-MORNING)*60 + mn;
}

int eve_time(int hr, int mn){
    if(hr >= NIGHT){
        hr = NIGHT;
        mn = 0;
    }
    return (hr-NOON)*60 + mn;
}

int nig_time(int hr, int mn){
    if (hr >= MORNING) {
        hr = MORNING;
        mn = 0;
    }
    return (hr-NIGHT)*60 + mn;
}

int main(){
    
    const double day_fee[5] = {0.10, 0.25, 0.53, 0.87, 1.44};
    const double eve_fee[5] = {0.06, 0.15, 0.33, 0.47, 0.80};
    const double nig_fee[5] = {0.02, 0.05, 0.13, 0.17, 0.30};
    
    char type;
    int type_change;
    while(cin >> type){
        if(type == '#') break;
        else type_change = (type - 'A');
        
        int day, eve, nig;
        string phone_number;
        int str_hr, str_mn, end_hr, end_mn;
        
        cin >> phone_number >> str_hr >> str_mn >> end_hr >> end_mn;
        
        if(end_hr < str_hr || (end_hr >= str_hr && end_mn < str_mn)) {
            /* span accross the day time */
            day = day_time(end_hr, end_mn) - day_time(str_hr, str_mn);
            eve = eve_time(end_hr, end_mn) - eve_time(str_hr, str_mn);
            nig = nig_time(end_hr, end_mn) - nig_time(str_hr, str_mn);
        } else {
            day = day_time(end_hr, end_mn) - day_time(str_hr, str_mn);
            eve = eve_time(end_hr, end_mn) - eve_time(str_hr, str_mn);
            nig = nig_time(end_hr, end_mn) - nig_time(str_hr, str_mn);
        }

        double fee = day_fee[type_change]*day + eve_fee[type_change]*eve + nig_fee[type_change]*nig;
        
        cout << fee << endl;
    }
    
    return 0;
}
