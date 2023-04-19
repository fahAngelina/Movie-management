#include <iostream>
#include"LL.h"

using namespace std;

//LL constructor
LL::LL(){
       hol=NULL;
       size=0;
}

//LL destructor
LL::~LL(){
     theater* t=hol;
     theater* temp;
     for(int i=0;i<size;i++){
          temp = t;
          t=t->move_next();
          delete temp;
     }
     size = 0;
}

//show all theater node
void LL::show_all(){
     theater* t=hol;
     for(int i=1;i<=size;i++){
          cout<<i<<". ";
          t->show_node();
          t=t->move_next();
     }
}

//add theater node in front
void LL::add_node(theater *&A){
       hol->insert(A);
       hol=A;
       size++;
 }

//get head
theater* LL::get_head(){
     return hol;
}

//get size
int LL::get_size(){
     return size;
}
