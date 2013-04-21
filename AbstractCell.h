#ifndef ABSTRACTCELL_H
#define ABSTRACTCELL_H

class AbstractCell {
	friend bool operator == (const AbstractCell& lhs, const AbstractCell& rhs) {
		return lhs.equals(rhs);
	}

	friend bool operator != (const AbstractCell& lhs, const AbstractCell& rhs) {
		return !(lhs == rhs);
	}

	friend std::istream& operator >> (std::istream& lhs, AbstractCell& rhs) {
		return rhs.read(lhs);
	}

	friend std::ostream& operator << (std::ostream& lhs, const AbstractCell& rhs) {
		return rhs.write(lhs);
	}

private:
	bool _alive;

protected:
	AbstractCell& operator = (const AbstractCell& that) {
		_alive = that._alive;
		return *this;
	}

	virtual bool equals (const AbstractCell& that) const = 0;

	virtual std::istream& read (std::istream& in) = 0;

	virtual std::ostream& write (std::ostream& out) const = 0;

public:
	AbstractCell (bool alive) :
			_alive(alive)
		{}
/*
	AbstractCell (const AbstractCell& that) :
			_alive (that._alive)
		{}
*/
	virtual ~AbstractCell ()
		{}

	virtual int grow (int a, int d) = 0;
	
	bool health() const {
		return _alive;
	}
	
	void revive() {
		_alive = 1;
	}
	
	void kill() {
		_alive = 0;
	}
	
	virtual AbstractCell* clone () const = 0;

};

bool AbstractCell::equals (const AbstractCell& that) const {
    return (_alive == that._alive);
}

std::istream& AbstractCell::read (std::istream& in) {
    return in >> _alive;
}

std::ostream& AbstractCell::write (std::ostream& out) const {
    return out;
}

#endif
