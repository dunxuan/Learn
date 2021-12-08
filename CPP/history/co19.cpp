#include <iostream>
#include <fstream>

using namespace std;
//������
struct PersonListNode * PersonInfoListCreate(string Name, string ID, enum Sex P_Sex, int Age, string Address);
struct TrailListNode * TrailInfoListCreate(string Time, string Place, float Temperature);
//������������
struct PersonListNode * InputPersonInfo(void);
struct PersonListNode * InputTrailInfo(PersonListNode * q);
struct PersonListNode * SearchTrailInfo(PersonListNode * q);
struct PersonListNode * SearchTemperatureAbnormal(PersonListNode * q);
//�ļ���������
//�´���д

//�Ա�
enum Sex {
	Female,
	Male
};
//�г���Ϣ��ʱ�䡢�ص�
struct TrailInfo {
	string Time;
	string Place;
	float Temperature;
};
//��Ա��Ϣ
struct PersonInfo {
	string Name{};//����
	string ID{};//ID
	Sex P_Sex{};//�Ա�
	int Age{};//����
	string Address{};//��ͥסַ
	TrailListNode * P_TrailListNode{};
};
//������Ա��Ϣ
struct PersonListNode {
	PersonInfo P_PersonInfo;
	PersonListNode * next;
};
//�����켣�ͽ�����Ϣ
struct TrailListNode {
	TrailInfo P_TrailInfo;//�г���Ϣ��ʱ�䡢�ص㡢����         
	TrailListNode * next;
};

PersonListNode * head = nullptr;

int main(void)
{
	bool DoesPersonInfoSave = false;
	char change = 0;
	PersonListNode * p;
	PersonListNode * q = head;//ָ�����¼�����Ա��Ϣ
	for (;;) {
		cout << "����Ҫ���еĲ���->¼����Ա��Ϣ(i)����¼ĳ�˳��й켣������(r)����ѯĳ�˳��й켣���������(s)����ѯ�����쳣��Ա(e):";
		cin >> change;
		switch (change) {
		case 'i'://¼����Ա��Ϣ
			p = InputPersonInfo();
			if (p != nullptr) {
				cout << "¼��ɹ���" << endl;
				if (DoesPersonInfoSave == false) {
					DoesPersonInfoSave = true;
					q = head = p;
				} else {
					q->next = p;
				}
			} else {
				cout << "¼��ʧ�ܡ�" << endl;
			}
			break;
		case 'r'://��¼ĳ�˳��й켣������
			p = InputTrailInfo(q);
			if (p != nullptr) {
				cout << "¼����ɡ�" << endl;
			} else {
				cout << "¼��ʧ�ܡ�" << endl;
			}
			break;
		case 's'://��ѯĳ�˳��й켣���������
			p = SearchTrailInfo(q);
			if (p != nullptr) {
				cout << "��ѯ��ɡ�" << endl;
			} else {
				cout << "��ѯʧ�ܡ�" << endl;
			}
			break;
		case 'e'://��ѯ�����쳣��Ա
			p = SearchTemperatureAbnormal(q);
			if (p != nullptr) {
				cout << "��ѯ��ɡ�" << endl;
			} else {
				cout << "��ѯʧ�ܡ�" << endl;
			}
			break;
		default:
			continue;
		}
	}
	return 0;
}

//���ܣ���������ڵ㲢������Ա��Ϣ
//����������Ա��Ϣ����
//���أ�(PersonListNode *) -> �ڵ��ַ��nullptr -> �����ڵ�ʧ��
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

//���ܣ���������ڵ㲢����켣��������Ϣ
//���������켣��������Ϣ����
//���أ�(TrailListNode *) -> �ڵ��ַ��nullptr -> �����ڵ�ʧ��
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

//���ܣ�¼����Ա��Ϣ
//���أ�(PersonListNode *) -> ¼����Ϣ�ɹ���nullptr -> ¼����Ϣʧ��
struct PersonListNode * InputPersonInfo(void)
{
	string Name;//����
	string ID;//ID
	string P_SexInput;//�Ա��ݴ���������
	Sex P_Sex = Female;//�Ա𣬴��������
	int Age = 0;//����
	string Address;//��ͥסַ
	PersonListNode * p = head;

	cout << "����������";
	cin >> Name;
	cout << "�������֤�ţ�";
	cin >> ID;
	while (p != nullptr) {
		if (p->P_PersonInfo.ID == ID) {
			cout << "���д��ˡ�" << endl;
			return nullptr;
		}
		p = p->next;
	}
	cout << "�����Ա�";
	cin >> P_SexInput;
	cout << "�������䣺";
	cin >> Age;
	cout << "�����ͥסַ��";
	cin >> Address;
	//�Ա𣬴�����������
	if (P_SexInput == "��") {
		P_Sex = Male;
	} else {
		P_Sex = Female;
	}
	//���������ݲ���������
	PersonListNode * q = PersonInfoListCreate(Name, ID, P_Sex, Age, Address);
	if (q != nullptr) {
		return q;
	} else {
		return nullptr;
	}
}

//���ܣ���¼ĳ�˳��й켣������
//�������ж�������Ա�ɱ�¼��
//���أ�(TrailListNode *) -> ¼����й켣��������Ϣ�ɹ���nullptr -> ¼����й켣��������Ϣʧ��
struct PersonListNode * InputTrailInfo(PersonListNode * q)
{
	if (q == nullptr) {
		cout << "��ǰ����Ա��¼�롣" << endl;
		return nullptr;
	}

	string Name;//����
	string ID;//ID
	cout << "����������";
	cin >> Name;
	cout << "�������֤�ţ�";
	cin >> ID;

	PersonListNode * p = head;
	string Time;//ʱ��
	string Place;//�ص�
	float Temperature;//����
	while (p != nullptr) {
		if (p->P_PersonInfo.Name == Name && p->P_PersonInfo.ID == ID) {
			cout << "����ʱ�䣺";
			cin >> Time;
			cout << "����ص㣺";
			cin >> Place;
			cout << "�������£�";
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
	cout << "���޴��ˡ�" << endl;;
	return nullptr;
}

//���ܣ���ѯĳ�˳��й켣���������
//�������ж�������Ա�ɱ���ѯ
//���أ�(PersonListNode *) -> ��ѯ�ɹ���nullptr -> ��ѯʧ��
struct PersonListNode * SearchTrailInfo(PersonListNode * q)
{
	if (q == nullptr) {
		cout << "��ǰ����Ա�ɲ�ѯ��" << endl;
		return nullptr;
	}

	string Name;//����
	string ID;//ID

	cout << "����������";
	cin >> Name;
	cout << "�������֤�ţ�";
	cin >> ID;

	PersonListNode * p = head;
	while (p != nullptr) {
		if (p->P_PersonInfo.ID == ID) {
			/*cout << "������" << p->P_PersonInfo.Name << endl;
			cout << "���֤�ţ�" << p->P_PersonInfo.ID << endl;*/
			cout << "�Ա�" << p->P_PersonInfo.P_Sex << endl;
			cout << "���䣺" << p->P_PersonInfo.Age << endl;
			cout << "��ͥ��ַ��" << p->P_PersonInfo.Address << endl;
			TrailListNode * r = p->P_PersonInfo.P_TrailListNode;
			if (r == nullptr) {
				cout << "�����޳��й켣��������Ϣ��" << endl;
				return p;
			}
			while (r != nullptr) {
				cout << "ʱ�䣺" << r->P_TrailInfo.Time << endl;
				cout << "\t�ص㣺" << r->P_TrailInfo.Place << endl;
				cout << "\t���£�" << r->P_TrailInfo.Temperature << endl;
				r = r->next;
			}
			return p;
		}
	}
}

//���ܣ���ѯ�����쳣��Ա
//�������ж�������Ա�ɱ���ѯ
//���أ�(PersonListNode *) -> ��ѯ�ɹ���nullptr -> ��ѯʧ��
struct PersonListNode * SearchTemperatureAbnormal(PersonListNode * q)
{
	if (q == nullptr) {
		cout << "��ǰ����Ա�ɲ�ѯ��" << endl;
		return nullptr;
	}

	PersonListNode * p = head;
	while (p != nullptr) {
		TrailListNode * r = p->P_PersonInfo.P_TrailListNode;
		while (r != nullptr) {
			bool DoesPersonInfoOutput = false;
			if (r->P_TrailInfo.Temperature > 37.3) {
				if (DoesPersonInfoOutput == false) {
					/*cout << "������" << p->P_PersonInfo.Name << endl;
					cout << "���֤�ţ�" << p->P_PersonInfo.ID << endl;*/
					cout << "�Ա�" << p->P_PersonInfo.P_Sex << endl;
					cout << "���䣺" << p->P_PersonInfo.Age << endl;
					cout << "��ͥ��ַ��" << p->P_PersonInfo.Address << endl;
				}
				cout << "ʱ�䣺" << r->P_TrailInfo.Time << endl;
				cout << "\t�ص㣺" << r->P_TrailInfo.Place << endl;
				cout << "\t���£�" << r->P_TrailInfo.Temperature << endl;
			}
			r = r->next;
		}
		p = p->next;
	}
}