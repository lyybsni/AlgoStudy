/* lyybsni 10050 C++ "Hartals" */

#define DAYS_IN_A_WEEK 7
#define FRI 5
#define SAT 6

#include <iostream>
#include <string.h>
using namespace std;

int main() {

	int case_number;		/* the test case number */
	cin >> case_number;

	for (int i = 0; i < case_number; i++) {
		int day_number;		/* the testing days */
		int party_number;	/* the party number */

		cin >> day_number >> party_number;

		int* party_para = new int[party_number];
		for (int j = 0; j < party_number; j++) {
			cin >> party_para[j];
		}

		int count = 0;
		for (int j = 0; j < day_number; j++) {
			if (j%DAYS_IN_A_WEEK == FRI || j%DAYS_IN_A_WEEK == SAT) continue;

			for (int k = 0; k < party_number; k++) {
				if ((j + 1) % party_para[k] == 0) {
					count++;
					break;
				}
			}
		}

		cout << count << endl;
	}

	return 0;
}