#include <iostream>

using namespace std;

class seat{
protected:
    bool stats;
    int seat_number;
    seat* next;
public:
    seat(int=0);
    bool display_stats();
    int display_seat_number();
    void insert_seat(seat*&);
    int return_price();
    seat* move_next();
    void show_node();
    virtual ~seat();
};

class delux_seat:public seat{
public :
    int return_price(){
        return 150;
    }
    delux_seat(int=0);
    ~delux_seat();
};

class sofa_seat:public seat{
public :
    int return_price(){
        return 150;
    }
    sofa_seat(int=0);
    ~sofa_seat();
};