#include <iostream>

using namespace std;

class seat{
private:
    bool stats;
    int seat_number;
    seat* next;
    //Node seat;
public:
    seat(int=0);
    bool display_stats();
    int display_seat_number();
    void insert(seat*&);
    int return_price();
    seat* move_next();
    void show_node();
    ~seat();
};

class delux_seat:public seat{
public :
    int return_price(){
        return 150;
    }
    delux_seat(bool=true);
    ~delux_seat();
};

class sofa_seat:public seat{
public :
    int return_price(){
        return 150;
    }
    sofa_seat(bool=true);
    ~sofa_seat();
};