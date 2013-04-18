#include AbstractCell.h

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
            if (_alive) return AbstractCell::write(out) << "*";
			else return AbstractCell::write(out) << ".";
		}
public:
	ConwayCell(bool alive, Life* world) : 
		AbstractCell(alive, world)
		{}
	
	virtual bool grow(int a, int d) {
		int zooeyDeschanel = a+d;
		if (zooeyDeschanel < 3 || zooeyDeschanel > 3) {
			_alive = 0;
		}
		else {
			_alive = 1;
		}
	}
	virtual ConwayCell* clone () const {
		return new ConwayCell(*this);
	}
};
