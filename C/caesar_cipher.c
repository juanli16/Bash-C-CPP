#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	//Declare and allocated arrays with 100 buffer size
	char original[100], encrypted[100], decrypted[100];
	int key,i,len,letter; //i for indexing, len for length of array, letter for temporary storage of char[i]

	printf("Sentence: ");
	scanf("%[^\n]s", original); //Fetch sentence with white space
	printf("Key: ");
	scanf("%d", &key);	//Fetch keys
	
	printf("Original message: %s\n",original);
	
	//Verify if the key is in the accepted range, if not, print out error message and exit the funciton. 
	if (key<1 || key>25){
		printf("The key should be between 1 and 25.\n");
		exit(1);
	}

	//Store the length of the array to len by calling strlen function in string library
	len=strlen(original);
	int a='a';	//store the interger value of letter a
	int A='A';  //store the interger value of letter A

	//For loop to encrypt the message
	for(i=0;i<len;i++){
		letter=original[i];	
		if (letter>=A && letter<='Z')				//Verify if the letter is capitalized
		{	
			encrypted[i]=original[i]-A;				//convert capitalized letter to numerical values between 0 to 26
			encrypted[i]=(encrypted[i]+26-key)%26;	//left shit letter by key
			encrypted[i]=encrypted[i]+A;				//Store the encrypted letter to encrypted array
		}else if(letter>=a && letter <='z')			//verify if the letter is not capitalized
		{
			encrypted[i]=original[i]-a;				//Same procedure as above but for the not capitalized case
			encrypted[i]=(encrypted[i]+26-key)%26;
			encrypted[i]=encrypted[i]+a;
		}else if(letter==' ')						//Special case for empty space, we do not need to encrypt it.
		{
			encrypted[i]=letter;
			
		}else										//If we encounter a char that is neither a alphabet or a white space, return an errro message.
		{
			printf("Invalid input: %c\n",original[i]);
		}
		
	}
	encrypted[i]='\0';								//Add a null character at the end of the array to preventing printing irrelevant stuffs.
	printf("Encrypted message: %s\n",encrypted);	//Print the result
	

	//For loop to decrypt the message. Same procedue as above but reverse the math operation for shifting.
	for(i=0;i<len;i++){
		letter=encrypted[i];
		if (letter>=A && letter<='Z'){
			decrypted[i]=encrypted[i]-A;
			decrypted[i]=(decrypted[i]+key)%26;
			decrypted[i]=decrypted[i]+A;
		}else if(letter>=a && letter <='z'){
			decrypted[i]=encrypted[i]-a;
			decrypted[i]=(decrypted[i]+key)%26;
			decrypted[i]=decrypted[i]+a;
		}else if(letter==' '){
			decrypted[i]=letter;
			
		}
	}	
	decrypted[i]='\0';								//Add a null character at the end of the array to preventing printing irrelevant stuffs.
	printf("Decrypted message: %s\n",decrypted);	//Print out the decrypted message.

	//Verify if the orignal message is the same as the decrypted message:
	for(i=0;i<len;i++){
		if(original[i]!=decrypted[i]){
			printf("Decrypted message is not the same as the original message for char: %c and %c at index: %d\n",original[i],decrypted[i],i);
			exit(2);
		}
	}
	return 0;
}
