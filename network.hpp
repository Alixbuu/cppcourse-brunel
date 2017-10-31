#include "neuron.hpp"
#include <iostream>
using namespace std;
#ifndef Network_H
#define Network_H
#include <cmath>
#include <vector>
#include <fstream>




class Network {
	
	private:
	vector <Neuron> TabNeuron;
	vector <vector<int>> Connexions;
	
	public:
	Network (); // constructeur
	~Network() {}; // tilda a rajouté
	
	const int Nb_excitatory;
	const int Nb_Inhibitory;
	
	void CreateConnexions ();
	
	void startsimulation();
	
};

#endif
	
	
	
