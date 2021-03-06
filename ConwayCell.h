#ifndef CONWAY_H
#define CONWAY_H
#include "AbstractCell.h"

class ConwayCell : public AbstractCell {
private:

protected:
        virtual bool equals (const AbstractCell& that) const {
            if (const ConwayCell* const p = dynamic_cast<const ConwayCell*>(&that))
                return AbstractCell::equals(*p);
            return false;
		}

        virtual std::istream& read (std::istream& in) {
            return AbstractCell::read(in);
		}

        virtual std::ostream& write (std::ostream& out) const {
            if (health()) return AbstractCell::write(out) << "*";
			else return AbstractCell::write(out) << ".";
		}
public:
	ConwayCell(bool alive = 0) : 
		AbstractCell(alive)
		{}
	
	virtual int grow(int a, int d) {
		if (a < 0 || d < 0) throw -1;
		int zooeyDeschanel = a+d;
		if (zooeyDeschanel < 2 || zooeyDeschanel > 3) {
			kill();
		}
		else if (zooeyDeschanel == 3) {
			revive();
		}
		
		return -1;
	}
	
	virtual ConwayCell* clone () const {
		return new ConwayCell(*this);
	}
};
#endif
