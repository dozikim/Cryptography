#include<stdio.h>
#include<string.h>

void caesar_encrypt(char* plaintext, int key, char* ciphertext){
	int i;
	for(i=0;plaintext[i]!='\0';i++){
		char ch = plaintext[i];
		if(ch>='A' && ch<='Z'){
			ciphertext[i]=((ch-'A'+key)%26)+'A';
			printf("Encrypting : plaintext[%d] = %c, ciphertext[%d] = %c\n",i,ch,i,ciphertext[i]);
		}
		else{
			ciphertext[i]=ch;
		}
	}
	ciphertext[i]='\0';
}

void caesar_decrypt(char* ciphertext, int key, char* decrypt_text){
	int i;
	for(i=0;ciphertext[i]!='\0';i++){
		char ch = ciphertext[i];
		if(ch>='A' && ch<='Z'){
			decrypt_text[i]=((ch-'A'-key+26)%26)+'A';
			printf("Decrypting : ciphertext[%d] = %c, decrypt_text[%d] = %c\n",i,ch,i,decrypt_text[i]);
		}
		else{
			decrypt_text[i]=ch;
		}
	}
	decrypt_text[i]='\0';
}

void brute_force_attack(char* ciphertext){
	char decrypted_text[100];
	int key;
	for(key=0;key<26;key++){
		caesar_decrypt(ciphertext,key,decrypted_text);
		printf("Key %d : %s\n",key,decrypted_text);
	}
}

int main(){
	char plaintext[100], ciphertext[100], decrypted_text[100];
	int key;
	
	printf("Enter the plaintext (uppercase letters only) : ");
	fgets(plaintext,sizeof(plaintext), stdin);
	
	printf("Enter the key: ");
	scanf("%d",&key);
	
	caesar_encrypt(plaintext,key,ciphertext);
	printf("Encrypted Text : %s\n",ciphertext);
	
	printf("\nAttempting Brute-force attack.....\n");
	brute_force_attack(ciphertext);
	
	return 0;
}
