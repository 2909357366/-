#include "Graph.h"
#include "Tourism.h"
#include <iostream>
#define MAX_VERTEX_NUM  7

CGraph cgraph;
Path pa;
PathList p = &pa;
int path = 0;
int flog = 1;

void Init(void)
{
	for (int i = 0; i < 32; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (i == j) cgraph.m_aAdjMatrix[i][j] = 0;
			else cgraph.m_aAdjMatrix[i][j] = INF;
		}
	}
	cgraph.m_nVexNum = 0;
}




bool CGraph::InsertVex(Vex sVex[])
{
	//int p = 0;
	while(m_nVexNum < MAX_VERTEX_NUM)
	{
		m_aVexs[m_nVexNum] = sVex[m_nVexNum];
		//cout << m_nVexNum << endl;
		m_nVexNum++;
		//p++;
		//顶点已满
	}
	//cout << m_nVexNum << endl;
	return true;
	 //插入顶点信息
	//cout << m_nVexNum << endl;
}



bool CGraph::InsertEdge(Edge sEdge)
{
	if (sEdge.vex1 < 0 || sEdge.vex1 >= m_nVexNum || sEdge.vex2 < 0 || sEdge.vex2 >= m_nVexNum)
	{
		// 下标越界
		return false;
	}
	// 插入边的信息
	m_aAdjMatrix[sEdge.vex1][sEdge.vex2] = sEdge.weight;
	m_aAdjMatrix[sEdge.vex2][sEdge.vex1] = sEdge.weight;
	return true;
}


int CGraph::FindEdge(int v, Edge aEdge[])
{
		int k = 0;
		for (int i = 0; i < m_nVexNum; i++)
		{
			// 得到边的消息
			if (k == v)
			{
				return k;
			}
				k++;
		}
		return k; // 返回边的条数
}

/*
int get_index(GraphAdList& G, int k)
{
	for (int i = 0; i < G.numV; i++)
	{
		if (k == G.AdjList[i]->data)
		{
			return i;
		}
	}
}

void DFSTraverse(GraphAdList& G, int key)
{
	VertaxNode* temp = G.AdjList[key]->next;
	while (temp != NULL) {
		int vx = get_index(G, temp->data);
		if (visited[vx] == 0)
		{
			
			p->vexs[path] = temp->data;
			path++;
			visited[vx] = 1;
			DFSTraverse(G, vx);
		}
		temp = temp->next;
	}

}





void DFS(GraphAdList& G)
{
	//p->vexs[path] = 2;
//	path++;
	//visited[2] = 1;
	//cout << G.AdjList[2]->next->data;
	for (int i = 0; i < G.numV; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			//cgraph.ShowVexName(G.AdjList[i]->data);
			p->vexs[path] = G.AdjList[i]->data;
			path++;
			VertaxNode* temp = G.AdjList[i]->next;
			while (temp != NULL)
			{
				int vx = get_index(G, temp->data);
				if(visited[vx] == 0)
				{
					
					p->vexs[path] = temp->data;
					path++;
					visited[vx] = 1;
					DFSTraverse(G, vx);
				}
				temp = temp->next;
			}
		}
	}
}
*/




void DFS(int nVex, bool aVisited[], int& nIndex, GraphAdList G, CGraph CG)
{
	aVisited[nVex] = true; // 改为已访问
	p->vexs[nIndex] = nVex; //访问顶点 nVex
	nIndex++;
	
	VertaxNode* temp = G.AdjList[nVex]->next;
	if (nIndex == 7)
	{	
		cout << "线路" << flog++ << ": ";
		CG.ShowVexName(p->vexs[0]);
		for (int i = 1; i < MAX_VERTEX_NUM; i++)
		{
			cout << " -> ";
			CG.ShowVexName(p->vexs[i]);
		}
		cout << endl;
	//	nIndex = 0;
		
	}
	else
	{
		while (temp != NULL) //搜索 v 的所有邻接点
		{
			if ( !aVisited[temp->data])
			{
				DFS(temp->data, aVisited, nIndex, G, CG); //递归调用 DFS
				aVisited[temp->data] = false; // 2、改为未访问
				nIndex--; // 索引值减 1
			}
			temp = temp->next;
		}
	}
	
}

void DFSTraverse(int nVex,GraphAdList G, CGraph CG)
{
	int nIndex = 0;
	bool aVisited[MAX_VERTEX_NUM] = { false };
	DFS(nVex, aVisited, nIndex, G, CG);
}
/*
void ShowPath(CGraph CG)
{
	
	while (p != NULL)
	{
		cout << "导游路线为：" << endl;
		CG.ShowVexName(p->vexs[0]);
		for (int i = 1; i < MAX_VERTEX_NUM; i++)
		{
			cout << " -> ";
			CG.ShowVexName(p->vexs[i]);
		}
		cout << endl;
	
	 	p= p->next;
	}

}*/