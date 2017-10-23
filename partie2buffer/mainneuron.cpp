#include <iostream>
using namespace std;
#include "neuron.hpp"
#include <fstream>
#include <vector>

 int main()
{ 
 double t_start=20;
 double t_stop =990;
 double I_ext;//courant externe
 double I_input;
 double I_hi=0.0;
 int    t_glo=0;
 double t_stopsimu =1000;
 cout << "entrer la valeur du courant: ";
 cin >>I_input;
 I_ext=I_input;
 Neuron ne;
 Neuron bb;
 vector <Neuron> neurone;
 neurone.push_back(ne);
 neurone.push_back(bb);
 
 
 ofstream Membpotfile; // output files
 Membpotfile.open("./Membpotfile"); //open with a name
 Membpotfile<<"starting simulation.\n";
 
 
 while (t_glo < t_stopsimu) {  
	 if(t_glo >=t_start and t_glo < t_stop) { // si entre l intervalle de temps il y a du courant
		 //ne.update(I_ext);
		 for(size_t i(0); i<neurone.size();++i)
		 { if(i==0) {
			 neurone[i].update(I_ext);
		   }else {
			 neurone[i].update(I_hi);
		   }
		   Membpotfile<<" le potentiel est " << neurone[i].getmembrane()<<" au temps "<< (t_glo+1)*h<<'\t';
	     }
		Membpotfile << endl;
		
		} else {                                 // pas de courant si pas entre start and stop
		   for(size_t i(0); i< neurone.size(); ++ i)
		   { neurone[i].update(I_hi);
			Membpotfile<<" le potentiel est " << neurone[i].getmembrane()<<" au temps "<< (t_glo+1)*h<<'\t';
		   }
		  Membpotfile << endl;
		  }
		  
 neurone[0].sendspike(neurone[1]); // fais un tableau de deux neurones
		  
		
 ++t_glo;
 }	
 Membpotfile.close();
 return 0;
 }
 
		 
 
