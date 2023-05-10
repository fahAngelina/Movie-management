#include <iostream>
#include <iomanip>
#include <windows.h> 
#include "LL.h"
#include "exception.h"

using namespace std;

int receive_input(int,int,int);
void show_pop(),show_list(),center_text(string),select_seat(theater*),display_seat(seat*);
theater* select_movie(theater*,int);

int main(int argc, char *argv[]){
    //create pointer for all type
    int flag;
    LL A;
    theater* t;
    seat* s;
    // create LL theater
    for(int i=argc-3;i>0;i-=3) {
        t=new theater(argv[i],atof(argv[i+1]),atoi(argv[i+2]));
        A.add_node(t);
        //create LLs seat in theater
        for(int j=60;j>0;j--){
            if(j<=40)
                s=new seat(j);
            else if(j<=55)
                s=new delux_seat(j);
            else
                s=new sofa_seat(j);   
            t->add_node(s);
        }
    }
    //main loop
    do{
        flag=1;
        show_pop();         
        cout<<endl<<"----------------------------------------------------------------------------------------------------------------"<<endl;   
        center_text("|| Movie List ||");      
        cout<<endl<<"----------------------------------------------------------------------------------------------------------------"<<endl;   
        A.show_all();   
        show_list();                                                                    
        switch(receive_input(1,4,1)){
            case 1:
                select_seat(select_movie(A.get_head(),A.get_size()));
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

//show text in center
void center_text(string a){
    cout<<setw((115/2)+(a.size()/2))<<a<<endl;
}

//show POP THEATER
void show_pop(){
    system("CLS"); 
    cout<<".______     ______   .______      .___________. __    __   _______     ___   .___________. _______ .______          "<<endl;
    cout<<"|   _  \\   /  __  \\  |   _  \\     |           ||  |  |  | |   ____|   /   \\  |           ||   ____||   _  \\    "<<endl;
    cout<<"|  |_)  | |  |  |  | |  |_)  |    `---|  |----`|  |__|  | |  |__     /  ^  \\ `---|  |----`|  |__   |  |_)  |       "<<endl;
    cout<<"|   ___/  |  |  |  | |   ___/         |  |     |   __   | |   __|   /  /_\\  \\    |  |     |   __|  |      /       "<<endl;
    cout<<"|  |      |  `--'  | |  |             |  |     |  |  |  | |  |____ /  _____  \\   |  |     |  |____ |  |\\  \\----. "<<endl;
    cout<<"| _|       \\______/  | _|             |__|     |__|  |__| |_______/__/     \\__\\  |__|     |_______|| _| `._____| "<<endl<<endl;
}              

//show list
void show_list(){
    cout<<endl<<"----------------------------------------------------------------------------------------------------------------"<<endl;   
    center_text("|| Main Menu ||");
    cout<<endl<<"----------------------------------------------------------------------------------------------------------------"<<endl;   
    center_text("1. Buy ticket");
    center_text("2. Avaliable seat");
    center_text("3. Promotion");
    center_text("4. exit");
    cout<<endl<<"----------------------------------------------------------------------------------------------------------------"<<endl; 
}

//receive userinput with exception
int receive_input(int con1,int con2,int con3){
    int x,a=0;
    do{
		try{
            if(con3 == 1)
			    cout<<"Select option number :"<<endl;
            if(con3 == 2)
                cout<<"Select Movie number :"<<endl;
            if(con3 == 3)
                cout<<"Select Seat number :"<<endl;
			cin>>x;
			a=0;
			if(cin.fail())
				throw cin_fail;
			if(x>con2 || x<con1)
				throw outof_range;
		}
		catch(exception& e){
			cout<<e.what()<<endl;
			a=1;
		}
	}while(a);
    return x;
}

//select movie
theater* select_movie(theater* a ,int b){
    int movie_number;
    movie_number = b-receive_input(1,b,2)+1;
    for(int i = 1;i<=movie_number;i++){
        if(i == movie_number){
            show_pop();        
            center_text(a->display_name());
            break;
        }
        a=a->move_next();
    }
    return a;
}

//select seat and reserved it
void select_seat(theater* t){
    int seat_number;
    seat* s;
    s = t->get_head_seat();
    display_seat(s);
    seat_number = receive_input(1,60,3);
    for(int i = 1;i<=seat_number;i++){
        if(i == seat_number){
            cout<<"buy seat : "<<s->display_seat_number()<<endl;
            s->change_stats();
            break;
        }
        s=s->move_next();
    }
    system("PAUSE");
}

//display seat
void display_seat(seat* s){
    //display seat
    center_text("________________________________");
    for(int i=1;i<=40;i++){
        switch(i){
            case 1:
                cout<<endl<<"                                       A   ";
                break;
            case 11:
                cout<<" A"<<endl<<"                                       B   ";
                break;
            case 21:
                cout<<" B"<<endl<<"                                       C   ";
                break;
            case 31:
                cout<<" C"<<endl<<"                                       D   ";
                break;
        }
        if(s->display_stats())
            cout<<"O  ";
        else
            cout<<"X  ";
        if(i==40)
            cout<<" D"<<endl;
        s=s->move_next();
    }
    //display delux seat
    for(int i=1;i<=15;i++){
        if(i == 1)
            cout<<endl<<"                                       E   ";
        if(i == 9)
            cout<<"E"<<endl<<"                                       F     ";
        if(s->display_stats()){
            if(i==8)
                cout<<"O  ";
            else
                cout<<"O   ";
        }
        else{
            if(i==8)
                cout<<"X  ";
            else
                cout<<"X   ";
        }
        if(i==15)
            cout<<" F"<<endl;
        s=s->move_next();
    }
    //display sofa seat
    for(int i=1;i<=5;i++){
        if(i == 1)
            cout<<endl<<"                                       G    ";
        if(s->display_stats())
            cout<<"OO    ";
        else
            cout<<"XX    ";
        if(i==5)
            cout<<"G"<<endl;
        s=s->move_next();
    }
    cout<<endl<<endl;
}