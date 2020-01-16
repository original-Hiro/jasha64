#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

std::istream& read_hw(std::istream&, std::vector<double>&);

class Core {
	friend class Student_info;

private:
	std::string n; //姓名
	virtual Core* clone() const { return new Core(*this); }
	//成员函数：克隆

protected:
	double midterm, final; //期中期末分数
	std::vector<double> homework; //家庭作业分数

	std::istream& read_common(std::istream& input) { input >> n >> midterm >> final; return input; }
	//成员函数：读入Core与Grad的公共部分
	//成员函数：读入家庭作业成绩
public:
	Core() : midterm(0), final(0) {}
	Core(std::istream& input) { read(input); }
	//构造函数

	virtual ~Core() {}
	//析构函数（虚析构函数）

	std::string name() const { return n; } //访问器函数：姓名
	bool valid() const { return !homework.empty(); } //成员函数：该Core对象是否有效
	std::istream& read(std::istream& input) { read_common(input); read_hw(input, homework); return input; }
	//成员函数：读入一个Core对象
	virtual double grade() const; //成员函数：成绩（虚函数）
};
class Grad : public Core
{
public:
	Grad() : thesis(0) {}
	Grad(std::istream& input) { read(input); }
	//构造函数

	double grade() const { return std::min(Core::grade(), thesis); } //成员函数：成绩
	std::istream& read(std::istream&);
	//成员函数：读入一个Grad对象

private:
	double thesis; //论文分数
	Grad* clone() const { return new Grad(*this); }
	//成员函数：克隆
};
class Student_info
{
private:
	Core * cp;

public:
	Student_info() : cp(0) {}
	Student_info(std::istream& input) { read(input); }
	//构造函数
	
	Student_info(const Student_info&);
	Student_info& operator = (const Student_info&);
	~Student_info() { delete cp; }
	//复制、赋值、析构函数

	std::istream& read(std::istream&);
	//成员函数：读入

	std::string name() const
	{
		if (cp) return cp->name();
		else throw std::runtime_error("uninitialized Student");
	}
	double grade() const
	{
		if (cp) return cp->grade();
		else throw std::runtime_error("uninitialized Student");
	}
	//访问器函数：姓名、成绩

	static bool compare(const Student_info& a, const Student_info& b) { return a.name() < b.name(); }
	//静态成员函数：比较（用作排序依据）
};

bool compare(const Core&, const Core&);

