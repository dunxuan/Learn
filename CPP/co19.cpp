#include <iostream>

using namespace std;

struct PersonListNode * ListCreate(string Name, string ID, enum Sex P_Sex, int Age, string Address);

struct PersonListNode * InputPersonInfo(void);

//�Ա�
enum Sex {
	Female,
	Male
};
//�켣��Ϣ��ʱ�䡢�ص�
struct TrailInfo {
	string Time;
	string Place;
};
//������Ϣ��ʱ�䡢����
struct HealthInfo {
	string Time;
	float Temperature;
};
//��Ա��Ϣ
struct PersonInfo {
	string Name;//����
	string ID;//ID
	Sex P_Sex;//�Ա�
	int Age;//����
	string Address;//��ͥסַ
	TrailInfo P_TrailInfo;//�켣��Ϣ��ʱ�䡢�ص�
	HealthInfo P_HealthInfo;//������Ϣ��ʱ�䡢����
};
//����
struct PersonListNode {
	PersonInfo P_PersonInfo;
	PersonListNode * next;
};

int main(void)
{
	PersonListNode * head = NULL;
	bool DoesPersonInfoSave = false;
	char change = 0;
	PersonListNode * p;
	PersonListNode * q;
	for (;;) {
		cout << "����Ҫ���еĲ�����¼����Ա��Ϣ(i)����¼ĳ�˳��й켣������(r)����ѯĳ�˳��й켣���������(s)����ѯ�����쳣��Ա(e):";
		cin >> change;
		switch (change) {
		case 'i'://¼����Ա��Ϣ
			p = InputPersonInfo();
			if (p) {
				cout << "¼��ɹ���" << endl;
				if (DoesPersonInfoSave == false) {
					DoesPersonInfoSave = true;
					q = head = p;
				} else {
					q->next = p;
				}
			} else {
				cout << "¼��ʧ�ܣ����������롣" << endl;
			}
			break;
		case 'r'://��¼ĳ�˳��й켣������

			break;
		case 's'://��ѯĳ�˳��й켣���������

			break;
		case 'e'://��ѯ�����쳣��Ա

			break;
		default:
			continue;
		}
	}
	return 0;
}

struct PersonListNode * ListCreate(string Name, string ID, enum Sex P_Sex, int Age, string Address)
{
	PersonListNode * NewListNode = new PersonListNode;
	if (NewListNode == (PersonListNode *)NULL) {
		return (PersonListNode *)NULL;
	}

	NewListNode->P_PersonInfo.Name = Name;
	NewListNode->P_PersonInfo.ID = ID;
	NewListNode->P_PersonInfo.P_Sex = P_Sex;
	NewListNode->P_PersonInfo.Age = Age;
	NewListNode->P_PersonInfo.Address = Address;
	NewListNode->next = NULL;

	return NewListNode;
}

//���ܣ�¼����Ա��Ϣ
//���أ�(PersonListNode *)��ַ -> ¼����Ϣ�ɹ���NULL -> ¼����Ϣʧ��
struct PersonListNode * InputPersonInfo(void)
{
	string Name;//����
	string ID;//ID
	string P_SexInput;//�Ա��ݴ���������
	Sex P_Sex = Female;//�Ա𣬴��������
	int Age = 0;//����
	string Address;//��ͥסַ

	cout << "����������";
	cin >> Name;
	cout << "����ID��";
	cin >> ID;
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
	PersonListNode * p = ListCreate(Name, ID, P_Sex, Age, Address);
	if (p) {
		return p;
	} else {
		return (PersonListNode *)NULL;
	}
}

//���ܣ���¼ĳ�˳��й켣������
//