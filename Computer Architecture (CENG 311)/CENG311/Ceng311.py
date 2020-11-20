import time

########## Ramazan Arslan - 2020 ##########
# Sources:
 #### https://realpython.com/python-timer/
 #### https://www.w3schools.com/python/python_file_open.asp



file1 = open("randomNumbers1000.txt", "r") #reading nums from file ,you can change the text name for trying the other files.
readedFile= file1.read()
nums = readedFile.split(' ')
nums.pop() # I used pop to delete the element at the end of the list.
tree = [None] * 10000000
intNums =[]

begin = time.time() # beginning of the operation time


def add(key,parent): # Adds the numbers to the tree.

    if( key > parent):
        index = tree.index(parent)
        if(tree[index*2 +2] != None):
            add(key,tree[(index*2) + 2])
        else:
            tree[index*2+2] = key

    elif(key < parent):
        index = tree.index(parent)
        if (tree[index * 2 + 1] != None):
            add(key, tree[(index*2) + 1])
        else:
             tree[index * 2 + 1] = key

def writeFile(parentIndex):# writing numbers to file
    file2 = open("Python_Ordered_BST.txt", "a") #If you run and control code you need to delete Python_Ordered_BST.txt from directory.
    file2.write((str(tree[parentIndex])) + " ") #If you don't delete file , The program overwrites to file.
    file2.close()

def inorder(parent): # in order traversal
    if(parent == None):
        return
    index = tree.index(parent)
    inorder(tree[(2 * index) + 1])
    #print(parent)
    writeFile(index)
    inorder(tree[(2 * index) + 2])

for j in (nums): #convertes numbers str to int
    convertedNum = int(j)
    intNums.append(convertedNum)

tree[0] = intNums[0] #declares root element in the tree
for i in intNums: #adds to the tree readed numbers from text.
    add( i , intNums[0] )

end = time.time() #ending of the operation time
inorder(tree[0]) # call inorder function for in-order traversal

print("Total execute time : " , end-begin) #printing total execution time

