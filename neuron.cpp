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
		Vtemp=c1*membrane_pot + I*c2 + spikereceived*5;
		membrane_pot=Vtemp;
		spikereceived=0;
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
	  
	   b.spikereceived +=1;
	   
  }
}

void addinbuffer()
{
	if(spikereceived!=0.0) {
		
	
		
			
			
			




	
