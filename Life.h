#include AbstractCell.h
#include Handle.h

struct neighbors {
	int a;
	int d;
};

template<typename T> 
class Life {

	friend std::ostream& operator << (std::ostream& lhs, const Life& rhs) {
		return rhs.write(lhs);
	}
	
private:
	vector<T> _cells;
	int _generation;
	int _h;
	int _w;
	
	vector<neighbors> neighbors() {
		vector<neighbors> n();
		//loop through _cells and fill with neighbor counts
		for (int i = 0; i < _h*_w; i++) {
			neighbors cnd = {0, 0};
			
			if (i >= _w) {
				//check top, add to a
				cnd.a += _cells.at(i-_w)->health();
				if (i%_w != 0) {
					//check top left, add to d
					cnd.d += _cells.at(i-_w-1)->health();
				}
				
				if ( (i+1)%_w != 0 ) {
					//check top right, add to d
					cnd.d += _cells.at(i-_w+1)->health();
				}
			}
			
			if ( (i+1)%_w != 0) {
				//check right, add to a
				cnd.a += _cells.at(i+1)->health();
				if (i != (_w*_h - 1)) {
					//check bottom right, add to d
					cnd.d += _cells.at(i+_w+1)->health();
				}
			}
			
			if (i + _w < _w*_h) {
				//check bottom, add to a
				cnd.a += _cells.at(i+_w)->health();
				
				if ( i%_w != 0) {
					//check bottom left, add to d
					cnd.d += _cells.at(i+_w-1)->health();
				}
			}
			
			if ( i%_w != 0) { 
				//check left, add to a
				cnd.a += _cells.at(i-1)->health();
			}
			//now have neighborcount, add to array
			n.push_back(cnd);
		}
		
		return n;
	}
	
public:
	Life(int h, int w, std::istream &input) : 
		_cells(h*w),
		_generation(0),
		_h(h),
		_w(w) {
		init(input);
	}
		
	void init(std::istream& input) {
		char temp;
		for (int i = 0; i < _h*_w; i++) {
			input >> temp;
			T newCell;
			switch (temp) {
				case '.':
					newCell = ConwayCell(0);
					break;
				case '*':
					newCell = ConwayCell(1);
					break;
				case '-':
					newCell = FredkinCell(0, 0);
					break;
				case 0:
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:
					newCell = FredkinCell(1, temp);
					break;
				case '+':
					newCell = FredkinCell(1, 10);
					break;
				default :
					//new line character or garbage, disregard
					break;
			}
			_cells.push_back(newCell);
		}
		//board is populated
	}
	
	void run(int gens = 1) {
		//run gens genrations of life
		for (int i = 0; i < gens; i++) {
			vector<neighbors> n = neighbors();
			for (int curCell = 0; curCell < _h*_w; curCell++) {
				_cells.at(curCell).grow(n[curCell].a, n[curCell].d);
			}
			_generation++;
		}
	}
	
	
}

std::ostream& Life::write (std::ostream& out) const {
	//write a print method
	out << "Generation = " << _generation << ", Population = " << population() << ".\n";
	//print the board
    return out;
}