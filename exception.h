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

class check_range:public exception{
public:
    const char* what() const throw(){
        cin.clear();
		cin.ignore(50,'\n');
        return "Please enter number in range";
    }
} outof_range;

class check_char:public exception{
public:
    const char* what() const throw(){
        cin.clear();
		cin.ignore(50,'\n');
        return "Please enter alphabet A-G";
    }
} outof_alphabet;
