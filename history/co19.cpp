#include <iostream>
#include <fstream>

using namespace std;
//链表函数
struct PersonListNode * PersonInfoListCreate(string Name, string ID, enum Sex P_Sex, int Age, string Address);
struct TrailListNode * TrailInfoListCreate(string Time, string Place, float Temperature);
//基本操作函数
struct PersonListNode * InputPersonInfo(void);
struct PersonListNode * InputTrailInfo(PersonListNode * q);
struct PersonListNode * SearchTrailInfo(PersonListNode * q);
struct PersonListNode * SearchTemperatureAbnormal(PersonListNode * q);
//文件操作函数
//下次再写

//性别
enum Sex {
	Female,
	Male
};
//行程信息：时间、地点
struct TrailInfo {
	string Time;
	string Place;
	float Temperature;
};
//人员信息
struct PersonInfo {
	string Name{};//姓名
	string ID{};//ID
	Sex P_Sex{};//性别
	int Age{};//年龄
	string Address{};//家庭住址
	TrailListNode * P_TrailListNode{};
};
//链表：人员信息
struct PersonListNode {
	PersonInfo P_PersonInfo;
	PersonListNode * next;
};
//链表：轨迹和健康信息
struct TrailListNode {
	TrailInfo P_TrailInfo;//行程信息：时间、地点、体温         
	TrailListNode * next;
};

PersonListNode * head = nullptr;

int main(void)
{
	bool DoesPersonInfoSave = false;
	char change = 0;
	PersonListNode * p;
	PersonListNode * q = head;//指向最后录入的人员信息
	for (;;) {
		cout << "输入要进行的操作->录入人员信息(i)、记录某人出行轨迹和体温(r)、查询某人出行轨迹和体温情况(s)、查询体温异常人员(e):";
		cin >> change;
		switch (change) {
		case 'i'://录入人员信息
			p = InputPersonInfo();
			if (p != nullptr) {
				cout << "录入成功。" << endl;
				if (DoesPersonInfoSave == false) {
					DoesPersonInfoSave = true;
					q = head = p;
				} else {
					q->next = p;
				}
			} else {
				cout << "录入失败。" << endl;
			}
			break;
		case 'r'://记录某人出行轨迹和体温
			p = InputTrailInfo(q);
			if (p != nullptr) {
				cout << "录入完成。" << endl;
			} else {
				cout << "录入失败。" << endl;
			}
			break;
		case 's'://查询某人出行轨迹和体温情况
			p = SearchTrailInfo(q);
			if (p != nullptr) {
				cout << "查询完成。" << endl;
			} else {
				cout << "查询失败。" << endl;
			}
			break;
		case 'e'://查询体温异常人员
			p = SearchTemperatureAbnormal(q);
			if (p != nullptr) {
				cout << "查询完成。" << endl;
			} else {
				cout << "查询失败。" << endl;
			}
			break;
		default:
			continue;
		}
	}
	return 0;
}

//功能：创建链表节点并存入人员信息
//参数：将人员信息传入
//返回：(PersonListNode *) -> 节点地址，nullptr -> 创建节点失败
struct PersonListNode * PersonInfoListCreate(string Name, string ID, enum Sex P_Sex, int Age, string Address)
{
	PersonListNode * NewListNode = new PersonListNode;
	if (NewListNode == nullptr) {
		return nullptr;
	}

	NewListNode->P_PersonInfo.Name = Name;
	NewListNode->P_PersonInfo.ID = ID;
	NewListNode->P_PersonInfo.P_Sex = P_Sex;
	NewListNode->P_PersonInfo.Age = Age;
	NewListNode->P_PersonInfo.Address = Address;
	NewListNode->P_PersonInfo.P_TrailListNode = nullptr;
	NewListNode->next = nullptr;

	return NewListNode;
}

//功能：创建链表节点并存入轨迹和体温信息
//参数：将轨迹和体温信息传入
//返回：(TrailListNode *) -> 节点地址，nullptr -> 创建节点失败
struct TrailListNode * TrailInfoListCreate(string Time, string Place, float Temperature)
{
	TrailListNode * NewListNode = new TrailListNode;
	if (NewListNode == nullptr) {
		return nullptr;
	}

	NewListNode->P_TrailInfo.Time = Time;
	NewListNode->P_TrailInfo.Place = Place;
	NewListNode->P_TrailInfo.Temperature = Temperature;
	NewListNode->next = nullptr;

	return NewListNode;
}

//功能：录入人员信息
//返回：(PersonListNode *) -> 录入信息成功，nullptr -> 录入信息失败
struct PersonListNode * InputPersonInfo(void)
{
	string Name;//姓名
	string ID;//ID
	string P_SexInput;//性别，暂存输入内容
	Sex P_Sex = Female;//性别，处理后内容
	int Age = 0;//年龄
	string Address;//家庭住址
	PersonListNode * p = head;

	cout << "输入姓名：";
	cin >> Name;
	cout << "输入身份证号：";
	cin >> ID;
	while (p != nullptr) {
		if (p->P_PersonInfo.ID == ID) {
			cout << "已有此人。" << endl;
			return nullptr;
		}
		p = p->next;
	}
	cout << "输入性别：";
	cin >> P_SexInput;
	cout << "输入年龄：";
	cin >> Age;
	cout << "输入家庭住址：";
	cin >> Address;
	//性别，处理输入内容
	if (P_SexInput == "男") {
		P_Sex = Male;
	} else {
		P_Sex = Female;
	}
	//将输入数据并入链表中
	PersonListNode * q = PersonInfoListCreate(Name, ID, P_Sex, Age, Address);
	if (q != nullptr) {
		return q;
	} else {
		return nullptr;
	}
}

//功能：记录某人出行轨迹和体温
//参数：判断有无人员可被录入
//返回：(TrailListNode *) -> 录入出行轨迹和体温信息成功，nullptr -> 录入出行轨迹和体温信息失败
struct PersonListNode * InputTrailInfo(PersonListNode * q)
{
	if (q == nullptr) {
		cout << "当前无人员可录入。" << endl;
		return nullptr;
	}

	string Name;//姓名
	string ID;//ID
	cout << "输入姓名：";
	cin >> Name;
	cout << "输入身份证号：";
	cin >> ID;

	PersonListNode * p = head;
	string Time;//时间
	string Place;//地点
	float Temperature;//体温
	while (p != nullptr) {
		if (p->P_PersonInfo.Name == Name && p->P_PersonInfo.ID == ID) {
			cout << "输入时间：";
			cin >> Time;
			cout << "输入地点：";
			cin >> Place;
			cout << "输入体温：";
			cin >> Temperature;
			TrailListNode * q = p->P_PersonInfo.P_TrailListNode;
			while (q != nullptr) {
				q = q->next;
			}
			q = TrailInfoListCreate(Time, Place, Temperature);
			return p;
		} else {
			p = p->next;
		}
	}
	cout << "查无此人。" << endl;;
	return nullptr;
}

//功能：查询某人出行轨迹和体温情况
//参数：判断有无人员可被查询
//返回：(PersonListNode *) -> 查询成功，nullptr -> 查询失败
struct PersonListNode * SearchTrailInfo(PersonListNode * q)
{
	if (q == nullptr) {
		cout << "当前无人员可查询。" << endl;
		return nullptr;
	}

	string Name;//姓名
	string ID;//ID

	cout << "输入姓名：";
	cin >> Name;
	cout << "输入身份证号：";
	cin >> ID;

	PersonListNode * p = head;
	while (p != nullptr) {
		if (p->P_PersonInfo.ID == ID) {
			/*cout << "姓名：" << p->P_PersonInfo.Name << endl;
			cout << "身份证号：" << p->P_PersonInfo.ID << endl;*/
			cout << "性别：" << p->P_PersonInfo.P_Sex << endl;
			cout << "年龄：" << p->P_PersonInfo.Age << endl;
			cout << "家庭地址：" << p->P_PersonInfo.Address << endl;
			TrailListNode * r = p->P_PersonInfo.P_TrailListNode;
			if (r == nullptr) {
				cout << "此人无出行轨迹和体温信息。" << endl;
				return p;
			}
			while (r != nullptr) {
				cout << "时间：" << r->P_TrailInfo.Time << endl;
				cout << "\t地点：" << r->P_TrailInfo.Place << endl;
				cout << "\t体温：" << r->P_TrailInfo.Temperature << endl;
				r = r->next;
			}
			return p;
		}
	}
}

//功能：查询体温异常人员
//参数：判断有无人员可被查询
//返回：(PersonListNode *) -> 查询成功，nullptr -> 查询失败
struct PersonListNode * SearchTemperatureAbnormal(PersonListNode * q)
{
	if (q == nullptr) {
		cout << "当前无人员可查询。" << endl;
		return nullptr;
	}

	PersonListNode * p = head;
	while (p != nullptr) {
		TrailListNode * r = p->P_PersonInfo.P_TrailListNode;
		while (r != nullptr) {
			bool DoesPersonInfoOutput = false;
			if (r->P_TrailInfo.Temperature > 37.3) {
				if (DoesPersonInfoOutput == false) {
					/*cout << "姓名：" << p->P_PersonInfo.Name << endl;
					cout << "身份证号：" << p->P_PersonInfo.ID << endl;*/
					cout << "性别：" << p->P_PersonInfo.P_Sex << endl;
					cout << "年龄：" << p->P_PersonInfo.Age << endl;
					cout << "家庭地址：" << p->P_PersonInfo.Address << endl;
				}
				cout << "时间：" << r->P_TrailInfo.Time << endl;
				cout << "\t地点：" << r->P_TrailInfo.Place << endl;
				cout << "\t体温：" << r->P_TrailInfo.Temperature << endl;
			}
			r = r->next;
		}
		p = p->next;
	}
}