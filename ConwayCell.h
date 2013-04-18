#include AbstractCell.h

class ConwayCell : public AbstractCell {
private:

protected:
        virtual bool equals (const AbstractCell& that) const {
            if (const ConwayCell* const p = dynamic_cast<const ConwayCell*>(&that))
                return AbstractCell::equals(*p);
            return false;}

        virtual std::istream& read (std::istream& in) {
            return AbstractCell::read(in);}

        virtual std::ostream& write (std::ostream& out) const {
            return AbstractCell::write(out);}
public:
	ConwayCell(bool alive, Life* world) : 
		AbstractCell(alive, world)
		{}
	
	virtual bool mutate() {
		//check for neighbors, act accordingly
	}
	virtual ConwayCell* clone () const {
		return new ConwayCell(*this);
	}
};
