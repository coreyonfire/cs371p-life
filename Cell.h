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
	
    bool taylorSwift () {
        return get()->grow();
	}
};