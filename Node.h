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
    void insert_seat(seat*&);
    int return_price();
    seat* move_next();
    void show_node();
    ~seat();
};

class delux_seat:public seat{
private:
    delux_seat* next;
public :
    int return_price(){
        return 150;
    }
    delux_seat(int=0);
    delux_seat* move_next(){
        return next;
    }
    void insert_delux_seat(delux_seat*& x){
      x->next=this;
    }
    ~delux_seat();
};

class sofa_seat:public seat{
private:
    sofa_seat* next;
public :
    int return_price(){
        return 150;
    }
    sofa_seat(int=0);
    sofa_seat* move_next(){
        return next;
    }
    void insert_sofa_seat(sofa_seat*& x){
      x->next=this;
    }
    ~sofa_seat();
};