#pragma warning (disable:4996)
#include <fstream>
#include "Tourism.h"
#include "Graph.h"
#include <string.h>


Vex vex[7];
Edge edge[9];
CGraph m_Graph;
GraphAdList G;


using namespace std;
void CreatGraph()
{	 
	Init();
	string filename = "C:\\Users\\yangbin\\Desktop\\qqdocument\\数据结构实验\\Edge.txt";
	string filename2 = "C:\\Users\\yangbin\\Desktop\\qqdocument\\数据结构实验\\Vex.txt";
	ifstream ifs;
	//cout << "请输入要打开的文件名！" << endl;
	//cin >> filename2;
	ifs.open(filename2, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	char v[1024];
	int n = 0;
	int k = 0;
	while (ifs >> v)
	{
		if (n == 0) {
			for (int i = 0; i < sizeof(v); i++) {
				vex[k].num[i] = v[i];
			}
			//cout << V[k].num << endl;
			n++;
		}
		else if (n == 1) {
			for (int i = 0; i < sizeof(v); i++) {
				vex[k].name[i] = v[i];
			}
			//strcpy(vex.name, v);
			//cout << V[k].name << endl;
			n++;
		}
		else if (n == 2) {
			for (int i = 0; i < sizeof(v); i++) {
				vex[k].desc[i] = v[i];
			}
			//strcpy(vex.desc, v);
			//cout <<V[k].desc << endl;
			k++;
			n = 0;
		}
	}
	ifs.close();
	m_Graph.InsertVex(vex);
	for (int i = 0; i < MAX_VERTEX_NUM; i++)
	{
		cout << vex[i].num << endl;
		cout << vex[i].name << endl;
		cout << vex[i].desc << endl;
	}

	//cout << "请输入要打开的文件名！" << endl;
	//cin >> filename;
	ifs.open(filename,ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return ;
	}
	int c;
	int m = 0;
	int h = 0;
	while (ifs >> c)
	{

		if (m == 0) {
			edge[h].vex1 = c;
			//cout << e[h].vex1 << endl;
			m++;
		}
		else if(m == 1){
			edge[h].vex2 = c;
			//cout << e[h].vex2 << endl;
			//cout << edge[2].vex2 << endl;
			m++;
		}
		else if (m == 2) {
			edge[h].weight = c;
			//cout << e[h].weight << endl;
			m_Graph.InsertEdge(edge[h]);
			m = 0;
			h++;
		}
	}
	ifs.close();

	for (int i = 0; i < 10; i++)
	{
		cout << edge[i].vex1 << endl;
		cout << edge[i].vex2 << endl;
		cout << edge[i].weight << endl;
	}

	//cout << edge[5].vex1 << "\t" << edge[5].vex2 << "\t" << edge[5].weight << endl;
	//构造图
	int vi, vj, w;
	G.numV = MAX_VERTEX_NUM;
	for (int i = 0; i < G.numV; i++)
	{
		VertaxNode* new_code = new VertaxNode;
		new_code->data = i;
		G.AdjList[i] = new_code;
		//cout << G.AdjList[i]->data << endl;
	}

	G.numE = 10;
	for (int i = 0; i < G.numE; i++)
	{
		vi = edge[i].vex1;
		vj = edge[i].vex2;
		//cout << vj << endl;
		//cout << edge[i].vex2 << endl;
		w = edge[i].weight;
		for (int j = 0; j < G.numE; j++)
		{
			if (vi == G.AdjList[j]->data)
			{
				VertaxNode* temp = G.AdjList[j];
				//尾插
				while (temp->next != NULL)
				{
					temp = temp->next;
				}
				VertaxNode* newEdge = new VertaxNode;
				newEdge->data = vj;
				newEdge->weigth = w;
				temp->next = newEdge;
				//cout << vj << endl;
				
				break;
			}
		}
		int t = vi;
		vi = vj;
		vj = t;
		for (int j = 0; j < G.numV; j++)
		{
			if (vi == G.AdjList[j]->data)
			{
				VertaxNode* temp = G.AdjList[j];
				while (temp->next != NULL)
				{
					temp = temp->next;
				}
				VertaxNode* newEdge = new VertaxNode;
				newEdge->data = vj;
				newEdge->weigth = w;
				temp->next = newEdge;
				break;
			}
		}
	}


	



	////////////////// 1 初始化图

	///////////////////// 2 设置图的顶点
	//…

	/////////////////////// 3 设置图的边
	//…
	//m_Graph.InsertEdge(edge);

	cout << "==== 创建景区景点图 ====" << endl;
	cout << "顶点个数：7" << endl;
	m_Graph.ViewFormation();
	m_Graph.ViewFromation1();
}




void GetSpotInfo()
{
	cout << "==== 查询景点信息 ====" << endl;
	int figer = 0;
	cout << "请输入想要查询的景点编号：";
	cin >> figer;
	int k = m_Graph.FindEdge(figer,edge);
	m_Graph.ShowVex(figer);
	m_Graph.ShowAround(figer);
//	m_Graph.PrintMatrix();
}








void TravelPath()
{
	cout << "请输入起始点编号：" << endl;
	int m = 0;
	cin >> m;
	cout << "导游路线为：" << endl;
	DFSTraverse(m, G, m_Graph);
//	ShowPath(m_Graph);
}