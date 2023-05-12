#include <iomanip>
#include "theater.h"

//theater constructor
theater::theater(string a,float b,int c){
    movie_name = a;
    time = b;
    theater_number = c;
}

//theater destructor
theater::~theater(){
    //cout<<"Deconstructing theater : "<<theater_number<<endl;
    seat* t=hol_seat;
    seat* temp_seat;
    for(int i=1;i<=60;i++){
        temp_seat = t;
        t=t->move_next();
        delete temp_seat;
    }
}

//display movie name 
string theater::display_name(){
    return movie_name;
}

//display movie time
float theater::display_time(){
    return time;
}

//display theater number
int theater::display_theater_number(){
    return theater_number;
}

//next Ptr
theater* theater::move_next(){
    return next;
}

//show current node
void theater::show_node(int i){
    stringstream ss;
    cout<<setw((38)+(movie_name.size()/2))<<movie_name;
    ss<<fixed<<setprecision(2)<<time;
    if(movie_name.size()%2==1 && (movie_name.size()==5 || movie_name.size()==7))
        cout<<" ";
    for(int i=1;(i<19/movie_name.size()+12);i++){
        cout<<" ";
    }
    string var = ss.str()+"               "+to_string(theater_number);
    cout<<var<<endl;
}
//insert node
void theater::insert(theater*& x){
    x->next=this;
}

//add seat node in front
void theater::add_node(seat *&A){
        hol_seat->insert_seat(A);
        hol_seat=A;
}

//get head seat
seat* theater::get_head_seat(){
     return hol_seat;
}
