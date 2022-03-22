#include "doctest.h"
#include "Notebook.hpp"
#include <string>

namespace ariel
{
    
    TEST_CASE("read rest")
    {
        Notebook notebook{};
        CHECK_THROWS(notebook.read(100,-1,2,Direction::Horizontal,3));
        CHECK_THROWS(notebook.read(100,-1,-2,Direction::Horizontal,3));
        CHECK_THROWS(notebook.read(100,1,-2,Direction::Horizontal,1));
        CHECK_THROWS(notebook.read(100,1,12,Direction::Horizontal,0));
        CHECK_THROWS(notebook.read(100,1,12,Direction::Horizontal,-1));
        
        std::string val;
        val=notebook.read(100,1,12,Direction::Horizontal,3);
        CHECK(val.length() == 3);
        CHECK(val != "");
    }

    TEST_CASE("post test")
    {
        Notebook notebook{};
        CHECK_THROWS(notebook.write(100,-1,0,Direction::Horizontal,"ahmad"));
        CHECK_THROWS(notebook.write(100,-1,-2,Direction::Horizontal,"ahmad"));
        CHECK_THROWS(notebook.write(100,1,2,Direction::Horizontal,""));
        CHECK_THROWS(notebook.write(100,1,-2,Direction::Horizontal,"ahmad"));
    }

    TEST_CASE("read write test")
    {
        Notebook notebook{};
        notebook.write(100,0,0,Direction::Horizontal,"ahmad");
        std::string val;
        val=notebook.read(100,0,0,Direction::Horizontal,3);
        CHECK(val == "ahm");
        notebook.write(100,0,0,Direction::Vertical,"abed");
        val=notebook.read(100,0,0,Direction::Vertical,3);
        CHECK(val == "abe");
        val=notebook.read(100,0,0,Direction::Horizontal,3);
        CHECK(val == "aba");
        val=notebook.read(100,0,5,Direction::Vertical,3);
        CHECK(val == "f__");
        notebook.write(100,0,2,Direction::Vertical,"hello");
        val=notebook.read(100,1,0,Direction::Horizontal,3);
        CHECK(val == "i_e");
        val=notebook.read(100,3,0,Direction::Horizontal,3);
        CHECK(val == "a_l");
        notebook.write(100,2,2,Direction::Horizontal,"foo");
        val=notebook.read(100,2,2,Direction::Horizontal,3);
        CHECK(val == "foo");
        val=notebook.read(100,0,2,Direction::Vertical,5);
        CHECK(val == "hello");
        val=notebook.read(100,1,4,Direction::Vertical,3);
        CHECK(val == "_a_");
    }

    TEST_CASE ("empty borad") {
    Notebook notebook;
    CHECK(notebook.read(100,20,30,Direction::Horizontal, 1) == "_");
    CHECK(notebook.read(100,20,30,Direction::Horizontal, 2) == "__");
    CHECK(notebook.read(100,20,30,Direction::Horizontal, 8) == "________");
    CHECK(notebook.read(100,80,180,Direction::Vertical, 6) == "______");


}


}