import random
#Ramazan Arslan / 250201023
wincount = 0
losecount = 0

listeplus = []
listeminus = []
totalwingain = 0
totallossgain = 0


def game(bet): #In this function ,I designed the craps game with the given rules.

    dice1 = random.randint(1, 6)
    dice2 = random.randint(1, 6)
    totalnum = dice1 + dice2


    if (totalnum == 7 or totalnum == 11):
        listeplus.append(bet*8/36) #(bet * dice)   to calculate the expected value.

        return True

    elif (totalnum == 2 or totalnum == 3 or totalnum == 12):
        listeminus.append(-bet * 4/ 36) #(bet * dice)   to calculate the expected value.

        return False

    else:
        while(True):
            dice3 = random.randint(1, 6)
            dice4 = random.randint(1, 6)
            totalnum2 = dice3+dice4
            if(totalnum2 ==7):
                listeminus.append(-bet*6/36) #(bet * dice)   to calculate the expected value.

                return False
            elif(totalnum2 == totalnum):
                if(totalnum == 4 or totalnum == 10):
                    listeplus.append(bet* 3/36) #(bet * dice)   to calculate the expected value.
                elif (totalnum == 5 or totalnum == 9):
                    listeplus.append(bet * 4 / 36) #(bet * dice)   to calculate the expected value.
                if (totalnum == 6 or totalnum == 8):
                    listeplus.append(bet * 5 / 36)#(bet * dice)   to calculate the expected value.

                return True
            else:
                continue




Money=1000
print("Gambler A1 İnitial Money: ", Money)
bet = 1

while(True):# In this loop, I made money and bet updates for gambler A.

    if(game(bet)):
        Money += bet
        wincount+=1
        bet = 1
    else:
        Money -= bet
        losecount +=1
        bet = bet*2
        if(bet > Money):
            break

for i in listeplus: #I collect the positive elements in the list.
    totalwingain += i

for i in listeminus: # I collect the negative elements in the list.
    totallossgain += i
expectedGain = (totalwingain+totallossgain)/2 #I calculated the expected gain.



print("Gambler A1 Remaning Money: ", Money)
print("Gambler A1 Bet: " ,bet)
print("Gambler A1 WinGain:  ", totalwingain)
print("Gambler A1 LoseGain:",totallossgain)
print("Gambler A1 ExpectedGain: ", expectedGain)
print("Gambler A1 WinProbability  : ", wincount/(wincount+losecount))
print("")

listeplus.clear()  #I deleted the items of list.
listeminus.clear()


Money2=1000000
print("Gambler A2 İnitial Money: ", Money2)
bet2 = 1
wincount2 = 0
losecount2 = 0
while(True): # In this loop, I made money and bet updates for gambler A.

    if(game(bet2)):
        Money2 += bet2
        wincount2 +=1
        bet2 = 1
    else:
        Money2 -= bet2
        losecount2 +=1
        bet2 = bet2*2
        if(bet2 > Money2):
            break

for i in listeplus:
    totalwingain += i

for i in listeminus:
    totallossgain += i
expectedGain = (totalwingain+totallossgain)/2

print("Gambler A2 Remaning Money: ", Money2)
print("Gambler A2 Bet: " ,bet2)
print("Gambler A2 WinGain:  ", totalwingain)
print("Gambler A2 LoseGain:",totallossgain)
print("Gambler A2 ExpectedGain: ", expectedGain)
print("Gambler A2 WinProbability  ", wincount2/(wincount2+losecount2))
print("")
listeplus.clear() #I deleted the items of list.
listeminus.clear()


Money3=1000
print("Gambler B1 İnitial Money: ", Money3)
r = 1
wincount3 = 0
losecount3 = 0
while(True): # In this loop, I made money and bet updates for gambler B.
    x = random.uniform(0, r) #I create x value between 0 and r.
    bet3 = r * (x ** 1 / 2) #I took the integral of the function given in the homework and obtained the bet function by taking the inverse.

    if(game(bet3)):
        Money3 += bet3
        wincount3+=1
        if(bet3 >500):
            break
        r +=1
    else:
        Money3 -= bet3
        losecount3+=1
        r+=1
        if(bet3 > Money3):
            break

for i in listeplus:
    totalwingain += i

for i in listeminus:
    totallossgain += i
expectedGain = (totalwingain+totallossgain)/2



print("Gambler B1 Remaning Money: ", Money3)
print("Gambler B1 Bet: " ,bet3)
print("Gambler B1 WinGain:  ", totalwingain)
print("Gambler B1 LoseGain:",totallossgain)
print("Gambler B1 ExpectedGain: ", expectedGain)
print("Gambler B1 WinProbability ", wincount3/(wincount3+losecount3))
print("")

listeplus.clear()  #I deleted the items of list.
listeminus.clear()


Money4=1000000
print("Gambler B2 İnitial Money: ", Money4)
r = 1
wincount4 = 0
losecount4 = 0
while(True): # In this loop, I made money and bet updates for gambler A.
    x = random.uniform(0, r) #I create x value between 0 and r.
    bet4 = r * (x ** 1 / 2) # I took the integral of the function given in the homework and obtained the bet function by taking the inverse.

    if(game(bet4)):
        Money4 += bet4
        wincount4+=1
        if(bet4 >500):
            break
        r +=1
    else:
        Money4 -= bet4
        losecount4+=1
        r+=1
        if(bet4 > Money4):
            break

for i in listeplus:
    totalwingain += i

for i in listeminus:
    totallossgain += i
expectedGain = (totalwingain+totallossgain)/2



print("Gambler B2 Remaning Money: ", Money4)
print("Gambler B2 Bet: " ,bet4)
print("Gambler B2 WinGain:  ", totalwingain)
print("Gambler B2 LoseGain:",totallossgain)
print("Gambler B2 ExpectedGain: ", expectedGain)
print("Gambler B2 WinProbability ", wincount4/(wincount4+losecount4))





