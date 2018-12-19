#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>


#define MAXVERTEXNUM 100
#define INF 65535

using namespace std;

typedef struct{
    int num;//�������
    string name;//��������
    string features;//������Ϣ
}VertexType;
typedef int EdgeType;
typedef struct{
    VertexType vexs[MAXVERTEXNUM];
    EdgeType edges[MAXVERTEXNUM][MAXVERTEXNUM];
    int numVertexes,numEdges;
}MGraph;
typedef int Pathmatrix[MAXVERTEXNUM][MAXVERTEXNUM];
typedef int ShortPathTable[MAXVERTEXNUM][MAXVERTEXNUM];

Pathmatrix P;
ShortPathTable D;

void Create(MGraph *G)//����ͼ���ڽӾ���洢�ṹ
{
    int i,j;
    G->numVertexes=12;
    for(i=1;i<=G->numVertexes;i++)
    {
            G->vexs[i].num=i;
    }
    G->vexs[1].name="�������";
    G->vexs[2].name="����������";
    G->vexs[3].name="����ѧԺ";
    G->vexs[4].name="�ٳ�";
    G->vexs[5].name="��Ϣѧ��";
    G->vexs[6].name="ͼ���";
    G->vexs[7].name="��԰����";
    G->vexs[8].name="У���Ͽ�";
    G->vexs[9].name="У�ű���";
    G->vexs[10].name="У�Ŷ���";
    G->vexs[11].name="���Ӿ���";
    G->vexs[12].name="����";


    G->vexs[1].features="��ְ����ѧ������������";
    G->vexs[2].features="�а�ѧУ��Ҫ�";
    G->vexs[3].features="��ѧԺ�칫¥";
    G->vexs[4].features="��������";
    G->vexs[5].features="��Ϣ��ѧ";
    G->vexs[6].features="����ְ����ѧ������ͼ�����ϰ";
    G->vexs[7].features="�����кɻ�ʢ��";
    G->vexs[8].features="��ѧ�����";
    G->vexs[9].features="��ѧ�����";
    G->vexs[10].features="��ѧ�����";
    G->vexs[11].features="���������Ҷ�ĺ�ȥ��";
    G->vexs[12].features="����ְ����ѧ���ò�";

    for(i=1;i<=G->numVertexes;i++)
    {
        for(j=1;j<=G->numVertexes;j++)
        {
            G->edges[i][j]=INF;
        }
    }

    G->edges[1][2]=200;
    G->edges[1][4]=350;
    G->edges[2][3]=500;
    G->edges[2][4]=480;
    G->edges[2][5]=500;
    G->edges[2][6]=400;
    G->edges[3][8]=400;
    G->edges[4][6]=280;
    G->edges[4][9]=200;
    G->edges[5][8]=400;
    G->edges[6][10]=300;
    G->edges[7][8]=500;
    G->edges[7][10]=200;
    G->edges[8][10]=600;
    G->edges[9][11]=100;
    G->edges[9][12]=100;
    G->edges[10][12]=100;
    G->edges[11][12]=100;

    for(i=1;i<=G->numVertexes;i++)
    {
        for(j=1;j<=G->numVertexes;j++)
        {
            if(G->edges[i][j]!=INF)
            {
                G->edges[j][i]=G->edges[i][j];
            }
        }
    }

    cout<<"�����ɹ�������"<<endl;
    cout<<"  �� �� �� �� �� �� �� �� �� �� ����";
    getchar();getchar();
}
VertexType GetVex(MGraph *G, int v){//���ͼ����һ�������
    cout<<"["<<G->vexs[v].name<<"]"<<"�Ľ���Ϊ:";
    cout<<G->vexs[v].features<<endl;
    cout<<"  �� �� �� �� �� �� �� �� �� �� ����";
    getchar();getchar();
}
void PutVertex(MGraph *G,int v){//�޸ľ�����Ϣ
    cout<<"�޸�ǰ��"<<endl;
    cout<<"�������ƣ�"<<G->vexs[v].name<<endl;
    cout<<"������ܣ�"<<G->vexs[v].features<<endl;
    if(v>=1&&v<=G->numVertexes)
    {
        cout<<"���������޸ĵľ�������"<<endl;
        cin>>G->vexs[v].name;
        cout<<"���������޸ĵľ������"<<endl;
        cin>>G->vexs[v].features;
        cout<<"�޸ĺ�"<<endl;
        cout<<"�������ƣ�"<<G->vexs[v].name<<endl;
        cout<<"������ܣ�"<<G->vexs[v].features<<endl;
    }
    else{
        cout<<"�����ڸþ�����ţ����޷��޸ģ���"<<endl;
    }
    cout<<"�� �� �� �� �� �� �� �� �� �� ����";
    getchar();getchar();
}

void Print(MGraph *G){//��ӡ���о���
    int i;
    for(i=1;i<=G->numVertexes;i++)
    {
        cout<<"������ţ�"<<i<<endl;
        cout<<"��["<<i<<"]�������ƣ�"<<G->vexs[i].name<<endl;
        cout<<"��["<<i<<"]������ܣ�"<<G->vexs[i].features<<endl;
    }
    cout<<"ȫ�������Ѿ���ӡ��ϣ���"<<endl;
    cout<<"  �� �� �� �� �� �� �� �� �� �� ����";
    getchar();getchar();
}


void InsertVertex(MGraph *G){//���Ӿ�����Ϣ
    G->numVertexes=G->numVertexes+1;
    cout<<"������Ҫ���ӵĵ�["<<G->numVertexes<<"]����������"<<endl;
    cin>>G->vexs[G->numVertexes].name;
    cout<<"������Ҫ���ӵĵ�["<<G->numVertexes<<"]���������"<<endl;
    cin>>G->vexs[G->numVertexes].features;
    cout<<"��Ӿ���ɹ�"<<endl;
    cout<<"  �� �� �� �� �� �� �� �� �� �� ����";
    getchar();getchar();
}
void DeleteVertex(MGraph *G){//ɾ��������Ϣ
    int n;
    int i,j;
    cout<<"��������Ҫɾ���ľ������"<<endl;
    cin>>n;
    if(n>=1&&n<G->numVertexes)
    {
        for(i=n;i<=G->numVertexes;i++)
        {
            G->vexs[i-1].name=G->vexs[i].name;
            G->vexs[i-1].features= G->vexs[i].features;
        }
        for(i=n;i<=G->numVertexes;i++)
        {
            for(j=n;j<=G->numVertexes;j++)
            {
                G->edges[i-1][j-1]=G->edges[i][j];
            }
        }
        G->numVertexes--;
        cout<<"ɾ���ɹ���"<<endl;

    }
    else if(n==G->numVertexes)
    {
        G->vexs[G->numVertexes].name="NULL";
        G->vexs[G->numVertexes].features="NULL";
        for(i=1;i<=G->numVertexes;i++)
        {
            for(j=1;j<=G->numVertexes;j++)
            {
                if(i==G->numVertexes||j==G->numVertexes){
                    G->edges[i][j]=INF;
                }

            }
        }

        (G->numVertexes)--;
        cout<<"ɾ���ɹ���"<<endl;
    }
    else
    {
        cout<<"�����ڸþ���!!!"<<endl;
    }
    cout<<"  �� �� �� �� �� �� �� �� �� �� ����";
    getchar();getchar();
}
void InsertArc(MGraph *G,int v, int w){//���ӵ�·
    int weight;
    cout<<"������"<<v<<"->"<<w<<"�ĵ�·����"<<endl;
    cin>>weight;
    if(G->edges[v][w]==INF)
    {
        G->edges[v][w]=weight;
        cout<<"���Ӻ�"<<v<<"->"<<w<<"�ĵ�·���ȣ�  "<<G->edges[v][w]<<endl;
    }
    else
         cout<<"��������Ѿ����ڵ�·�������������ӣ���"<<endl;
    cout<<"  �� �� �� �� �� �� �� �� �� �� ����";
    getchar();getchar();

}
void DeleteArc(MGraph*G ,int v,int w){//ɾ����·
    cout<<"ɾ��ǰ"<<v<<"->"<<w<<"�ĳ���Ϊ��  "<<G->edges[v][w]<<endl;
    if(G->edges[v][w]!=INF)
    {
        G->edges[v][w]=INF;
        cout<<"ɾ���ɹ�"<<endl;
        cout<<"ɾ����"<<v<<"->"<<w<<"����Ϊ��  "<<G->edges[v][w]<<endl;
    }
    else
        cout<<"������䲻���ڵ�·�������޷�ɾ������"<<endl;
    cout<<"  �� �� �� �� �� �� �� �� �� �� ����";
    getchar();getchar();


}
void ShortestPath_Floyd(MGraph *G,Pathmatrix *P,ShortPathTable *D)
{//����ĳһ���㵽������������·��
    int startp;
    cout<<"���������"<<endl;
    cin>>startp;
    int v,w,k;
    for(v=1;v<=G->numVertexes;v++)
    {
        for(w=1;w<=G->numVertexes;w++)
        {
            (*D)[v][w]=G->edges[v][w];
            (*P)[v][w]=w;
        }
    }
    for(k=1;k<=G->numVertexes;++k)
    {
        for(v=1;v<=G->numVertexes;v++)
        {
            for(w=1;w<=G->numVertexes;w++)
            {
                if((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
                {
                    (*D)[v][w]=(*D)[v][k]+(*D)[k][w];
                    (*P)[v][w]=(*P)[v][k];
                }
            }
        }
    }

    for(v=1;v<=G->numVertexes;++v)
    {
        for(w=1;w<=G->numVertexes;w++)
        {   if(v==startp&&w!=startp)
            {
                cout<<"v"<<v<<"-v"<<w<<"  weight:"<<(*D)[v][w];
                k=(*P)[v][w];
                cout<<" path: "<<v;
                while(k!=w)
                {
                    cout<<" -> "<<k;
                    k=(*P)[k][w];
                }
                cout<<" -> "<<w<<endl;
            }
        }

    }
    cout<<"  �� �� �� �� �� �� �� �� �� �� ����";
    getchar();getchar();
}


void ToDestination(MGraph *G,Pathmatrix *P,ShortPathTable *D){
    //������һ��������֮������·��
    int startp,endp;
    cout<<"���������"<<endl;
    cin>>startp;
    cout<<"�������յ�"<<endl;
    cin>>endp;
    int v,w,k;
    for(v=1;v<=G->numVertexes;v++)
    {
        for(w=1;w<=G->numVertexes;w++)
        {
            (*D)[v][w]=G->edges[v][w];
            (*P)[v][w]=w;
        }
    }
    for(k=1;k<=G->numVertexes;++k)
    {
        for(v=1;v<=G->numVertexes;v++)
        {
            for(w=1;w<=G->numVertexes;w++)
            {
                if((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
                {
                    (*D)[v][w]=(*D)[v][k]+(*D)[k][w];
                    (*P)[v][w]=(*P)[v][k];
                }
            }
        }
    }

    for(v=1;v<=G->numVertexes;++v)
    {
        for(w=1;w<=G->numVertexes;w++)
        {
            if(v==startp&&w==endp&&w!=startp)
            {
                cout<<"v"<<v<<"-v"<<w<<"  weight:"<<(*D)[v][w];
                k=(*P)[v][w];
                cout<<" path: "<<v;
                while(k!=w)
                {
                    cout<<" -> "<<k;
                    k=(*P)[k][w];
                }
                cout<<" -> "<<w<<endl;
            }
        }
        //cout<<endl;
    }
    cout<<"  �� �� �� �� �� �� �� �� �� �� ����";
    getchar();getchar();

}
int Menu(){
    int command;

    cout<<"================Menu==============="<<endl;
    cout<<"   �밴�����ѡ������Ҫʵ�ֵĹ���  "<<endl;
    cout<<"           0.�˳�ϵͳ              "<<endl;
    cout<<"           1.����Ա��¼            "<<endl;
    cout<<"           2.�ο͵�¼              "<<endl;
    cout<<"=============���������============"<<endl;
    cout<<"=============������ʾ��============"<<endl;
    cout<<"=����Ա���ο͵��˺ż����붼Ϊ��0��="<<endl;
    while(cin>>command,command<0||command>2)
    {
        cout<<"��������ȷ����ţ���"<<endl;
        cout<<"���������룡��"<<endl;
    }

    return command;
}
int display1(){
    int command;
    cout<<"=======================����Ա����======================="<<endl;
    cout<<"                       0.�������˵�                     "<<endl;
    cout<<"               1.����ͼ���ڽӾ���洢�ṹ               "<<endl;
    cout<<"                  2.���ͼ����һ�������                "<<endl;
    cout<<"                    3.�޸ľ�����Ϣ                      "<<endl;
    cout<<"                    4.���Ӿ�����Ϣ                      "<<endl;
    cout<<"                    5.ɾ��������Ϣ                      "<<endl;
    cout<<"                      6.���ӵ�·                        "<<endl;
    cout<<"                      7.ɾ����·                        "<<endl;
    cout<<"           8.����ĳһ���㵽������������·��           "<<endl;
    cout<<"            9.������һ��������֮������·��            "<<endl;
    cout<<"                     10.��ӡȫ������                    "<<endl;
    cout<<"===================����������Ҫѡ��Ĺ���==============="<<endl;
    cout<<"========================������ʾ��======================"<<endl;
    cout<<"ʹ���κι���֮ǰ������ѡ��1������ͼ����Ȼ�����޷�����ʹ��"<<endl;
    while(cin>>command,command<0||command>10)
    {
        cout<<"��������ȷ����ţ���"<<endl;
        cout<<"���������룡��"<<endl;
    }
    return command;
}
int display2(){
    int command;
    cout<<"=========================�οͽ���========================"<<endl;
    cout<<"                       0.�������˵�                      "<<endl;
    cout<<"               1.����ͼ���ڽӾ���洢�ṹ                "<<endl;
    cout<<"                  2.���ͼ�����⾰�����                 "<<endl;
    cout<<"           3.����ĳһ���㵽������������·��            "<<endl;
    cout<<"            4.������һ��������֮������·��             "<<endl;
    cout<<"                      5.��ӡȫ������                     "<<endl;
    cout<<"=========================������ʾ��======================"<<endl;
    cout<<"ʹ���κι���֮ǰ������ѡ��1������ͼ����Ȼ�����޷�����ʹ��"<<endl;
    while(cin>>command,command<0||command>5)
    {
        cout<<"��������ȷ����ţ���"<<endl;
        cout<<"���������룡��"<<endl;
    }
    return command;
}
int main(){
    MGraph G;
    Pathmatrix P;
    ShortPathTable D;

    int command,t1,t2;
    string user,pw;
    int v,w;

    while(1)
    {
        command=Menu();
        if(command==1)
        {
            while(1)
            {
                cout<<"�������˺�"<<endl;
                cin>>user;
                cout<<"����������"<<endl;
                cin>>pw;
                if(user=="0"&&pw=="0") break;
                else cout<<"�˺Ż������������������!"<<endl;
            }
            system("cls");
            t1=0;
            while(t1==0)
            {
                command=display1();
                switch(command)
                {
                    case 0:t1=1;break;
                    case 1://����ͼ���ڽӾ���洢�ṹ
                            Create(&G);
                            system("cls");
                            break;
                    case 2://���ͼ����һ�������
                            cout<<"������Ҫ��ѯ�ľ������"<<endl;
                            cin>>v;
                            GetVex(&G,v);
                            system("cls");
                            break;
                    case 3://�޸ľ�����Ϣ
                            cout<<"������Ҫ�޸ĵľ������"<<endl;
                            cin>>v;
                            PutVertex(&G,v);
                            system("cls");
                            break;
                    case 4://���Ӿ�����Ϣ
                            InsertVertex(&G);
                            system("cls");
                            break;
                    case 5://ɾ��������Ϣ
                            DeleteVertex(&G);
                            system("cls");
                            break;
                    case 6://���ӵ�·
                            cout<<"�����������ӵ�·�����"<<endl;
                            cin>>v;
                            cout<<"�����������ӵ�·���յ�"<<endl;
                            cin>>w;
                            InsertArc(&G,v,w);
                            system("cls");
                            break;
                    case 7://ɾ����·
                            cout<<"��������ɾ����·�����"<<endl;
                            cin>>v;
                            cout<<"��������ɾ����·���յ�"<<endl;
                            cin>>w;
                            DeleteArc(&G,v,w);
                            system("cls");
                            break;
                    case 8://����ĳһ���㵽������������·��
                            ShortestPath_Floyd(&G,&P,&D);
                            system("cls");
                            break;
                    case 9://������һ��������֮������·��
                            ToDestination(&G,&P,&D);
                            system("cls");
                            break;
                    case 10://��ӡȫ������
                            Print(&G);
                            system("cls");
                            break;
                }
            }
        }
        else if(command==2)
            {
                while(1)
                {
                    cout<<"�������˺ţ�"<<endl;
                    cin>>user;
                    cout<<"���������룺"<<endl;
                    cin>>pw;
                    if(user=="0"&&pw=="0") break;
                    else cout<<"�˺Ż�����������������룡"<<endl;
                }
                system("cls");
                t2=0;
                while(t2==0)
                {
                    command=display2();
                    switch(command)
                    {
                        case 0:t2=1;break;
                        case 1://����ͼ���ڽӾ���洢�ṹ
                              Create(&G);
                              system("cls");
                              break;
                        case 2://���ͼ����һ�������
                              cout<<"������Ҫ��ѯ�ľ���"<<endl;
                              cin>>v;
                              GetVex(&G,v);
                              system("cls");
                              break;
                        case 3://����ĳһ���㵽������������·��
                              ShortestPath_Floyd(&G,&P,&D);
                              system("cls");
                              break;
                        case 4://������һ��������֮������·��
                              ToDestination(&G,&P,&D);
                              system("cls");
                              break;
                        case 5://��ӡȫ������
                            Print(&G);
                            system("cls");
                            break;
                    }
                }
            }
        else
             break;
    }




}
