#include <iostream>
using namespace std;
#include <cmath>
#ifndef Constante_H
#define Constante_H

 double const h=0.1; // temps par step
 double const N=1; // nb de neuron
  double const Ne = ceil(N*0.8);// prend le seuil superieur si resultat à  virgules
  double const Ni = N-Ne;
  double const t_ = 20.00;      //tau
  double const V_thr = 20;  
  double const V_reset= 10; // reset potential
  double const trefact=2.00;
  double const c1 = exp(-h/t_);
  double const R=20.00;
  double const c2 = R*(1-exp(-h/t_));
  
  
  
  
 #endif
