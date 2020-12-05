#include<stdio.h>
#include<stdbool.h>
/* 将字符变成数字则是 数字加上‘0’*/
#define N 13
bool valid(char ch[]){
	bool valid = false;
	int i,num;
	
	for(i=0; i<N; i++){
		if(i==1 || i==5 || i==11){
			if(ch[i]!='-'){
				break;
			}
		}
		else if(i==N-1){
			num = ch[i];
			if(num<48 || num>57 && num!=88){
				break;
			}
		} 
		else{
			num = ch[i];
			if(num<48 || num>57){
				break;
			}
		}
	}
	
	if(i==N){
		valid = true;
	}
	return valid;
	
}

int main()
{
    char ch[N]={0};
    int sum,i;
    
    while(scanf("%s",ch)!=EOF && valid(ch))
    {
        i=0;
        sum=0;
        sum=sum+(ch[i]-'0');
        for(i=2;i<5;i++)
        {
            sum=sum+((ch[i]-'0')*i);
        }
        for(i=6;i<11;i++)
        {
            sum=sum+((ch[i]-'0')*(i-1));
        }
        sum=sum%11;
        if(sum==10)
        {
            if(ch[12]=='X')
                printf("Right\n");
            else{
                    ch[12]='X';
            printf("%s\n",ch) ;
             }
        }
       else if(sum==(ch[12]-'0'))
        printf("Right\n");
        else
        {
            ch[12]=(char)(sum+'0');
            printf("%s\n",ch);
 
        }
    }return 0;
}

