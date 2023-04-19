#define	BORDER_X_POSN	2	// U.L coordinates for drawing the Q border.
#define	BORDER_Y_POSN	1
#define	ITEMS_IN_Q		10	// # of entries the Q can hold
#define	EXIT_CHAR		27	// 27 = escape.

//-- function prototypes.
void PlaceDataInQ (int inData, int idxNum, int startingX, int startingY, int NumSpaces);
void DrawQ (int);

