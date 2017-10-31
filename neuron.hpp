#include <iostream>
using namespace std;
#include "fichier_const.hpp"

#ifndef Neuron_H
#define Neuron_H
#include <cmath>
#include <vector>

typedef vector<double> time_vector;

class Neuron {
	private:
	 double membrane_pot;
	 time_vector timespike; // peut etre pas une bonne idee
	 int numberspike;
	 //double T=n*h;
	 bool n_refractory = false;
	 int local_t;
	 vector<int> buffer; // vector avec les incoming spike
	 
	  
	 
	 
	public : 
	Neuron(double membranepotential=0.0, int numspike= 0,double local=0.0);
	bool update(double I);
	bool updatetest(double I); 
	double getmembrane();
	int getnumspike();
	void setmembrane( double V);
	void sendspike( Neuron& b,double spikevalue);
	void addinbuffer(double spikevalue);
};
	
	
	
	
	
	
	
	
	
	
#endif	
