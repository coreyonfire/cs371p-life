#include "Handle.h"

struct Cell : Handle<AbstractCell> {
    Cell (AbstractCell* p) :
            Handle<AbstractCell> (p)
        {}
/*
    Cell (const Cell& that) :
            Handle<AbstractCell> (that)
        {}

    ~Cell ()
        {}

    Cell& operator = (const Cell& that) {
        Handle<AbstractCell>::operator=(that);
        return *this;}
*/
	
	
	/** Execute the evaluation of a cell's condition!
	  * Returns -1 if it's a conway,
	  * or the Fredkin cell's age
	  */
    int grow () {
       	int age = get()->grow();
		//if age is -1, is conwaycell
		//if age is anything else, is fredkin
       	if (age == 2) {
			mutate_pls();
		}
	}
	
	
	/** 
	  * Turn the current fredkin into a conway
	  *
	  */
	void mutate_pls() {
		*this = new ConwayCell(); 
	}
};
