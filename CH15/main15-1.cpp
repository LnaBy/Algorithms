#include <iostream>

using namespace std;
//��������ֵ
int fastWay(int a[2][6],int t[2][5],int e[2][2],int f[2][6],int L1[6],int L2[6],int n,int *Tag){
     int temp1,temp2;
     f[0][0]=e[0][0]+a[0][0];
     f[1][0]=e[1][0]+a[1][0];
     for(int i=1;i<n;i++){
        //��һ��
        temp1=f[0][i-1]+a[0][i];
        temp2=f[1][i-1]+a[0][i]+t[1][i-1];

        if(temp1>=temp2){
            f[0][i]=temp2;
            L1[i]=2;
        }else{
            f[0][i]=temp1;
            L1[i]=1;
        }
        //�ڶ���
        temp1=f[1][i-1]+a[1][i];
        temp2=f[0][i-1]+a[1][i]+t[0][i-1];
        if(temp1>=temp2){
            f[1][i]=temp2;
            L2[i]=1;
        }else{
            f[1][i]=temp1;
            L2[i]=2;
        }
    }
        //���һ��
        temp1=f[0][n-1]+e[0][1];
        temp2=f[1][n-1]+e[1][1];
        if(temp1>=temp2){
            *Tag=2;
            return temp2;

        }else{
            *Tag=1;
            return temp1;
        }

}
//��ӡװ��վ
void Print(int L1[6],int L2[6],int n,int *Tag){
    if(*Tag==1){
        for(int i=1;i<n;i++){
            if(L1[i]==1){
                cout<<"Line 1"<<"; station "<<i<<endl;
            }else{
                cout<<"Line 2"<<"; station "<<i<<endl;
            }
        }
        cout<<"Line 1"<<"; station "<<n<<endl;

    }else{
        for(int i=1;i<n;i++){
            if(L2[i]==1){
                cout<<"Line 1"<<"; station "<<i<<endl;
            }else{
                cout<<"Line 2"<<"; station "<<i<<endl;
            }
        }
        cout<<"Line 2"<<"; station "<<n<<endl;

    }

}
//�������Ž�
int main()
{
   int a[2][6]={{7,9,3,4,8,4},{8,5,6,4,5,7}};//װ����1��2վ������ʱ��
    int t[2][5]={{2,3,1,3,4},{2,1,2,2,1}};//��1װ����ת��2�ߺ�2��ת��1�������ʱ��
    int e[2][2]={{2,3},{4,2}};//�˵����˳�1��2������ʱ��
    int f[2][6]={{},{}};
    int L1[6]={0};//��¼ÿ�μӹ���վ��
    int L2[6]={0};
    int Tag=0;//��־������������
    int min=0;
    int n=6;
    min =fastWay(a,t,e,f,L1,L2,n,&Tag);
    cout<<"Tag"<<Tag<<endl;
    cout<<"װ��������ֵ��"<<min<<endl;
    Print(L1,L2,n,&Tag);
    return 0;
}
