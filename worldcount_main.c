#include<stdio.h>
#include<stdlib.h>
#include<String.h>
//�������
/*
*���е�ʱ����������Ŀ�ļ������ҵ�/Debug�ļ��У���cmd�ڴ�Ŀ¼�£�ִ�и��ļ��µ�WordCount.exe��
*WordCount.exe  -[c][w] [�ļ�ȫ·��]  
 */
int main(int   argc,   char*   argv[])
{
	int i=0;
	char model=NULL;
	char *addr;
	FILE* f;
	int count=0;//ͳ�ƽ��
	char buf[1024]={0};
	for(i=0;i<argc;i++)
		{
			if(i==1)
			{
				if(strcmp(argv[i],"-c")==0||strcmp(argv[i],"-C")==0)
					{
						model='c';
					}
				else if(strcmp(argv[i],"-w")==0||strcmp(argv[i],"-W")==0)
					{	
						model='w';
					}
				else
					{
					}
			}
			if(i==2)
				{
				addr=argv[i];
				}
				
		}

	//get_statisticnum(model,*addr);
	
	printf("model=%c\taddr=%s\n",model,addr);
	if((f=fopen(addr,"r"))==NULL) //�����������ļ�
		{
           printf("û������ļ�.......");
           exit(0); //�ر������ļ�����ֹ����ִ�еĳ���
		}
	else//
	{
		
		//��ѡ��������ļ��е��ַ�������
		if (model=='c')
			{
				int len=0;
				int i=0;
				while(fgets(buf,1024,f) != '\0')
					{
						len=strlen(buf);
					    i=0;
						while(i<len)
							{
								//putchar(buf[i]);
//�ҳ�Ӣ����ĸ
	if((buf[i]>='a'&&buf[i]<='z')||(buf[i]>='A'&&buf[i]<='Z'))
									{
										count+=1;//ͳ����ĸ��Ŀ��1
									}
								i++;
							}
					}
		printf("�� %d ��Ӣ���ַ�\n",count );
		printf("--------------------------------------------\n");
			}
		//��ѡ��������ļ��еĵ��ʵĸ���
		else if(model=='w')
			{
				int len=0;
				int i=0;
				while(fgets(buf,1024,f) != '\0')
					{
						len=strlen(buf);
					    i=0;
						while(i<len)
							{
								//putchar(buf[i]);
								if(buf[i]==' '||(buf[i])==',')
									{
										if(buf[i-1]!=buf[i])//�����ж���ո�ķ������ж���ո�ֻ����һ���ָ���
											{
													//printf("char=%c\ti=%d\n",buf[i],i);
													count+=1;//ͳ�Ƶ�����Ŀ��1
											}
											
									}
								else if((buf[i]>='a'&&buf[i]<='z')||(buf[i]>='A'&&buf[i]<='Z'))
									{
									 
									}
								i++;
							}
					}
				printf("�� %d ������\n",count );
				printf("--------------------------------------------\n");
			}
		else
			{
			printf("����ѡ���ȡģʽ����");
			}
	}

	fclose(f);
	
	return 0;
}