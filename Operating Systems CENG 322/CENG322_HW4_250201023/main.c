#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

//Ramazan Arslan - 250201023
// Of course, not an excuse, but also I'm working, so time was not enough and I couldn't finish.
struct Product // struct of product 
{
    char product_name[50];
    char product_type[50];
    int price;
};

struct Node // struct of node 
{
    struct Product *data;
    struct Node *next;
};

void delay(int number_of_seconds) // delay function
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}


struct Product newProduct(struct Product product, char product_name[], char product_type[], int price) 
{
    //creates new product so product constructor function
    for (int i = 0; i < 50; i++)
    {
        product.product_name[i] = product_name[i];
        product.product_type[i] = product_type[i];
    }

    product.price = price;
    return product;
}

int checker(char input[],char check[]) // for check that user input (product type) and product type are equal.
{
    int i,result=1;
    for(i=0; input[i]!='\0' || check[i]!='\0'; i++) {
        if(input[i] != check[i]) {
            result=0;
            break;
        }
    }
    return result;
}

void printList(struct Node *n, int listnumber) // prints products and their attributes
{   
    if(listnumber != 3){
    printf("Products %d: \n" , listnumber);
    }
    else{
        printf("Favories: \n");  
    }
    while (n != NULL)
    {
            printf("Product name: %s  ,", n->data->product_name);   
            printf("product type %s  ,", n->data->product_type);
            printf("price %d  \n", n->data->price);
         
        
        n = n->next;
    }
}
void cutProduct(struct Node *head, struct Node *head2,char productType[50]) // for cut and pasting thread but
 {                                                                           // not working well :{
    if (head == NULL ||  head2 == NULL)
       return;

     struct Node *headFavories = NULL;
    headFavories = (struct Node*)malloc(sizeof(struct Node));

    headFavories->data = NULL;

       

    srand(time(NULL));

  
    struct Product *result = head->data;
  
    struct Node *current = head;
    int n;
    for (n=2; current!=NULL; n++)
    {
       
        if (rand() % n == 0)
           result = current->data;
  
        current = current->next;
        
    }

    if(!checker(result->product_type,productType)){
            //cutProduct(head,head2,productType);
        }

    printf("Product price is increased in Product: %s, %s ,%d \n",productType ,result->product_type ,result->price);

}

void increasePrice(struct Node *head, int listnumber) // increases 20% the product price by choosing a random product
{

    //printf("Type 3 threadis perfoming. \n");
    if (head == NULL)
       return;
    
    srand(time(NULL));
  
    struct Product *result = head->data;
  
    struct Node *current = head;
    int n;
    for (n=2; current!=NULL; n++)
    {
       
        if (rand() % n == 0)
           result = current->data;
  
        current = current->next;
    }
   result->price = result->price*1.2;
    printf("Product price is increased in Product %d: %s, %d \n", listnumber,result->product_name ,result->price);
}

void productOffer(struct Node *head,struct Node *head2,int budget) // for offer product according to user's budget
                // not complete
{
}


void freeList(struct Node *n) // for fresh a ram memory.
{
    struct Node *temp = n;
    
    
    while (temp != NULL)
    {
        free(temp);
        temp = temp->next;
    }
}




int main()
{
    struct Product product; // creates products 
    struct Product product1, product2, product3, product4, product5, product6, product7, product8, product9, product10,
     product11, product12, product13, product14, product15, product16, product17, product18, product19, product20;
    product1 = newProduct(product, "phone", "electronicDevice", 200);
    product2 = newProduct(product, "shoes", "clothing", 550);
    product3 = newProduct(product, "powerbank", "electronicDevice", 100);
    product4 = newProduct(product, "detergent", "market", 20);
    product5 = newProduct(product, "coke", "market", 5);
    product6 = newProduct(product, "tshirt", "clothing", 70);
    product7 = newProduct(product, "jean", "clothing", 220);
    product8 = newProduct(product, "dress", "clothing", 300);
    product9 = newProduct(product, "hairDreier", "electronicDevice", 300);
    product10 = newProduct(product, "blender", "electronicDevice", 500);

    product11 = newProduct(product, "Iphone X", "electronicDevice", 700);
    product12 = newProduct(product, "shirt", "clothing", 450);
    product13 = newProduct(product, "computer", "electronicDevice", 950);
    product14 = newProduct(product, "water", "market", 10);
    product15 = newProduct(product, "chocalate", "market", 15);
    product16 = newProduct(product, "head", "clothing", 50);
    product17 = newProduct(product, "glasses", "clothing", 120);
    product18 = newProduct(product, "flip-flop", "clothing", 100);
    product19 = newProduct(product, "speaker", "electronicDevice", 250);
    product20 = newProduct(product, "washing machine", "electronicDevice", 800);

    char productType[50]; // takes input from user.
    printf("Please enter your favorite product_type(in lower case):");
    fgets(productType, sizeof(productType), stdin); // read string
    printf("productType: %s", productType);
    strtok(productType, "\n");

    int budget;

    printf("Please enter your budget for shopping: ");
    scanf("%d", &budget);
    printf("Budget: %d", budget);

    //printf("Type 1 threadis perfoming. ");
 
    struct Node *head2 = NULL; //creates second product linkedlist.
    head2 = (struct Node*)malloc(sizeof(struct Node));

    struct Node *second2 = NULL;
    second2 = (struct Node*)malloc(sizeof(struct Node));

    struct Node *third2 = NULL;
    third2 = (struct Node*)malloc(sizeof(struct Node));

     struct Node *fourth2 = NULL;
    fourth2 = (struct Node*)malloc(sizeof(struct Node));

     struct Node *fifth2 = NULL;
    fifth2 = (struct Node*)malloc(sizeof(struct Node));

     struct Node *sixth2 = NULL;
    sixth2 = (struct Node*)malloc(sizeof(struct Node));

    struct Node *seventh2 = NULL;
    seventh2 = (struct Node*)malloc(sizeof(struct Node));

    struct Node *eighth2 = NULL;
    eighth2 = (struct Node*)malloc(sizeof(struct Node));

     struct Node *nineth2 = NULL;
    nineth2 = (struct Node*)malloc(sizeof(struct Node));

     struct Node *tenth2 = NULL;
    tenth2 = (struct Node*)malloc(sizeof(struct Node));

    head2->data = &product11;
    head2->next = second2;

    second2->data = &product12;
    second2->next = third2;

    third2->data = &product13;
    third2->next = fourth2;

    fourth2->data = &product14;
     fourth2->next = fifth2;

    fifth2->data = &product15;
     fifth2->next = sixth2;

    sixth2->data = &product16;
    sixth2->next = seventh2;

    seventh2->data = &product17;
    seventh2->next = eighth2;


    eighth2->data = &product18;
    eighth2->next = nineth2;

    nineth2->data = &product19;
     nineth2->next = tenth2;

    tenth2->data = &product20;
     tenth2->next = NULL;

     struct Node *head = NULL; // create first product linkedlist.
    head = (struct Node*)malloc(sizeof(struct Node));

    struct Node *second = NULL;
    second = (struct Node*)malloc(sizeof(struct Node));

    struct Node *third = NULL;
    third = (struct Node*)malloc(sizeof(struct Node));

     struct Node *fourth = NULL;
    fourth = (struct Node*)malloc(sizeof(struct Node));

     struct Node *fifth = NULL;
    fifth = (struct Node*)malloc(sizeof(struct Node));

     struct Node *sixth = NULL;
    sixth = (struct Node*)malloc(sizeof(struct Node));

    struct Node *seventh = NULL;
    seventh = (struct Node*)malloc(sizeof(struct Node));

    struct Node *eighth = NULL;
    eighth = (struct Node*)malloc(sizeof(struct Node));

     struct Node *nineth = NULL;
    nineth = (struct Node*)malloc(sizeof(struct Node));

     struct Node *tenth = NULL;
    tenth = (struct Node*)malloc(sizeof(struct Node));

    head->data = &product1;
    head->next = second;

    second->data = &product2;
    second->next = third;

    third->data = &product3;
    third->next = fourth;

    fourth->data = &product4;
     fourth->next = fifth;

    fifth->data = &product5;
     fifth->next = sixth;

    sixth->data = &product6;
    sixth->next = seventh;

    seventh->data = &product7;
    seventh->next = eighth;

    eighth->data = &product8;
    eighth->next = nineth;

    nineth->data = &product9;
     nineth->next = tenth;

    tenth->data = &product10;
     tenth->next = NULL;




   
    cutProduct(head,head2,productType);

   printList(head,1);  
    printList(head2,2);  
    increasePrice(head,1);
    freeList(head);
    



    return 0;
}
