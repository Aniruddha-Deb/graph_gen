#include <iostream.h>
#include <graphics.h>
#include <process.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

///////////////////// VARIABLE DECLARATION //////////////////////////////////////////////////////////
float u, v, a, t, S;
char uInput, vInput, aInput, tInput, SInput;
int numUnknown = 5;

void drawLine() {

	cout << "================================================================================";
}

// show opening menu

void showMenu() {

	gotoxy( 26, 1);
	cout << "Graph Generator v. 2.3 Final " << endl;

	gotoxy( 26, 2);
	cout << "Copyright Aniruddha Deb 2015" << endl;

	gotoxy( 1, 3 );
	drawLine();
	cout << endl;
}

///////////////////// OBTAINING VALUES //////////////////////////////////////////////////////////
void obtainu() {

	int success = 0;

	do {
		cout << " Initial Velocity (u): ";
		cin >> u;

		// logic to flush cin if user entered a char

		if( cin.fail() ) {

			char buffer[256];

			cin.clear();
			cin >> buffer;

			// If entered char is ?, input is successful, else invalid

			if( buffer[0] == '?' ) {
				success = 1;
				u = '?';
				uInput = '?';
			}
			else{
				cout << "The value you have entered is incorrect. Please enter a valid value\n";
			}
		}
		else {
			success = 1;
			uInput = 1;
			numUnknown--;
		}

	}while( success == 0 ) ;

}

void obtainv() {

	int success = 0;

	do {
		cout << " Final Velocity (v): ";
		cin >> v;

		// logic to flush cin if user entered a char

		if( cin.fail() ) {

			char buffer[256];

			cin.clear();
			cin >> buffer;

			// If entered char is ?, input is successful, else invalid

			if( buffer[0] == '?' ) {
				success = 1;
				v = '?';
				vInput = '?';
			}
			else{
				cout << "The value you have entered is incorrect. Please enter a valid value\n";
			}
		}
		else {
			success = 1;
			vInput = 1;
			numUnknown--;
		}

	}while( success == 0 ) ;

}

void obtaina() {

	int success = 0;

	do {
		cout << " Acceleration of the body (a): ";
		cin >> a;

		// logic to flush cin if user entered a char

		if( cin.fail() ) {

			char buffer[256];

			cin.clear();
			cin >> buffer;

			// If entered char is ?, input is successful, else invalid

			if( buffer[0] == '?' ) {
				success = 1;
				a = '?';
				aInput = '?';
			}
			else{
				cout << "The value you have entered is incorrect. Please enter a valid value\n";
			}
		}
		else {
			success = 1;
			aInput = 1;
			numUnknown--;
		}

	}while( success == 0 ) ;

}

void obtaint() {

	int success = 0;

	do {
		cout << " Time taken (t): ";
		cin >> t;

		// logic to flush cin if user entered a char

		if( cin.fail() ) {

			char buffer[256];

			cin.clear();
			cin >> buffer;

			// If entered char is ?, input is successful, else invalid

			if( buffer[0] == '?' ) {
				success = 1;
				t = '?';
				tInput = '?';
			}
			else{
				cout << "The value you have entered is incorrect. Please enter a valid value\n";
			}
		}
		else {
			success = 1;
			tInput = 1;
			numUnknown--;
		}

	}while( success == 0 ) ;

}

void obtainS() {

	int success = 0;

	do {
		cout << " Distance covered (S): ";
		cin >> S;

		// logic to flush cin if user entered a char

		if( cin.fail() ) {

			char buffer[256];

			cin.clear();
			cin >> buffer;

			// If entered char is ?, input is successful, else invalid

			if( buffer[0] == '?' ) {
				success = 1;
				S = '?';
				SInput = '?';
			}
			else{
				cout << "The value you have entered is incorrect. Please enter a valid value\n";
			}
		}
		else {
			success = 1;
			SInput = 1;
			numUnknown--;
		}

	}while( success == 0 ) ;

}

void obtainValues() {

	for( int valuesEntered = 0; valuesEntered < 5; ) {

		cout << "Please enter the fol. values in SI units, enter ? if blank: " << endl;

		numUnknown = 5;

		obtainu();
		valuesEntered++;

		obtainv();
		valuesEntered++;

		obtaina();
		valuesEntered++;

		obtaint();
		valuesEntered++;

		obtainS();
		valuesEntered++;
	}
}

///////////////////// COMPUTING VALUES //////////////////////////////////////////////////////////
float computet() {

	if( u!='?' && v!='?' && a!='?' ) {

		return( v-u )/ a;
	}

	else if( S!='?' && u!='?' && a!='?' ) {

		return( -u + sqrt( pow( u, 2 ) + 2*a*S ) ) / a;
	}

	else{

		return '?';
	}

}

float computev() {

	if( u!='?' && a!='?' && t!='?' ) {

		return ( u + a*t );
	}

	else if( u!='?' && a!='?' && S!='?' ) {

		return ( sqrt( pow(u, 2) ) + 2*a*S );
	}

	else{

		return '?';
	}
}

float computea() {

	if( v!='?' && u!='?' && t!='?' ) {

		return ( (v-u) / t );
	}

	else if( v!='?' && u!='?' && S!='?' ) {

		return ( (pow(v, 2) - pow(u, 2)) / (2*S) );
	}

	else if( v!='?' && t!='?' && S!='?' ) {

		return ( ((v*t - S) * 2) / pow(t, 2) );
	}

	else{

		return '?';
	}
}

float computeu() {

	if( v!='?' && a!='?' && t!='?' ) {

		return ( v - a*t );
	}

	else if( v!='?' && a!='?' && S!='?' ) {

		return ( sqrt( pow(v, 2) ) - 2*a*S );
	}

	else{

		return '?';
	}
}

float computeS() {

	if( u!='?' && a!='?' && t!='?' ) {

		return ( (u*t) + ((a*pow(t, 2)) / 2) );
	}

	else{

		return '?';
	}
}

void computeValues() {

	int ncVals, loop;

	for( ncVals  = 0, loop = 1; ncVals !=5; loop++ ) {

		if( u != '?' ) ncVals++;
		else if( u == '?' ) {

			u = computeu();
		}

		if( v != '?' ) ncVals++;
		else if( v == '?' ) {

			v = computev();
		}

		if( a != '?' ) ncVals++;
		else if( a == '?' ) {

			a = computea();
		}

		if( t != '?' ) ncVals++;
		else if( t == '?' ) {

			t = computet();
		}

		if( S != '?' ) ncVals++;
		else if( S == '?' ) {

			S = computeS();
		}

		if( loop >= 50 ) {
			cout << "Insufficient data\n";
			break;
		}
	}

}

///////////////////// GUI ORIENTED FUNCTIONS //////////////////////////////////////////////////////////
#define WIN_TLX             0
#define WIN_TLY             0
#define WIN_BRX           639
#define WIN_BRY           479

#define WIN_W             (WIN_BRX - WIN_TLX)
#define WIN_H             (WIN_BRY - WIN_TLY)

#define TITLE_WIN_TLY     WIN_TLY
#define TITLE_WIN_TLX     WIN_TLX
#define TITLE_WIN_H        50
#define TITLE_WIN_W       WIN_W
#define TITLE_WIN_BRY     (TITLE_WIN_TLY + TITLE_WIN_H)
#define TITLE_WIN_BRX     (TITLE_WIN_TLX + TITLE_WIN_W)

#define GRAPH_WIN_TLY     (TITLE_WIN_BRY + 1)
#define GRAPH_WIN_TLX     WIN_TLX
#define GRAPH_WIN_H       330
#define GRAPH_WIN_W       WIN_W
#define GRAPH_WIN_BRX     (GRAPH_WIN_TLX + GRAPH_WIN_W)
#define GRAPH_WIN_BRY     (GRAPH_WIN_TLY + GRAPH_WIN_H)

#define IP_WIN_TLY        (GRAPH_WIN_BRY + 1)
#define IP_WIN_TLX        WIN_TLX
#define IP_WIN_H          (WIN_BRY - IP_WIN_TLY)
#define IP_WIN_W          (WIN_W/2)
#define IP_WIN_BRY        (IP_WIN_TLY + IP_WIN_H)
#define IP_WIN_BRX        (IP_WIN_TLX + IP_WIN_W)

#define OP_WIN_TLY        (GRAPH_WIN_BRY + 1)
#define OP_WIN_TLX        (IP_WIN_BRX + 1)
#define OP_WIN_H          (WIN_BRY - OP_WIN_TLY)
#define OP_WIN_W          (WIN_W/2)
#define OP_WIN_BRY        (OP_WIN_TLY + OP_WIN_H)
#define OP_WIN_BRX        (OP_WIN_TLX + OP_WIN_W)

#define Y_AXIS_GUTTER      120
#define X_AXIS_GUTTER      30

#define X_AXIS_START_PIX  (GRAPH_WIN_TLX + Y_AXIS_GUTTER)
#define X_AXIS_END_PIX    (GRAPH_WIN_BRX - Y_AXIS_GUTTER)
#define Y_AXIS_START_PIX  (GRAPH_WIN_BRY - X_AXIS_GUTTER)
#define Y_AXIS_END_PIX    (GRAPH_WIN_TLY + X_AXIS_GUTTER)

#define X_AXIS_SIZE       (X_AXIS_END_PIX - X_AXIS_START_PIX)
#define Y_AXIS_SIZE       (Y_AXIS_START_PIX - Y_AXIS_END_PIX)

#define NUM_X_AXIS_DIV    10
#define NUM_Y_AXIS_DIV    10

float yAxisPerPixelVal = 0 ;
int   yAxisNumPixPerDiv= 0 ;
float yAxisPerDivVal   = 0 ;

float xAxisPerPixelVal = 0 ;
int   xAxisNumPixPerDiv= 0 ;
float xAxisPerDivVal   = 0 ;

void initgraph() {

	int gd, gm;

	detectgraph( &gd, &gm );
	initgraph( &gd, &gm, "c:\\tc\\bgi" );
}

void computeYAxisPerPixelVal() {

	float maxVal = (u>=v)?u:v;

	float maxAxisVal = 0 ;

	if     ( maxVal <= 10  ) maxAxisVal = 10   ;
	else if( maxVal <= 50  ) maxAxisVal = 50  ;
	else if( maxVal <= 100 ) maxAxisVal = 100  ;
	else if( maxVal <= 500 ) maxAxisVal = 500  ;
	else                     maxAxisVal = 1000 ;

	yAxisPerPixelVal = maxAxisVal / Y_AXIS_SIZE ;
	yAxisNumPixPerDiv= Y_AXIS_SIZE / NUM_Y_AXIS_DIV ;
	yAxisPerDivVal   = maxAxisVal / NUM_Y_AXIS_DIV ;
}

void computeXAxisPerPixelVal() {

	float maxAxisVal = 30000 ;

	if( t <= 0.1 ) {
		maxAxisVal = 0.1 ;
	}
	else if( t <= 1 ) {
		maxAxisVal = 1 ;
	}
	else {
		for( int i=0; i<2000; i++ ) {
			if( t<=i*10 ) {
				maxAxisVal = i*10 ;
				break ;
			}
		}
	}

	xAxisPerPixelVal = maxAxisVal / X_AXIS_SIZE ;
	xAxisNumPixPerDiv= X_AXIS_SIZE / NUM_X_AXIS_DIV ;
	xAxisPerDivVal   = maxAxisVal / NUM_X_AXIS_DIV ;
}

void drawYAxis() {

	char buffer[10];

	line( X_AXIS_START_PIX, Y_AXIS_START_PIX,
		  X_AXIS_START_PIX, Y_AXIS_END_PIX );

	for( int i=1; i<=NUM_Y_AXIS_DIV; i++ ) {

		float val = yAxisPerDivVal * i ;
		int y = Y_AXIS_START_PIX - val/yAxisPerPixelVal ;

		// drawing ticks
		line( X_AXIS_START_PIX-2,y,
			  X_AXIS_START_PIX,  y );

		// outputting tick values
		itoa( i*yAxisPerDivVal, buffer, 10 );
		outtextxy( X_AXIS_START_PIX-25, y, buffer );


		// drawing grid
		setlinestyle( DOTTED_LINE, 1, 1 );
		setcolor( BLUE );

		line( X_AXIS_START_PIX+1, y,
			  X_AXIS_END_PIX    , y );

		setlinestyle( SOLID_LINE, 1, 1 );
		setcolor( WHITE );

	}

	outtextxy( X_AXIS_START_PIX-(Y_AXIS_GUTTER/2),
			   Y_AXIS_END_PIX-(X_AXIS_GUTTER/2),
			   "Velocity (m/s)" );
}

void drawXAxis() {

	char buffer[10];

	line( X_AXIS_START_PIX, Y_AXIS_START_PIX,
		  X_AXIS_END_PIX,   Y_AXIS_START_PIX );

	for( int i=1; i<=NUM_X_AXIS_DIV; i++ ) {

		float val = xAxisPerDivVal * i ;
		int x = X_AXIS_START_PIX + val/xAxisPerPixelVal ;


		// drawing ticks
		line( x, Y_AXIS_START_PIX,
			  x, Y_AXIS_START_PIX+2 );

		// outputting tick values
		char* fmtbuf;

		if     ( t<=0.1 ) fmtbuf = "%-4.2f";
		else if( t<=1   ) fmtbuf = "%-4.1f";
		else 			  fmtbuf =  "%4.0f";

		sprintf( buffer, fmtbuf, (float)i*xAxisPerDivVal );
		outtextxy( x-xAxisNumPixPerDiv/2,
				   Y_AXIS_START_PIX+(X_AXIS_GUTTER/3),
				   buffer );

		// drawing grid
		setlinestyle( DOTTED_LINE, 1, 1 );
		setcolor( BLUE );

		line( x, Y_AXIS_START_PIX-1,
			  x, Y_AXIS_END_PIX    );

		setlinestyle( SOLID_LINE, 1, 1 );
		setcolor( WHITE );
	}

	outtextxy( X_AXIS_END_PIX+10,
			   Y_AXIS_START_PIX-(X_AXIS_GUTTER/4),
			   "Time (s)" );
}

void drawWin( int tlx, int tly, int brx, int bry ) {

	setcolor( LIGHTCYAN );
	rectangle( tlx, tly, brx, bry );
	setcolor( WHITE );
}

void drawTitleWindow() {

	drawWin( TITLE_WIN_TLX, TITLE_WIN_TLY,
			 TITLE_WIN_BRX, TITLE_WIN_BRY );

	settextstyle( TRIPLEX_FONT, HORIZ_DIR, 3 );
	setcolor( LIGHTGREEN );
	outtextxy( TITLE_WIN_BRX/4, TITLE_WIN_TLY+10,
			   "Graph Generator v.2.3 Final" );
	setcolor( WHITE );
	settextstyle( 0, 0, 1 );
}

void drawGraphWindow() {

	computeYAxisPerPixelVal() ;
	computeXAxisPerPixelVal() ;

	drawWin( GRAPH_WIN_TLX, GRAPH_WIN_TLY,
			 GRAPH_WIN_BRX, GRAPH_WIN_BRY );

	drawXAxis();
	drawYAxis();

	outtextxy( X_AXIS_START_PIX-10,
			   Y_AXIS_START_PIX+10, "0" );
}

void winLabel( int winTlx, int winTly,
			   int numRow, char* text ) {

	outtextxy( winTlx + 5, winTly + 25 + numRow*10, text ) ;
}

void fmtLabel( char* buffer, char flag, float val,
			   char* label, char *unit ) {

	if( flag == 1 ) {
		sprintf( buffer, "%s = %4.2f %s", label, val, unit ) ;
	}
	else {
		sprintf( buffer, "%s = ? %s", label, unit ) ;
	}
}

void drawIPWindow() {

	char buffer[256] ;

	drawWin( IP_WIN_TLX, IP_WIN_TLY,
			 IP_WIN_BRX, IP_WIN_BRY );

	setcolor( LIGHTGRAY );

	outtextxy( IP_WIN_BRX/3, IP_WIN_TLY+5, "Input Values: " );

	fmtLabel( buffer, uInput, u,  "Initial velocity", "m/s" ) ;
	winLabel( IP_WIN_TLX, IP_WIN_TLY, 0, buffer ) ;

	fmtLabel( buffer, vInput, v,  "Final velocity  ", "m/s" ) ;
	winLabel( IP_WIN_TLX, IP_WIN_TLY, 1, buffer ) ;

	fmtLabel( buffer, aInput, a,  "Acceleration    ", "m/s^2" ) ;
	winLabel( IP_WIN_TLX, IP_WIN_TLY, 2, buffer ) ;

	fmtLabel( buffer, tInput, t,  "Time            ", "s" ) ;
	winLabel( IP_WIN_TLX, IP_WIN_TLY, 3, buffer ) ;

	fmtLabel( buffer, SInput, S,  "Distance        ", "m" ) ;
	winLabel( IP_WIN_TLX, IP_WIN_TLY, 4, buffer ) ;

	setcolor( WHITE );
}

void drawOPWindow() {

	char buffer[256];

	drawWin( OP_WIN_TLX, OP_WIN_TLY,
			 OP_WIN_BRX, OP_WIN_BRY );

	outtextxy( OP_WIN_BRX/6+IP_WIN_BRX, OP_WIN_TLY+5, "Output Values: " );

	sprintf( buffer, "Initial Velocity = %4.2f m/s", u ) ;
	outtextxy( OP_WIN_TLX+5, OP_WIN_TLY+25, buffer );

	sprintf( buffer, "Final Velocity   = %4.2f m/s", v ) ;
	outtextxy( OP_WIN_TLX+5, OP_WIN_TLY+35, buffer );

	sprintf( buffer, "Acceleration     = %4.2f m/s^2", a ) ;
	outtextxy( OP_WIN_TLX+5, OP_WIN_TLY+45, buffer );

	sprintf( buffer, "Time             = %4.2f s", t ) ;
	outtextxy( OP_WIN_TLX+5, OP_WIN_TLY+55, buffer );

	sprintf( buffer, "Distance         = %4.2f m", S ) ;
	outtextxy( OP_WIN_TLX+5, OP_WIN_TLY+65, buffer );
}

void drawWindows(){

	drawTitleWindow();
	drawGraphWindow();
	drawIPWindow();
	drawOPWindow();
}


void drawGraph() {

	float originX = X_AXIS_START_PIX;
	float originY = Y_AXIS_START_PIX;

	int uX = floor( originX ) ;
	int uY = floor( originY - u/yAxisPerPixelVal ) ;
	int vX = floor( originX + t/xAxisPerPixelVal ) ;
	int vY = floor( originY - v/yAxisPerPixelVal ) ;

	setlinestyle( SOLID_LINE, 1, 1 );
	setcolor( GREEN );

	line( uX, uY, vX, vY );

	setcolor( WHITE );

}

void showGUI() {

	initgraph();

	drawWindows();
	drawGraph() ;
}

///////////////////// OBTAINING CHOICE FOR RETRY //////////////////////////////////////////////////////////
int obtainUserChoice() {

	char choice;

	clrscr();

	showMenu();

	cout << "Would you like to view another graph? (y/n): ";
	cin >> choice;

	if( choice == 'y'|| choice == 'Y' ) return 0;
	else if( choice == 'n' || choice == 'N' ) return 1;
}

///////////////////// MAIN FUNCTION //////////////////////////////////////////////////////////
void main() {

	do{
		clrscr();
		showMenu();
		obtainValues();

		if( numUnknown > 2 ) {
			cout << endl
				 << "Insufficient Data Entered." << endl
				 << "Atleast 3 values required.";
			getch();
		}
		else if( numUnknown == 0 ) {
			cout << endl
				 << "Nothing to compute." << endl
				 << "No unknowns provided.";
			getch();
		}
		else{
			computeValues();
			showGUI();
			getch();
			closegraph();
		}

	}while( obtainUserChoice() == 0 );

}

