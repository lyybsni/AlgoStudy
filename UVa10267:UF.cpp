/* lyybsni 10267 C++ "Graphical Editor"*/

#include <iostream>
#include <string.h>
using namespace std;

void paint(char** map, int x, int y, char color) {
    map[x-1][y-1] = color;
}

void paint(char** map, int x1, int x2, int y1, int y2, char color){
    for (int i = x1-1; i < x2; i++) {
        for (int j = y1-1; j < y2; j++) {
            map[i][j] = color;
        }
    }
}

void print(char** map, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

int main(){
    char control, buff;
    string curr;
    
    int height, width;
    char** map;
    
    int x1, x2, x3, x4;
    
    while(cin.get(control)){
        if(control == '\n') continue;
//        cout << "Control Element Is: " << control << endl;
        switch(control){
            case 'I':
                cin >> width >> height;
                map = new char*[height];
                for (int i = 0; i < height; i++) {
                    map[i] = new char[width];
                }
            case 'C':
                paint(map, 1, height, 1, width, 'O');
                break;
            case 'L':
//                cout << "Line 50: " << endl;
                cin >> x1 >> x2 >> buff;
//                cout << "Line 50: " << x1 << " " << x2 << endl;
                paint(map, x2, x1, buff);
                break;
            case 'S':
                cin.get(buff);
                getline(cin, curr);
                cout << curr << endl;
                print(map, height, width);
                break;
            case 'V':
                cin >> x1 >> x2 >> x3 >> buff;
                if(x2 > x3) swap(x2, x3);
                paint(map, x2, x3, x1, x1, buff);
                break;
            case 'H':
                cin >> x1 >> x2 >> x3 >> buff;
                if(x1 > x2) swap(x1, x2);
                paint(map, x3, x3, x1, x2, buff);
                break;
            case 'K':
                cin >> x1 >> x2 >> x3 >> x4 >> buff;
                if(x1 > x2) swap(x1, x2);
                if(x3 > x4) swap(x3, x4);
                paint(map, x3, x4, x1, x2, buff);
                break;
            case 'F':
                cin >> x1 >> x2 >> buff;
                /* All the -linked- need a BFS */
                if (x2 > 1 && map[x1][x2-1] == map[x1][x2]) map[x1][x2-1] = buff;
                if (x2 < height && map[x1][x2+1] == map[x1][x2]) map[x1][x2+1] = buff;
                if (x1 > 1 && map[x1-1][x2] == map[x1][x2]) map[x1-1][x2] = buff;
                if (x1 < width && map[x1+1][x2] == map[x1][x2]) map[x1+1][x2] = buff;
                map[x1][x2] = buff;
                break;
            case 'X':
                return 0;
                break;
            default:
                /* useless */
                getline(cin, curr);
                break;
        }
        
    }
    
    return 0;
}
