#include <iostream> 
#define MAX_VERTEX_NUM 7
const int INF = 0x3f3f3f3f;
//bool aVisited[MAX_VERTEX_NUM] = { false };
using namespace std;




//定义节点
struct VertaxNode
{
	int data;		//节点数据
	int weigth = 0;		//	边的权值
	VertaxNode* next = NULL;
};

//定义图
struct GraphAdList
{
	VertaxNode* AdjList[MAX_VERTEX_NUM];
	int numV, numE;
};

typedef struct Path
{
	int vexs[20]; //保存一条路径
	Path* next; //下一条路径
}*PathList;


//Vex结构体
struct Vex
{
	char num[1024]; // 景点编号
	char name[1024]; // 景点名字
	char desc[1024]; // 景点介绍
};


//Edge 结构体
struct Edge
{
	int vex1; // 边的第一个顶点
	int vex2; // 边的第二个顶点
	int weight; // 权值
};

class CGraph
{
private:
	int m_aAdjMatrix[20][20]; // 邻接矩阵
	Vex m_aVexs[20]; // 顶点信息数组
	int m_nVexNum; // 当前图的顶点个数
public:
	friend void Init(void);
	bool InsertVex(Vex Vex[]);
	/* {
		if (m_nVexNum == MAX_VERTEX_NUM)
		{
			//顶点已满
			return false;
		}
		m_aVexs[m_nVexNum++] = sVex; //插入顶点信息
		return true;
	}*/
	bool InsertEdge(Edge sEdge);
	/* {
		if (sEdge.vex1 < 0 || sEdge.vex1 >= m_nVexNum || sEdge.vex2 < 0 || sEdge.vex2 >= m_nVexNum)
			{
				// 下标越界
			return false;
			}
			// 插入边的信息
		m_aAdjMatrix[sEdge.vex1][sEdge.vex2] = sEdge.weight;
		m_aAdjMatrix[sEdge.vex2][sEdge.vex1] = sEdge.weight;
		return true;
	}*/
	void ViewFormation() 
	{
		cout << "---- 顶点 ----" << endl;
		for (int i = 0; i < m_nVexNum; i++)
		{
			cout << this->m_aVexs[i].num << "-" << this->m_aVexs[i].name << endl;
		}
	}

	void ViewFromation1()
	{
		cout << "---- 边 ----" << endl;
		for (int i = 0; i < m_nVexNum; i++)
		{
			for (int j = 0; j < m_nVexNum; j++)
			{
				if (i < j && m_aAdjMatrix[i][j] != 0)
				{
					cout << "<v" << i << ",v" << j << ">" << m_aAdjMatrix[i][j] << endl;
				}
			}
		}
	}
	int FindEdge(int v, Edge aEdge[]);
	void ShowVexName(int m) 
	{
		cout << this->m_aVexs[m].name;
	}
	void ShowVex(int i)
	{
		cout << this->m_aVexs[i].name << endl;
		cout << this->m_aVexs[i].desc << endl;
	}
	void ShowAround(int n)
	{
		for (int i = 0; i < this->m_nVexNum; i++)
		{
				if (i == n)
				{
					for (int k = 0; k < this->m_nVexNum; k++)
					{
						if (this->m_aAdjMatrix[i][k] != 0)
						{
							cout << this->m_aVexs[i].name << "->" << this->m_aVexs[k].name << "\t" << this->m_aAdjMatrix[i][k] << "m" << endl;
						}
					}
				}
		}
	}


	void PrintMatrix()
	{
		for (int i = 0; i < this->m_nVexNum; i++)
		{
			for (int j = 0; j < this->m_nVexNum; j++)
			{
					cout << this->m_aAdjMatrix[i][j] << "\t";
			}
			cout << endl;
		}
	}
};


void Init(void);
//void DFSTraverse(GraphAdList& G, int key);
void DFSTraverse(int nVex, GraphAdList G, CGraph CG);
//void DFS(GraphAdList& G);
void DFS(int nVex, bool aVisited[], int& nIndex, GraphAdList G, CGraph CG);
int get_index(GraphAdList& G, int k);
void ShowPath(CGraph CG);