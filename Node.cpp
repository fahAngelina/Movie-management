#include "Node.h"

seat::seat(int a){
    seat_number = a;
    stats = true;
}

seat::~seat(){
    //cout<<"Destruct seat : "<<seat_number<<endl;
}

int seat::display_seat_number(){
    return seat_number;
}

seat* seat::move_next(){
    return next;
}

void seat::show_node(){
    cout<<"seat : "<<seat_number<<endl;
}

void seat::insert_seat(seat*& x){
      x->next=this;
}

int seat::return_price(){
    return 100;
}

delux_seat::delux_seat(int a):seat(a){};

sofa_seat::sofa_seat(int a):seat(a){};

delux_seat::~delux_seat(){
    //cout<<"Destruct delux seat : "<<seat_number<<endl;
};

sofa_seat::~sofa_seat(){
    //cout<<"Destruct sofa seat : "<<seat_number<<endl;
};