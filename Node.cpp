#include "Node.h"

//seat constructor
seat::seat(int a){
    seat_number = a;
    reserve_stats = true;
    stats = true;
}

//seat destructor
seat::~seat(){
    //cout<<"Destruct seat : "<<seat_number<<endl;
}

//return seat type(1=seat,2=delux,3=sofa)
int seat::display_seat_type(){
        return 1;
}

//return seat stats
bool seat::display_stats(){
    return stats;
}

//return seat reserve stats
bool seat::display_reserve_stats(){
    return reserve_stats;
}

//return seat number
int seat::display_seat_number(){
    return seat_number;
}

//next Ptr
seat* seat::move_next(){
    return next;
}

////change seat reserve stats
void seat::change_reserve_stats(){
    if(reserve_stats)
        reserve_stats=false;
    else
        reserve_stats=true;
}

//change seat stats
void seat::change_stats(){
    if(stats)
        stats=false;
    else
        stats=true;
}

//show current node
void seat::show_node(){
    cout<<"seat : "<<seat_number<<endl;
}

//insert node
void seat::insert_seat(seat*& x){
      x->next=this;
}

//return seat price
int seat::return_price(){
    return 150;
}

//delux seat constructor
delux_seat::delux_seat(int a):seat(a){};

//sofa seat constructor
sofa_seat::sofa_seat(int a):seat(a){};

//delux seat destructor
delux_seat::~delux_seat(){
    //cout<<"Destruct delux seat : "<<seat_number<<endl;
};

//sofa seat destructor
sofa_seat::~sofa_seat(){
    //cout<<"Destruct sofa seat : "<<seat_number<<endl;
};