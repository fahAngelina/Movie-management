#include <iostream>
#include <iomanip>
#include "LL.h"

using namespace std;

int main(int argc, char *argv[]){
    LL A;
    theater* t;
    seat* s;
    delux_seat* d;
    sofa_seat* f;
    for(int i=1;i<argc;i+=3) {
        t=new theater(argv[i],atof(argv[i+1]),atoi(argv[i+2]));
        A.add_node(t);
        for(int j=55;j>0;j--){
            if(j<=40){
                s=new seat(j);
                t->add_node_seat(s);
            }
            else if(j<=50){
                d=new delux_seat(j);
                t->add_node_delux_seat(d);
            }
            else{
                f=new sofa_seat(j);
                t->add_node_sofa_seat(f);
            }      
        }
    }
    A.show_all();
    return 0;
}