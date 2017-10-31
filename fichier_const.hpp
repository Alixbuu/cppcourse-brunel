#include <iostream>
using namespace std;
#include <cmath>
#ifndef Constante_H
#define Constante_H

  double const h=0.1; // temps par step
  int const Nbneuron=12500; // nb de neuron
  int const Ne = ceil(Nbneuron*0.8);// prend le seuil superieur si resultat à  virgules
  int const Ni = Nbneuron-Ne;
  double const t_ = 20.00;      //tau
  double const V_thr = 20;  
  double const V_reset= 0.0; // reset potential
  int const trefact=20;
  double const c1 = exp(-h/t_);
  double const R=20.00;
  double const c2 = R*(1-exp(-h/t_));
  int const delay= 15;
  double const J=0.1;
  double const Ji=-0.5;
  double const Iext=0.0;
  double const Teta = 20;
  double const eta = 2;
  
  
  int const t_stopsimu =5000;
   // poisson law
  double const Nuthr = (Teta/(0.1*0.8*Nbneuron*J*t_));
  double const Nuext =  (eta*0.1*0.8*Nbneuron*Nuthr);
  double const lambda = (Nuext*h);
  
  
 #endif
