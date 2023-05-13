#include <iostream>
#include "Node.h"

using namespace std;

class theater{
private:
    seat* hol_seat;
    string movie_name;
    float time;
    int theater_number;
    theater* next;
public:
    theater(string="theater",float=0.00,int=0);
    string display_name();
    float display_time();
    int display_theater_number();
    void insert(theater*&);
    theater* move_next();
    void show_node(int);
    void add_node(seat*&);
    seat* get_head_seat();
    ~theater();
};