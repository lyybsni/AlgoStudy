/* Largest Subsequence */

#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main()
{
	stack<char> T;
	int caseNumber;			// number of strings
	cin >> caseNumber;

	for (int i = 0; i < caseNumber; i++) {
		string curr;
		cin >> curr;

		for (char tempChar : curr) {
			while (!T.empty() && T.top() < tempChar) {
				T.pop();
			}
			T.push(tempChar);
		}

		string result = "";
		while (!T.empty()) {
			result = T.top() + result;
			T.pop();
		}

		cout << result << endl;
	}

	return 0;
}

