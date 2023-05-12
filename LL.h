#include "theater.h"

class LL{
      theater* hol;
      int size;
public:
       void add_node(theater*&);
       void show_all();
       theater* get_head();
       int get_size();
       LL();
       ~LL();
      
};