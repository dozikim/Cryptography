#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 5
char matrix [SIZE] [SIZE];
void prepareMatrix(char *key){
	int used[26] = {0};
	used['J'-'A']=1;
	
	int index = 0;
	for(int i=0; key[i]!='\0';i++){
		char ch= toupper(key[i]);
		if (!used[ch - 'A']&& isalpha(ch)){
			matrix[index/SIZE][index%SIZE]=ch;
			used[ch-'A']=1;
			
			printf("Added %c to the matrix at position(%d,%d)\n",ch,index/SIZE, index%SIZE);
			index++;
		}
	}
	for(char ch='A'; ch<='Z';ch++){
		if(!used[ch-'A']){
			matrix[index/SIZE] [index%SIZE]=ch;
			used[ch-'A']=1;
			printf("Added %c to the matrix at position (%d,%d)\n",ch,index/SIZE,index%SIZE);
			index++;
			
		}
	}
}
void displayMatrix(){
	printf("Playfair Ciper Matrix:\n");
	for(int i=0; i<SIZE;i++){
		for(int j=0; j<SIZE;j++){
			printf("%c",matrix[i][j]);
		}
		printf("\n");
	}
}

void findPosition(char ch, int *row,int *col){
	if(ch=='J')ch='I';
	for(int i=0;i<SIZE;i++){
		for( int j=0; j<SIZE;j++){
			if (matrix[i][j]==ch){
				*row=i;
				*col=j;
				printf("Character %c found at position (%d,%d)\n",ch,i,j);
				return;
			}
		}	
	}
	printf("Character %c not found in thje matrix \n",ch);
}

void decryptPlayfair(char *ciphertext ,char *plaintext){
	int len=strlen(ciphertext);
	int isOdd=len%2;
	if (isOdd){
		ciphertext[len]='x';
		ciphertext[len+1]='\0';
		len++;
	}
	printf("Decrypting Ciphertexxt: %s \n", ciphertext);
	for (int i=0;i<len; i+=2){
		char a= toupper(ciphertext[i]);
		char b= toupper(ciphertext[i+1]);
		int row1,col1,row2,col2;
		findPosition(a, &row1, &col1);
		findPosition(b, &row2, &col2);
		printf("Processing pair: %c %c(Position:[%d,%d] and [%d,%d])\n",a,b,row1,col1,row2,col2);
		
		
	if (row1==row2){
		plaintext[i]=matrix[row1] [(col1-1+SIZE)%SIZE];
		plaintext[i+1]=matrix[row2] [(col2-1+SIZE)%SIZE];
		printf("Same Row->%c%c\n",plaintext[i] ,plaintext[i+1]);
	}else if (col1==col2){
		plaintext[i]=matrix[(row1-1+SIZE)%SIZE] [col1];
		plaintext[i+1]=matrix[(row2-1+SIZE)%SIZE] [col2];
		printf("Same Column->%c%c\n",plaintext[i],plaintext[i+1]);
	}else {
		plaintext[i]=matrix[row1][col2];
		plaintext[i+1]=matrix[row2][col1];
		printf("Rectangle Swap -> %c%c\n",plaintext[i],plaintext[i+1]);
	}
	}
	plaintext[len]='\0';
	printf("Decrypted Plaintext:%s\n",plaintext);
	
}
int main(){
	char key[]="Parul";
	char ciphertext[100]; char plaintext[100];
	printf("Enter the ciphertext:");
	scanf("%s",ciphertext);
	prepareMatrix(key);
	displayMatrix();
	decryptPlayfair(ciphertext, plaintext);
	printf("Decrypted plaintext:%s\n", plaintext);
	return 0;
}


