#include <iostream>
using namespace std;
#include "neuron.hpp"
#include <fstream>


 int main()
{ 
 double t_start=20;
 double t_stop =990;
 double I_ext;//courant externe
 double I_input;
 double I_hi=0.0;
 double t_glo=0.0;
 double t_stopsimu =1000;
 cout << "entrer la valeur du courant: ";
 cin >>I_input;
 I_ext=I_input;
 Neuron ne;
 
 ofstream Membpotfile; // output files
 Membpotfile.open("./Membpotfile"); //open with a name
 Membpotfile<<"starting simulation.\n";
 
 
 while (t_glo < t_stopsimu) {  
	 if(t_glo >=t_start and t_glo < t_stop) { // si entre l intervalle de temps il y a du courant
		 ne.update(I_ext);
		 Membpotfile<<"le membrane potentiel est "<< ne.getmembrane();
		} else {                                 // pas de courant si pas entre start and stop
		  ne.update(I_hi);
		  Membpotfile <<"le membrane potentiel est "<< ne.getmembrane();
		}
		Membpotfile<<" At time "<<t_glo;
		Membpotfile <<" Nombre de spike "<< ne.getnumspike()<<endl;
 ++t_glo;
 }	
 Membpotfile.close();
 return 0;
 }
 
		 
 
