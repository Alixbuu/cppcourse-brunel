#include <iostream>
#include "neuron.hpp"
#include <cmath>
#include <vector>
using namespace std;

Neuron::Neuron (double membranepot,int numspike,double local)
:membrane_pot(membranepot),numberspike(numspike),local_t(local)
{}



double Neuron::getmembrane()
{ 
	return membrane_pot;
}

int Neuron::getnumspike()
{ 
	return numberspike;
}

void Neuron::update(double I )
{
	if(membrane_pot > V_thr) { 
		timespike.push_back(local_t);
		n_refractory=true;
		++numberspike;	
	}
	
	if (!timespike.empty() and local_t - trefact > timespike.back()) {
		n_refractory=false;
	}
	
	if(n_refractory) {
		membrane_pot=V_reset;
	} else {
		double Vtemp;
		Vtemp=c1*membrane_pot + I*c2;
		membrane_pot=Vtemp;
	 }
	++local_t;
}
		 
			
			
			




	
