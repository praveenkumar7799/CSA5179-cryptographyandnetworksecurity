#include<stdio.h>
int main(){
	char cipher_text[100];
	int r1=0,c1=0,r2=0,c2=0;
	char str[200];
	char letter[100]="abcdefghiklmnopqrstuvwxyz",arr[100][100];
	int m=0;
	char input[100],input_key[100][100];
	int lenght;
	scanf("%s",&str);
	printf("%s\n", strcat(str,letter));
	printf("Enter a plain text :");
	scanf("%s",&input);
	int n=0;
	
	
	if(strlen(input)%2==0){
		lenght=strlen(input)/2;
	}
	else{
		lenght=(strlen(input)/2)+1;
	}
	
	for(int i=0;i<lenght;i++){
		for(int j=0;j<2;j++){
			input_key[i][j]=input[n];
			n++;
			
		}	
	}
	
	if(strlen(input)%2!=0){
		input_key[lenght-1][1]='x';
	}
	
	
	
	for(int i = 0; i < strlen(str); i++)
  	{
  		for(int j = i + 1; str[j] != '\0'; j++)
  		{
  			if(str[j] == str[i])  
			{
  				for(int k = j; str[k] != '\0'; k++)
				{
					str[k] = str[k + 1];
				}
 			}
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			arr[i][j]=str[m];
			m++;
		}
	}
	printf("The Key matrix is :\n");
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			printf("%c  ",arr[i][j]);
		}
		printf("\n");
		
	}
	
	
	printf("Your Plain text is : %s\n\n",input);
	
	printf("%s\n",input_key);
	for (int k1 = 0; k1 < strlen(input); k1++) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (arr[i][j] == input[k1]) {
                    r1 = i;
                    c1 = j;
                    printf("%d  %d",r1,c1);
                } else if (arr[i][j] == input[k1 + 1]) {
                    r2 = i;
                    c2 = j;
                }
            }
        }
 
        if (r1 == r2) {
            cipher_text[k1] = arr[r1][(c1 + 1) % 5];
            cipher_text[k1 + 1] = arr[r1][(c2 + 1) % 5];
        }
 
        else if (c1 == c2) {
            cipher_text[k1] = arr[(r1 + 1) % 5][c1];
            cipher_text[k1 + 1] = arr[(r2 + 1) % 5][c1];
        } else {
            cipher_text[k1] = arr[r1][c2];
            cipher_text[k1 + 1] = arr[r2][c1];
        }
 
        k1 = k1 + 1;
    }	
	printf("/nCipher text : %s",cipher_text);
}
			