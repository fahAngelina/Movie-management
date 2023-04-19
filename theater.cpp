#include <iomanip>
#include "theater.h"

theater::theater(string a,float b,int c){
    movie_name = a;
    time = b;
    theater_number = c;
}

theater::~theater(){
    //cout<<"Deconstructing theater : "<<theater_number<<endl;
    seat* a=hol_seat;
    seat* temp_seat;
    delux_seat* b=hol_delux_seat;
    delux_seat* temp_delux_seat;
    sofa_seat* c=hol_sofa_seat;
    sofa_seat* temp_sofa_seat;
    for(int i=1;i<=55;i++){
        if(i<=40){
            temp_seat = a;
            a=a->move_next();
            delete temp_seat;
        }
        else if(i<=50){
            temp_delux_seat = b;
            b=b->move_next();
            delete temp_delux_seat;
        }
        else{
            temp_sofa_seat = c;
            c=c->move_next();
            delete temp_sofa_seat;
        }
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

void theater::add_node_seat(seat *&A){
        hol_seat->insert_seat(A);
        hol_seat=A;
}

void theater::add_node_delux_seat(delux_seat *&B){
        hol_delux_seat->insert_delux_seat(B);
        hol_delux_seat=B;
}
   
void theater::add_node_sofa_seat(sofa_seat *&C){
        hol_sofa_seat->insert_sofa_seat(C);
        hol_sofa_seat=C;
}

seat* theater::get_head_seat(){
     return hol_seat;
}

delux_seat* theater::get_head_delux_seat(){
    return hol_delux_seat;
}

sofa_seat* theater::get_head_sofa_seat(){
    return hol_sofa_seat;
}