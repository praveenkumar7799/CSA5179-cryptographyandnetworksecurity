#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	int k=3,lenght;
	char input[lenght];
	printf("Enter input string:");
	scanf("%s",&input);
	for(int i=0;i<strlen(input);i++){
		if(islower(input[i])){
			input[i]=((input[i]-'a'+k)%26)+'a';	
		}
		else{
			input[i]=((input[i]-'A'+k)%26)+'A';	
		}
	}
	printf("Encrytption is :%s",input);
	
}