#include <iostream>
#include <stdexcept>
#include "Direction.hpp"
#include <map>
#include <vector>

using namespace std;

namespace ariel{
    class Notebook{

        private:
        map< int, map<int, char> > notebook;
        int  min_row, min_col,min_pages,max_pages, max_row, max_col;


        public:
        Notebook();  
        void show(int page);
        string read(int page, int row,int col, Direction direction, int length);
        void erase(int page, int row,int col, Direction direction, int lebgth);
        void write(int page, int row, int col, Direction direction, string str);
        
    };
    
}