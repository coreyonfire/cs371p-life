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

#define private public
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <fstream>
#include <vector>
#include "AbstractCell.h"
#include "Cell.h"
#include "Life.h"


bool runGlider = 1;
bool runWeekender = 1;
bool runConwayMain = 1;
bool runGun = 1;
bool runFredkinMain = 1;
bool runCellMain = 1;
bool runCell2 = 1;
bool runCell3 = 1;
bool runCell4 = 1;
bool runCell5 = 1;
bool runCell6 = 1;


// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

	//RUN GLIDER?
	if (runGlider) {
		// ------------------
		// Conway Cell Glider 10x10
		// ------------------

		try {
		    cout << "*** Life<ConwayCell> 10x10 (Glider) ***" << endl;
		    
			//set up i/o
			int h, w;
			ifstream input;
			input.open("RunLifeConwayGlider.in");
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
		}
		catch (const invalid_argument&) {
			cout << "Invalid Argument!" << endl;
		    assert(false);
		}
		catch (const out_of_range&) {
			cout << "Out of Range!" << endl;
		    assert(false);
		}
	}
	
	//RUN WEEKENDER?
	if (runWeekender) {
		// ------------------
		// Conway Cell Weekender 17x20
		// ------------------

		try {
		    cout << "*** Life<ConwayCell> 17x20 (Weekender) ***" << endl;
		    
			//set up i/o
			int h, w;
			ifstream input;
			input.open("RunLifeConwayWeekender.in");
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
			for (int i = 0; i < 14; i++) {
				life.run();
				cout << life << endl;
			}
		}
		catch (const invalid_argument&) {
			cout << "Invalid Argument!" << endl;
		    assert(false);
		}
		catch (const out_of_range&) {
			cout << "Out of Range!" << endl;
		    assert(false);
		}
	}
	
	//RUN MAIN CONWAY TEST?
	if (runConwayMain) {
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
	}
	
	
	//RUN GLIDER GUN?
	if (runGun) {
		// ------------------
		// Conway Gosper Glider Gun 22x53
		// ------------------

		try {
		    cout << "*** Life<ConwayCell> 22x53 (Gosper Glider Gun) ***" << endl;
		 
			//set up i/o
			int h, w;
			ifstream input;
			input.open("RunLifeConwayGun.in");
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
			for (int i = 0; i < 60; i++) {
				life.run();
				cout << life << endl;
			}
		}
		catch (const invalid_argument&) {
			cout << "Invalid Argument!" << endl;
		    assert(false);
		}
		catch (const out_of_range&) {
			cout << "Out of Range!" << endl;
		    assert(false);
		}
	}


    // ------------------
    // Fredkin Cell 20x20
    // ------------------
	if (runFredkinMain) {
		try {
		    cout << "*** Life<FredkinCell> 20x20 ***" << endl;
		    /*
		    read RunLifeFredkin.in // assume all Fredkin cells
		    Simulate 5 moves.
		    Print every grid (i.e. 0, 1, 2...5)
		    */
		    
		    //set up i/o
			int h, w;
			ifstream input;
			input.open("RunLifeFredkin.in");
			input >> h;
			input >> w;
			char temp = 0;
			vector<FredkinCell> cells;
			for (int i = 0; i < h*w; i++) {
				input >> temp;
				//cout << temp << ": ";
				FredkinCell newCell;
				switch (temp) {
					case '-':
						//cout << "Adding dead, " << temp << endl;
						newCell = FredkinCell(false);
						break;
					case '+':
						//cout << "Adding old, " << temp << endl;
						newCell = FredkinCell(true, 10);
						break;
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case '0':
						//cout << "Adding cell of age " << (int) temp << endl;
						newCell = FredkinCell(true, atoi(&temp));
						break;
					default :
						//new line character or garbage, disregard
						break;
				}
				cells.push_back(newCell);
			}
			//board is populated
			//cout << "Vector created." <<endl;
			Life<FredkinCell> life(h, w, cells);
			//cout << "Running now." << endl;
			cout << life << endl;
			for (int i = 0; i < 5; i++) {
				life.run();
				cout << life << endl;
			}
		    
		}
		catch (const invalid_argument&) {
		    assert(false);}
		catch (const out_of_range&) {
		    assert(false);}
	}
	
	if (runCellMain) {
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
		    
		    //set up i/o
			int h, w;
			ifstream input;
			input.open("RunLifeCell.in");
			input >> h;
			input >> w;
			char temp;
			vector<Cell> cells;
			for (int i = 0; i < h*w; i++) {
				input >> temp;
				//cout << temp << ": ";
				switch (temp) {
					case'.':
						cells.push_back(new ConwayCell(false));
						break;
					case'*':
						cells.push_back(new ConwayCell(true));
						break;
					case '-':
						//cout << "Adding dead, " << temp << endl;
						cells.push_back(new FredkinCell(false));
						break;
					case '+':
						//cout << "Adding old, " << temp << endl;
						cells.push_back(new FredkinCell(true, 10));
						break;
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case '0':
						//cout << "Adding cell of age " << (int) temp << endl;
						cells.push_back(new FredkinCell(true, atoi(&temp)));
						break;
					default :
						//new line character or garbage, disregard
						break;
				}
			}
			//board is populated
			//cout << "Vector created." <<endl;
			Life<Cell> life(h, w, cells);
			//cout << "Running now." << endl;
			cout << life << endl;
			for (int i = 0; i < 5; i++) {
				life.run();
				cout << life << endl;
			}
		    
		    }
		catch (const invalid_argument&) {
		    assert(false);}
		catch (const out_of_range&) {
		    assert(false);}
	}
	
	if (runCell2) {
		// ----------
		// Cell 20x20
		// ----------

		try {
		    cout << "*** Life<Cell> part 2 20x20 ***" << endl;
		    /*
		    read RunLifeCell.in // assume all Fredkin cells
		    Simulate 5 moves.
		    Print every grid (i.e. 0, 1, 2...5)
		    */
		    
		    //set up i/o
			int h, w;
			ifstream input;
			input.open("RunLifeCell2.in");
			input >> h;
			input >> w;
			char temp;
			vector<Cell> cells;
			for (int i = 0; i < h*w; i++) {
				input >> temp;
				//cout << temp << ": ";
				switch (temp) {
					case'.':
						cells.push_back(new ConwayCell(false));
						break;
					case'*':
						cells.push_back(new ConwayCell(true));
						break;
					case '-':
						//cout << "Adding dead, " << temp << endl;
						cells.push_back(new FredkinCell(false));
						break;
					case '+':
						//cout << "Adding old, " << temp << endl;
						cells.push_back(new FredkinCell(true, 10));
						break;
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case '0':
						//cout << "Adding cell of age " << (int) temp << endl;
						cells.push_back(new FredkinCell(true, atoi(&temp)));
						break;
					default :
						//new line character or garbage, disregard
						break;
				}
			}
			//board is populated
			//cout << "Vector created." <<endl;
			Life<Cell> life(h, w, cells);
			//cout << "Running now." << endl;
			cout << life << endl;
			for (int i = 0; i < 1; i++) {
				life.run();
			}
			cout << life << endl;
		    
		    }
		catch (const invalid_argument&) {
		    assert(false);}
		catch (const out_of_range&) {
		    assert(false);}
	}
	
	if (runCell3) {
		// ----------
		// Cell 20x20
		// ----------

		try {
		    cout << "*** Life<Cell> 5x5 ***" << endl;
		    /*
		    read RunLifeCell.in // assume all Fredkin cells
		    Simulate 5 moves.
		    Print every grid (i.e. 0, 1, 2...5)
		    */
		    
		    //set up i/o
			int h, w;
			ifstream input;
			input.open("RunLifeCell3.in");
			input >> h;
			input >> w;
			char temp;
			vector<Cell> cells;
			for (int i = 0; i < h*w; i++) {
				input >> temp;
				//cout << temp << ": ";
				switch (temp) {
					case'.':
						cells.push_back(new ConwayCell(false));
						break;
					case'*':
						cells.push_back(new ConwayCell(true));
						break;
					case '-':
						//cout << "Adding dead, " << temp << endl;
						cells.push_back(new FredkinCell(false));
						break;
					case '+':
						//cout << "Adding old, " << temp << endl;
						cells.push_back(new FredkinCell(true, 10));
						break;
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case '0':
						//cout << "Adding cell of age " << (int) temp << endl;
						cells.push_back(new FredkinCell(true, atoi(&temp)));
						break;
					default :
						//new line character or garbage, disregard
						break;
				}
			}
			//board is populated
			//cout << "Vector created." <<endl;
			Life<Cell> life(h, w, cells);
			//cout << "Running now." << endl;
			cout << life << endl;
			for (int i = 0; i < 10; i++) {
				life.run();
			}
			cout << life << endl;
		    
		    }
		catch (const invalid_argument&) {
		    assert(false);}
		catch (const out_of_range&) {
		    assert(false);}
	}
	
	if (runCell4) {
		// ----------
		// Cell 20x20
		// ----------

		try {
		    cout << "*** Life<Cell> part three 20x20 ***" << endl;
		    /*
		    read RunLifeCell.in // assume all Fredkin cells
		    Simulate 5 moves.
		    Print every grid (i.e. 0, 1, 2...5)
		    */
		    
		    //set up i/o
			int h, w;
			ifstream input;
			input.open("RunLifeCell4.in");
			input >> h;
			input >> w;
			char temp;
			vector<Cell> cells;
			for (int i = 0; i < h*w; i++) {
				input >> temp;
				//cout << temp << ": ";
				switch (temp) {
					case'.':
						cells.push_back(new ConwayCell(false));
						break;
					case'*':
						cells.push_back(new ConwayCell(true));
						break;
					case '-':
						//cout << "Adding dead, " << temp << endl;
						cells.push_back(new FredkinCell(false));
						break;
					case '+':
						//cout << "Adding old, " << temp << endl;
						cells.push_back(new FredkinCell(true, 10));
						break;
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case '0':
						//cout << "Adding cell of age " << (int) temp << endl;
						cells.push_back(new FredkinCell(true, atoi(&temp)));
						break;
					default :
						//new line character or garbage, disregard
						break;
				}
			}
			//board is populated
			//cout << "Vector created." <<endl;
			Life<Cell> life(h, w, cells);
			//cout << "Running now." << endl;
			cout << life << endl;
			for (int i = 0; i < 10; i++) {
				life.run();
			}
			cout << life << endl;
		    
		    }
		catch (const invalid_argument&) {
		    assert(false);}
		catch (const out_of_range&) {
		    assert(false);}
	}
	
	if (runCell5) {
		// ----------
		// Cell 20x20
		// ----------

		try {
		    cout << "*** Life<Cell> 30x69 ***" << endl;
		    /*
		    read RunLifeCell.in // assume all Fredkin cells
		    Simulate 5 moves.
		    Print every grid (i.e. 0, 1, 2...5)
		    */
		    
		    //set up i/o
			int h, w;
			ifstream input;
			input.open("RunLifeCell5.in");
			input >> h;
			input >> w;
			char temp;
			vector<Cell> cells;
			for (int i = 0; i < h*w; i++) {
				input >> temp;
				//cout << temp << ": ";
				switch (temp) {
					case'.':
						cells.push_back(new ConwayCell(false));
						break;
					case'*':
						cells.push_back(new ConwayCell(true));
						break;
					case '-':
						//cout << "Adding dead, " << temp << endl;
						cells.push_back(new FredkinCell(false));
						break;
					case '+':
						//cout << "Adding old, " << temp << endl;
						cells.push_back(new FredkinCell(true, 10));
						break;
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case '0':
						//cout << "Adding cell of age " << (int) temp << endl;
						cells.push_back(new FredkinCell(true, atoi(&temp)));
						break;
					default :
						//new line character or garbage, disregard
						break;
				}
			}
			//board is populated
			//cout << "Vector created." <<endl;
			Life<Cell> life(h, w, cells);
			//cout << "Running now." << endl;
			cout << life << endl;
			for (int i = 0; i < 10; i++) {
				life.run();
			}
			cout << life << endl;
		    
		    }
		catch (const invalid_argument&) {
		    assert(false);}
		catch (const out_of_range&) {
		    assert(false);}
	}
	
	if (runCell6) {
		// ----------
		// Cell 20x20
		// ----------

		try {
		    cout << "*** Life<Cell> 20x25 ***" << endl;
		    /*
		    read RunLifeCell.in // assume all Fredkin cells
		    Simulate 5 moves.
		    Print every grid (i.e. 0, 1, 2...5)
		    */
		    
		    //set up i/o
			int h, w;
			ifstream input;
			input.open("RunLifeCell6.in");
			input >> h;
			input >> w;
			char temp;
			vector<Cell> cells;
			for (int i = 0; i < h*w; i++) {
				input >> temp;
				//cout << temp << ": ";
				switch (temp) {
					case'.':
						cells.push_back(new ConwayCell(false));
						break;
					case'*':
						cells.push_back(new ConwayCell(true));
						break;
					case '-':
						//cout << "Adding dead, " << temp << endl;
						cells.push_back(new FredkinCell(false));
						break;
					case '+':
						//cout << "Adding old, " << temp << endl;
						cells.push_back(new FredkinCell(true, 10));
						break;
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					case '0':
						//cout << "Adding cell of age " << (int) temp << endl;
						cells.push_back(new FredkinCell(true, atoi(&temp)));
						break;
					default :
						//new line character or garbage, disregard
						break;
				}
			}
			//board is populated
			//cout << "Vector created." <<endl;
			Life<Cell> life(h, w, cells);
			//cout << "Running now." << endl;
			cout << life << endl;
			for (int i = 0; i < 10; i++) {
				life.run();
			}
			cout << life << endl;
		    
		    }
		catch (const invalid_argument&) {
		    assert(false);}
		catch (const out_of_range&) {
		    assert(false);}
	}

    return 0;
}
