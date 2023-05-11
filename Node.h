#include <iostream>

using namespace std;

//Super class seat
class seat{
protected:
    bool stats,reserve_stats;
    int seat_number;
    seat* next;
public:
    seat(int=0);
    bool display_stats();
    bool display_reserve_stats();
    int display_seat_number();
    virtual int display_seat_type();
    void insert_seat(seat*&);
    virtual int return_price();
    seat* move_next();
    void show_node();
    void change_reserve_stats();
    void change_stats();
    virtual ~seat();
};

//class delux seat that inheritance from Super class
class delux_seat:public seat{
public :
    int return_price(){
        return 200;
    }
    int display_seat_type(){
        return 2;
    }
    delux_seat(int=0);
    ~delux_seat();
};

//class sofa seat that inheritance from Super class
class sofa_seat:public seat{
public :
    int return_price(){
        return 500;
    }
    int display_seat_type(){
        return 3;
    }
    sofa_seat(int=0);
    ~sofa_seat();
};