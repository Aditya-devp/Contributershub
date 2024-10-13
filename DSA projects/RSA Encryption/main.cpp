#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
int arr[16],cm[16];

int gcd(int a, int b)                               //Finds the HCF of e and phi
{
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b = t;
   }
}

int find_d(int e, int phi)                   //Finds d such that (d*e) % phi = 1
{
    int d=2;
    while((d*e)%phi!=1)
    {
        d++;
    }
    return d;
}

void string_to_ascii(string a)                        //Converts string to ascii
{
    for(int i=0;i<a.length();i++)
    {
        int c=a[i];
        arr[i]=c;
    }
}

string ascii_to_string()                              //Converts ascii to string
{
    int num = 0;
    string b;
    int len = sizeof(cm)/sizeof(cm[0]);
    for (int i=0;i<len;i++)
    {
        num = cm[i];
        if (num>=32 && num<=122)
        {
            char ch=(char)num;
            b+=ch;
            num = 0;
        }
    }
    return b;
}

string encoder(string key)              //Generates encoded string for KW Cipher
{
	string encoded = "";
	// This array represents the
	// 26 letters of alphabets
	bool arr1[26] = {0};

	// This loop inserts the keyword
	// at the start of the encoded string
	for (int i=0; i<key.size(); i++)
	{
		if(key[i] >= 'A' && key[i] <= 'Z')
		{
			// To check whether the character is inserted
			// earlier in the encoded string or not
			if (arr1[key[i]-65] == 0)
			{
				encoded += key[i];
				arr1[key[i]-65] = 1;
			}
		}
		else if (key[i] >= 'a' && key[i] <= 'z')
		{
			if (arr1[key[i]-97] == 0)
			{
				encoded += key[i] - 32;
				arr1[key[i]-97] = 1;
			}
		}
	}

	// This loop inserts the remaining
	// characters in the encoded string.
	for (int i=0; i<26; i++)
	{
		if(arr1[i] == 0)
		{
			arr1[i]=1;
			encoded += char(i + 65);
		}
	}
	return encoded;
}

string kwc_encrypt(string msg, string encoded) //Encryption using Keyword Cipher
{
	string cipher="";

	// This loop ciphered the message.
	// Spaces, special characters and numbers remain same.
	for (int i=0; i<msg.size(); i++)
	{
		if (msg[i] >='a' && msg[i] <='z')
		{
			int pos = msg[i] - 97;
			cipher += encoded[pos];
		}
		else if (msg[i] >='A' && msg[i] <='Z')
		{
			int pos = msg[i] - 65;
			cipher += encoded[pos];
		}
		else
		{
			cipher += msg[i];
		}
	}
	return cipher;
}

string kwc_decrypt(string ct, string encoded)  //Decryption using Keyword Cipher
{
    string decipher="";
 
    for (int i=0; i<ct.length(); i++)
    {
        int j=0;
        while(ct[i]!=encoded[j] && j<=26)
            j++;
        
        if (ct[i] >='A' && ct[i] <='Z')
        {
            char ch = j+65;
            decipher += ch;
        }
        else
        {
            decipher += ct[i];
        }
    }
    return decipher;
}

int cdn( int c, int d, int n )                            // works out c^d mod n
{
   int value = 1;
   while( d > 0 )
   {
      value *= c;
      value %= n;
      d--;
   }
   return value;
}

int main()                                                        // Driver Code
{
    //2 random prime numbers
    double p = 13;
    double q = 11;
    double n=p*q;
    double track;
    double phi= (p-1)*(q-1);
    
    //public key e stands for encrypt
    //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
    
    long double e=7;
    while(e<phi) 
    {
       track = gcd(e,phi);
       if(track==1)
          break;
       else
          e++;
    }
    
    //private key d stands for decrypt
    //choosing d such that it satisfies d*e = 1 mod phi
   
    int d = find_d(e,phi);

    //Enrypting the message.....................................................
    	
	string key = "Secret";   //key for cipher
    cout<<"\nOriginal Key:   "<<key<<endl;
    int l=key.length();
	string encoded = encoder(key);

    ifstream pt("plainText.txt");
    stringstream str1;
    str1 << pt.rdbuf();
    string plaintext = str1.str();
    pt.close();

    string ciphertext = kwc_encrypt(plaintext, encoded);
    ofstream ct("cipherText.txt");
    ct << ciphertext;
    ct.close();
	
	//..........................................................................
	
	cout<<"\n***********************\nRSA Values:\n";
	cout<<"\n"<<"p = "<<p;
    cout<<"\n"<<"q = "<<q;
    cout<<"\n"<<"n = pq = "<<n;
    cout<<"\n"<<"phi = "<<phi;
    cout<<"\n"<<"e = "<<e;
    cout<<"\n"<<"d = "<<d;
    cout<<"\n***********************\n";
    
	//Encrypting the key with RSA...............................................
    string_to_ascii(key);
    
    double c,m;
    int i;
    
    string ekey;
    for(i=0;i<l;i++)
    {
        cm[i] = cdn(arr[i],e,n);
        char ch = cm[i];
        ekey+=ch;
    }
    cout<<"\nEncrypted Key:   ";
    for(i=0;i<l;i++)
        cout<<cm[i]<<" ";
    cout<<"\n             :    "<<ekey;
    
    //Decrypting the key with RSA...............................................
    string dkey;
    
    for(i=0;i<l;i++)
    {
        cm[i] = cdn(cm[i],d,n);
        char ch = cm[i];
        dkey+=ch;
    } 
    cout<<"\n\nDecrypted Key:   ";
    for(i=0;i<l;i++)
        cout<<cm[i]<<" ";
    cout<<"\n             :   "<<dkey;
    
    //Decrypting CipherText.....................................................
   
    encoded = encoder(dkey);
    string deciphertext = kwc_decrypt(ciphertext, encoded);
    ofstream dt("decipherText.txt");
    dt << deciphertext;
    dt.close();
   
    return 0;
}