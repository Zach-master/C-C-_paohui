#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Save(char na[],char id[]){
    FILE *s;
    s = fopen("Birth.txt", "a");
    fprintf(s,"%s ����: %c%c%c%c��%c%c��%c%c��\n",na,id[6],id[7],id[8],id[9],id[10],id[11],id[12],id[13]);
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
        printf("����: %s\n���֤��: %s\n��������: %c%c%c%c��%c%c��%c%c��\n\n",na,id,id[6],id[7],id[8],id[9],id[10],id[11],id[12],id[13]);
        Save(na,id);
    }
    fclose(r);
}

int main()
{
    Openfile();
    printf("������Ϣ�ѱ��浽Birth.txt�ĵ�");
    system("pause");
    return 0;
}

