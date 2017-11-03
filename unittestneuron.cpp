#include <iostream>
#include "neuron.hpp"
#include "gtest/gtest.h"
#include <cmath>

TEST (NeuronTest,positiveimput) // test membane potential for different input
{ 
	Neuron neuron1;
    double I= 1.00;
	// premier test
	neuron1.updatetest(I);
	EXPECT_EQ(20.0*(1.0-std::exp(-0.1/20.0)), neuron1.getmembrane());
	neuron1.setmembrane(0.0);
  
	//test after many updates
	for (int i(0); i<100000; ++i)
	{ neuron1.updatetest(I);
	}
	// membrane potential should tend to 20 but never reach it
	// should never spike
	EXPECT_EQ(0, neuron1.getnumspike());
	EXPECT_GT(1E-3, std::fabs(19.999-neuron1.getmembrane()));
	neuron1.setmembrane(0.0);
	 
    // membrane potential should tend towards 0 with i=0.0
 
    I=0.0;
    for( int i(0); i<2000;++i)
    {
	  neuron1.updatetest(I);
    }
    EXPECT_NEAR(0,neuron1.getmembrane(),1e-3);
    neuron1.setmembrane(0.0);
}

TEST (neurontest, Negativeimput) 
{
	Neuron neuron2;
	double I=-1.00;
	// first update test
	neuron2.updatetest(I);
	EXPECT_EQ(-20.0*(1.0-std::exp(-0.1/20.0)), neuron2.getmembrane());
	neuron2.setmembrane(0.0);
	// test after many update
	for(int i(0);i<100000; ++i)
	{
		neuron2.updatetest(I);
	}
	// the membrane potential should tend to -20
	EXPECT_GT(1E-3, std::fabs(-19.999 -neuron2.getmembrane()));
	neuron2.setmembrane(0.0);
	
	// membrane potential should tend towards 0 with i=0.0
  
    I=0.0;
    for( int i(0); i<2000;++i)
    {
	  neuron2.updatetest(I);
    }
    EXPECT_NEAR(0,neuron2.getmembrane(),1e-3);
    neuron2.setmembrane(0.0);
}
    
TEST (NeuronTest, SpikeTimes)
{
	Neuron neuron3;
	double I=1.01;
	// we know that the spike times are at 92.4ms, 186.8ms, 281.2ms and 375.6ms
	// we are waiting for the first spike
	// also check that the value  og te otential membrane go back to 0.0 after a spike
	for(int i(0); i<924;++i)
	{
	  neuron3.updatetest(I);
    }
    EXPECT_EQ(0,neuron3.getnumspike());
    neuron3.updatetest(I);
    EXPECT_EQ(1, neuron3.getnumspike());
    EXPECT_EQ(0.0,neuron3.getmembrane());
    //waiting for the second spike
    for(int i(0); i<943; ++i)
    {
		neuron3.updatetest(I);
	}
	EXPECT_EQ(1,neuron3.getnumspike());
    neuron3.updatetest(I);
    EXPECT_EQ(2, neuron3.getnumspike());
    
    
}
    
TEST (NeuronTest, StandaloneSimulation) // checking the number of occuring spike
{
	Neuron neuron;
	double I=1.01;
	// we know that the spike times are at 92.4ms, 186.8ms 201.2ms and 375.6ms
	// we are waiting for 4 spike
	for( int i(0); i<4000; ++i)
	{
		neuron.updatetest(I);
	}
	EXPECT_EQ(4, neuron.getnumspike());
}

TEST (TwoNeuronTest, NOspike2)
{
	Neuron neuron1;
	Neuron neuron2;
	int delay=15;
	double I=1.01;
	// we wait for the first spike and observe the impact on the second neuron
	for( int i(0); i<925+delay; ++i)
	{
		if(neuron1.updatetest(I))
		{
		neuron1.sendspike(neuron2,1,i);
	}
		neuron2.updatetest(0.0);
	}
	EXPECT_EQ(0.1,neuron2.getmembrane());
}

TEST (TwoNeuronTest,withspike2)
{
	Neuron neuron1;
	Neuron neuron2;
	int delay=15;
	double I=1.01;
	double I2=1.0;
	// we wait for the second spike and observe the impact on the second neuron --> neuron 2 should spike spiker
	for( int i(0); i<1870+delay; ++i) // neuron 2 have to receive 2 spike from neuron 1 to pass the threshold , 1868+2 step because sendspike is called after the incrementation of time in update
	{
		if(neuron1.updatetest(I))
		{
		neuron1.sendspike(neuron2,1,i);
	}
		neuron2.updatetest(I2);
	}
	EXPECT_EQ(1,neuron2.getnumspike());
}


int main(int argc, char **argv)	{
	:: testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	
}
	
	
		
	

	
  

