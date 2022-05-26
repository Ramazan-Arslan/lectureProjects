// This code compiled with C99”.
#include <stdio.h>
#include <stdlib.h>

//Ramazan Arslan - 250201023
// Some resources:
// https://www.geeksforgeeks.org/write-your-own-strcmp-which-ignores-cases/
// https://stackoverflow.com

// This homework does not just provide the string completion feature. You need to give the whole name of the product.

struct Product // struct of product
{
    char name[50];
    double unitPrice;
    int quantity;

};
struct Product operation(struct Product product,char name[],double unitPrice,int quantity){ 
    //creates product so product constructor function
    for (int i = 0; i < 50; i++){
        product.name[i] = name[i];
    }
    product.unitPrice = unitPrice;
    product.quantity = quantity;
    return product;
}
char* array(int arraySize,char input[],char *ptr){ // pointer operations
// if inputsize greater than arraysize of array,arraysize so dynamic array will double.
    int length = -1;
    for(int i = 0; input[i] != '\0';i++){
        length ++;
        }
    while (arraySize < length){ 
           arraySize *= 2;
           ptr =(char*)malloc(arraySize);
    }
    for(int i = 0; i<length;i++){
        ptr[i] = input[i];  
    }
    return ptr;

}
int mystrcmp(char *s1, char *s2) // compares two string- if they are same it will return 1.
{  
    int i;
    for (i = 0; s1[i] && s2[i]; ++i)
    {
        if (s1[i] == s2[i] || (s1[i] ^ 32) == s2[i])
           continue;
        else
           break;
    }
  
    if (s1[i] == s2[i])
        return 1;
  
    if ((s1[i] | 32) < (s2[i] | 32)) 
        return -1;
    return -1;
}

int main() {
    //creates all of the products (Line 38-62)
    struct Product product,product1,product2,product3,product4,product5,product6,product7,product8,product9,product10,product11;

    product1 = operation(product,"Bread", 3.5 ,10);
    product2 = operation(product,"Egg", 2.82 ,30);
     product3 = operation(product,"Pasta", 2.79 ,15);
    product4 = operation(product,"Fish", 15.98 ,25);
     product5 = operation(product,"Milk", 10.26 ,10);
    product6 = operation(product,"Water Small", 1.55 ,35);
     product7 = operation(product,"Hand Sanitizer", 20.55 ,20);
    product8 = operation(product,"Toothpaste", 10.83 ,15);
     product9= operation(product,"Pizza", 15.30 ,10);
    product10 = operation(product,"Chocolate", 5.21 ,40);

    struct Product products[10];
    struct Product productBasket[10];
    products[0] = product1;
    products[1] = product2;
    products[2] = product3;
     products[3] = product4;
    products[4] = product5;
    products[5] = product6;
     products[6] = product7;
    products[7] = product8;
    products[8] = product9;
     products[9] = product10;
     
    
    char input[50];
    char *inputChar;   
    double total =0;

    while(1){ // Shopping Loop
    char *ptr;
    int arraySize = 5; // some necessary variables
    ptr =(char*)malloc(arraySize);
    int choice = 0; // for user inputs
    int quantity;
    char deneme[5];
    int productCheck;
    int itemOrder;
    printf( "---- MAIN MENU ----\n"); // shopping informations
    printf( "1- Buy a product \n");
    printf( "2- List all products \n");
    printf( "3- Shopping summary \n");
    printf( "4- Exit\n");
    printf( "--------------------\n");
    printf("Enter a choice: ");
    scanf("%d", &choice);
    if(choice == 1){ // first choice operations
        printf("Name of the product:");
        gets(deneme);
        fgets(input,50,stdin);
        ptr = array(arraySize,input,ptr);//sets dynamic array size according to user input
        for(int i = 0; i<10 ;i++ ){
            productCheck= mystrcmp(ptr, products[i].name); // if input and product name are same,return 1.
            if(productCheck== 1){
                itemOrder = i;
                break;
            }   
        }
        if(productCheck!= 1){ // product not found 
        printf("Product not found\n");
        continue;
        }
        printf("Quantity of the product: "); //takes number of product quantity from user
         scanf("%d", &quantity);
        if(products[itemOrder].quantity >= quantity){ // setting the amount of product and adds item to product basket for shopping summary
            printf("You bought %d %s \n", quantity,products[itemOrder].name);
            products[itemOrder].quantity -=quantity;
            product11 = operation(product,products[itemOrder].name,products[itemOrder].unitPrice,quantity);
            productBasket[itemOrder] = product11;
        }
        else{
            printf("\nThere is not enought \n");
        }
    }
    else if(choice ==2){ // orders products
        printf("-------Product List------\n");
        for(int i = 0; i<10;i++){
            printf("Product Name: %s , Unit Price: %f , Quantitiy: %d \n" ,
            products[i].name,products[i].unitPrice,products[i].quantity);
            }
        }
    else if(choice ==3){ // shows shopping summary 
        printf("----- Shopping Summary ----\n");
        for(int i = 0; i<10;i++){
            if(productBasket[i].quantity < 0 || productBasket[i].quantity > 50){
                continue;
                }
            else{
                printf("Product Name: %s , Unit Price: %f , Quantitiy: %d \n" ,
                productBasket[i].name,productBasket[i].unitPrice,productBasket[i].quantity);
                total += productBasket[i].unitPrice*productBasket[i].quantity;
                }
            }    
        printf("Total Price : %f \n", total);
        } 
     else if(choice ==4){ //ends shopping
        printf("----- Shopping is ended ----\n");
        exit(0);
        }
    else if( (choice != 1) || (choice != 2) || (choice != 3) ){ // for invalid input if choice does not equal 1,2,3 or 4.
        printf("Invalid Input");
        break;
    }
    else{
        continue;
        } 
    }

    return(0);

}