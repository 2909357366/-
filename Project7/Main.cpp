#include "Tourism.h"
#include <iostream>
using namespace std;

int main(void)
{
	//C:\\Users\\yangbin\\Desktop\\qq文件\\数据结构实验
	int sc = 0;
	bool bRunning = false;
	while (!bRunning)
	{
		//output
		cout << " = = = = 景区信息管理系统 = = = = " << endl;
		cout << "1.创建景区景点图" << endl;
		cout << "2.查询景点信息" << endl;
		cout << "3.旅游景点导航" << endl;
		cout << "4.搜索最短路径" << endl;
		cout << "5.铺设电路规划" << endl;
		cout << "0.退出" << endl;
		cout << "请输入操作编号<0~5>:" << endl;
		cin >> sc;
		switch (sc)
		{
		case 1:CreatGraph(); break;
		case 2:GetSpotInfo(); break;
		case 3:TravelPath(); break;
		case 0:bRunning = true; break;
		default:
			break;
		}
	}
	
	
	return 0;
}