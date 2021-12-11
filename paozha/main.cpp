# include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	int i,j,len;
    char str[20]; 
    printf("ÇëÊäÈë×Ö·û´®£º");
	scanf("%s",str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(isalpha(str[i]))
		{
			for(j=len;j>i+1;j--)str[j]=str[j-1];
			len++;
			str[i+1]='@';
		}
	}
	puts(str);
    return 0;
}