#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Save(char na[],char id[]){
    FILE *s;
    s = fopen("Birth.txt", "a");
    fprintf(s,"%s 生日: %c%c%c%c年%c%c月%c%c日\n",na,id[6],id[7],id[8],id[9],id[10],id[11],id[12],id[13]);
    fclose(s);
}

void Openfile ( )
{
    char na[10],id[19];
    int t, s;
    FILE *r;
    if ( ( r = fopen ("ID.txt", "r" ) ) == NULL ) {
		printf("can't open the file!!!\n");
		return ;
    }
    while ( fscanf ( r, "%s%s", na, id) != EOF ) { 
        printf("姓名: %s\n身份证号: %s\n出生日期: %c%c%c%c年%c%c月%c%c日\n\n",na,id,id[6],id[7],id[8],id[9],id[10],id[11],id[12],id[13]);
        Save(na,id);
    }
    fclose(r);
}

int main()
{
    Openfile();
    printf("生日信息已保存到Birth.txt文档");
    system("pause");
    return 0;
}

