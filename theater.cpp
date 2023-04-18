#include <iomanip>
#include "theater.h"

theater::theater(string a,float b,int c){
    movie_name = a;
    time = b;
    theater_number = c;
}

theater::~theater(){
    cout<<"Deconstructing theater : "<<theater_number<<endl;
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
    cout<<"Theater : "<<theater_number<<" Movie name : "<<movie_name<<" Show time : "<<fixed<<setprecision(2)<<time<<endl;
}

void theater::insert(theater*& x){
      x->next=this;
}

void theater::add_node(seat *&A){
       hol->insert(A);
       hol=A;
       size++;
 }

seat* theater::get_head(){
     return hol;
}