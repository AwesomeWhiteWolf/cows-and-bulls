#include <iostream>
using namespace std;

class Player {
public:
	string str;
	string number(int name) {
		//srand(time(0));
		string answers[5] = {"Good choice\n", "Okay\n", "Wise choice\n", "Excellent\n", "Amazing\n"};
		string s;
		cout << "P" << name << " guess your number: ";
		cin >> s;
		cout << answers[rand() % 5];
		system("pause");
		system("cls");
		return s;
	}
	int answer(string str, int name) {
		string ans;
		cout << "P" << name << " enter your answer: ";
		cin >> ans;
		int bulls = 0, cows = 0;
		for (size_t i = 0; i < 4; ++i) {
			if (ans[i] == str[i]) {
				bulls++;
			}
			else if (str.find(ans[i]) != string::npos) {
				cows++;
			}
		}
		cout << "Cows: " << cows << "\nBulls: " << bulls << "\n";
		return bulls;
	}
};

void greetings() {
	cout << "Welcome to the game Cows and Bulls!\n";
	system("pause");
	cout << "You need to choose the first player and then guess a four-digit number one by one.\n";
	system("pause");
	cout << "One rule: don't peek ;)\n";
	system("pause");
}

int main() {
	system("mode con cols=60 lines=20");
	srand(time(NULL));

	Player p1;
	Player p2;
	//greetings();
	p1.str = p1.number(1);
	p2.str = p1.number(2);

	while (true) {
		//p1
		if (p1.answer(p2.str, 1) == 4) {
			cout << "The P1 win! But P2 still have a chance\n";
			if (p2.answer(p1.str, 2) == 4) {
				cout << "P1 and P2 win!!!\n";
			}
			else {
				cout << "P1 win!!!\n";
			}
			break;
		}

		//p2
		if (p2.answer(p1.str, 2) == 4) {
			cout << "P2 win!!!\n";
			break;
		}
	}
	
	system("pause");
	return 0;
}

