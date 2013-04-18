#include Life.h

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
	Life *_world;

protected:
	AbstractCell& operator = (const AbstractCell& that) {
		_alive = that._alive;
		_world = that._world;
		return *this;
	}

	virtual bool equals (const AbstractCell& that) const = 0;

	virtual std::istream& read (std::istream& in) = 0;

	virtual std::ostream& write (std::ostream& out) const = 0;

public:
	AbstractCell (bool input, Life *environment) :
			_alive(input),
			_world(environment)
		{}
/*
	AbstractCell (const AbstractCell& that) :
			_alive (that._alive),
			_world (that._world)
		{}
*/
	virtual ~AbstractCell ()
		{}

	virtual bool mutate () const = 0;

	virtual AbstractCell* clone () const = 0;

};

bool AbstractCell::equals (const AbstractCell& that) const {
    return (_alive == that._alive) && (_world == that._world);
}

std::istream& AbstractCell::read (std::istream& in) {
    return in >> _alive >> _world;
}

std::ostream& AbstractCell::write (std::ostream& out) const {
    return out ;
}
