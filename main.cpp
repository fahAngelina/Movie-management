#include <iostream>
#include <iomanip>
#include<cstdlib>
#include <windows.h> 
#include "LL.h"
#include "exception.h"

using namespace std;

int receive_input_int(int,int,int);
char receive_input_char();
void show_pop(),show_list(),center_text(string),select_seat(theater*),display_seat(seat*,theater*),avaliable_seat(theater*),show_promotion();
void cancel_reservation(seat*),payment(seat*,theater*),reservation(seat*),random_fill_seat(theater*,int);
theater* select_movie(theater*,int);

bool devmode=true;

int main(int argc, char *argv[]){
    //create pointer for all type
    srand((unsigned) time(NULL)); 
    system("Color 09");
    int flag;
    LL A;
    theater* t;
    seat* s;
    // create LL theater
    for(int i=argc-3;i>0;i-=3) {
        t=new theater(argv[i],atof(argv[i+1]),atoi(argv[i+2]));
        A.add_node(t);
        //create LL seat in theater
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
    //dev mode
    if(devmode){
        random_fill_seat(A.get_head(),A.get_size());
    }
    //main loop
    do{
        flag=1;
        show_pop();         
        cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;   
        center_text("|| Movie List ||");      
        cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;   
        center_text("Movie name          Show time          Theater");
        cout<<endl;
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
                show_promotion();
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
    cout<<setw((112/2)+(a.size()/2))<<a<<endl;
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
			    cout<<"Select option number : ";
            else if(con3 == 2)
                cout<<"Select Movie number : ";
            else if(con3 == 3)
                cout<<" :";
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
    movie_number = receive_input_int(1,b,2);
    for(int i = 1;i<=movie_number;i++){
        if(i == movie_number){       
            cout<<a->display_name();
            break;
        }
        a=a->move_next();
    }
    return a;
}

//select seat and reserved it
void select_seat(theater* t){
    int z=0,seat_number=0;
    char x;
    seat* s;
    s=t->get_head_seat();
    show_pop();
    display_seat(s,t);
    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl; 
    center_text("Menu");
    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl; 
    center_text("1. buy ticket");
    center_text("2. back ");
    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl; 
    if(receive_input_int(1,2,1)==1){
        flag1:
        s=t->get_head_seat();
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
                if(!s->display_reserve_stats()){
                    cout<<"You have already reserved this seat"<<endl;
                    break;
                }
                else if(s->display_stats()){
                    cout<<"Reserve Seat : "<<x<<z<<endl;
                    s->change_reserve_stats();
                }
                else{
                    cout<<"This seat is reserved"<<endl;
                    break;
                }
                break;
            }
            s=s->move_next();
        }
        system("PAUSE");
        system("CLS");
        show_pop();
        display_seat(t->get_head_seat(),t);
        cout<<"----------------------------------------------------------------------------------------------------------------"<<endl; 
        center_text("Menu");
        cout<<"----------------------------------------------------------------------------------------------------------------"<<endl; 
        center_text("1. Select another seat");
        center_text("2. Payment");
        center_text("3. Cancel reservation");
        cout<<"----------------------------------------------------------------------------------------------------------------"<<endl; 
        switch(receive_input_int(1,3,1)){
            case 1:
                goto flag1;
                break;
            case 2:
                payment(t->get_head_seat(),t);
                break;
            case 3:
                cancel_reservation(t->get_head_seat());
                break;
            default:
                cout<<"Error !!"<<endl;
        }
    }
}

//display seat
void display_seat(seat* s,theater* t){
    //display seat
    show_pop();
    center_text(t->display_name());
    center_text(" 1 ________________________________ 10");
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
        if(!s->display_reserve_stats())
            cout << "\033[35m" <<"O  "<< "\033[94m";
        else if(s->display_stats())
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
        if(!s->display_reserve_stats()){
            if(i==8)
                cout << "\033[35m" <<"O  "<< "\033[94m";
            else
                cout << "\033[35m" <<"O   "<< "\033[94m";
        }
        else if(s->display_stats()){
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
        if(!s->display_reserve_stats())
            cout << "\033[35m" <<"OO    "<< "\033[94m";
        else if(s->display_stats())
            cout << "\033[34m" <<"OO    "<< "\033[94m";
        else
            cout << "\033[91m" <<"XX    "<< "\033[94m";
        if(i==5)
            cout<<"G"<<endl;
        s=s->move_next();
    }
    cout <<endl<< "\033[96m" <<"                                  O"<< "\033[94m"<<" = Normal seat  ";
    cout << "\033[36m" <<"O"<< "\033[94m"<<" = Delux seat  ";
    cout << "\033[34m" <<"OO"<< "\033[94m"<<" = Sofa seat  "<<endl<<endl;
}

//show avaliable seat in that theater
void avaliable_seat(theater* t){
    display_seat(t->get_head_seat(),t);
    system("PAUSE");
}

//cancel all reservation in that theater
void cancel_reservation(seat* s){
    for(int i=1;i<=60;i++){
        if(!s->display_reserve_stats())
            s->change_reserve_stats();
        s=s->move_next();
    }
}

//reservation seat in that theater
void reservation(seat* s){
    for(int i=1;i<=60;i++){
        if(!s->display_reserve_stats()){
            s->change_reserve_stats();
            s->change_stats();
        }
        s=s->move_next();
    }
}

//user payment
void payment(seat* s,theater* t){
    int result=0,seat=0,delux=0,sofa=0;
    int price_seat=0,price_delux=0,price_sofa=0;
    system("CLS");
    show_pop();
    display_seat(t->get_head_seat(),t);
    for(int i=1;i<=60;i++){
        if(!s->display_reserve_stats()){
            result+= s->return_price();
            switch(s->display_seat_type()){
                case 1:
                    seat++;
                    price_seat+=s->return_price();
                    break;
                case 2:
                    delux++;
                    price_delux+=s->return_price();
                    break;
                case 3:
                    sofa++;
                    price_sofa+=s->return_price();
                    break;
                default:
                    cout<<"Error!!"<<endl;
            }
        }
        s=s->move_next();
    }
    string var;
    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl; 
    center_text("Payment");
    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl; 
    center_text("Seat type                     Amount    Price");
    cout<<endl;
    if(seat != 0){
        var = "Normal Seat                       "+to_string(seat)+"      "+to_string(price_seat);
        center_text(var);
    }
    if(delux != 0){
        var = "Delux Seat                        "+to_string(delux)+"      "+to_string(price_delux);
        center_text(var);
    }
    if(sofa != 0){
        var = "Sofa Seat                         "+to_string(sofa)+"      "+to_string(price_sofa);
        center_text(var);
    }
    cout<<endl;
    var = "Total                             "+to_string(seat+delux+sofa)+"      "+to_string(result);
    center_text(var);
    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl; 
    int money=0;
    do{
        cout<<"Enter amount of money : ";
        money = receive_input_int(0,50000,0);
    }while(result<=money && money!=0);
    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl; 
    if(money == 0){
        cancel_reservation(t->get_head_seat());
    }
    else if(money == price_seat+price_delux+price_sofa){
        center_text("Thank You");
    }
    else{
        var = "Change "+to_string(money-(price_seat+price_delux+price_sofa));
        center_text(var);
        center_text("Thank You");
    }
    cout<<"----------------------------------------------------------------------------------------------------------------"<<endl; 
    reservation(t->get_head_seat());
    system("PAUSE");
}


void show_promotion(){
}

//random fill seat for all theater
void random_fill_seat(theater* t,int theater_size){
    seat* s;
    int random;
    for(int i=1;i<=theater_size;i++){
        s=t->get_head_seat();
        for(int j=1;j<=60;j++){
            random = 1 + (rand() % 5);
            if(random == 1)
                s->change_stats();
            s=s->move_next();
        }
        t=t->move_next();
    }
}