#include <iostream>
#include "neuron.hpp"
#include <cmath>
#include <vector>

using namespace std;

Neuron::Neuron (double membranepot,int numspike,int local)
 :membrane_pot(membranepot),
  numberspike(numspike),
  local_t(local)
{
	buffer.resize(delay +1); //resize my buffer at the right size :16
}



double Neuron::getmembrane() //return the membrane potential
{ 
	return membrane_pot;
}

void Neuron::setmembrane( double V) // set the membrane potential
 { 
	 membrane_pot=V;
 }
	 

int Neuron::getnumspike() // return the number of the spike of the neuron
{ 
	return numberspike;
}

bool Neuron::update(double I, double poisson )
{   
	bool spike=false;    // will be return a the end
	double Jbuffer=0.0; // for the buffer value
	
	if(membrane_pot > V_thr) {           //check if the membrane potential passed the threshold
		timespike.push_back(local_t); // put the time of the spike in the vector
		n_refractory=true;
		++numberspike;
		spike=true;	
	}
	
	if (!timespike.empty() and (local_t - trefact) > (timespike.back()-1)) {   //check the number of refractory steps
		n_refractory=false;
	}
	if((buffer[(local_t)%(buffer.size())]>0) or (buffer[(local_t)%(buffer.size())]<0)) //check if a spikevalue in the right case of the buffer
	{
		Jbuffer=buffer[(local_t)%(buffer.size())]; 
		buffer[local_t%buffer.size()]=0; // reset the buffer case used to 0.0
	}
	
	if(n_refractory) {
		membrane_pot=V_reset; // reset  the membrane potential to 0.0 when refractory
	} else {
		double Vtemp;
		Vtemp=c1*membrane_pot + I*c2 + Jbuffer + poisson*J; //calculate the evolution of membrane potential
		membrane_pot=Vtemp;
		
	 }
 // there is a possibility that the membrane potential goes under 0 bc of the jI received and the value of the potential a this time
	 if(membrane_pot < 0.0) 
	 {
		 membrane_pot = V_reset; // reset at 0 if lower than it
	 }
	++local_t;
	return spike;  // return if the neuron spiked or not
}




// update for my gtest-> without the poisson law

bool Neuron::updatetest(double I )
{  
	bool spike=false;
	double Jbuffer=0.0;
	
	if(membrane_pot > V_thr) { 
		timespike.push_back(local_t);
		n_refractory=true;
		++numberspike;
		spike=true;	
	}
	
	if (!timespike.empty() and (local_t - trefact) > (timespike.back()-1)) {
		n_refractory=false;
	}
	if((buffer[(local_t)%(buffer.size())]>0) or (buffer[(local_t)%(buffer.size())]<0)) 
	{
		Jbuffer=buffer[(local_t)%(buffer.size())]; 
		buffer[local_t%buffer.size()]=0;
	}
	
	if(n_refractory) {
		membrane_pot=V_reset;
	} else {
		double Vtemp;
		Vtemp=c1*membrane_pot + I*c2 + Jbuffer*J;
		membrane_pot=Vtemp;
		
	 }
	++local_t;
	return spike;
}


// if the neuron spike he sendspike with a spike value and the time of the spike
void Neuron::sendspike(Neuron& b,double spikevalue,int time)
{ 																																																																																																																																																																																																																			;
	b.addinbuffer(spikevalue,time); // call the method of addinbuffer for  the neuron spiked
}



// add the spikevalue receive in a case of the vector buffer taking into account the delay
void Neuron::addinbuffer(double spikevalue, int time)
{
	buffer[(time+delay)%buffer.size()]+=spikevalue; 
}	 
		
int Neuron::getspiketime() // return the last spike time
{
	return timespike.back();
}
		
			
			
			




	
