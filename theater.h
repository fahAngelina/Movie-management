#include <iostream>
#include "Node.h"

using namespace std;

class theater{
private:
    seat* hol;
    string movie_name;
    int size;
    float time;
    int theater_number;
    theater* next;
    //Node seat;
public:
    theater(string="theater",float=0.00,int=0);
    string display_name();
    float display_time();
    int display_theater_number();
    void insert(theater*&);
    theater* move_next();
    void show_node();
    void show_all();
    void add_node(seat*&);
    seat* get_head();
    ~theater();
};