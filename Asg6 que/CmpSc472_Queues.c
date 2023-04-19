/*
	Hansi Seitaj
	CMPSC 472
	04 - 01 - 2022
	
	A queue display and implementation that will allow the user to add or delete data by keyboard strokes.
*/
#include <stdio.h>
#include <conio.h>
#include "Lab2_Funcs.h"
#include <stdbool.h>
#define MAX_Q_SIZE 10

// Finds a Queue length and returns the length as an integer.
// Accepts an queue in a form of an integer array. 
int QueueLength(int myQueue[]) {
	int length = 0;
	for (int i = 0; i < 10; i++) {
		//printf("%d\n", queue[i]);
		if (myQueue[i] != 0) {
			length++;
		}
	}
	return length;	

}

int main(int argc, char *argv[]) {
	
	int head;
	int tail;
	int idx = 3;
	int queue[ITEMS_IN_Q] = {111, 222, 333};

	int input;

	DrawQ(ITEMS_IN_Q);
	PlaceDataInQ(111, 0, 5, 2, 3);
	PlaceDataInQ(222, 1, 5, 2, 3);
	PlaceDataInQ(333, 2, 5, 2, 3); 
	_gotoxy(1, 22);
	
	
	//Find the length of the queue
	int length = 0;

	bool conditionIn = true;
	int counter = 0;
	length = QueueLength(queue);

	int pos = 25;
	int key = 0;
	bool condition = true;
	printf("\nPlease press the key 'A' for adding elements to the queue.\n");
	printf("Please press the key 'R' for deleting an element.\n");
	
	while (condition){
		length = QueueLength(queue);
		// wait for user key stroke
		if (_kbhit()) {
			// get the value of the key
			key = _getch();
			// if the key is 'a' or 'A' then add an integer
			if ( key == 65 || key == 97 ) {
				//pos = pos + 1;
				do {	
					//pos = pos + 1;
					_gotoxy(1, pos);
					printf("Please enter a positive integer: ");
					scanf("%d", &input);
					if( input < 0 || input > 9999) {
						printf("Invalid input! No negative or integer larger then 9999.\n");
						pos++;
						}
				} while (input < 0 || input > 9999);
				queue[idx] = input;
				PlaceDataInQ(input, idx, 5, 2, 3);
				idx = (idx+1) % MAX_Q_SIZE;
				_gotoxy(1, pos);
				if (length == 10) {
					printf("You reached the total amount of integer in the queue.The queue will restart placing data.\n");
					pos++;
				} 
			}
			// if the key is an 'r' or an 'R' delete an element starting from the head of the queue
			else if ( key == 82 || key == 114) {
				if(conditionIn){
					idx = 0;
					conditionIn = false;
				}
				queue[idx] = 0;
				PlaceDataInQ(-1, idx, 5, 2, 3);
				idx = (idx + 1) % MAX_Q_SIZE;
				_gotoxy(1, pos);

 				if(length == 0) {
					pos++;
					printf("\nThe queue is empty!\n");
					counter = 0;
					idx = 0;
				}
			}
		// if the key matches the ESC ASCI table value then leave the program.
		else if(key == 27) {
			_gotoxy(1, pos + 1);
			printf("\nThank you for using this program.\n");
			condition = false;
			}
		}
	}
	return 0;
}

