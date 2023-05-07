#include <iostream>
#include <iomanip>
//#include "Node.h"
//#include "theater.h"
#include "LL.h"
#include "exception.h"

using namespace std;

int receive_input();

int main(int argc, char *argv[]){
    //create pointer for all type
    int flag;
    LL A;
    theater* t;
    seat* s;
    // create LL theater
    for(int i=1;i<argc;i+=3) {
        t=new theater(argv[i],atof(argv[i+1]),atoi(argv[i+2]));
        A.add_node(t);
        //create LLs seat in theater
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
    //main loop
    do{                                                   
        flag=1;
        system("CLS");          
        cout<<" ____   ___  ____    _____ _   _ _____    _  _____ _____ ____   "<<endl;
        cout<<"|  _ \\ / _ \\|  _ \\  |_   _| | | | ____|  / \\|_   _| ____|  _ \\  "<<endl;
        cout<<"| |_) | | | | |_) |   | | | |_| |  _|   / _ \\ | | |  _| | |_) | "<<endl;
        cout<<"|  __/| |_| |  __/    | | |  _  | |___ / ___ \\| | | |___|  _ <  "<<endl;
        cout<<"|_|    \\___/|_|       |_| |_| |_|_____/_/   \\_\\_| |_____|_| \\_\\ "<<endl;          
        A.show_all();                                                                                                  
        switch(receive_input()){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                flag=0;
                break;
            default:
                break;
        }
    }while(flag);
    return 0;
}

int receive_input(){
    int x,a=0;
    do{
		try{
			cout<<"Select option number :"<<endl;
			cin>>x;
			a=0;
			if(cin.fail())
				throw cin_fail;
			if(x>4 || x<=0)
				throw outof_range;
		}
		catch(exception& e){
			cout<<e.what()<<endl;
			a=1;
		}
	}while(a);
    return x;
}