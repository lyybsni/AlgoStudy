/* Largest Subsequence */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class disjoint_set {

private:
	int* container;
	int* depth;

public:
	disjoint_set(int size) {
		container = new int[size];
		for (int i = 0; i < size; i++) {
			container[i] = i;
			depth[i] = 1;
		}
	}

	bool ds_find(int i, int j) {
		int root_i = i, root_j = j;
		while (depth[root_i] != 1) {
			root_i = container[i];
		}
		while (depth[root_j] != 1) {
			root_j = container[j];
		}
		return root_i == root_j;
	}

	void ds_union(int i, int j) {
		int root_i = i, root_j = j;
		if (depth[i] > depth[j]) {
			while (depth[root_i] != 1) {
				root_i = container[i];
			}
			container[j] = root_i;
			depth[j] = depth[root_i] + 1;
		}
		else {
			while (depth[root_j] != 1) {
				root_j = container[j];
			}
			container[i] = root_j;
			depth[i] = depth[root_j] + 1;
		}
	}

};

int main()
{
	int caseNumber;			// number of strings
	cin >> caseNumber;

	int person, pair;

	for (int i = 0; i < caseNumber; i++) {
		cin >> person >> pair;

		disjoint_set T(person);

		int first, second;

		for (int j = 0; j < pair; j++) {
			cin >> first >> second;
			if (!T.ds_find(first, second)) {
				T.ds_union();
			}
		}

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

