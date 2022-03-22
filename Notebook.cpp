#include <iostream>
#include <stdexcept>
#include "Direction.hpp"
#include "Notebook.hpp"
using namespace std;

namespace ariel{
    Notebook::Notebook(){}
    void Notebook::show( int row){}
    void Notebook::write( int page, int row, int col,Direction direction, string str){}
    string Notebook::read( int page, int row, int col, Direction direction, int length){
        return "ahmad";
    }
    void Notebook::erase(int page, int row,int col, Direction direction, int length){}
    
}