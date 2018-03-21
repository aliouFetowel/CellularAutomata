#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string parse = "$
      ....x.....
      ..x..x....
      ...x...x..
      ........x.
      x.....x...
      ..x...x...
      ..........
      ...x......
      .....x....
      ...x....x.
      $</baseQueueName>";
    stringstream ss(parse);
    string temp = "";

    cout << "current position " << ss.tellg() << endl;
    getline(ss, temp, '$');
    cout << "current position " << ss.tellg() << endl;
    getline(ss, temp, '$');
       
  
    cout << "temp: " << temp << endl;

    cin.ignore();
    return 0;
}