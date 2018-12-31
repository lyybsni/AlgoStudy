/* lyybsni 10196 C++ "Check the Check" */

#define WHITE 'K'
#define BLACK 'k'
#define EMPTY '.'
#define SIZE 8

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

bool bound(int x){
    return (x < 0 || x >= SIZE);
}

int check(int x, int y, int delta_x, int delta_y, char chess, int offset, char** map){
    int changed_x = x+delta_x;
    int changed_y = y+delta_y;
    if(bound(changed_x) || bound(changed_y)) return false;
    
    if (map[changed_x][changed_y] == chess+offset)
        return 1;
    else if(map[changed_x][changed_y] == EMPTY)
        return 0;
    else return -1;
}

int check(int x, int y, char chess, int offset, char** map){
    return check(x,y,0,0,chess,offset,map);
}

bool checkRookLike(int x, int y, char chess, int offset, char** map){
    bool res = false;
    
    int co_x[4] = {1,-1,0,0};
    int co_y[4] = {0,0,1,-1};
    
    for(int j = 0; j < 4; j++){
        bool isTerm = false;
        for(int i = 1; i < SIZE; i++){
            //            cout << i << " " << j << " " << check(x,y,i*co_x[j],i*co_y[j],chess,offset,map) << endl;
            switch(check(x,y,i*co_x[j],i*co_y[j],chess,offset,map)){
                case 1:
                    return true;
                case -1:
                    isTerm = true;
                    break;
            }
            if(isTerm) break;
        }
    }
    
    return res;
}

bool checkBishopLike(int x, int y, char chess, int offset, char** map){
    bool res = false;
    
    int co_x[4] = {1,1,-1,-1};
    int co_y[4] = {1,-1,1,-1};
    
    for(int j = 0; j < 4; j++){
        bool isTerm = false;
        for(int i = 1; i < SIZE; i++){
//            cout << i << " " << j << " " << check(x,y,i*co_x[j],i*co_y[j],chess,offset,map) << endl;
            switch(check(x,y,i*co_x[j],i*co_y[j],chess,offset,map)){
                case 1:
                    return true;
                case -1:
                    isTerm = true;
                    break;
            }
            if(isTerm) break;
        }
    }
    
    return res;
}

bool checkNight(int x, int y, char chess, int offset, char** map){
    int change_x[8] = {-2,-1,1,2,2,1,-1,-2};
    int change_y[8] = {-1,-2,-2,-1,1,2,2,1};
    
    bool res = false;
    for(int i = 0; i < 8; i++){
        if(check(x,y,change_x[i],change_y[i],chess,offset,map) == 1){
                return true;
        }
    }
    return res;
}

bool checkKing(char king, int x, int y, char** map){
    /* (x,y) is the coordinate of the king */
    
    int offset = 'A'-'a';
    if(king == WHITE){
        offset = 0;
    }
    
    bool res = false;
    if(king == BLACK){
        res = (check(x, y, 1, -1, 'p', offset, map)==1) || (check(x, y, 1, 1, 'p', offset, map)==1);
    } else {
        res = (check(x, y, -1, -1, 'p', offset, map)==1) || (check(x, y, -1, 1, 'p', offset, map)==1);
    }
    if(res) return true;
    
    res = res || checkRookLike(x, y, 'r', offset, map);
//    cout << "Rook: " << king << res << endl;
    
    res = res || checkBishopLike(x, y, 'b', offset, map);
//    cout << "Bishop: " << king << res << endl;
    
    res = res || checkRookLike(x, y, 'q', offset, map) || checkBishopLike(x, y, 'q', offset, map);
//    cout << "Queen: " << king << res << endl;
    
    res = res || checkNight(x, y, 'n', offset, map);
//    cout << "Night: " << king << res << endl;
    
    return res;
}


int main(){
    bool input = true;
    int count = 0;
    char** map = new char*[SIZE];
    for(int i = 0; i < SIZE; i++){
        map[i] = new char[SIZE];
    }
    
    while(input){
        bool isChanged = false;
        
        int white = -1, black = -1;
        char tempChar;
        for(int i = 0; i < SIZE*SIZE; i++){
            cin >> tempChar;
            map[i/SIZE][i%SIZE] = tempChar;
            if(tempChar != '.') isChanged = true;
            
            if(tempChar == WHITE) white = i;
            else if(tempChar == BLACK) black = i;
        }
        
        if(!isChanged){
            input = false;
            break;
        }
        
        count++;
        cout << "Game #" << count << ": ";
        
        if(checkKing(WHITE, white/SIZE, white%SIZE, map)) cout << "white";
        else if(checkKing(BLACK, black/SIZE, black%SIZE, map)) cout << "black" ;
        else cout << "no";
        cout << " king is in check." << endl;
    
//        checkKing(BLACK, black/SIZE, black%SIZE, map);
        
//        cout << black << " "<< white << endl;

    }
    return 0;
}
