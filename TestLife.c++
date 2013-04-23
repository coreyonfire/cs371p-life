// --------------------------------
// projects/life/TestLife.c++
// Copyright (C) 2013
// cmbes
// --------------------------------

// --------
// includes
// --------
#define private public
#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <cassert>
#ifndef assert
   #define assert assert
#endif
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include <fstream>
#include <vector>
#include "AbstractCell.h"
#include "Cell.h"
#include "Life.h"

// -----------
// TestLife
// -----------

struct TestLife : CppUnit::TestFixture {


    // -----
    // suite
    // -----
    
    void test_construct1 () {
    	int h, w;
		std::ifstream input;
		input.open("TestLifeSmall.in");
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
		Life<ConwayCell> life(h, w, cells);
		CPPUNIT_ASSERT(life.population() == 5);
		
    }
    
    void test_run1 () {
    	int h, w;
		std::ifstream input;
		input.open("TestLifeSmall.in");
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
		Life<ConwayCell> life(h, w, cells);
		life.run();
		CPPUNIT_ASSERT(life.population() == 5);
		CPPUNIT_ASSERT(life.generation() == 1);
    }
    
    void test_construct2 () {
    	int h, w;
		std::ifstream input;
		input.open("TestLifeLarge.in");
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
					cells.push_back(new FredkinCell(true, (int)( temp - '0')));
					break;
				default :
					//new line character or garbage, disregard
					break;
			}
		}
		Life<Cell> life(h, w, cells);
		CPPUNIT_ASSERT(life.population() == 48);
		
    }
    
    void test_run2 () {
    	int h, w;
		std::ifstream input;
		input.open("TestLifeLarge.in");
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
					cells.push_back(new FredkinCell(true, (int)( temp - '0')));
					break;
				default :
					//new line character or garbage, disregard
					break;
			}
		}
		Life<Cell> life(h, w, cells);
		life.run(10);
		CPPUNIT_ASSERT(life.population() == 370);
		CPPUNIT_ASSERT(life.generation() == 10);
    }
    
    void test_construct3 () {
    	int h, w;
		std::ifstream input;
		input.open("TestLifeEmpty.in");
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
					cells.push_back(new FredkinCell(true, (int)( temp - '0')));
					break;
				default :
					//new line character or garbage, disregard
					break;
			}
		}
		Life<Cell> life(h, w, cells);
		CPPUNIT_ASSERT(life.population() == 0);
		
    }
    
    void test_run3 () {
    	int h, w;
		std::ifstream input;
		input.open("TestLifeEmpty.in");
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
					cells.push_back(new FredkinCell(true, (int)( temp - '0')));
					break;
				default :
					//new line character or garbage, disregard
					break;
			}
		}
		Life<Cell> life(h, w, cells);
		life.run(10);
		CPPUNIT_ASSERT(life.population() == 0);
		CPPUNIT_ASSERT(life.generation() == 10);
    }
    
    void test_construct4 () {
    	int h, w;
		std::ifstream input;
		input.open("TestLifeFull.in");
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
					cells.push_back(new FredkinCell(true, (int)( temp - '0')));
					break;
				default :
					//new line character or garbage, disregard
					break;
			}
		}
		Life<Cell> life(h, w, cells);
		CPPUNIT_ASSERT(life.population() == 25);
		
    }
    
    void test_run4 () {
    	int h, w;
		std::ifstream input;
		input.open("TestLifeFull.in");
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
					cells.push_back(new FredkinCell(true, (int)( temp - '0')));
					break;
				default :
					//new line character or garbage, disregard
					break;
			}
		}
		Life<Cell> life(h, w, cells);
		life.run(10);
		CPPUNIT_ASSERT(life.population() == 0);
		CPPUNIT_ASSERT(life.generation() == 10);
    }
    
    //test with empty
    void test_construct5 () {
    	int h, w;
		std::ifstream input;
		input.open("TestLifeFull.in");
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
					cells.push_back(new FredkinCell(true, (int)( temp - '0')));
					break;
				default :
					//new line character or garbage, disregard
					break;
			}
		}
		try {
			Life<Cell> life(0, 0, cells);
			life.run(10);
			CPPUNIT_ASSERT(false);
		}
		catch (...) {CPPUNIT_ASSERT(true);}
    }
    
    //run with bad input
    void test_run5 () {
    	int h, w;
		std::ifstream input;
		input.open("TestLifeFull.in");
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
					cells.push_back(new FredkinCell(true, (int)( temp - '0')));
					break;
				default :
					//new line character or garbage, disregard
					break;
			}
		}
		Life<Cell> life(h, w, cells);
		life.run(-1);
		life.run(9);
		CPPUNIT_ASSERT(life.population() == 0);
		CPPUNIT_ASSERT(life.generation() == 10);
    }
    
    void test_conway1 () {
    	ConwayCell c = ConwayCell(true);
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_conway2 () {
    	ConwayCell c = ConwayCell(false);
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_conway3 () {
    	ConwayCell c = ConwayCell(true);
    	c.kill();
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_conway4 () {
    	ConwayCell c = ConwayCell(true);
    	c.revive();
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_conway5 () {
    	ConwayCell c = ConwayCell(true);
    	c.kill();
    	c.revive();
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_conway6 () {
    	ConwayCell c = ConwayCell(false);
    	c.revive();
    	c.kill();
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_conway7 () {
    	ConwayCell c = ConwayCell(true);
    	c.revive();
    	c.kill();
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_conway8 () {
    	ConwayCell c = ConwayCell(true);
    	c.grow(1, 2);
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_conway9 () {
    	ConwayCell c = ConwayCell(true);
    	c.grow(2, 2);
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_conway10 () {
    	ConwayCell c = ConwayCell(true);
    	try {
    		c.grow(-1, 2);
    	} catch (...) {}
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_fredkin1 () {
    	FredkinCell c = FredkinCell(true);
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_fredkin2 () {
    	FredkinCell c = FredkinCell(false);
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_fredkin3 () {
    	FredkinCell c = FredkinCell(true);
    	c.kill();
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_fredkin4 () {
    	FredkinCell c = FredkinCell(true);
    	c.revive();
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_fredkin5 () {
    	FredkinCell c = FredkinCell(true);
    	c.kill();
    	c.revive();
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_fredkin6 () {
    	FredkinCell c = FredkinCell(false);
    	c.revive();
    	c.kill();
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_fredkin7 () {
    	FredkinCell c = FredkinCell(true);
    	c.revive();
    	c.kill();
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_fredkin8 () {
    	FredkinCell c = FredkinCell(true);
    	c.grow(1, 2);
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_fredkin9 () {
    	FredkinCell c = FredkinCell(true);
    	c.grow(2, 2);
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_fredkin10 () {
    	FredkinCell c = FredkinCell(true);
    	try {
    		c.grow(-1, 2);
    	} catch (...) {}
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_cell1 () {
    	Cell c = new ConwayCell(true);
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_cell2 () {
    	Cell c = new ConwayCell(false);
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_cell3 () {
    	Cell c = new ConwayCell(true);
    	c.kill();
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_cell4 () {
    	Cell c = new ConwayCell(true);
    	c.revive();
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_cell5 () {
    	Cell c = new ConwayCell(true);
    	c.kill();
    	c.revive();
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_cell6 () {
    	Cell c = new ConwayCell(false);
    	c.revive();
    	c.kill();
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_cell7 () {
    	Cell c = new ConwayCell(true);
    	c.revive();
    	c.kill();
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_cell8 () {
    	Cell c = new ConwayCell(true);
    	c.grow(1, 2);
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_cell9 () {
    	Cell c = new ConwayCell(true);
    	c.grow(2, 2);
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_cell10 () {
    	Cell c = new ConwayCell(true);
    	try {
    		c.grow(-1, 2);
    	} catch (...) {}
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_cell11 () {
    	Cell c = new FredkinCell(true);
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_cell12 () {
    	Cell c = new FredkinCell(false);
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_cell13 () {
    	Cell c = new FredkinCell(true);
    	c.kill();
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_cell14 () {
    	Cell c = new FredkinCell(true);
    	c.revive();
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_cell15 () {
    	Cell c = new FredkinCell(true);
    	c.kill();
    	c.revive();
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_cell16 () {
    	Cell c = new FredkinCell(false);
    	c.revive();
    	c.kill();
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_cell17 () {
    	Cell c = new FredkinCell(true);
    	c.revive();
    	c.kill();
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_cell18 () {
    	Cell c = new FredkinCell(true);
    	c.grow(1, 2);
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_cell19 () {
    	Cell c = new FredkinCell(true);
    	c.grow(2, 2);
    	CPPUNIT_ASSERT(!c.health());
    }
    
    void test_cell20 () {
    	Cell c = new FredkinCell(true);
    	try {
    		c.grow(-1, 2);
    	} catch (...) {}
    	CPPUNIT_ASSERT(c.health());
    }
    
    void test_mutate_pls () {
    	Cell c = new FredkinCell(true);
    	c.mutate_pls();
    	int x = c.grow(1,1);
    	CPPUNIT_ASSERT(x == -1);
    }
    

    CPPUNIT_TEST_SUITE(TestLife);
    CPPUNIT_TEST(test_construct1);
    CPPUNIT_TEST(test_run1);
    CPPUNIT_TEST(test_construct2);
    CPPUNIT_TEST(test_run2);
    CPPUNIT_TEST(test_construct3);
    CPPUNIT_TEST(test_run3);
    CPPUNIT_TEST(test_construct4);
    CPPUNIT_TEST(test_run4);
    CPPUNIT_TEST(test_construct5);
    CPPUNIT_TEST(test_run5);
    CPPUNIT_TEST(test_conway1);
    CPPUNIT_TEST(test_conway2);
    CPPUNIT_TEST(test_conway3);
    CPPUNIT_TEST(test_conway4);
    CPPUNIT_TEST(test_conway5);
    CPPUNIT_TEST(test_conway6);
    CPPUNIT_TEST(test_conway7);
    CPPUNIT_TEST(test_conway8);
    CPPUNIT_TEST(test_conway9);
    CPPUNIT_TEST(test_conway10);
    CPPUNIT_TEST(test_fredkin1);
    CPPUNIT_TEST(test_fredkin2);
    CPPUNIT_TEST(test_fredkin3);
    CPPUNIT_TEST(test_fredkin4);
    CPPUNIT_TEST(test_fredkin5);
    CPPUNIT_TEST(test_fredkin6);
    CPPUNIT_TEST(test_fredkin7);
    CPPUNIT_TEST(test_fredkin8);
    CPPUNIT_TEST(test_fredkin9);
    CPPUNIT_TEST(test_fredkin10);
    CPPUNIT_TEST(test_cell1);
    CPPUNIT_TEST(test_cell2);
    CPPUNIT_TEST(test_cell3);
    CPPUNIT_TEST(test_cell4);
    CPPUNIT_TEST(test_cell5);
    CPPUNIT_TEST(test_cell6);
    CPPUNIT_TEST(test_cell7);
    CPPUNIT_TEST(test_cell8);
    CPPUNIT_TEST(test_cell9);
    CPPUNIT_TEST(test_cell10);
    CPPUNIT_TEST(test_cell11);
    CPPUNIT_TEST(test_cell12);
    CPPUNIT_TEST(test_cell13);
    CPPUNIT_TEST(test_cell14);
    CPPUNIT_TEST(test_cell15);
    CPPUNIT_TEST(test_cell16);
    CPPUNIT_TEST(test_cell17);
    CPPUNIT_TEST(test_cell18);
    CPPUNIT_TEST(test_cell19);
    CPPUNIT_TEST(test_cell20);
    CPPUNIT_TEST(test_mutate_pls);
    CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestLife.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestLife::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;
}
