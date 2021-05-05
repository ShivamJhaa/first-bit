#include <iostream>
using namespace std;

int main()
{
    int ftemp;
    cout <<"Enter the temperature in fareneight:\n";
    cin >> ftemp;
    int ctemp=(ftemp-32)*5/9;
    cout << "Temperature in celcius:"<<ctemp<<'\n';
    return 0;

}