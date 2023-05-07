#include <iostream>
#include <cstdlib>
#include <exception>
using namespace std;

class cin_fail:public exception{
public:
    const char* what() const throw(){
		cin.clear();
		cin.ignore(50,'\n');
        return "Error Incorrect type entered";
    }
} cin_fail;

class check_0:public exception{
public:
    const char* what() const throw(){
        return "Plase enter number in option";
    }
} outof_range;
