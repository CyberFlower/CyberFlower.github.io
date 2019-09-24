#include<bits/stdc++.h>
int main(void)
{
	while(1)
	{
		char name[105]={0,}; char ch;
		printf("File Name : ");
		if(scanf("%s", name) == EOF) break;
		FILE *in = fopen(name, "r");
		int len=strlen(name);
		for(int i=len+1;i>=2;i--) name[i]=name[i-2];
		name[len+2]='\0', name[0]='m', name[1]='_';
		FILE *out = fopen(name, "w");
		while(fscanf(in, "%c", &ch) != EOF)
		{
			if(ch == '\t') fprintf(out,"  ");
			else fprintf(out,"%c",ch);
		}
		printf("Succes\n");
	}
	return 0;
}
