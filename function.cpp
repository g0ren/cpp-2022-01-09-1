#include <iostream>

using namespace std;

template<typename T, typename R> T max(T a, R b) {
	return (a > b) ? a : b;
}

template<typename T, typename R> T min(T a, R b) {
	return (a < b) ? a : b;
}

template<typename T, typename R> T pow(T base, R power) {
	int n { 1 };
	for (int i = 0; i < power; i++)
		n *= base;
	return n;
}

int sumOfRange(int start, int end) {
	int sum { 0 };
	for (int i = start; i <= end; i++)
		sum += i;
	return sum;
}

int aliquotSum(int n) {
	int sum { 0 };
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum;
}

bool isPerfect(int n) {
	return aliquotSum(n) == n;
}

void printPerfectNumbersInRange(int start, int end) {
	for (int i = start; i <= end; i++)
		if (isPerfect(i))
			cout << i << " ";
	cout << endl;
}

int numberOfDigits(int n) {
	int num { 0 };
	while (n) {
		n /= 10;
		num++;
	}
	return num;
}

int sumOfDigits(int n) {
	int sum { 0 };
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

bool isLuckyNumber(int n) {
	return sumOfDigits(n % 1000) == sumOfDigits(n / 1000);
}

void task1() {
	int n { 0 }, m { 0 };
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter m: ";
	cin >> m;
	cout << "n^m=" << pow(n, m) << endl << endl;
}
void task2() {
	int a { 0 }, b { 0 };
	cout << "Enter two integers" << endl;
	cin >> a;
	cin >> b;
	cout << "Sum of all integers between " << min(a, b) << " and " << max(a, b)
			<< " is " << sumOfRange(min(a, b), max(a, b)) << endl << endl;
}
void task3() {
	int a { 0 }, b { 0 };
	cout << "Enter two integers" << endl;
	cin >> a;
	cin >> b;
	cout << "All perfect numbers between " << min(a, b) << " and " << max(a, b)
			<< ":" << endl;
	printPerfectNumbersInRange(min(a, b), max(a, b));
	cout << endl;
}

void task4() {
	int card { 0 }, suit { 0 };
	while (!card) {
		cout
				<< "Enter card number (Ace is 1, Jack is 11, Queen is 12, King is 13)"
				<< endl;
		cin >> card;
		if (card < 1 || card > 13) {
			card = 0;
			cout << "Wrong number!" << endl;
		}
	}
	while (!suit) {
		cout
				<< "Enter the suit (1 - Hearts, 2 - Diamonds, 3 - Clubs, 4 - Spades)"
				<< endl;
		cin >> suit;
		if (suit < 1 || suit > 4) {
			suit = 0;
			cout << "Wrong suit!";
		}
	}
	switch (card) {
	case 1:
		cout << "A";
		break;
	case 11:
		cout << "J";
		break;
	case 12:
		cout << "Q";
		break;
	case 13:
		cout << "K";
		break;
	default:
		cout << card;
	}
	cout << " ";
	switch (suit) {
	case 1:
		cout << "of Hearts" << endl;
		break;
	case 2:
		cout << "of Diamonds" << endl;
		break;
	case 3:
		cout << "of Clubs" << endl;
		break;
	case 4:
		cout << "of Spades" << endl;
		break;
	}
	cout << endl;
}

void task5() {
	int n { 0 };
	while (1) {
		cout << "Enter a 6-digit number: ";
		cin >> n;
		if (!(numberOfDigits(n) == 6)) {
			cout << "Not a 6-digit number!" << endl;
			continue;
		}
		if (isLuckyNumber(n)) {
			cout << n << " is a \"lucky\" number";
		} else {
			cout << n << " is not a \"lucky\" number";
		}
		cout << endl << endl;
		return;
	}
}

int main() {
	int command { 0 };
	do {
		cout << "A program for testing various functions" << endl;
		cout
				<< "Task 1: Take numbers n and m and return n^m (only works properly with positive integer m)"
				<< endl;
		cout
				<< "Task 2: Take two numbers and return sum of all integers in the range between them"
				<< endl;
		cout
				<< "Task 3: Take two numbers and print the list of all perfect numbers in the range between them"
				<< endl;
		cout << "Task 4: Take and print a playing card" << endl;
		cout
				<< "Task 5: Take a 6-digit number and tell if it's a \"lucky\" number"
				<< endl;
		cout << "0 to exit" << endl;
		cin >> command;
		switch (command) {
		case 0:
			return 0;
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		case 5:
			task5();
			break;
		default:
			cout << "Wrong command!" << endl << endl;
		}
	} while (command);

	return 0;
}
