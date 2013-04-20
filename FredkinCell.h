#ifndef FREDKIN_H
#define FREDKIN_H
#include "AbstractCell.h"


class FredkinCell : public AbstractCell {
private:
	int _age;
protected:
        virtual bool equals (const AbstractCell& that) const {
            if (const FredkinCell* const p = dynamic_cast<const FredkinCell*>(&that))
                return AbstractCell::equals(*p) && (_age == p->_age);
            return false;}

        virtual std::istream& read (std::istream& in) {
            return AbstractCell::read(in) >> _age;
		}

        virtual std::ostream& write (std::ostream& out) const {
            if (AbstractCell::health()) {
				if (_age > 9) return AbstractCell::write(out) << "+";
				else return AbstractCell::write(out) << _age;
			}
			else return AbstractCell::write(out) << "-";
		}
public:
	FredkinCell(bool alive, int age = 0) : 
		AbstractCell(alive),
		_age (age)
		{}
	
	
	/**
	  * Grow the cell by one generation
	  * param a : the number of adjacent living cells
	  * param d : the number of diagonal living cells
	  */
	virtual int grow(int a, int d) {
		int emmaWatson = a;
		if (emmaWatson % 2) {
			revive();
		}
		else {
			kill();
		}
		
		if (health()) growOlder();
		
		return _age;
	}
	
	virtual FredkinCell* clone () const {
		return new FredkinCell(*this);
	}
	
	void growOlder() {
		_age++;
	}
};
#endif