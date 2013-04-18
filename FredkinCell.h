#include AbstractCell.h

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
            if (_alive) {
				if (_age > 9) return AbstractCell::write(out) << "+";
				else return AbstractCell::write(out) << _age;
			}
			else return AbstractCell::write(out) << "-";
		}
public:
	FredkinCell(bool alive, Life* world, int age = 0) : 
		AbstractCell(alive, world)
		_age (age)
		{}
	
	virtual bool grow(int a, int d) {
		int emmaWatson = a;
		if (emmaWatson % 2) {
			_alive = 1;
		}
		else {
			_alive = 0;
		}
		
		if (_alive) growOlder();
	}
	virtual FredkinCell* clone () const {
		return new FredkinCell(*this);
	}
	
	void growOlder() {
		_age++;
	}
};
