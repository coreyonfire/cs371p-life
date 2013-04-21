#ifndef LIFE_H
#define LIFE_H
#include "FredkinCell.h"
#include "ConwayCell.h"
#include "Cell.h"
#include "AbstractCell.h"
#include "Handle.h"
#include <vector>
using std::vector;

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
	
	vector<neighbors> neighborCount() {
		vector<neighbors> n;
		//loop through _cells and fill with neighbor counts
		for (int i = 0; i < _h*_w; i++) {
			neighbors cnd = {0, 0};
			//std::cout<< "getting count for space (" << i/_w << ", " << i%_w << ")/"<<i<<" out of " <<_w*_h<< std::endl;
			if (i >= _w) {
				//check top, add to a
				//std::cout << "Top" << std::endl;
				cnd.a += _cells.at(i-_w).health();
				if (i%_w != 0) {
					//check top left, add to d
					//std::cout << "Top Left" << std::endl;
					cnd.d += _cells.at(i-_w-1).health();
				}
				
				if ( (i+1)%_w != 0 ) {
					//check top right, add to d
					//std::cout << "Top Right" << std::endl;
					cnd.d += _cells.at(i-_w+1).health();
				}
			}
			
			if ( (i+1)%_w != 0) {
				//check right, add to a
				//std::cout << "Right" << std::endl;
				cnd.a += _cells.at(i+1).health();
				if (i/_w < _h-1) {
					//check bottom right, add to d
					//std::cout << "Bottom Right " <<i/_w << ", " << _h-1 << std::endl;
					cnd.d += _cells.at(i+_w+1).health();
				}
			}
			
			if (i + _w < _w*_h) {
				//check bottom, add to a
				//std::cout << "Bottom" << std::endl;
				cnd.a += _cells.at(i+_w).health();
				
				if ( i%_w != 0) {
					//check bottom left, add to d
					//std::cout << "Bottom Left" << std::endl;
					cnd.d += _cells.at(i+_w-1).health();
				}
			}
			
			if ( i%_w != 0) { 
				//check left, add to a
				//std::cout << "Left" << std::endl;
				cnd.a += _cells.at(i-1).health();
			}
			assert(cnd.a + cnd.d < 9);
			//now have neighborcount, add to array
			n.push_back(cnd);
		}
		
		return n;
	}
	
	int population() const {
		int pop = 0;
		for (int i = 0; i < _w*_h; i++) {
			if (_cells.at(i).health()) pop++;
		}
		return pop;
	}
	
	int generation() const {
		return _generation;
	}
	
protected:
	std::ostream& write (std::ostream& out) const {
		//write a print method
		out << "Generation = " << _generation << ", Population = " << population() << ".\n";
		//print the board
		for (int i = 0; i < _h*_w; i++) {
			out << _cells.at(i);
			if (!((i+1)%_w)) out << std::endl;
		}
		return out;
	}
public:
	Life(int h, int w, vector<T> &input) : 
		_cells(input),
		_generation(0),
		_h(h),
		_w(w) 
		{if (h < 1 || w < 1) throw -1;}
		
		
	
	void run(int gens = 1) {
		//run gens genrations of life
		if (gens < 1) gens = 1;
		for (int i = 0; i < gens; i++) {
			vector<neighbors> n = neighborCount();
			//std::cout << "Neighbors created." << std::endl;
			for (int curCell = 0; curCell < _h*_w; curCell++) {
				_cells.at(curCell).grow(n[curCell].a, n[curCell].d);
			}
			//std::cout << "Generation complete." << std::endl;
			_generation++;
		}
	}
};
#endif
