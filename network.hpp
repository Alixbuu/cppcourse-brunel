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
	
	/******************************************//**
	 * 		Private Arguments of the Class
	 * 
	 ********************************************//
	
	private:
	
	vector <Neuron> TabNeuron;//! table of all my neurons 
	vector <vector<int>> Connexions;//! a table of vector of connexions of neurons
	
	/****************************************************//**
	 * 		Public Arguments and Methods of the class
	 * 
	 *******************************************************/
	public:
	/**
	 * Constructor of Network
	 */
	Network ();
	
	/**
	 *Destructor of Network
	 */
	~Network() {};
	
	
	const int Nb_excitatory; //! number of neurons excitatory
	const int Nb_Inhibitory; //! number of neurons inhibitory
	
	/*********************************************************//**
	 * Createconnexions and Startsimulation methods
	 * 
	 ************************************************************/
	/**
	 * Createconnexiosn
	 * @brief create connexions between neurons randomly using an uniform distribution
	 */
	void CreateConnexions ();
	
	/**
	 * Startsimulation
	 *@brief run the simulation for a certain number of steps
	 * update all the table of neurons for a number of steps
	 * write in a file when a neuron spike and the time of the spike
	 */
	void startsimulation();
	
};

#endif
	
	
	
