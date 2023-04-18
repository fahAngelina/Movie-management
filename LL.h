#include "theater.h"

class LL{
      theater* hol;
      int size;
public:
       void add_node(theater*&);
       void show_all();
       theater* get_head();
       int check_monster();
       int get_size();
       LL();
       ~LL();
      
};