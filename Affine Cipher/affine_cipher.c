/*

y --> cipher text
x --> plain text
(a,b) --> key pair

y = ((x*a) + b) mod 26 (encrypt)

x = [(a^(-1)) * (y-b)] mod 26 (decrypt) 

    For decryption we need to use inverse modulo

*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define N 50 

typedef struct AffineCipher{
int a, b, x, y;
char plain_text[N], cipher_text[N];

}AffineCipher;

int gcd(int a, int b) //EUCLIDEAN ALGORITHM
{
    int q, r;
    q = a/b;
    r = a%b;
    
    if(r==0){
        return b;
    }
    else{
        gcd(b,r);
    }  
}

// key pair(a,b) iff {0<=a<=25 && 0<=b<=25 && gcd(a,26) == 1)
bool check(int a, int b){ 
    
    if(b>=0 && b<=25 && gcd(a,26)==1){
        return true;    
    }
}


void encrypt(AffineCipher AC){   
    
    bool flag;    
    printf("\nEnter Plain Text: ");
    fgets(AC.plain_text,N,stdin);
    strcpy(AC.cipher_text,AC.plain_text);
    
    key:
    printf("\nEnter multicative parameter(a) and additive parameter(b): ");
    scanf("%d %d",&(AC.a),&(AC.b));
    flag = check(AC.a, AC.b);
    
    if(!flag)
    {
        printf("\nEntered key pair is invalid\n\n");
        goto key;
    }
    
    for(int i=0;i<strlen(AC.plain_text)-1;i++){
        if(AC.plain_text[i]>='a' && AC.plain_text[i]<='z'){
            AC.x = AC.plain_text[i] - 'a';
            AC.y = ((AC.x*AC.a + AC.b)%26 +26)%26 +'a';
        }
        else if((AC.plain_text[i]>='A' && AC.plain_text[i]<='Z'))
        {
            AC.x = AC.plain_text[i] - 'A';
            AC.y = ((AC.x*AC.a + AC.b)%26 +26)%26 + 'A';
        }
        else
        {
            printf("Invalid Plain Text\n");exit(0);
        }
        AC.cipher_text[i] = (char)AC.y;
        
         
    }
    printf("\nCipher Text: %s\n",AC.cipher_text);
}

void decrypt(AffineCipher AC){
    
    bool flag;    
    printf("\nEnter Cipher Text: ");
    fgets(AC.cipher_text,N,stdin);
    strcpy(AC.plain_text,AC.cipher_text);
    
    key:
    printf("\nEnter multicative parameter(a) and additive parameter(b): ");
    scanf("%d %d",&(AC.a),&(AC.b));
    flag = check(AC.a, AC.b);
    
    if(!flag)
    {
        printf("\nEntered key pair is invalid\n\n");
        goto key;
    }
    for(int i =0;i<26;i++){
        if((AC.a*i)%26 == 1) // Finding the modular Inverse for a
        {
            AC.a = i;
        }
    }
    for(int i=0;i<strlen(AC.cipher_text)-1;i++){
        if(AC.cipher_text[i]>='a' && AC.cipher_text[i]<='z'){
            AC.y = AC.cipher_text[i] - 'a';
            AC.x = (((AC.y-AC.b)*AC.a)%26 +26)%26 +'a';
        }
        else if((AC.plain_text[i]>='A' && AC.plain_text[i]<='Z'))
        {
            AC.y = AC.cipher_text[i] - 'A';
            AC.x = (((AC.y-AC.b)*AC.a)%26 +26)%26 +'A';
        }
        else
        {
            printf("Invalid Plain Text\n");exit(0);
        }
        AC.plain_text[i] = (char)AC.x;
   
        
         
    }
    printf("\nPlain Text: %s\n",AC.plain_text);
}

void main(){

    AffineCipher AC;
    int ch;
    printf("\t AFFINE CIPHER \n\n");

    printf("1. Encryption \n");
    printf("2. Decryption \n\n");
    printf("Enter the Service: ");
    scanf("%d",&ch);
    getchar(); // ENTER = '\n'. '\n' is stored in buffer which affects the fgets(), to avoid that we are using getch() 

    switch(ch){
        case 1: encrypt(AC);break;
        case 2: decrypt(AC);break;
        default: printf("Invalid input \n");

    }
}
