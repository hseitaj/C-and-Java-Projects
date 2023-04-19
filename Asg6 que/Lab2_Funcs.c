
//-----------------------------------------------------------------------------
//	Frank Ganther	Tues. 3/09/21
//	CmpSc472, Spring 2021
//
//	Demonstration on how to simulate a queue.
//	----------------------------------------
//	Below are some snipets of code that help demonstrate parts of this lab.
//
//	Draw a queue using the extended ascii table.
//	Accept keystrokes in real-time.
//		Key "A" - Add data to the queue.
//		Key "R" - Remove the Head item from the queue.
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#include "Lab2_Funcs.h"

//-----------------------------------------------------------------------------

//------------------------------------------------------
//	Params: 1. the integer to be placed in the q.
//			2. The indexNum of the Q/Array.
//			3. # of spaces in each Q's entry.
//------------------------------------------------------
void PlaceDataInQ (int inData, int idxNum, int startingX, int startingY, int NumSpaces)
	{
	int x = startingX;
	int y = startingY + ( idxNum * 2);
	_gotoxy (x, y);
	if (inData == -1) {
		printf("%*c", 5, ' ');
	}
	else {
		printf ("%5d", inData);
	}
	}

//-------------------------------------------------------------------------
void DrawQ (int numOfItems)
	{
	int x = BORDER_X_POSN;
	int y = BORDER_Y_POSN;

	//-- Draw ractangles on a console window.
	char r1[] = { 218, 196, 196, 196, 196, 196, 191, 0 };		
	char r2[] = { 179,  32,  32,  32,  32,  32, 179, 0 };
	char r3[] = { 195, 196, 196, 196, 196, 196, 180, 0 };
	char r4[] = { 192, 196, 196, 196, 196, 196, 217, 0 };

	_gotoxy (x, y);
	printf ("  %s\n", r1);			// print top bar.

	for (int i = 0; i < numOfItems-1; i++)
		{	
		y++;  _gotoxy (x, y);  printf ("  %s\n", r2);	// print open space
		y++;  _gotoxy (x, y);  printf ("  %s\n", r3);	// print cross bar
		}

	y++;  _gotoxy (x, y);  printf ("  %s\n", r2);	// print last open space
	y++;  _gotoxy (x, y);  printf ("  %s\n", r4);	// print bottom bar.

	}


