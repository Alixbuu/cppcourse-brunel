#include <iostream>
#include "fichier_const.hpp"
#include <cmath>
#include <vector>
#include <random>
#ifndef Neuron_H
#define Neuron_H

using namespace std;

typedef vector<double> time_vector;
/*************************************************************
 * 			Definition of the class Neuron
 * 
 **************************************************************/
class Neuron {
/************************************************************
 * 			Private arguments of the  class
 * 
 *************************************************************/
	
	private:
	
	 double membrane_pot;//!< membrane potential of the neuron
	 time_vector timespike; //!< vector of the spike times of the neuron 
     int numberspike;//!< number of spike of the neuron /
     bool n_refractory = false;//!<state of the refraction of the neuron 
     int local_t;///< the local clock of the neuron 
     vector<double> buffer;//!< the ring buffer of the neuron 
     

/*************************************************************
 * 			Public arguments and methods of the class
 * 
 **************************************************************/
	  
	public :
	
	/** 
	 *Constructor of the Neuron
	 *@brief can initialise with given value or default value
	 */
	Neuron(double membranepotential=0.0, int numspike= 0,int local=0.0);
/****************************************************************
 * 						GETTERS
 * 
 ****************************************************************/
	/**
	 * @return [double] the membrane potential
	 */
	double getmembrane();
	
	/**
	 * @return the number of spike of the neuron
	 */
	int getnumspike();
	
	/**
	 * @return the time of the last spike
	 */
	int getspiketime();
	
	/************************************************************
	 * 					SETTERS
	 * 
	 *************************************************************/
	
	/**
	 *@brief set the membrane value with a given value
	 * @param [double] a membrane potential
	 */
	void setmembrane( double V);
	
	/************************************************************
	 * 			Methods Update and Updatetest
	 *
	 *************************************************************/
	
	/**
	 *@brief update the membrane potential and the state of neuron(refractory or not) on one timestep.
	 * check the value of the membrane potential for the threshold
	 * if spike the neuron become refractory
	 * look in the buffer for a spikevalue and after reset the case to 0
	 *  membrane potential calculation if not refractory
	 * @param an external current I
	 * @param a poisson distribution
	 * @return a [bool] to know if spike or not
	 */
	bool update(double I, double poisson);
	/**
	 * @brief same update but without the poisson distribution for the googletest.
	 * @param an external current
	 * @return a [bool] 
	 */
	bool updatetest(double I); 
	
	/***********************************************************
	 * 		   Methods Sendspike and Addinbuffer
	 * 
	 ************************************************************/
	
	/**
	 * @brief when the neuron spike he sends a spikevalue(J or Ji) to its connexions.
	 * call the addinbuffer method for the neuron spiked
	 * @param Neuron receiving the spike
	 * @param [double] spikevalue
	 * @param [int]  a time of the spike
	 */
	void sendspike( Neuron& b,double spikevalue, int time);
	
	/**
	 * @brief the neuron receving the spike add in the spike value in his buffer with a delay.
	 * 
	 * Add in the case [time+delay%buffer.size] the spike value.
	 * spikevalue can be negative or positive.
	 * @param [double] spikevalue
	 * @param [int] time of the neuron spiking
	 */
	void addinbuffer(double spikevalue, int time);
	
};
	
	
	
	
	
	
	
	
	
	
#endif	
