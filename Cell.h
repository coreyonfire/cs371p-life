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
    int taylorSwift () {
       	int age = get()->taylorSwift();
       	if (age == 2 && dynamic_cast<const FredkinCell*>(get())) {
			mutate_pls();
		}
	}
	
	
	/** 
	  * Turn the current fredkin into a conway
	  *
	  */
	void mutate_pls() {
		this = new ConwayCell(); 
	}
};
