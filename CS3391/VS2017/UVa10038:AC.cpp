/* lyybsni 10038 C++ "Jolly Jumpers" */

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int count;		/* the count of the current case */

	while (cin >> count) {

		if (count == 0) {
			cout << "Not jolly" << endl;
			continue;
		}

		bool* changed = new bool[count];
		bool isJolly = true;

		memset(changed, 0, sizeof(bool)*count);

		int prev, curr;		/* previous one and current one */
		cin >> prev;
		for (int i = 1; i < count; i++) {
			cin >> curr;
			int diff = abs(curr - prev);

			if (diff <= 0 || diff >= count) {
				isJolly = false;
//				cout << "Checkpoint 1: difference is out of bound: " << diff << endl;
			}
			else if (changed[diff]) {
				isJolly = false;
//				cout << "Checkpoint 2: difference is repeating." << endl;
			}
			else {
				changed[diff] = true;
			}
			
			prev = curr;
		}

		if (!isJolly) {
			cout << "Not jolly" << endl;
		}
		else {
			for (int i = 1; i < count; i++) {
				if (!changed[i]) {
					isJolly = false;
					cout << "Not jolly" << endl;
					break;
				}
			}
			if (isJolly) {
				cout << "Jolly" << endl;
			}
		}
	}

	return 0;
}

