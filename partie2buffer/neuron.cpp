#include <iostream>
#include "neuron.hpp"
#include <cmath>
#include <vector>
using namespace std;

Neuron::Neuron (double membranepot,int numspike,double local)
:membrane_pot(membranepot),numberspike(numspike),local_t(local)
{
	buffer.resize(delay +1);
}



double Neuron::getmembrane()
{ 
	return membrane_pot;
}

void Neuron::setmembrane( double V)
 { 
	 membrane_pot=V;
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
	
	if (!timespike.empty() and (local_t - trefact) > (timespike.back()-1)) {
		n_refractory=false;
	}
	
	if(n_refractory) {
		membrane_pot=V_reset;
	} else {
		double Vtemp;
		Vtemp=c1*membrane_pot + I*c2 + buffer[(local_t)%(buffer.size())]*J;
		membrane_pot=Vtemp;
		buffer[local_t%buffer.size()]=0;
	 }
	++local_t;
}
	
bool Neuron::hasjustspike(double steps)
{
	if(timespike.empty()) {
		return false;
	}
	
	if(timespike.back()== (steps-1)) {
		return true;
		
		
	}
	return false;
}	 

void Neuron::sendspike(Neuron& b)
{ 
	if(hasjustspike(local_t)) { // local t ou global t?
	  
	   b.spikereceived +=1																																																																																																																																																																																																																						;
	   b.addinbuffer();
	}
  
}

void Neuron::addinbuffer()
{
	if(spikereceived!=0.0) {
		buffer[(local_t+delay)%buffer.size()]+=1; 
		spikereceived=spikereceived-1; // 
	}
	
}	 
		
	
		
			
			
			




	
