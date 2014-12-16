# include <stdio.h>
# include <string.h>
char refer[10][5][5];
char res[23][12*8+8+1];
void printmap(int size,int pos)
{
	int i,j;
	for(i=0;i<2*size+3;i++)
	  {
		  for(j=0;j<=pos;j++) printf("%c",res[i][j]);
		  printf("\n");
	  }
}
void addprint(int size,int num,int *pos)
{
	int r=0,i,flag;
	(*pos)+=size+2;
	for(i=0;i<5;i++)
	{
		int j,k,insert=*pos,det=0;
		for(j=2;j>=0;j--)
		{
			switch(refer[num][i][j])
			{
			case ' ':
				flag=1;
				for(k=i-1;k>0;k--)
					if(refer[num][k][j]=='-')
					{
						flag=0;
						break;
					}
				for(k=i+1;k<5;k++)
					if(refer[num][k][j]=='-')
					{
						flag=0;
						break;
					}
				if(!flag) insert-=size;
				else insert--;
				break;
			case '|':
				for(k=r;k<r+size;k++) res[k][insert]='|';
				insert--;
				det=1;
				break;
			case '-':
				for(k=0;k<size;k++) res[r][insert--]='-';
				det=0;
				break;
			};
		}
		if(det) r+=size;
		else r++;
	}
}
int main()
{
  strcpy(refer[0][0]," - ");
  strcpy(refer[0][1],"| |");
  strcpy(refer[0][2],"   ");
  strcpy(refer[0][3],"| |");
  strcpy(refer[0][4]," - ");

  strcpy(refer[1][0],"   ");
  strcpy(refer[1][1],"  |");
  strcpy(refer[1][2],"   ");
  strcpy(refer[1][3],"  |");
  strcpy(refer[1][4],"   ");

  strcpy(refer[2][0]," - ");
  strcpy(refer[2][1],"  |");
  strcpy(refer[2][2]," - ");
  strcpy(refer[2][3],"|  ");
  strcpy(refer[2][4]," - ");

  strcpy(refer[3][0]," - ");
  strcpy(refer[3][1],"  |");
  strcpy(refer[3][2]," - ");
  strcpy(refer[3][3],"  |");
  strcpy(refer[3][4]," - ");

  strcpy(refer[4][0],"   ");
  strcpy(refer[4][1],"| |");
  strcpy(refer[4][2]," - ");
  strcpy(refer[4][3],"  |");
  strcpy(refer[4][4],"   ");

  strcpy(refer[5][0]," - ");
  strcpy(refer[5][1],"|  ");
  strcpy(refer[5][2]," - ");
  strcpy(refer[5][3],"  |");
  strcpy(refer[5][4]," - ");

  strcpy(refer[6][0]," - ");
  strcpy(refer[6][1],"|  ");
  strcpy(refer[6][2]," - ");
  strcpy(refer[6][3],"| |");
  strcpy(refer[6][4]," - ");

  strcpy(refer[7][0]," - ");
  strcpy(refer[7][1],"  |");
  strcpy(refer[7][2],"   ");
  strcpy(refer[7][3],"  |");
  strcpy(refer[7][4],"   ");

  strcpy(refer[8][0]," - ");
  strcpy(refer[8][1],"| |");
  strcpy(refer[8][2]," - ");
  strcpy(refer[8][3],"| |");
  strcpy(refer[8][4]," - ");

  strcpy(refer[9][0]," - ");
  strcpy(refer[9][1],"| |");
  strcpy(refer[9][2]," - ");
  strcpy(refer[9][3],"  |");
  strcpy(refer[9][4]," - ");
    int tp = 0;
  while(1)
  {
	  int size,i,j,pos=-1;
	  char data[10];
	  scanf("%d %s",&size,data);
	  if(!size)
        break;
        if (tp)
         printf("\n");
         tp++;
	  memset(res,' ',sizeof(res));
	  for(i=0;i<strlen(data);i++)
	  {
		  addprint(size,data[i]-'0',&pos);
		  pos++;
	  }
	  for(i=0;i<2*size+3;i++)
	  {
		  for(j=0;j<=pos;j++) printf("%c",res[i][j]);
		  printf("\n");
	  }

  }
  return 0;
}
