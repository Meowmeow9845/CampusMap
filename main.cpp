#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>


#define MAXVERTEXNUM 100
#define INF 65535

using namespace std;

typedef struct{
    int num;//景点序号
    string name;//景点名称
    string features;//顶点信息
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

void Create(MGraph *G)//创建图的邻接矩阵存储结构
{
    int i,j;
    G->numVertexes=12;
    for(i=1;i<=G->numVertexes;i++)
    {
            G->vexs[i].num=i;
    }
    G->vexs[1].name="体检中心";
    G->vexs[2].name="邯郸音乐厅";
    G->vexs[3].name="网计学院";
    G->vexs[4].name="操场";
    G->vexs[5].name="信息学部";
    G->vexs[6].name="图书馆";
    G->vexs[7].name="花园景观";
    G->vexs[8].name="校门南口";
    G->vexs[9].name="校门北口";
    G->vexs[10].name="校门东口";
    G->vexs[11].name="银杏景观";
    G->vexs[12].name="餐厅";


    G->vexs[1].features="教职工和学生定期身体检查";
    G->vexs[2].features="承办学校重要活动";
    G->vexs[3].features="本学院办公楼";
    G->vexs[4].features="放松休闲";
    G->vexs[5].features="信息教学";
    G->vexs[6].features="供教职工和学生借阅图书和自习";
    G->vexs[7].features="夏天有荷花盛开";
    G->vexs[8].features="教学区入口";
    G->vexs[9].features="教学区入口";
    G->vexs[10].features="教学区入口";
    G->vexs[11].features="秋天观赏落叶的好去处";
    G->vexs[12].features="供教职工和学生用餐";

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

    cout<<"创建成功！！！"<<endl;
    cout<<"  返 回 上 级 菜 单 请 按 回 车 键：";
    getchar();getchar();
}
VertexType GetVex(MGraph *G, int v){//浏览图中任一景点介绍
    cout<<"["<<G->vexs[v].name<<"]"<<"的介绍为:";
    cout<<G->vexs[v].features<<endl;
    cout<<"  返 回 上 级 菜 单 请 按 回 车 键：";
    getchar();getchar();
}
void PutVertex(MGraph *G,int v){//修改景点信息
    cout<<"修改前："<<endl;
    cout<<"景点名称："<<G->vexs[v].name<<endl;
    cout<<"景点介绍："<<G->vexs[v].features<<endl;
    if(v>=1&&v<=G->numVertexes)
    {
        cout<<"请输入拟修改的景点名称"<<endl;
        cin>>G->vexs[v].name;
        cout<<"请输入拟修改的景点介绍"<<endl;
        cin>>G->vexs[v].features;
        cout<<"修改后："<<endl;
        cout<<"景点名称："<<G->vexs[v].name<<endl;
        cout<<"景点介绍："<<G->vexs[v].features<<endl;
    }
    else{
        cout<<"不存在该景点序号！！无法修改！！"<<endl;
    }
    cout<<"返 回 上 级 菜 单 请 按 回 车 键：";
    getchar();getchar();
}

void Print(MGraph *G){//打印所有景点
    int i;
    for(i=1;i<=G->numVertexes;i++)
    {
        cout<<"景点序号："<<i<<endl;
        cout<<"第["<<i<<"]景点名称："<<G->vexs[i].name<<endl;
        cout<<"第["<<i<<"]景点介绍："<<G->vexs[i].features<<endl;
    }
    cout<<"全部景点已经打印完毕！！"<<endl;
    cout<<"  返 回 上 级 菜 单 请 按 回 车 键：";
    getchar();getchar();
}


void InsertVertex(MGraph *G){//增加景点信息
    G->numVertexes=G->numVertexes+1;
    cout<<"请输入要增加的第["<<G->numVertexes<<"]个景点名称"<<endl;
    cin>>G->vexs[G->numVertexes].name;
    cout<<"请输入要增加的第["<<G->numVertexes<<"]个景点介绍"<<endl;
    cin>>G->vexs[G->numVertexes].features;
    cout<<"添加景点成功"<<endl;
    cout<<"  返 回 上 级 菜 单 请 按 回 车 键：";
    getchar();getchar();
}
void DeleteVertex(MGraph *G){//删除景点信息
    int n;
    int i,j;
    cout<<"请输入你要删除的景点序号"<<endl;
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
        cout<<"删除成功！"<<endl;

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
        cout<<"删除成功！"<<endl;
    }
    else
    {
        cout<<"不存在该景点!!!"<<endl;
    }
    cout<<"  返 回 上 级 菜 单 请 按 回 车 键：";
    getchar();getchar();
}
void InsertArc(MGraph *G,int v, int w){//增加道路
    int weight;
    cout<<"请输入"<<v<<"->"<<w<<"的道路长度"<<endl;
    cin>>weight;
    if(G->edges[v][w]==INF)
    {
        G->edges[v][w]=weight;
        cout<<"增加后"<<v<<"->"<<w<<"的道路长度：  "<<G->edges[v][w]<<endl;
    }
    else
         cout<<"此两点间已经存在道路！！！不可增加！！"<<endl;
    cout<<"  返 回 上 级 菜 单 请 按 回 车 键：";
    getchar();getchar();

}
void DeleteArc(MGraph*G ,int v,int w){//删除道路
    cout<<"删除前"<<v<<"->"<<w<<"的长度为：  "<<G->edges[v][w]<<endl;
    if(G->edges[v][w]!=INF)
    {
        G->edges[v][w]=INF;
        cout<<"删除成功"<<endl;
        cout<<"删除后"<<v<<"->"<<w<<"长度为：  "<<G->edges[v][w]<<endl;
    }
    else
        cout<<"此两点间不存在道路！！！无法删除！！"<<endl;
    cout<<"  返 回 上 级 菜 单 请 按 回 车 键：";
    getchar();getchar();


}
void ShortestPath_Floyd(MGraph *G,Pathmatrix *P,ShortPathTable *D)
{//查找某一景点到其他景点的最短路径
    int startp;
    cout<<"请输入起点"<<endl;
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
    cout<<"  返 回 上 级 菜 单 请 按 回 车 键：";
    getchar();getchar();
}


void ToDestination(MGraph *G,Pathmatrix *P,ShortPathTable *D){
    //查找任一两个景点之间的最短路径
    int startp,endp;
    cout<<"请输入起点"<<endl;
    cin>>startp;
    cout<<"请输入终点"<<endl;
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
    cout<<"  返 回 上 级 菜 单 请 按 回 车 键：";
    getchar();getchar();

}
int Menu(){
    int command;

    cout<<"================Menu==============="<<endl;
    cout<<"   请按照序号选择你所要实现的功能  "<<endl;
    cout<<"           0.退出系统              "<<endl;
    cout<<"           1.管理员登录            "<<endl;
    cout<<"           2.游客登录              "<<endl;
    cout<<"=============请输入序号============"<<endl;
    cout<<"=============友情提示：============"<<endl;
    cout<<"=管理员和游客的账号及密码都为‘0’="<<endl;
    while(cin>>command,command<0||command>2)
    {
        cout<<"请输入正确的序号！！"<<endl;
        cout<<"请重新输入！！"<<endl;
    }

    return command;
}
int display1(){
    int command;
    cout<<"=======================管理员界面======================="<<endl;
    cout<<"                       0.返回主菜单                     "<<endl;
    cout<<"               1.创建图的邻接矩阵存储结构               "<<endl;
    cout<<"                  2.浏览图中任一景点介绍                "<<endl;
    cout<<"                    3.修改景点信息                      "<<endl;
    cout<<"                    4.增加景点信息                      "<<endl;
    cout<<"                    5.删除景点信息                      "<<endl;
    cout<<"                      6.增加道路                        "<<endl;
    cout<<"                      7.删除道路                        "<<endl;
    cout<<"           8.查找某一景点到其他景点的最短路径           "<<endl;
    cout<<"            9.查找任一两个景点之间的最短路径            "<<endl;
    cout<<"                     10.打印全部景点                    "<<endl;
    cout<<"===================请输入你想要选择的功能==============="<<endl;
    cout<<"========================友情提示：======================"<<endl;
    cout<<"使用任何功能之前都请先选【1】创建图，不然可能无法正常使用"<<endl;
    while(cin>>command,command<0||command>10)
    {
        cout<<"请输入正确的序号！！"<<endl;
        cout<<"请重新输入！！"<<endl;
    }
    return command;
}
int display2(){
    int command;
    cout<<"=========================游客界面========================"<<endl;
    cout<<"                       0.返回主菜单                      "<<endl;
    cout<<"               1.创建图的邻接矩阵存储结构                "<<endl;
    cout<<"                  2.浏览图中任意景点介绍                 "<<endl;
    cout<<"           3.查找某一景点到其他景点的最短路径            "<<endl;
    cout<<"            4.查找任一两个景点之间的最短路径             "<<endl;
    cout<<"                      5.打印全部景点                     "<<endl;
    cout<<"=========================友情提示：======================"<<endl;
    cout<<"使用任何功能之前都请先选【1】创建图，不然可能无法正常使用"<<endl;
    while(cin>>command,command<0||command>5)
    {
        cout<<"请输入正确的序号！！"<<endl;
        cout<<"请重新输入！！"<<endl;
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
                cout<<"请输入账号"<<endl;
                cin>>user;
                cout<<"请输入密码"<<endl;
                cin>>pw;
                if(user=="0"&&pw=="0") break;
                else cout<<"账号或密码错误，请重新输入!"<<endl;
            }
            system("cls");
            t1=0;
            while(t1==0)
            {
                command=display1();
                switch(command)
                {
                    case 0:t1=1;break;
                    case 1://创建图的邻接矩阵存储结构
                            Create(&G);
                            system("cls");
                            break;
                    case 2://浏览图中任一景点介绍
                            cout<<"请输入要查询的景点序号"<<endl;
                            cin>>v;
                            GetVex(&G,v);
                            system("cls");
                            break;
                    case 3://修改景点信息
                            cout<<"请输入要修改的景点序号"<<endl;
                            cin>>v;
                            PutVertex(&G,v);
                            system("cls");
                            break;
                    case 4://增加景点信息
                            InsertVertex(&G);
                            system("cls");
                            break;
                    case 5://删除景点信息
                            DeleteVertex(&G);
                            system("cls");
                            break;
                    case 6://增加道路
                            cout<<"请输入拟增加道路的起点"<<endl;
                            cin>>v;
                            cout<<"请输入拟增加道路的终点"<<endl;
                            cin>>w;
                            InsertArc(&G,v,w);
                            system("cls");
                            break;
                    case 7://删除道路
                            cout<<"请输入拟删除道路的起点"<<endl;
                            cin>>v;
                            cout<<"请输入拟删除道路的终点"<<endl;
                            cin>>w;
                            DeleteArc(&G,v,w);
                            system("cls");
                            break;
                    case 8://查找某一景点到其他景点的最短路径
                            ShortestPath_Floyd(&G,&P,&D);
                            system("cls");
                            break;
                    case 9://查找任一两个景点之间的最短路径
                            ToDestination(&G,&P,&D);
                            system("cls");
                            break;
                    case 10://打印全部景点
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
                    cout<<"请输入账号："<<endl;
                    cin>>user;
                    cout<<"请输入密码："<<endl;
                    cin>>pw;
                    if(user=="0"&&pw=="0") break;
                    else cout<<"账号或密码错误，请重新输入！"<<endl;
                }
                system("cls");
                t2=0;
                while(t2==0)
                {
                    command=display2();
                    switch(command)
                    {
                        case 0:t2=1;break;
                        case 1://创建图的邻接矩阵存储结构
                              Create(&G);
                              system("cls");
                              break;
                        case 2://浏览图中任一景点介绍
                              cout<<"请输入要查询的景点"<<endl;
                              cin>>v;
                              GetVex(&G,v);
                              system("cls");
                              break;
                        case 3://查找某一景点到其他景点的最短路径
                              ShortestPath_Floyd(&G,&P,&D);
                              system("cls");
                              break;
                        case 4://查找任一两个景点之间的最短路径
                              ToDestination(&G,&P,&D);
                              system("cls");
                              break;
                        case 5://打印全部景点
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
