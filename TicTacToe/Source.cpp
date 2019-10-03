#include <iostream>
using namespace std;

void board(char* arr, size_t size) {
	cout << endl;
	for (size_t i = 0; i < size; i = i+3) {
		for (size_t j = i; j < (i + 3); j++) {
			cout << " | " << *(arr + j) << " |";
		}
		cout << endl;
	}
}

int checkwin(char* arr, size_t size) {
	int n = 0 , k=0 , l=0 , m= 0;

	for (size_t i = 0; i < size; i = i + 3) {
		n = 0;
		for (size_t j = i; j < (i + 2); j++) {
			if (*(arr + j) == *(arr + (j + 1)) ) {
				n = n + 1;
			}
		}
		if (n == 2) {
			return 1;
		}
	}

	for (size_t i = 0; i < size - 1; i = i + 4) {
		if (*(arr + i) == *(arr + (i + 4))) {
			k = k + 1;
		}
		if (k == 2) {
			return 1;
		}
	}

	for (size_t i = 2; i < 5; i = i + 2) {
		if (*(arr + i) == *(arr + (i + 2))) {
			l = l + 1;
		}
		if (l == 2) {
			return 1;
		}
	}

	for (size_t i = 0; i < 3; i++) {
		m = 0;
		for (size_t j = i; j < (i + 6); j = j + 3) {
			if (*(arr + j) == *(arr + (j + 3))) {
				m = m + 1;
			}
		}
		if (m == 2) {
			return 1;
		}
	}
}

void printIntro() {
	cout << "				#     #                                              #######           #######             #######                  #######               " << endl;
	cout << "				#  #  # ###### #       ####   ####  #    # ######       #     ####        #    #  ####        #      ##    ####        #     ####  ###### " << endl;
	cout << "				#  #  # #      #      #    # #    # ##  ## #            #    #    #       #    # #    #       #     #  #  #    #       #    #    # #	   " << endl;
	cout << "				#  #  # #####  #      #      #    # # ## # #####        #    #    #       #    # #            #    #    # #            #    #    # #####  " << endl;
	cout << "				#  #  # #      #      #      #    # #    # #            #    #    #       #    # #            #    ###### #            #    #    # #      " << endl;
	cout << "				#  #  # #      #      #    # #    # #    # #            #    #    #       #    # #    #       #    #    # #    #       #    #    # #      " << endl;
	cout << "				## ##  ###### ######  ####   ####  #    # ######       #     ####        #    #  ####        #    #    #  ####        #     ####  ######  " << endl << endl;
	cout << "You Will See 10 Number's on the Board, Choose a Number and then Enter it to Mark There " << endl;
	cout << "The Game will start with Player 1 as O " << endl << endl;
}

int main() {
	char arr[] = { '1', '2', '3', '4', '5' , '6', '7', '8', '9' };
	size_t size = sizeof(arr) / sizeof(arr[0]);
	printIntro();
	board(arr, size);
	int k , player;

	do {
		int n ;
		player = 1;
		if(player == 1){
			cout << endl << "Player 1 Choose where to Mark O : ";
			cin >> n;
			while (n < 1 || n > 9) {
				cout << "Please Limit Your Input from 1 - 9 " << endl;
				cout << "Input Again Please" << endl;
				cin >> n;
			}
			while (arr[n - 1] == 'X') {
				cout << "Player 2 Has Already Marked Here, Please Input Again" << endl;
				cin >> n;
			}
			arr[n - 1] = 'O';
			k = checkwin(arr, size);
			board(arr, size);
			if (k == 1) {
				cout << endl << "Congratulations Player 1 Won !!" << endl;
				break;
			}
			player = 2;
		}

		if (player == 2) {
			cout << endl << "Player 2 Choose where to Mark X : ";
			cin >> n;
			while (n < 1 || n > 9) {
				cout << "Please Limit Your Input from 1 - 9 " << endl;
				cout << "Input Again Please" << endl;
				cin >> n;
			}
			while (arr[n - 1] == 'O') {
				cout << "Player 1 Has Already Marked Here, Please Input Again" << endl;
				cin >> n;
			}
			arr[n - 1] = 'X';
			k = checkwin(arr, size);
			board(arr, size);
			if (k == 1) {
				cout << endl << "Congratulations Player 2 Won !!" << endl;
				break;
			}
			player = 1;
		}

	} while (k != 1);
}