#include <iostream>
#include <iomanip>
#include "LL.h"

using namespace std;

int main(int argc, char *argv[]){
    LL A;
    theater* t;
    for(int i=1;i<argc;i+=3) {
        t=new theater(argv[i],atof(argv[i+1]),atoi(argv[i+2]));
        A.add_node(t);
    }
    A.show_all();
    return 0;
}