#include "neuron.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

#ifndef Network_H
#define Network_H

using namespace std;


/******************************************//**
 * Definition of the class Network
 * 
 *********************************************/

class Network {
	
	/********************************************
	 * 		Private Arguments of the Class
	 * 
	 ********************************************/
	
	private:
	
	//! table of all my neurons 
	vector <Neuron> TabNeuron;
	//! a table of vector of connexions of neurons
	vector <vector<int>> Connexions;
	
	/******************************************************
	 * 		Public Arguments and Methods of the class
	 * 
	 *******************************************************/
	public:
	/**
	 * Constructor of Network
	 * @brief initialize th number of neuron and create them.
	 * initialize the number of excitatory neurons and inhibitory neurons
	 */
	Network ();
	
	/**
	 *Destructor of Network
	 */
	~Network() {};
	
	
	const int Nb_excitatory; //! number of neurons excitatory
	const int Nb_Inhibitory; //! number of neurons inhibitory
	
	/***********************************************************
	 * Createconnexions and Startsimulation methods
	 * 
	 ************************************************************/
	/**
	 * Createconnexion
	 * @brief create connexions between neurons randomly using an uniform distribution.
	 * neuron connect with 0.1*Nb_excitatory.
	 * Neuron connect with 0.1*Nb_inhibitory
	 */
	void CreateConnexions ();
	
	/**
	 * Startsimulation
	 *@brief run the simulation for a certain number of steps.
	 * update all the table of neurons for a number of steps
	 * write in a file when a neuron spike and the time of the spike for an interval of time 
	 */
	void startsimulation();
	
};

#endif
	
	
	
