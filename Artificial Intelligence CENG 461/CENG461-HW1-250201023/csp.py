# Ramazan Arslan 250201023

sizes = [6,7,8,9] #shirts sizes

class Shirt(object): #shirts object
    def __init__(self, domain, size,color):
        self.color = color
        self.size = size
        self.domain = domain

def find_var_mrv(shirt1,shirt2,shirt3,shirt4,shirts):
    global sizes

    shirt1.domain = "Moore" #if red's owner Moore
    shirt1.size = sizes[0] #if the red shirt's size is 6
    if(find_val_lcv(shirt1,shirt2,shirt3,shirt4,shirts) == 'false'):
        #The red shirt's size is 7 if not 6.The red shirt can be only 6 or 7 because red + 2 = black and max size is 9
        shirt1.size = sizes[1]
        if(find_val_lcv(shirt1,shirt2,shirt3,shirt4,shirts) == 'true'):
            shirt3.domain = "Ellison" #Assigns name to one of two remaining shirt.
            shirt4.domain = "Quinn"
            if(find_val_lcv(shirt1,shirt2,shirt3,shirt4,shirts) == 'false'):
                shirt3.domain = "Quinn"
                shirt4.domain = "Ellison"

def find_val_lcv(shirt1,shirt2,shirt3,shirt4,shirts):
    global sizes
    sizes.pop(sizes.index(shirt1.size))
    shirt2.size = 1 + shirt1.size   #The green's shirt size = the red shirt's size + 1
    sizes.pop(sizes.index(shirt2.size))
    shirt3.size = 1 + shirt2.size   #The black's shirt size = the green shirt's size + 1
    sizes.pop(sizes.index(shirt3.size)) 
    shirt4.size = sizes.pop(); #The purple's shirt size = The last remaining shirt size
    sizes = [6,7,8,9]
    for shirt in shirts: 
        DeansSize = shirt4.size + 2 #The Dean's shirt size = The purple's shirt size + 2
        if(shirt.size == DeansSize):
           shirt.domain = "Dean" # Assigns the name to the corresponding shirt color and size
    return apply_arc_consistency(shirt1,shirt2,shirt3,shirt4,shirts)

def apply_arc_consistency(shirt1,shirt2,shirt3,shirt4,shirts):
   #Returns false if the red shirt's size not 6 or 7. The red shirt can be only 6 or 7 because red + 2 = black and max size is 9
   if(shirt1.size == 8 or shirt1.size == 9): 
      return "false";
   if(shirt2.size > 9 or shirt2.size < 6): #The green shirt's can't be bigger than 9 and lover than 6 sizes.
      return "false";
   if(shirt3.size > 9 or shirt3.size < 6): #The black shirt's can't be bigger than 9 and lover than 6 sizes.
      return "false";
   # Returns false if the purple shirt's size not 6 or 7. The purple shirt can be only 6 or 7,
   # because Dean's shirt = the purple shirt's size + 2 and max size is 9.
   if(shirt4.size == 8 or shirt4.size == 9):
      return "false";    
  
   ellisonSize = 0
   quinnSize = 0

   for shirt in shirts: # takes sizes of Ellison and Quinn shirt
        if(shirt.domain == "Ellison"):
            ellisonSize = shirt.size
        elif(shirt.domain == "Quinn"):
            quinnSize = shirt.size

   for shirt in shirts: # Returns false if the Ellison's shirt size bigger than Quinn's shirt size
        if(ellisonSize > quinnSize):
            return "false";
  
   return "true";

def main():
    shirt1 = Shirt('',0,'red') # Creates the shirt objects
    shirt2 = Shirt('',0,'green')
    shirt3 = Shirt('',0,'black')
    shirt4 = Shirt('',0,'purple')
    shirts = [shirt1,shirt2,shirt3,shirt4];
    find_var_mrv(shirt1,shirt2,shirt3,shirt4,shirts)
    # Prints results
    print(shirt1.domain,"'s shirt size",shirt1.size,"and color of shirt is",shirt1.color)
    print(shirt2.domain,"'s shirt size",shirt2.size,"and color of shirt is",shirt2.color)
    print(shirt3.domain,"'s shirt size",shirt3.size,"and color of shirt is",shirt3.color)
    print(shirt4.domain,"'s shirt size",shirt4.size,"and color of shirt is",shirt4.color)

if __name__ == "__main__":
    main()

