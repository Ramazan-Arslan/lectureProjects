# Ramazan Arslan - 250201023 - CENG461 HW2
from pgmpy.inference import VariableElimination
from pgmpy.models import BayesianModel
from pgmpy.factors.discrete import TabularCPD


model = BayesianModel([('A', 'B'), ('B', 'D'),('A', 'C'), ('C', 'D'),('C', 'E')]) #Bayesian network model

node_a = TabularCPD(variable='A', variable_card=2, values=[[0.2], [0.8]], #creates node a and their values
                                state_names={'A': ['True', 'False']},)

node_b = TabularCPD(variable='B', variable_card=2, #creates node b and their values
                   values=[[0.8, 0.2], 
                           [0.2, 0.8]],
                   evidence=['A'],
                   evidence_card=[2],
                         state_names={'B': ['True', 'False'],
                                   'A': ['True', 'False']}
                   )

node_c = TabularCPD(variable='C', variable_card=2, #creates node c and their values
                   values=[[0.2, 0.05], 
                           [0.8, 0.95]],
                   evidence=['A'],
                   evidence_card=[2],
                   state_names={'C': ['True', 'False'],
                                   'A': ['True', 'False']}
                   )

node_d = TabularCPD(variable='D', variable_card=2, #creates node d and their values
                   values=[[0.8, 0.8, 0.8, 0.05],
                   [0.2, 0.2,  0.2, 0.95]],
                  evidence=['B', 'C'],
                  evidence_card=[2, 2],
                  state_names={'D': ['True', 'False'],
                                   'B': ['True', 'False'],
                                    'C': ['True', 'False'],
                               }
                   )

node_e = TabularCPD(variable='E', variable_card=2,  #creates node e and their values
                  values=[[0.8, 0.6], 
                           [0.2, 0.4]],
                   evidence=['C'],
                   evidence_card=[2],
                  state_names={'E': ['True', 'False'],
                                  'C': ['True', 'False']})

model.add_cpds(node_a, node_b, node_c, node_d, node_e) #insert notes to the bayesian model.

model.check_model()

infer = VariableElimination(model)
probability_of_d = infer.query(['D']) #calculation of relevant probabilities
probability_of_d_a = infer.query(['D','A'])
probability_of_e_b = infer.query(['E'], evidence={'B': 'False'})
probability_of_a_d_e= infer.query(['A'], evidence={'D': 'True', 'E': 'False'})
probability_of_b_e_a= infer.query(['B','E'], evidence={'A': 'True'})

print(probability_of_d) #prints result of calculations
print(probability_of_d_a)
print(probability_of_e_b)
print(probability_of_a_d_e)
print(probability_of_b_e_a)

############
# Question2- Monte Carlo Technique
print("\n------------Question2------------\n")
import numpy
N = 10000
probabilityOfA = []
probabilityOfB = []
probabilityOfC = []
probabilityOfD = []
probabilityOfE = []
for i in range(N):
  A = numpy.random.rand() < 0.2 # A is true if less than 0.2.
  probabilityOfA.append(A)
  if A: # calculation of B and C according to A's value
    B = numpy.random.rand() < 0.8
    C = numpy.random.rand() < 0.2
  else:
    B = numpy.random.rand() < 0.2
    C = numpy.random.rand() < 0.05
  probabilityOfB.append(B)
  probabilityOfC.append(C)

  if B and C: #calculation of D and C according to B's and C's value
     D = numpy.random.rand() < 0.8
  elif B and (not C):
     D = numpy.random.rand() < 0.8
  elif (not B) and C:
     D = numpy.random.rand() < 0.8
  else:
     D = numpy.random.rand() < 0.05
  probabilityOfD.append(D)
    
  if C and (not B):
    E = numpy.random.rand() < 0.8
  else:
    E = numpy.random.rand() < 0.6
  probabilityOfE.append(E)

print("Probability of A" ,sum(probabilityOfA)/N)
print("Probability of B" ,sum(probabilityOfB)/N)
print("Probability of C" ,sum(probabilityOfC)/N)
print("Probability of D" ,sum(probabilityOfD)/N)
print("Probability of E" ,sum(probabilityOfE)/N)