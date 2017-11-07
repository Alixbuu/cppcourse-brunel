#include <iostream>
#include "Network.hpp"



 Network::Network()
 :
 Nb_excitatory(Ne),
 Nb_Inhibitory(Nbneuron-Ne)
{
	for( int i(0); i<Nbneuron;++i) // create my vector of neurons and call the constructor of neuron
	{
		TabNeuron.push_back(Neuron());
	}
}


void Network::CreateConnexions() 
{
	for( int i(0); i<Nbneuron; ++i)
	{
		vector<int> page;             // add a  empty vector of connexion for the number of neuron to the table Connexions
		Connexions.push_back(page);
	}
	
	static random_device rd;
			static mt19937 gen(rd());
			static uniform_int_distribution<> connexion_with(0,Nb_excitatory-1);  //uniform distribution for excitatory neurons
			static uniform_int_distribution<> connexions_with(Nb_excitatory,Nbneuron); // uniform distribution for inhibitory neurons
			
	for(int i(0); i<Nbneuron;++i)
	{
		for( int j(0); j<0.1*Nb_excitatory; ++j) //10% of excitatory neurons will have  neuron i in their connexion vector
		{
			
			
			Connexions[connexion_with(gen)].push_back(i);
		}
		
		for(int n(0); n< 0.1*Nb_Inhibitory; ++n)  // 10% of inhibitory neurons will have neuron i in their connexion vector
		{
		
			
			
			Connexions[connexions_with(gen)].push_back(i);
		
		}
	}
}


		
void Network::startsimulation()
{
	int t_global(0);
	ofstream spikeC; // output files
	spikeC.open("./spikeC"); //open with a name
	
	static random_device rd;
	static mt19937 gen(rd());
	static poisson_distribution<> backgroundnoise(lambda); // poisson distribution for the background noise
 
	while(t_global<t_stopsimu) {
		
		for( size_t i(0); i<TabNeuron.size(); ++i)
		{
			if(TabNeuron[i].update(Iext, backgroundnoise(gen))) //update all the neuron 
			{  if(t_global>3000)                                   // write in the file only from the 3000 steps so the neurons have time to desynchronize themsleve-> plot better
				{
				spikeC<<t_global<<'\t'<<i+1<<'\n';
			    }
				for( size_t j(0); j<Connexions[i].size(); ++j)
				{
					int connect=Connexions[i][j]; //the indice in the TabNeuron of the neuron to connect
					
					if( i<Nb_excitatory-1)
					{
						TabNeuron[i].sendspike(TabNeuron[connect],J,t_global);	// if the neuron is excitatory send a positive spike to its connexions 
					}else{
						TabNeuron[i].sendspike(TabNeuron[connect],Ji,t_global);	//if the neuron is inhbithory send a positive spike to its connexions
					}
				}	
			}	
		}
		++t_global;
	}
	 spikeC.close();
}	
			
