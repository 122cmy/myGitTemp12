#include<iostream>
using namespace std;
int color[100];
bool isOk(int k,int c[][100])
{
    int i,j;
    for(i=1;i<k;i++)
        if(c[k][i]==1&&color[i]==color[k])
            return false;
        return true;
}

void graphcolor(int n,int m,int c[][100])
{
    int i;
    int k=1;
    int flag=false;
    for(i=1;i<=n;i++)
        color[i]=0;
    while(k>=1)
    {
        color[k]=color[k]+1;
        while(color[k]<=m)
            if(isOk(k,c)) 
			   break;
            else 
			   color[k]=color[k]+1;
        if(color[k]<=m&&k==n){
            for(i=1;i<=n;i++)
                cout<<color[i]<<" ";
            cout<<endl;
            flag=true;
        }
        else if(color[k]<=m&&k<n)
            k=k+1;   
        else{
            color[k]=0;
            k=k-1;
        }
    }
    if(flag==false){
    	cout<<"N0"<<endl;
	}
}


int main()
{
    int i,j,n,m;
    int c[100][100];
    cout<<"���붥����n����ɫ��m:"<<endl;
    cin>>n>>m;
    cout<<"��������ͼ���ڽӾ���:"<<endl;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>c[i][j];
    cout<<"���п��ܵĽ�:"<<endl;
    graphcolor(n,m,c);
}

 
