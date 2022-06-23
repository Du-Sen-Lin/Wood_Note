#pragma once
#include<iostream>

using namespace std;

class Student {
private:
	string m_name;
	int m_age;
	float m_score;
public:
	// 常成员函数
	string getname() const;
	int getage() const;
	float getscore() const;
	//set函数
	void setname(string name);
	void setage(int age);
	void setscore(float score);
	//声明普通成员函数
	void show();
	// 声明构造函数
	Student(string name, int age, float score);
public: //声明静态成员函数
	static int getTotal();
	static float getPoints();
private:
	static int m_total; //总人数
	static float m_points; //总成绩
};

/*析构函数*/
class VLA {
public:
	VLA(int len); //构造函数
	~VLA();       //析构函数
public:
	void input();
	void show();
private:
	int *at(int i); //获取第i个元素的指针
private:
	const int m_len; //array length
	int *m_arr;			//array pointer
	int *m_p;			//element pointer to array[i]
};

