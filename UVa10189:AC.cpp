/* lyybsni 10189 C++ "Minesweeper" */
/* Time Complexity: O(m*n) */
/* Space Complexity: O(m*n) */
/* Actual Running Time: 0.000 */

#include <string.h>
#include <iostream>
using namespace std;

void add(int, int, int**);
const int loc[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

int main(){
    int width, height;           // width and height of the maze, in [0, 100]
    int field = 1;               // field number
    while(cin >> width >> height) {
        /* End condition: width == height == 0 */
        if (width == 0 && height == 0) break;
        
        /* Creating storage*/
        int** result = new int*[width+2];
        for(int i = 0; i < width + 2; i++) {
            result[i] = new int[height+2];
            memset(result[i],0,sizeof(int)*(height+2));
        }
        
        char temp;              // reading
        for(int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                cin >> temp;
                if (temp == '*') {
                    result[i+1][j+1] = -1;
                    for(int k = 0; k < 8; k++) {
                        add(i+1+loc[k][0],j+1+loc[k][1],result);
                    }
                }
            }
        }
        
        /* Print */
        if(field != 1) cout << endl;                // formatting
        cout << "Field #" << field << ":" << endl;
        for (int i = 1; i <= width; i++) {
            for (int j = 1; j <= height; j++) {
                if(result[i][j] != -1){
                    cout << result[i][j] << "";
                } else {
                    cout << "*";
                }
            }
            cout << endl;
        }
        
        /* Deletion of the array */
        for(int i = 0; i < width+2; i++) {
            delete[] result[i];
        }
        delete[] result;
        
        field++;
    }
    return 0;
}

void add(int x, int y, int** a){
    if(a[x][y] != -1) a[x][y]++;
}
