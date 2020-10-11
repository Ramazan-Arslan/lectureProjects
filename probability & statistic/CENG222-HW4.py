#Ramazan Arslan / 250201023
import numpy as np
import random
import matplotlib.pyplot as plt
from scipy import stats
from scipy.stats import semicircular

def experiments(n):
    listt = []
    for i in range(100000):
        items = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

        x = sample(items, 1)  # Pick a random item from the list
        print(x[0])

    if(n == 2):
        plt.figure() #I printed the produced numbers before the first experiment.(1-2-3)
        plt.title("Histrogram for generated random variables")
        plt.hist(listt,100,density=True)
        plt.show()
    plt.figure()
    plt.title("Histrogram for sums of generated random variables")
    samples= []
    for i in range(100000):
        value2 = np.sum(random.choices(listt,k = n)) #I picked 'n' numbers, then I add them.
        samples.append(value2)
    mu = np.mean(samples) #I calculated the mean of the list.
    sigma = np.std(samples) #I calculated the standard deviaton of the list
    print("Mean: " ,mu)
    print("Standart Deviation: ",sigma)
    print()
    plt.hist(samples,100,density=True)
    x = np.linspace(mu -3*sigma,mu+3*sigma,1000) # mu +3*sigma and mu-3*sigma covers 99.7% of the entire distribution
    plt.plot(x,stats.norm.pdf(x,mu,sigma)) #I drew the curve
    plt.show()

print("Experiment1")
experiments(2)
print("Experiment2")
experiments(10)
print("Experiment3")
experiments(50)




listt3 = []
samples3 = []
for i in range(10000):
    sumlist = []
    for j in range (100):
        if(sum(sumlist)>40): #The range of random numbers varies depending on whether the total(sumlist) is greater than 40.
            value = np.random.uniform(-0.5,0.5) #I'm producing random numbers between -0,5 and 0,5.
            listt3.append(value)
            sumlist.append(value)
        else:
            value = np.random.uniform(0.5,1.5) #I'm producing random numbers between 0,5 and 1,5.
            listt3.append(value)
            sumlist.append(value)
    samples3.append(sum(sumlist)) #Elements of 'sumlist' are collected and they are appended to 'samples3'.

plt.figure() #I printed the produced numbers for the fourth experiment.
plt.title("histogram for generated random variables")
plt.hist(listt3,100,density=True)
plt.show()
plt.figure()
mu = np.mean(samples3) #I calculated the mean of the list.
sigma = np.std(samples3) #I calculated the standard deviaton of the list
print("Experiment4")
print("Mean" ,mu)
print("Standart Deviation",sigma)
print()
plt.title("Histrogram for sums of generated random variables")
plt.hist(samples3,100,density=True)
x = np.linspace(mu -3*sigma,mu+3*sigma,1000) # mu +3*sigma and mu-3*sigma covers 99.7% of the entire distribution
plt.plot(x,stats.norm.pdf(x,mu,sigma))  #I drew the curve
plt.show()



def experimentscircular(n):
    listt2 = []
    for i in range(100000):
        value = semicircular.rvs(2,1) #I'm producing random numbers in semicircle.
        listt2.append(value)
    if(n == 2): # I printed the produced numbers before the fifth experiment.(5-6-7)
        plt.figure()
        plt.title("Histrogram for generated random variables")
        plt.hist(listt2,100,density=True)
        plt.show()
    plt.figure()
    plt.title("Histrogram for sums of generated random variables")
    samples2 = []
    for i in range(100000):
        value2 = np.sum(random.choices(listt2,k = n)) #I picked 'n' numbers, then I addd them.
        samples2.append(value2)
    mu = np.mean(samples2) #I calculated the mean of the list.
    sigma = np.std(samples2) #I calculated the standard deviaton of the list
    print("Mean: " ,mu)
    print("Standart Deviation: ",sigma)
    print()
    plt.hist(samples2,100,density=True)
    x = np.linspace(mu -3*sigma,mu+3*sigma,1000) # mu +3*sigma and mu-3*sigma covers 99.7% of the entire distribution
    plt.plot(x,stats.norm.pdf(x,mu,sigma))  #I drew the curve
    plt.show()

print("Experiment5")
experimentscircular(2)
print("Experiment6")
experimentscircular(10)
print("Experiment7")
experimentscircular(50)