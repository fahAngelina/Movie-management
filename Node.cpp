#include "Node.h"

seat::seat(int a){
    seat_number = a;
    stats = true;
}

seat::~seat(){
    cout<<"Deconstructing seat : "<<seat_number<<endl;
}

int seat::display_seat_number(){
    return seat_number;
}

seat* seat::move_next(){
    return next;
}

void seat::show_node(){
    cout<<"seat : "<<endl;
}

void seat::insert(seat*& x){
      x->next=this;
}

int seat::return_price(){
    return 100;
}

delux_seat::delux_seat(bool a):seat(a){};

sofa_seat::sofa_seat(bool a):seat(a){};

delux_seat::~delux_seat(){};

sofa_seat::~sofa_seat(){};