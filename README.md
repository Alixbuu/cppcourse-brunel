# projet_neuro

Spiking neuron network simulation

This program simulates a network of neurons which can send and receive spikes and visualize how neurons interact when sending electrical spikes On the basis of Brunel's article Dynamics of Sparsely Connected Networks of Excitatory and Inhibitory Spiking Neurons will simulate how neurons send spikes to the neurons to which they are connected (randomly) upon crossing a certain potential threshold, and plot the number of neurons spiking at a given step of time

The program consists of two classes , one constant file, one google test file, one main.cpp and four spike file for plotting the differents graphs. The classes are: Neuron: represent a neuron with a membrane potential updated each step of time Network: represent a network of neurons, initialized witha vector of neuron. connect the neuron together so they can send spike to each other The main: create network with a number of neurons, create the connexions between them and run the simulation for a certain time To excecute the program: ( be in the right subdirectory ) cmake .. make

./Neuron (will run the simulation an generate the file for plot C)

or ./Neuron_unittest (will execute the google test)

github: I did multiple branches because it seemed like a good idea but i didnt merge it with the master because it would create conflict So my number of commits are not only in the master branch my final project can be find on the master branch or the projetfinalwith plot branch
