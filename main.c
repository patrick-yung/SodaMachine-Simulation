
#include <stdio.h>

int menu(){
  printf("\nWhat would you like to do?\n1. Read product information\n2. Insert coin\n3. Press product button\n4. Press return button\n9. Open service menu (code required)\n0. Quit\nYour choice:");
  return 0;
}
/////////////////////////////////////////////////////////////
int mid(int z,int x,int y,int u, int i,int total, int ap, int bp, int cp, int dp, int ep){
 if(z==0){
 printf("|  [X]  ");}
 else if(total>=ap) {printf("|  [O]  ");}
 else {printf("|  [ ]  ");}
 if(x==0){
 printf("[X]  ");}
 else if(total>=bp) {printf("[O]  ");}
 else printf("[ ]  ");
 if(y==0){
 printf("[X]  ");}
 else if(total>=cp) {printf("[O]  ");}
 else printf("[ ]  ");
 if(u==0){
 printf("[X]  ");}
 else if(total>=dp) {printf("[O]  ");}
 else printf("[ ]  ");
 if(i==0){
 printf("[X]  |\n");}
 else if (total>=ep) {printf("[O]  |\n");}
 else printf("[ ]  |\n");
 return 0;
 }

/////////////////////////////////////////////////////////////
int out(int drink){
  if(65<=drink&&drink<=69){
     printf("|           [=%c=]           |\n",drink);
  }else printf("|           [===]           |\n");
  drink=0;
  return drink;
}
/////////////////////////////////////////////////////////////

int coin(int z, int x, int y, int u, int i, int total,int drink,int ap, int bp, int cp, int dp, int ep){
  printf("*---------------------------*\n");
 printf("|      Vending Machine      |\n");
 printf("*---------------------------*\n");
 printf("|   A    B    C    D    E   |\n");

if(10<=ap){
printf("|  $%d",ap);}else{printf("|  $ %d",ap);}
if(10<=bp){printf("  $%d",bp);}else{
printf("  $ %d",bp);}
if(10<=cp){
printf("  $%d",cp);}else{printf("  $ %d",cp);}
if(10<=dp){
printf("  $%d",dp);}else{printf("  $ %d",dp);}
if(10<=ep){
printf("  $%d  |\n",ep);}else{printf("  $ %d  |\n",ep);}


 mid(z,x,y,u,i,total,ap,bp,cp,dp,ep);
 printf("*---------------------------*\n");
 if(total>=10){
 printf("|                    [$%d]  |\n",total);}else{printf("|                    [$ %d]  |\n",total);}

 printf("|                           |\n");
 out(drink);
 printf("*---------------------------*\n");
return total;
}
/////////////////////////////////////////////////////////////


int list(int n,int total, int x, int z, int y, int u, int i,int result,int ap,int bp, int cp, int dp, int ep, char an[20], char bn[20], char cn[20], char dn[20], char en[20]){
int p,b,drink,code;
int d=1;
if(n==1){
  printf("\n");
  printf("(1) The displayed products are:\nA. %s ($%d)\nB. %s ($%d)\nC. %s ($%d)\nD. %s ($%d)\nE. %s ($%d)\n",an,ap,bn,bp,cn,cp,dn,dp,en,ep);
  menu();
  n=0;
  scanf("%d",&n);
  list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);

}else if(n==2){
  int cash;
  int pat=0;
  while (pat==0){
    printf("\n");
    printf("(2) Which coin would you like to insert?\n1. $1\n2. $2\n3. $5\n4. $10\n0. Go back\nYour choice:");
    scanf("%d",&d);
    if(d==1||d==2||d==3||d==4){
      if(d==1){
        if(total<=98){
        cash=1;}
        else{total=99;
        cash=0;}
      }else if(d==2){
        if(total<=97){
        cash=2;}
        else{total=99;
        cash=0;}
      }else if(d==3){
        if(total<=94){
        cash=5;}
        else{total=99;
        cash=0;}
      }else if(d==4){
        if(total<=89){
        cash=10;}
        else{total=99;
        cash=0;}
      }

    printf("You have inserted $%d.\n\n",cash);
    total=cash+total;
    coin(z,x,z,u,i,total,drink,ap,bp,cp,dp,ep);
    
    }else if(d==0){ printf("Going back!\n\n");
    coin(z,x,z,u,i,total,drink,ap,bp,cp,dp,ep);
    menu();
    scanf("%d",&n);
    list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en); 
    break;
    }else{printf("Invalid choice!\n");}
  }
}else if(n==3){
 int pat;
 pat=0;
 while(pat==0){
 printf("\n(3) Which product button would you like to press?\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\nYour choice:");
  scanf("%d",&b);
  if(0<b&&b<6){
    printf("You have pressed button %c.\n\n",b+64);
    pat=1;
  }
  if(b==0){
    pat=1;
  }
  if(b==1){
    if(ap<=total&&0<z){
    z--;
     drink=b+64;
     total=total-ap;
     result=result+ap;
     printf("\n");  
     coin(z,x,y,u,i,total,drink,ap,bp,cp,dp,ep);
     drink=0;
     menu();
     scanf("%d",&n);
     list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an, bn,cn,dn,en);

    }else{
     coin(z,x,y,u,i,total,drink,ap,bp,cp,dp,ep);
     menu();
     scanf("%d",&n);
     list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an, bn,cn,dn,en);
    }

  }else if(b==2){
     if(bp<=total&&0<x){
     x--;
     drink=b+64;
     total=total-bp;
     result=result+bp;
     coin(z,x,y,u,i,total,drink,ap,bp,cp,dp,ep);
     drink=0;
     menu();
     scanf("%d",&n);
     list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);
    
     }else{
     coin(z,x,y,u,i,total,drink,ap,bp,cp,dp,ep);
     menu();
     scanf("%d",&n);
     list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);}
  }else if(b==3){
    if(cp<=total&&0<y){
    y--;
    drink=b+64;
    total=total-cp;
    result=result+cp;
    coin(z,x,y,u,i,total,drink,ap,bp,cp,dp,ep);
    drink=0;
     menu();
    scanf("%d",&n);
    list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);
    
    }else{
    coin(z,x,y,u,i,total,drink,ap,bp,cp,dp,ep);
    menu();
    scanf("%d",&n);
    list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);
    }
  }else if(b==4){
    if(dp<=total&&0<u){
    u--;
    drink=b+64;
    total=total-dp;
    result=result+dp;
    coin(z,x,y,u,i,total,drink,ap,bp,cp,dp,ep);
    drink=0;
    menu();
    scanf("%d",&n);
    list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);
    
    }else{
    coin(z,x,y,u,i,total,drink,ap,bp,cp,dp,ep);
    menu();
    scanf("%d",&n);
    list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);}
  }else if(b==5){
    if(ep<=total&&0<i){
    i--;
    drink=b+64;
    total=total-ep;
    result=result+ep;
    coin(z,x,z,u,i,total,drink,ap,bp,cp,dp,ep);
    drink=0;
    menu();
    scanf("%d",&n);
    list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);
    
    }else{
    coin(z,x,y,u,i,total,drink,ap,bp,cp,dp,ep);
    menu();
    scanf("%d",&n);
    list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);}

  }else if(b==0){
    printf("Going back!\n\n");
    coin(z,x,y,u,i,total,drink,ap,bp,cp,dp,ep);
    menu();
    scanf("%d",&n);
    list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);    
  }
  else if(5<b||b<0){
    printf("Invalid choice!\n");
    drink=0;}}

}else if(n==4){
  int temp;
  temp=total;
  total=0;
  printf("\n(4) Return button is pressed.\n$%d has been returned.\n\n",temp);

  coin(z,x,y,u,i,total,drink,ap,bp,cp,dp,ep);
  menu();
  scanf("%d",&n);
  list(n,0,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);
  

}else if(n==9){
 printf("\n(9) Opening service menu. Access code is required.\nEnter access code:");
 scanf("%d",&code);
 if(code==1110){
  printf("Correct code!\n");
  int nono=0;
  while(nono==0){
  printf("\n(9) What would you like to do?\n1. Inspect machine status\n2. Withdraw all money\n3. Refill product\n4. Change product\n0. Go back\nYour choice:");
  scanf("%d",&n);
  ///////////////////
  if(n==1){
   printf("\n(9-1) Machine status\nAmount of revenue: $%d\nAmount of inserted coins: $%d\nProduct information:\n",result,total);
   if(z==0){
   printf("A. %s ($%d) (sold out)\n",an,ap);
   }else{
   printf("A. %s ($%d) (%d left)\n",an,ap,z);}

   if(x==0){
   printf("B. %s ($%d) (sold out)\n",bn,bp);
   }else{
   printf("B. %s ($%d) (%d left)\n",bn,bp,x);}

   if(y==0){
   printf("C. %s ($%d) (sold out)\n",cn,cp);
   }else{
   printf("C. %s ($%d) (%d left)\n",cn,cp,y);}

   if(u==0){
   printf("D. %s ($%d) (sold out)\n",dn,dp);

   }else{
   printf("D. %s ($%d) (%d left)\n",dn,dp,u);}

   if(i==0){
   printf("E. %s ($%d) (sold out)\n",en,ep);
   }else{
   printf("E. %s ($%d) (%d left)\n",en,ep,i);}
  }
  else if(n==2){
    printf("\n(9-2) All money is being withdrawn.\n$%d is withdrawn.\n",result+total);
    result=0;
    total=0;
  }
  else if(n==3){
    int pat=0;
    while(pat==0){
    printf("\n(9-3) Which product would you like to refill?\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\nYour choice:");
    scanf("%d",&n);
    if(n==1){
      z=10;
      printf("You have refilled product A to full.\n");
      pat=1;
     }else if(n==2){
      x=10;
      printf("You have refilled product B to full.\n");
      pat=1;
     }else if(n==3){
      y=10;
      printf("You have refilled product C to full.\n");
      pat=1;
     }else if(n==4){
      u=10;
      printf("You have refilled product D to full.\n");
      pat=1;
     }else if(n==5){
      i=10;
      printf("You have refilled product E to full.\n");
      pat=1;
     }else if(n==0){
      printf("Going back!\n");
      pat=1;
     }else{printf("Invalid choice!\n");}}
    }
  else if(n==4){
    int pat=0;
    while (pat==0){
    printf("\n(9-4) Which product would you like to change?\n1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\nYour choice:");
    scanf("%d",&n);
    if(1<=n&&n<=5){
    printf("You are changing product %c.\n",64+n);
      int tmp;
      printf("\nEnter new product name:");
      if(n==1){
        scanf("%s",an);
        z=10;
        }else if(n==2){
        x=10;
        scanf("%s",bn);
        }else if(n==3){
        y=10;
        scanf("%s",cn);  
        }else if(n==4){
        u=10;
        scanf("%s",dn);
        }else if(n==5){
        i=10;
        scanf("%s",en);}
      printf("Enter new product price:");
      scanf("%d",&tmp);
        if(n==1){
        ap=tmp;
        printf("The new product %c has been filled to full.\n",n+64);
        }else if(n==2){
        bp=tmp;
        printf("The new product %c has been filled to full.\n",n+64);  
        }else if(n==3){
        cp=tmp;
        printf("The new product %c has been filled to full.\n",n+64);  
        }else if(n==4){
        dp=tmp;
        printf("The new product %c has been filled to full.\n",n+64);  
        }else if(n==5){
        ep=tmp;
        printf("The new product %c has been filled to full.\n",n+64);  
        }
        pat=1;
      }else if (n==0){printf("Going back!\n");
      pat=1;
      }else{printf("Invalid choice!\n");}}
  }else if(n==0){
    printf("Going back!\n\n");
    nono=1;
  }else {printf("Invalid choice!\n");}
  
  }
  coin(z,x,y,u,i,total,drink,ap,bp,cp,dp,ep);
   menu();
   scanf("%d",&n);
   list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);

 }else{
   printf("Incorrect code!\n\n");
   coin(z,x,y,u,i,total,drink,ap,bp,cp,dp,ep);
   menu();
   scanf("%d",&n);
   list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);
 }
}else if(n==0){
  return 0;
  return 0;
  }

 else{
  printf("Invalid choice!\n");
  menu();
  scanf("%d",&n);
  list(n,total,x,z,y,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);
  }
return 0;}



int start(){
 int n,total=0,x=1,z=2,y=5,u=1,i=9,result,ap=10,bp=6,cp=5,dp=8,ep=7;
 menu();
 scanf("%d",&n);
 char an[20]={"Juice"};
char bn[20]={"Cola"},cn[20]={"Tea"},dn[20]={"Water"},en[20]={"Coffee"}; 
 list(n,total,x,y,z,u,i,result,ap,bp,cp,dp,ep,an,bn,cn,dn,en);
 return 0;
}


int main(void) {
 printf("*---------------------------*\n");
 printf("|      Vending Machine      |\n");
 printf("*---------------------------*\n");
 printf("|   A    B    C    D    E   |\n");
 printf("|  $10  $ 6  $ 5  $ 8  $ 7  |\n");
 printf("|  [ ]  [ ]  [ ]  [ ]  [ ]  |\n");
 printf("*---------------------------*\n");
 printf("|                    [$ 0]  |\n");
 printf("|                           |\n");
 printf("|           [===]           |\n");
 printf("*---------------------------*\n");

start();


  return 0;
}
