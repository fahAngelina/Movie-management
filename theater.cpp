#include <iomanip>
#include "theater.h"

theater::theater(string a,float b,int c){
    movie_name = a;
    time = b;
    theater_number = c;
}

theater::~theater(){
    //cout<<"Deconstructing theater : "<<theater_number<<endl;
    seat* t=hol_seat;
    seat* temp_seat;
    for(int i=1;i<=55;i++){
        temp_seat = t;
        t=t->move_next();
        delete temp_seat;
    }
}

string theater::display_name(){
    return movie_name;
}

float theater::display_time(){
    return time;
}

int theater::display_theater_number(){
    return theater_number;
}

theater* theater::move_next(){
    return next;
}

void theater::show_node(){
    cout<<" Movie name : "<<movie_name<<" , show time : "<<fixed<<setprecision(2)<<time<<" (theater "<<theater_number<<")"<<endl;
}

void theater::insert(theater*& x){
    x->next=this;
}

void theater::add_node(seat *&A){
        hol_seat->insert_seat(A);
        hol_seat=A;
}

seat* theater::get_head_seat(){
     return hol_seat;
}