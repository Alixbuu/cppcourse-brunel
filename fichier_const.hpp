#include <iostream>
#include <cmath>
using namespace std;
#ifndef Constante_H
#define Constante_H

/*****************************************
 * CONSTANTS
 * 
 ******************************************/
  double const h=0.1;//! time per step
  int const Nbneuron=12500; //! number total of neuron
  int const Ne = ceil(Nbneuron*0.8);//! number of excitatory neurons
  int const Ni = Nbneuron-Ne;//!number of inhibitory neurons
  double const t_ = 20.00;//! Tau
  double const V_thr = 20;//! V threshold  
  double const V_reset= 0.0;//! potential reset
  int const trefact=20;//! time of the refracoty period(step)
  double const c1 = exp(-h/t_);//! constante of membrane potential
  double const R=20.00;//! Resistance
  double const c2 = R*(1-exp(-h/t_));//! constante 2 for the euqation of membrane potential
  int const delay= 15;//! delay for the buffer
  double const J=0.1;//! amplitude for excitatory neurons
  double const Ji=-0.6;//! amplitude for inhibitory neurons
  double const Iext=0.0;//! external current
  double const Teta = 20;//! Teta for poisson law
  double const eta = 2;//! Eta for poisson law
  
  
  int const t_stopsimu =5000;//! time of simulation
/***********************************************
    * Poisson Law
    * 
*************************************************/
  double const Nuthr = (Teta/(0.1*0.8*Nbneuron*J*t_));
  double const Nuext =  (eta*0.1*0.8*Nbneuron*Nuthr);
  double const lambda = (4/*Nuext*h*/);
  
  
 #endif
