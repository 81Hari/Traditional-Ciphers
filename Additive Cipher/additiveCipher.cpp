/*
C --> CIPHER TEXT
P --> PLAIN TEXT
K --> KEY

C = (P+k)mod 26 
P = (C-k)mod 26
*/

#include<iostream>

using namespace std;

class AdditiveCipher
{
    private:    
    string plain_text,cipher_text;
    int key;
    
    public:
    AdditiveCipher()
    {
        plain_text = "";
        cipher_text ="";
        key = 0;
    }
 
    //C = (P+k)mod 26   
    void encrypt()
    {
        
        int n;    
        cout<<"Plain Text: ";
        cin>>plain_text;
        cout<<"Key: ";
        cin>>key;

        n = plain_text.size();
        cipher_text = plain_text;
        for(int i=0;i<n;i++)
        {
            if(plain_text[i]>='a' && plain_text[i]<='z')
            {
              
               cipher_text[i] = ((((plain_text[i]-97)+key)%26+26)%26)+97; // POSITIVE MODULO 
                
            }   
            else if((plain_text[i]>='A' && plain_text[i]<='Z'))
            {
                cipher_text[i] = ((((plain_text[i]-65)+key)%26+26)%26)+65; // POSITIVE MODULO 
            }
            else
            {
                cout<<"Invalid Plain Text\n";exit(0);
            }
        }
        cout<<"Cipher Text: "<<cipher_text<<"\n";    
    
    }



    //P = (C-k)mod 26
    void decrypt()
    {
        int n;    
        cout<<"Cipher Text: ";
        cin>>cipher_text;
        cout<<"Key: ";
        cin>>key;

        n = cipher_text.size();
        plain_text = cipher_text;
        
        for(int i=0;i<n;i++)
        {
            if(cipher_text[i]>='a' && cipher_text[i]<='z')
            {
                plain_text[i] = ((((cipher_text[i]-97)-key)%26 + 26)%26)+97; // POSITIVE MODULO 
            }   
            else if((cipher_text[i]>='A' && cipher_text[i]<='Z'))
            {
               plain_text[i] = ((((cipher_text[i]-65)-key)%26+26)%26)+65; // POSITIVE MODULO 
            }
            else
            {
                cout<<"Invalid Cipher Text\n";exit(0);
            }
        }
        cout<<"Plain Text: "<<plain_text<<"\n";
        
    }




    void brute_force()
    {
        int n;    
        cout<<"Cipher Text: ";
        cin>>cipher_text;

        n = cipher_text.size();
        plain_text = cipher_text;
        for(int j=0;j<26;j++)
        {
            key = j;
            for(int i=0;i<n;i++)
            {
                if(cipher_text[i]>='a' && cipher_text[i]<='z')
                {
                    plain_text[i] = ((((cipher_text[i]-97)-key)%26 + 26)%26)+97;  // POSITIVE MODULO  
                }   
                else if((cipher_text[i]>='A' && cipher_text[i]<='Z'))
                {
                    plain_text[i] = ((((cipher_text[i]-65)-key)%26+26)%26)+65;     // POSITIVE MODULO 
                  
                }
                else
                {
                    cout<<"Invalid Cipher Text\n";exit(0);
                }
            }
            cout<<"Key = "<<j<<"\n \tPlain Text: "<<plain_text<<"\n \n";
        }
    }
};




int main()
{

    cout<<"\t \t ADDITIVE CIPHER\n";
    cout<<"1.Encryption \n";
    cout<<"2.Decryption \n";
    cout<<"3.Brute Force \n\n";
    cout<<"Enter your Service Number: ";

    int ch;
    cin>>ch;
    cout<<"\n";
    AdditiveCipher AC; 

    switch(ch)
    {
        case 1: AC.encrypt();break;
        case 2: AC.decrypt();break;
        case 3: AC.brute_force();break;
        default: cout<<"Invalid input";
    }
    return 0;
}
