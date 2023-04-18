#include <iostream>
#include"LL.h"

using namespace std;

LL::LL(){
       hol=NULL;
       size=0;
}

LL::~LL(){
     theater* t=hol;
     theater* temp;
     int i;
     for(i=0;i<size;i++){
          temp = t;
          t=t->move_next();
          delete temp;
     }
     size = 0;
}

void LL::show_all(){
     theater* t=hol;
     for(int i=1;i<=size;i++){
          cout<<i<<". ";
          t->show_node();
          t=t->move_next();
     }
}

void LL::add_node(theater *&A){
       hol->insert(A);
       hol=A;
       size++;
 }

theater* LL::get_head(){
     return hol;
}

int LL::get_size(){
     return size;
}
