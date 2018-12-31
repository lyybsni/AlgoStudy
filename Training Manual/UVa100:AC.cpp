/* lyybsni 100 C++ "3n + 1 Problem" */
/* Problem Type: NP-Complete */
/* Version 1: Running time 0.310 */

#include <iostream>
using namespace std;

int cycle(int num);
int version1(int start, int end);

int main() {
    int start, end;         // record the start and end number, in [0, 1e6]
    int max = 1;            // the max number of cycle
    while(cin >> start >> end){
        /* compute the maximum in the current range */
        cout << start << " " << end << " " << version1(start, end) << endl;
        /* release the max, re-initialize */
        max = 1;
    }
    return 0;
}

/**
 * Sub-function to compute the cycle length
 */
int cycle(int num) {
    int count = 1;          // initialize
    while (num != 1) {      // bondary case: num == 1, count == 1
        if (num % 2 == 0) num /= 2;
        else num = 3*num + 1;
        count++;
    }
    return count;
}

/**
 * Brute force
 */
int version1(int start, int end) {
    /* reverse the two if @end is greater than @start */
    if (start > end) swap(start, end);
    int max = 1;            // initialize as the possible smallest
    for(int i = start; i <= end; i++) {
        int current = cycle(i);
        if (max < current) max = current;
    }
    return max;
}
