#include <iostream>
#include <string>
#include <cmath>
#include <unistd.h>

using namespace std;

string ask(int aveNum){
    string answer;
    cout<<"Is it bigger or smaller than "<<aveNum<<" , or equal to "<<aveNum<<". (either up, down ,equal)"<<endl;
    cin>>answer;
    if(answer == "Up" || answer == "up"){
        return "up";
    }
    else if(answer == "Down" || answer == "down"){
        return "down";
    }
    else if(answer == "Equal" || answer == "equal"){
        return "equal";
    }
    else{
        return "wrong";
    }
}

int main(){

    int down, up, counter = 0;
    cout<<"Enter lower bound: "<<endl;
    cin>>down;
    cout<<"Enter upper bound: "<<endl;
    cin>>up;

    while(true){
        
        int average = floor((down + up)/2);
        counter += 1;
        string info = ask(average);
        if(info == "up"){
            down = average;
        }
        else if(info == "down"){
            up = average;
        }
        else if(info == "equal"){
            break;
        }
        else if(info == "wrong"){
            cout<<"Invalid input"<<endl;
            cout<<"Game will start again in 5 seconds. Be sure that you enter valid numbers."<<endl;
            sleep(5);
            system("clear"); // system("cls") for windows
            main();
        }
    }

    if(counter >= 10){
        cout<<"Finally, I found answer in "<<counter<<" tries."<<endl;
    }else{
        cout<<"Nice, I found answer in "<<counter<<" tries."<<endl;
    }
}