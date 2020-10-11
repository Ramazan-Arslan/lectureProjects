#Ramazan Arslan / 250201023
import numpy as np
import random
import matplotlib.pyplot as plt
import sympy as sym

f = open("titanic_data.txt", "r") #file/read operations
content = f.read()
content_list = content.splitlines() #puts each lines in the list
f.close()
firstclass = [] #required lists and variables are defined.Line(10-20)
secondclass = []
thirthclass = []
crewclass = []
rest = []
total1 = 0
crewsayı = 0
thirtsayı = 0
secondsayı = 0
firstsayı = 0
lines = len(content_list)
for i in range(1,lines):#puts the elements in the file in their own classes. Line(21-51)
    #counts alive and dead people.Line(21-51)
    a = content_list[i]
    a = a.split()
    if (a[0] == "0"):
        crewsayı += 1
        temp = int(a[1])
        if(temp == 1):
            total1 +=1
        crewclass.append(temp)
        rest.append(temp)
    elif (a[0] == "1"):
        firstsayı +=1
        temp = int(a[1])
        if (temp == 1):
            total1 += 1
        firstclass.append(temp)
    elif (a[0] == "2"):
        secondsayı+= 1
        temp = int(a[1])
        if (temp == 1):
            total1 += 1
        secondclass.append(temp)
        rest.append(temp)
    elif (a[0] == "3"):
        thirtsayı +=1
        temp = int(a[1])
        if (temp == 1):
            total1 += 1
        thirthclass.append(temp)
        rest.append(temp)

meanValueOfCrew = np.mean(crewclass) #calculate mean values the lists and prints it. 53-63
meanValueOfFirstClass = np.mean(firstclass)
meanValueOfSecondClass = np.mean(secondclass)
meanValueOfThirthClass = np.mean(thirthclass)
meanValueOfWholeData = total1/ (len(firstclass)+len(secondclass)+len(thirthclass)+len(crewclass))
print("Mean crew class : ", meanValueOfCrew )
print("Mean firt class : ", meanValueOfFirstClass)
print("Mean second class : ", meanValueOfSecondClass)
print("Mean thirth class : ",meanValueOfThirthClass)
print ("Whole data mean: ", meanValueOfWholeData)

aa = np.mean(crewclass)-np.mean(thirthclass)#mean difference for calculate p.(thirt-crew)
bb = np.mean(firstclass)-np.mean(rest)#mean difference for calculate p. (first-rest)
list1=[]
list2=[]
for i in range(10000):#To calculate the threshold of -0.01 and 0.35.
    ay = np.mean(random.choices(crewclass, k=375))
    by = np.mean(random.choices(thirthclass, k=375))
    cy = np.mean(random.choices(firstclass, k=375))
    dy = np.mean(random.choices(rest, k=375))
    list1.append(ay-by)
    list2.append(cy-dy)
varible = np.mean(list1)
varible2 = np.mean(list2)

means= []
means2 =[]
pforthirtcrew= []
pforfirstrest= []
for i in range(10000):
    a = np.mean(random.choices(crewclass,k=375)) #mean values ​​for 375 random elements Line(82-86)
    b = np.mean(random.choices(thirthclass,k=375))
    c = np.mean(random.choices(firstclass, k=375))
    d = np.mean(random.choices(rest, k=375))
    temp = a-b #mean differences thirth and crew
    temp2 = c-d #mean differences first and rest
    means.append(varible-temp)
    means2.append(varible2-temp2)

    if(aa+varible <= a-b <= aa-varible):# if the difference is less than 0.01,adds 1 to the list to calculate the rate.
        pforthirtcrew.append(1)
    else: # else adds 0.
        pforthirtcrew.append(0)
    if (bb +varible2 <= c - d <= bb -varible2):# if the difference is more than 0.35 ,adds 1 to the list to calculate the rate.
        pforfirstrest.append(1)
    else:#else adds 0.
        pforfirstrest.append(0)

totalnum = 0 #calculate ratio of 0.01 differences and less. Line(101-107).
ones = 0
for i in pforthirtcrew:
    if (i==1):
        ones+=1
    totalnum +=1
pvaluethirthcrew= ones/totalnum

totalnum = 0 #calculate ratio of 0.35 differences and more. Line(109-115).
ones = 0
for i in pforfirstrest:
    if (i==1):
        ones+=1
    totalnum +=1
pvaluefirsthrest= ones/totalnum

plt.figure() #Creates the graphics. Line(121-140).
plt.title("crew-thirt ")
plt.hist(means,150)
plt.show()

plt.figure()
plt.title("crew-thirt ")
plt.hist(means,125,cumulative = True,histtype = "step")
plt.axvline(varible, 0, pvaluethirthcrew, color='orange')
plt.show()
print("The p-value for" ,varible ,"difference and less between means for crew and 3rd class is  ", pvaluethirthcrew)

plt.figure()
plt.title("firsth-rest ")
plt.hist(means2,150)
plt.show()

plt.figure()
plt.hist(means2,125,cumulative = True,histtype = "step")
plt.show()
print("The p-value for" ,varible2 ,"difference and more in means for 1st class and the rest is ", pvaluefirsthrest)

def question4():
    Y = []
    Z = []
    Ys = []
    Zs = []
    Yss = []
    Zss = []
    c = 2
    a = -1
    b = 1.82
    a1 = -6
    b1 = 6
    for i in range(1000000):
        u = np.random.rand()
        v = np.random.rand()
        yu = (b - a)
        u + a
        zu = (b1 - a1)
        u + a1
        x = cv
        x1 = cv
        if (x <= y(yu)):
            Ys.append(yu)
            Yss.append(yu2)  # for 2nd moments
            if (yu < 0.3):
                Y.append(1)
            else:
                Y.append(0)
        if (x <= z(zu)):
            Zs.append(zu)
            Zss.append(zu2)
            if (zu < 0.3):
                Z.append(1)
            else:
                Z.append(0)




