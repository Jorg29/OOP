#include "catch2/catch_test_macros.hpp"

using namespace std;

bool move_forward(int c,int r){
    bool f=false;
    if((c==1 && startup_speed > r) || ((c>=2 && c<=8) && power>r))
    {
        f = true;
    }
    else if(((power+stamina)/2)>r && c>8)
    {
        f=true;
    }   
    return f;
}

TEST_CASE( "round", "[movement]" ) {
    REQUIRE (move_forward(1,1) == true );
    REQUIRE( move_forward(1,100) == false );
    REQUIRE( move_forward(3,40) == true );
    REQUIRE( move_forward(10,50) == true );
}
