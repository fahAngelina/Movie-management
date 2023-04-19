#include <iostream>
#include <iomanip>
//#include "Node.h"
//#include "theater.h"
#include "LL.h"

using namespace std;

int main(int argc, char *argv[]){
    LL A;
    theater* t;
    seat* s;
    for(int i=1;i<argc;i+=3) {
        t=new theater(argv[i],atof(argv[i+1]),atoi(argv[i+2]));
        A.add_node(t);
        for(int j=55;j>0;j--){
            if(j<=40)
                s=new seat(j);
            else if(j<=50)
                s=new delux_seat(j);
            else
                s=new sofa_seat(j);   
            t->add_node(s);
        }
    }
    A.show_all();
    return 0;
}