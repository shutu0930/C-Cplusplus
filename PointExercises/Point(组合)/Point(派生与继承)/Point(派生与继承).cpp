// Point(派生与继承).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;

class Point
{
	double X;
	double Y;

public:
	void Initpoint(double xx=0,double yy=0)
	{
		X=xx;Y=yy;
	
	}
	void Move(double xoff=0,double yoff=0)
	{
		X+=xoff;Y+=yoff;
	
	}
	double &GetX()
	{
		return X;
	}
	double &GetY()
	{
		return Y;
	}

};
class Cline
{	
	
	Point m_point1;
	Point m_point2;

	
public:
	
	Cline()
	{
		
		
	}
	void InitpointC(double x1,double y1,double x2,double y2)
	{
		m_point1.Initpoint(x1,y1);
		m_point2.Initpoint(x2,y2);
	
	}
	double Countlen()
	{	
		return sqrt((m_point1.GetX()-m_point2.GetX())*(m_point1.GetX()-m_point2.GetX())+(m_point1.GetY()-m_point2.GetY())*(m_point1.GetY()-m_point2.GetY()));
	
	}


};
void main()
{
	Cline cline1;
	cline1.InitpointC(1,2,3,4);
	
	cout<<cline1.Countlen()<<endl;
}

