/* lyybsni 10315 C++ "Poker Hands" */

# define CARDS 5

#include <iostream>
using namespace std;

const char value[13] = { '2','3','4','5','6','7','8','9','T','J','Q','K','A' };
const char color[4] = { 'C','D','H','S' };

/* test cases:

2H 3D 5S 9C KD 2C 3H 4S 8C AH
2H 4S 4C 2D 4H 2S 8S AS QS 3S
2H 3D 5S 9C KD 2C 3H 4S 8C KH
2H 3D 5S 9C KD 2D 3H 5C 9S KS

white wins/black wins/black wins/ties*/


int convert_value(char c) {
	if (c <= '9' && c >= '2') return (c - '2');
	else {
		switch (c) {
		case 'T': return 8;
		case 'J': return 9;
		case 'Q': return 10;
		case 'K': return 11;
		case 'A': return 12;
		default: return -1;
		}
	}
}

struct card {
	int value;
	char color;
	card() {};
	card(char v, char c) :color(c) {
		this->value = convert_value(v);
	};

	/* testing */
	void print() { cout << value << color << '\t'; }
};

void print(card* black, card* white) {
	cout << "Checkpoint #3: black is: ";

	for (int i = 0; i < CARDS; i++) {
		black[i].print();
	}
	cout << endl << "Checkpoint #3: white is: ";
	for (int i = 0; i < CARDS; i++) {
		white[i].print();
	}
	cout << endl;
}

void sort(card* cards) {
	for (int j = 1; j < CARDS; j++) {
		for (int i = 1; i < CARDS; i++) {
			if (cards[i].value < cards[i - 1].value) {
				swap(cards[i], cards[i - 1]);
			}
		}
	}
}

int* pairs(card* cards) {
	int count = 0;
	int cnt[2] = { -1,-1 };
	for (int i = 0; i < CARDS - 1; i++) {
		if (cards[i].value == cards[i + 1].value) {
			cnt[count++] = cards[i].value;
			i++;
		}
	}
	return cnt;
}

int number_of_pairs(card* cards) {
	int* pair = pairs(cards);
	if (pair[1] != -1) return 2;
	else if (pair[0] != -1) return 1;
	return 0;
}

int max_number_of_same(card* cards) {
	/* 1:High Card/Straight/Straight Flush -> 2:Pair/Two Pairs */
	/* 3:Three of a Pair/Full House -> 4:Four of A Kind */
	/* Suite is not considered then */
	int max = 1;
	int count = 1;
	int curr = cards[0].value;
	for (int i = 1; i < CARDS; i++) {
		int temp = cards[i].value;
		if (curr == temp) count++;
		else {
			curr = temp;
			if (count > max) max = count;
			count = 1;
		}
	}
	if (count > max) max = count;
//	cout << max;
	return max;
}

bool isConsec(card* cards) {
	for (int i = 1; i < CARDS; i++) {
		if (cards[i].value - cards[i-1].value != 1) return false;
	}
	return true;
}

bool isSameSuite(card* cards) {
	char suite = cards[0].color;
	for (int i = 1; i < CARDS; i++) {
		if (suite != cards[i].color) return false;
	}
	return true;
}

double rank_values(card* cards) {
	double result = 0;
	for (int i = 0; i < CARDS; i++) {
		result = result + cards[i].value;
		result = result / 20;
	}
	result /= 8000;
	return result;
}

double rank_cards(card* cards) {
	double rank = 0;

	bool same = isSameSuite(cards);
	bool cons = isConsec(cards);
	int max = max_number_of_same(cards);
	int pair = number_of_pairs(cards);

	if (same && cons) rank = 8;
	else if (max == 4) rank = 7;
	else if (max == 3 && pair == 2) { 
		rank = 6; 
		rank += pairs(cards)[0] / 400 + pairs(cards)[1] / 20;
	}
	else if (same) rank = 5;
	else if (cons) rank = 4;
	else if (max == 3) rank = 3;
	else if (pair == 2) {
		rank = 2;
		rank += pairs(cards)[0] / 400 + pairs(cards)[1] / 20;
	}
	else if (pair == 1) {
		rank = 1;
		rank += pairs(cards)[0] / 400;
	}

	rank = rank + rank_values(cards);
	return rank;
}

void printResult(card* black, card* white) {
	sort(black);
	sort(white);

	double black_grade = rank_cards(black);
	double white_grade = rank_cards(white);

//	cout << "Checkpoint #2: black is: " << black_grade << " and white is: " << white_grade << endl;

//	print(black, white);

	if (black_grade > white_grade) {
		cout << "Black wins." << endl;
	}
	else if (black_grade < white_grade) {
		cout << "White wins." << endl;
	}
	else {
		cout << "Ties." << endl;
	}
}

int main() {

	char tempChar;		/* for input */

	int count = 0;
	card* black = new card[CARDS];
	card* white = new card[CARDS];

	while ((tempChar = getchar()) != EOF) {

//		cout << "temp checkpoint: the input is well recorded: " << tempChar << endl;

		if (tempChar == ' ') /* do nothing */;
		else if (tempChar == '\n') {
//			cout << "Checkpoint #1: a case is finished." << endl;
			count = 0;
//			print(black, white);
			printResult(black, white);
			black = new card[CARDS];
			white = new card[CARDS];
		}
		else {
			card tempCard(tempChar, cin.get());
//			tempCard.print();
			if (count < CARDS) {
//				cout << "CP #4: Black is appended." << endl;
				black[count] = tempCard;
//				black[count].print();
				count++;
			}
			else white[(count++) - CARDS] = tempCard;
//			print(black, white);
		}
	}

	return 0;
}
