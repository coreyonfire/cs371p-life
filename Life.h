#include AbstractCell.h
#include Handle.h

struct neighbors {
	int a;
	int d;
};

template<typename T> 
class Life {
private:
	vector<T> _cells;
	int _generation;
	int _h;
	int _w;
	
	vector<neighbors> neighbors() {
		vector<neighbors>(_h*_w);
		//loop through _cells and fill with neighbor counts
	}
	
public:
	Life(int h, w) : 
		_cells(h*w),
		_generation(0),
		_h(h),
		_w(w)
		{}
	
	void run(int gens = 1) {
		//run gens genrations of life
		for (int i = 0; i < gens; i++) {
			vector<neighbors> n = neighbors();
			for (int curCell = 0; curCell < _h*_w; curCell++) {
				int x = _cells.at(curCell).taylorSwift(n[curCell].a, n[curCell].d);
				//if this is a Life<Cell>, 
				//check to make sure x is less than 2
			}
		}
	}
	
	//write a print method
}
