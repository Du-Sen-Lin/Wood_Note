#include<iostream>
#include<string>
#include "00_class.h"

using namespace std;

// example 1

// class Student {
// public:
// 	string name;
// 	int age;
// 	float score;

// 	//void say() {
// 	//	cout << name << "的年龄是" << age << ", 成绩" << score << endl;
// 	//}
// 	void say();
// };

// void Student::say() {
// 	cout << name << "的年龄是" << age << ", 成绩" << score << endl;
// }


// int main() {
// 	// Student stu;
// 	// stu.name = "Wood";
// 	// stu.age = 15;
// 	// stu.score = 92.5f;
// 	// stu.say();

// 	// 对象指针
// 	Student* pStu = new Student;
// 	pStu->name = "Wood";
// 	pStu->age = 16;
// 	pStu->score = 92.5f;
// 	pStu->say();
// 	delete pStu;

// 	return 0;
// }

//example 2

//void Student::setname(string name) {
//	m_name = name;
//}
//void Student::setage(int age) {
//	m_age = age;
//}
//void Student::setscore(float score) {
//	m_score = score;
//}
//void Student::show() {
//	cout << m_name << "的年龄是" << m_age << ",成绩是" << m_score << endl;
//}
//
//int main() {
//	Student stu;
//	stu.setname("Wood");
//	stu.setage(15);
//	stu.setscore(92.5f);
//	stu.show();
//	
//	// 对象指针
//	Student* pStu = new Student;
//	pStu->setname("Wood");
//	pStu->setage(16);
//	pStu->setscore(92.5f);
//	pStu->show();
//	delete pStu;
//
//	return 0;
//}

//ex 3 构造函数

//Student::Student(string name, int age, float score) {
//	m_name = name;
//	m_age = age;
//	m_score = score;
//}
//
//void Student::show() {
//	cout << m_name << "的年龄是" << m_age << ",成绩是" << m_score << endl;
//}
//
//int main() {
//	//创建对象时向构造函数传参
//	Student stu("Wood", 15, 92.5f);
//	stu.show();
//	//创建对象时向构造函数传参
//	Student *pstu = new Student("Wood", 16, 92.5f);
//	pstu->show();
//	delete pstu;
//
//	return 0;
//}

//ex 4	析构函数

//VLA::VLA(int len) :m_len(len) {
//	if (len > 0) {
//		m_arr = new int[len];
//	}
//	else {
//		m_arr = NULL;
//	}
//}
//
//VLA::~VLA() {
//	delete[] m_arr;
//}
//
//void VLA::input() {
//	for (int i = 0; m_p = at(i); i++) {
//		cin >> *at(i);
//	}
//}
//
//void VLA::show() {
//	for (int i = 0; m_p = at(i); i++) {
//		if (i == m_len - 1) {
//			cout << *at(i) << endl;
//		}
//		else {
//			cout << *at(i) << ", ";
//		}
//	}
//}
//
//int* VLA::at(int i) {
//	if (!m_arr || i<0 || i>=m_len) {
//		return NULL;
//	}
//	else {
//		return m_arr + i;
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	VLA* parr = new VLA(n);
//	parr->input();
//	parr->show();
//	delete parr;
//	return 0;
//}

// ex5  静态成员函数

//int Student::m_total = 0;
//float Student::m_points = 0.0;
//
//Student::Student(string name, int age, float score) :m_name(name), m_age(age), m_score(score) {
//	m_total++;
//	m_points += score;
//}
//void Student::show() {
//	cout << m_name << "的年龄是" << m_age << ",成绩是" << m_score << endl;
//}
//
//int Student::getTotal() {
//	return m_total;
//}
//
//float Student::getPoints() {
//	return m_points;
//}
//
//int main() {
//	(new Student("Wood", 15, 90.6))->show();
//	(new Student("Wood2", 15, 90.6))->show();
//	(new Student("Wood3", 15, 90.6))->show();
//	(new Student("Wood4", 15, 90.6))->show();
//
//	int total = Student::getTotal();
//	float points = Student::getPoints();
//
//	cout << "student nums:" << total << ", Score sums: " << points << ",ave score:" << points / total << endl;
//}

// ex 6 const变量、函数、对象

Student::Student(string name, int age, float score) :m_name(name), m_age(age), m_score(score) {}
void Student::show() {
	cout << m_name << "的年龄是" << m_age << ",成绩是" << m_score << endl;
}

string Student::getname() const {
	return m_name;
}

int Student::getage() const {
	return m_age;
}

float Student::getscore() const {
	return m_score;
}

int main() {
	const Student stu("Wood", 15, 90.6);
	//stu.show() // error
	cout << stu.getname() << ", age"<< stu.getage() << ",score" << stu.getscore() << endl;
	const Student* pstu = new Student("Wood2", 16, 80.5);
	cout << pstu->getname() << ",age" << pstu->getage() << ",score" << pstu->getscore() << endl;
	return 0;
}
