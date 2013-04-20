// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2013
// Glenn P. Downing
// -------------------------

/*
To run the program:
    % make RunLife
    % make run

To configure Doxygen:
    doxygen -g
That creates the file Doxyfile.
Make the following edits:
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    GENERATE_LATEX         = NO

To document the program:
    doxygen Doxyfile
*/

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <fstream>
#include <vector>
#include "AbstractCell.h"
#include "Cell.h"
#include "Life.h"



// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

    // ------------------
    // Conway Cell 109x69
    // ------------------

    try {
        cout << "*** Life<ConwayCell> 109x69 ***" << endl;
        /*
        read RunLifeConway.in // assume all Conway cells
        Simulate 283 moves.
        Print the first 10 grids (i.e. 0, 1, 2...9).
        Print the 283rd grid.
        Simulate 40 moves.
        Print the 323rd grid.
        Simulate 2177 moves.
        Print the 2500th grid.
        */
		
		//set up i/o
		int h, w;
		ifstream input;
		input.open("RunLifeConway.in");
		input >> h;
		input >> w;
		char temp;
		vector<ConwayCell> cells;
		for (int i = 0; i < h*w; i++) {
			input >> temp;
			ConwayCell newCell;
			switch (temp) {
				case '.':
					newCell = ConwayCell(false);
					break;
				case '*':
					newCell = ConwayCell(true);
					break;
				default :
					//new line character or garbage, disregard
					break;
			}
			cells.push_back(newCell);
		}
		//board is populated
		//cout << "Vector created." <<endl;
		Life<ConwayCell> life(h, w, cells);
		//cout << "Running now." << endl;
		cout << life << endl;
		for (int i = 0; i < 10; i++) {
			life.run();
			cout << life << endl;
		}
		life.run(273);
		cout << life <<endl;
		life.run(40);
		cout << life << endl;
		life.run(2177);
		cout << life << endl;
    }
    catch (const invalid_argument&) {
		cout << "Invalid Argument!" << endl;
        assert(false);
	}
    catch (const out_of_range&) {
		cout << "Out of Range!" << endl;
        assert(false);
	}

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    try {
        cout << "*** Life<FredkinCell> 20x20 ***" << endl;
        /*
        read RunLifeFredkin.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    // ----------
    // Cell 20x20
    // ----------

    try {
        cout << "*** Life<Cell> 20x20 ***" << endl;
        /*
        read RunLifeCell.in // assume all Fredkin cells
        Simulate 5 moves.
        Print every grid (i.e. 0, 1, 2...5)
        */
        }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}

    return 0;
}