#include <iostream>
#include "Network.hpp"



 Network::Network()
 :
 Nb_excitatory(Ne),
 Nb_Inhibitory(Nbneuron-Ne)
{
	for( int i(0); i<Nbneuron;++i)
	{
		TabNeuron.push_back(Neuron());
	}
}

void Network::CreateConnexions()
{
	for( int i(0); i<Nbneuron; ++i)
	{
		vector<int> page;
		Connexions.push_back(page);
	}
	
	static random_device rd;
			static mt19937 gen(rd());
			static uniform_int_distribution<> connexion_with(0,Nb_excitatory-1);
			static uniform_int_distribution<> connexions_with(Nb_excitatory,Nbneuron);
			
	for(int i(0); i<Nbneuron;++i)
	{
		for( int j(0); j<0.1*Nb_excitatory; ++j)
		{
			
			
			Connexions[connexion_with(gen)].push_back(i);
		}
		
		for(int n(0); n< 0.1*Nb_Inhibitory; ++n)
		{
		
			
			
			Connexions[connexions_with(gen)].push_back(i);
		
		}
	}
}
		
void Network::startsimulation()
{
	int t_global(0);
	ofstream Membpotfile; // output files
	Membpotfile.open("./Membpotfile"); //open with a name
	
	static random_device rd;
	static mt19937 gen(rd());
	static poisson_distribution<> backgroundnoise(lambda);
 
	while(t_global<t_stopsimu) {
		
		for( size_t i(0); i<TabNeuron.size(); ++i)
		{
			if(TabNeuron[i].update(Iext, backgroundnoise(gen)))
			{  if(t_global>3000){
				Membpotfile<<t_global<<'\t'<<i+1<<'\n';
			}
				for( size_t j(0); j<Connexions[i].size(); ++j)
				{
					int connect=Connexions[i][j];
					
					if( i<Nb_excitatory-1)
					{
						TabNeuron[i].sendspike(TabNeuron[connect],J,t_global);	
					}else{
						TabNeuron[i].sendspike(TabNeuron[connect],Ji,t_global);	
					}
				}	
			}	
		}
		++t_global;
	}
	 Membpotfile.close();
}	
			
