#include <iostream>
using namespace std;
#include "neuron.hpp"
#include "network.hpp"
#include <vector>

 int main()
{ 
	
 Network network;
 cout << "network created" << endl;
 network.CreateConnexions();
 cout << "connexions between neurons made" << endl;
 cout<< " start of simulation"<< endl;
 network.startsimulation();
 cout << "end of simulation" << endl;
 return 0;
 }
 
		 
 
