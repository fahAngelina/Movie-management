#include <iostream>
#include <iomanip>
#include <windows.h> 
#include "LL.h"
#include "exception.h"

using namespace std;

int receive_input_int(int,int,int);
char receive_input_char();
void show_pop(),show_list(),center_text(string),select_seat(theater*),display_seat(seat*,theater*),avaliable_seat(theater*);
theater* select_movie(theater*,int);

int main(int argc, char *argv[]){
    //create pointer for all type
    system("Color 09");
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
        cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;   
        center_text("|| Movie List ||");      
        cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;   
        A.show_all();   
        show_list();                                                                    
        switch(receive_input_int(1,4,1)){
            case 1:
                select_seat(select_movie(A.get_head(),A.get_size()));
                break;
            case 2:
                avaliable_seat(select_movie(A.get_head(),A.get_size()));
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
    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;   
    center_text("|| Main Menu ||");
    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;   
    center_text("1. Buy ticket");
    center_text("2. Avaliable seat");
    center_text("3. Promotion");
    center_text("4. exit");
    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl; 
}

//receive userinput(char) with exception
char receive_input_char(){
    int a=0;
    char x;
    do{
		try{
			cout<<"Select Seat(alphabet,number) :";
			cin>>x;
			a=0;
			if(!isalpha(x))
				throw cin_fail;
            x=toupper(x);
			if(x>='H' && x<='Z')
				throw outof_alphabet;
		}
		catch(exception& e){
			cout<<e.what()<<endl;
			a=1;
		}
	}while(a);
    return x;
}

//receive userinput(int) with exception
int receive_input_int(int con1,int con2,int con3){
    int x,a=0;
    do{
		try{
            if(con3 == 1)
			    cout<<"Select option number :";
            else if(con3 == 2)
                cout<<"Select Movie number :";
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
    movie_number = b-receive_input_int(1,b,2)+1;
    for(int i = 1;i<=movie_number;i++){
        if(i == movie_number){       
            break;
        }
        a=a->move_next();
    }
    return a;
}

//select seat and reserved it
void select_seat(theater* t){
    flag1:
    int z=0,seat_number=0;
    char x;
    seat* s;
    s = t->get_head_seat();
    display_seat(s,t);
    x=receive_input_char();
    switch(x){
        case 'A':
            z=receive_input_int(1,10,0);
            seat_number=z;
            break;
        case 'B':
            z=receive_input_int(1,10,0);
            seat_number=10+z;
            break;
        case 'C':
            z=receive_input_int(1,10,0);
            seat_number=20+z;
            break;
        case 'D':
            z=receive_input_int(1,10,0);
            seat_number=30+z;
            break;
        case 'E':
            z=receive_input_int(1,8,0);
            seat_number=40+z;
            break;
        case 'F':
            z=receive_input_int(1,7,0);
            seat_number=48+z;
            break;
        case 'G':
            z=receive_input_int(1,5,0);
            seat_number=55+z;
            break;
        default:
            cout<<"Error!!"<<endl;
    }
    for(int i = 1;i<=seat_number;i++){
        if(i == seat_number){
            if(s->display_stats()){
                cout<<"Reserve Seat : "<<x<<z<<endl;
                s->change_stats();
            }
            else{
                cout<<"This seat is reserved"<<endl;+
                system("PAUSE");
                system("CLS");
                goto flag1;
            }
            break;
        }
        s=s->move_next();
    }
    system("PAUSE");
}

//display seat
void display_seat(seat* s,theater* t){
    //display seat
    show_pop();
    center_text(t->display_name());
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
            cout << "\033[96m" <<"O  "<< "\033[94m";
        else
            cout << "\033[91m" <<"X  "<< "\033[94m";
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
                cout << "\033[36m" <<"O  "<< "\033[94m";
            else
                cout << "\033[36m" <<"O   "<< "\033[94m";
        }
        else{
            if(i==8)
                 cout << "\033[91m" <<"X  "<< "\033[94m";
            else
                 cout << "\033[91m" <<"X   "<< "\033[94m";
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
            cout << "\033[34m" <<"OO    "<< "\033[94m";
        else
            cout << "\033[91m" <<"XX    "<< "\033[94m";
        if(i==5)
            cout<<"G"<<endl;
        s=s->move_next();
    }
    cout<<endl<<endl;
}

void avaliable_seat(theater* t){
    seat* s;
    s=t->get_head_seat();
    display_seat(s,t);
    system("PAUSE");
}