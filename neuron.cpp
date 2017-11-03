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

bool Neuron::update(double I )
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
	if(buffer[(local_t)%(buffer.size())]>0)
	{
		Jbuffer=buffer[(local_t)%(buffer.size())];
		buffer[local_t%buffer.size()]=0;
	}
	
	if(n_refractory) {
		membrane_pot=V_reset;
	} else {
		double Vtemp;
		
		static random_device rd;
		static mt19937 gen(rd());
		static poisson_distribution<> backgroundnoise(lambda);
		
		Vtemp=c1*membrane_pot + I*c2 + Jbuffer + backgroundnoise(gen)*J;
		membrane_pot=Vtemp;
		
	 }
	++local_t;
	return spike;
}






bool Neuron::updatetest(double I )
{  bool spike=false;
	if(membrane_pot > V_thr) { 
		timespike.push_back(local_t);
		n_refractory=true;
		++numberspike;
		spike=true;	
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
	return spike;
}



void Neuron::sendspike(Neuron& b,double spikevalue,int time)
{ 																																																																																																																																																																																																																			;
	b.addinbuffer(spikevalue,time);
}




void Neuron::addinbuffer(double spikevalue, int time)
{
	buffer[(time+delay)%buffer.size()]+=spikevalue; 
}	 
		
int Neuron::getspiketime()
{
	return timespike.back();
}
		
			
			
			




	
