#Ramazan Arslan / 250201023
import numpy as np
import random
import matplotlib.pyplot as plt
from scipy import stats
from scipy.stats import binom
import math


def function(N): # binomial distribution
    samples = []
    sigmacount = 0
    Xcount = 0
    p = 0.3
    count = 0
    for i in range(N):  # generate 'N' samples
        for i in range(40):  # generates sample for n= 40 trials
            prob = np.random.rand()
            if ( prob < p):
                count += 1
        problatiyOfSample = count
        count = 0
        samples.append(problatiyOfSample)  #appends the samples to list.
        Xcount += problatiyOfSample  # calculates x' , so mean value ,(x' = n samples / n),  24-25
    Xcount = Xcount / N

    for i in range(N):
        sigmacount += ((samples[i] - Xcount) ** 2)  # (sample-mean)**2 / N for standart deviation 28-29
    sigmacount = sigmacount / N
    Phead = 1 - (sigmacount / Xcount)  # calculates p'  ,  p' = 1-(standard deviation/ mean)
    nhead = Xcount / Phead  # calculates n'  , n' = mean/p'

    return Phead,nhead


pheadlist200 = [] #creates the lists 36-42
nheadlist200 = []
pheadlist800 = []
nheadlist800 = []
pheadlist3200 = []
nheadlist3200 = []
for i in range(1000): #I simulated distributions 1000 times.
    Phead200, nhead200 = function(200)
    nheadlist200.append(nhead200)
    pheadlist200.append(Phead200)

    Phead800, nhead800 = function(800)
    nheadlist800.append(nhead800)
    pheadlist800.append(Phead800)

    Phead3200,nhead3200 =function(3200)
    nheadlist3200.append(nhead3200)
    pheadlist3200.append(Phead3200)

#calculates mean and standard deviations of distributions. 56-71

muofp200 = np.mean(pheadlist200)
sigmaofp200 = np.std(pheadlist200)
muofn200 = np.mean(nheadlist200)
sigmaofn200 = np.std(nheadlist200)

muofp800 = np.mean(pheadlist800)
sigmaofp800 = np.std(pheadlist800)
muofn800 = np.mean(nheadlist800)
sigmaofn800 = np.std(nheadlist800)

muofp3200 = np.mean(pheadlist3200)
sigmaofp3200 = np.std(pheadlist3200)
muofn3200 = np.mean(nheadlist3200)
sigmaofn3200 = np.std(nheadlist3200)

#prints the necessary calculations 72-87

print("Mean of Estimated p for sample size of 200 is: ", muofp200)
print("Standart Deviation for estimated p for sample size 200 is : ", sigmaofp200)
print("Mean of Estimated n for sample size of 200 is: ", muofn200)
print("Standart Deviation for estimated n for sample size 200 is : ", sigmaofn200)
print("")
print("Mean of Estimated p for sample size of 800 is: ", muofp800)
print("Standart Deviation for estimated p for sample size 800 is : ", sigmaofp800)
print("Mean of Estimated n for sample size of 800 is: ", muofn800)
print("Standart Deviation for estimated n for sample size 800 is : ", sigmaofn800)
print("")
print("Mean of Estimated p for sample size of 3200 is: ", muofp3200)
print("Standart Deviation for estimated p for sample size 3200 is : ", sigmaofp3200)
print("Mean of Estimated n for sample size of 3200 is: ", muofn3200)
print("Standart Deviation for estimated n for sample size 3200 is : ", sigmaofn3200)

#creates histograms 90-102
plt.figure()
plt.hist(pheadlist200,100,density=True,alpha=0.5,color = "skyblue",label = "200")
plt.hist(pheadlist800,100,density=True,alpha=0.5,color = "orange",label = "800")
plt.hist(pheadlist3200,100,density=True,alpha=0.5,color = "green",label = "3200")
plt.title("Histogram for estimated p")
plt.legend()
plt.show()

plt.figure()
plt.hist(nheadlist200,100,density=True,alpha=0.5,color = "skyblue",label = "200")
plt.hist(nheadlist800,100,density=True,alpha=0.5,color = "orange",label = "800")
plt.hist(nheadlist3200,100,density=True,alpha=0.5,color = "green",label = "3200")
plt.title("Histogram for estimated n")
plt.legend()
plt.show()