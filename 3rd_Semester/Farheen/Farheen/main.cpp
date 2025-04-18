//
//  main.cpp
//  Farheen
//
//  Created by Ahmad Gill on 12/7/22.
//

#include <iostream>
using namespace std;
class machine
{
public:
   virtual void run(){
       cout<<"dfjdfjd";
   }
 class parts
    {
        
    };
    
};
class car: public machine
{
public:
    void run()
    {
        cout<<"The car is running"<<endl;
    }
    class parts
    {
        int getWheel()
        {
            cout<<"A car has four wheels\n";
            return 4;
        }
        string getFuel()
        {
            cout<<"A car use gasoline\n";
            return "gasoline";
        }
    };
};

int main() {
    car c;
    c.run();
    return 0;
}
