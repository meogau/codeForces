#include <iostream> 
#include <string>

using namespace std;

int main(void) 
{
    string ToDo = "I'll think about that in one hour"; 
    string Schedule = "today yesterday tomorrow";
    
    ToDo.replace(0, ToDo.length(), Schedule, 0, Schedule.length());
    cout << ToDo << endl;
    return 0;
}
