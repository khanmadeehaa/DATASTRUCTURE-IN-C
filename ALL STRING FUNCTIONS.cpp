#include<stdio.h>
void length(char str[])   //char str[] is the input string
{
	int i,l=0;
	for(i=0;str[i]!='\0';i++)
	l++;
	printf("Length of string is: %d",l);
}

void reverse(char str[]){
		int i,l=0;
	for(i=0;str[i]!='\0';i++)   //start the loop from the last index
	l++;
	printf("Reversed String: ");
	for(i=l-1;i>=0;i--)
	printf("%c",str[i]);
}
void con(char str[], char strr[]){
	int i,j;
	for(i=0;str[i]!='\0';i++);    //this loop basically find the end of the first string
	for(j=0;strr[j]!='\0';j++,i++)
	{
		str[i]=strr[j];          //append charcaters of second string 
	}
	str[i]='\0';                 //we append '\0' to indicate the new end of the string
	printf(" Concatenated string: %s",str);
}
void copy(char str[],char strr[]){
	int i;
	
	for(i=0;str[i]!='\0';i++){
		strr[i]=str[i];
	}
	strr[i]='\0';
	printf("\nCopied String: %s",strr);
}

	void compare(char str[], char strr[]) {
    int i = 0, flag = 0; //flag=0->we initially assume that both the strings are equal,so flag=0 means no diff found yet
    while (str[i] != '\0' && strr[i] != '\0') {
        if (str[i] != strr[i]) {
            flag = 1;   //if any charcter does not match we set flag=1 to indicate that strings are not equal
            break;
        }
        i++;
    }
    if (flag == 0 && str[i] == '\0'&& strr[i]=='\0')  //checling both the strings ended at the same time
    printf("\nStrings are equal");
    else
    printf("\nStrings are not equal");
}

int main(){
	char str1[200];
	char str2[200];
	int c;
	printf("Enter a choice for the operation youy want to perform:");
	printf("\n1.Length \n2.Reverse \n3.Concatenate \n4.Copy \n5.Compare \n");
	scanf("%d",&c);
	getchar();   //used to consume a newline left in the buffer by scanf
	switch (c){
		case 1: printf("Enter a string:");
		scanf("%[^\n]",str1);
		length(str1);
		break;
		
		case 2: printf("Enter a string:");
		scanf("%[^\n]",str1);
		reverse(str1);
		break;
		
		case 3:  printf("Enter a string:");
		scanf("%[^\n]",str1);
		 getchar();
		 printf("Enter another string:");
		scanf("%[^\n]",str2);
		con(str1,str2);
		break;
		
		case 4: printf("Enter a string you want to copy:");
		scanf("%[^\n]",str1);
		copy(str1,str2);
		break;
		
		case 5: printf("Enter a string:");
		scanf("%[^\n]",str1);
		 getchar();
		 printf("Enter another string with which you want to compare:");
		scanf("%[^\n]",str2);
		compare(str1,str2);
		break;
		
		default: printf ("\nInvalid Option");
	}
	return 0;
}
