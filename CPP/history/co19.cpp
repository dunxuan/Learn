#include <iostream>

using namespace std;
//������
struct PersonListNode * PersonInfoListCreate(string Name, string ID, enum Sex P_Sex, int Age, string Address);
struct TrailAndHealthListNode * TrailAndHealthInfoListCreate(string Time, string Place, float Temperature);
//��������
struct PersonListNode * InputPersonInfo(void);
struct PersonListNode * InputTrailAndHealthInfo(PersonListNode * q);
struct PersonListNode * SearchTrailAndHealthInfo(PersonListNode * q);
struct PersonListNode * SearchTemperatureAbnormal(PersonListNode * q);

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
	TrailAndHealthListNode * P_TrailAndHealthListNode;
};
//������Ա��Ϣ
struct PersonListNode {
	PersonInfo P_PersonInfo;
	PersonListNode * next;
};
//�����켣�ͽ�����Ϣ
struct TrailAndHealthListNode {
	TrailInfo P_TrailInfo;//�켣��Ϣ��ʱ�䡢�ص�
	HealthInfo P_HealthInfo;//������Ϣ��ʱ�䡢����
	TrailAndHealthListNode * next;
};

PersonListNode * head = nullptr;

int main(void)
{
	bool DoesPersonInfoSave = false;
	char change = 0;
	PersonListNode * p;
	PersonListNode * q = head;//ָ�����¼�����Ա��Ϣ
	for (;;) {
		cout << "����Ҫ���еĲ�����¼����Ա��Ϣ(i)����¼ĳ�˳��й켣������(r)����ѯĳ�˳��й켣���������(s)����ѯ�����쳣��Ա(e):";
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
			p = InputTrailAndHealthInfo(q);
			if (p != nullptr) {
				cout << "¼����ɡ�" << endl;
			} else {
				cout << "¼��ʧ�ܡ�" << endl;
			}
			break;
		case 's'://��ѯĳ�˳��й켣���������
			p = SearchTrailAndHealthInfo(q);
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
	NewListNode->P_PersonInfo.P_TrailAndHealthListNode = nullptr;
	NewListNode->next = nullptr;

	return NewListNode;
}

//���ܣ���������ڵ㲢����켣��������Ϣ
//���������켣��������Ϣ����
//���أ�(TrailAndHealthListNode *) -> �ڵ��ַ��nullptr -> �����ڵ�ʧ��
struct TrailAndHealthListNode * TrailAndHealthInfoListCreate(string Time, string Place, float Temperature)
{
	TrailAndHealthListNode * NewListNode = new TrailAndHealthListNode;
	if (NewListNode == nullptr) {
		return nullptr;
	}

	NewListNode->P_TrailInfo.Time = NewListNode->P_HealthInfo.Time = Time;
	NewListNode->P_TrailInfo.Place = Place;
	NewListNode->P_HealthInfo.Temperature = Temperature;
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
//���أ�(TrailAndHealthListNode *) -> ¼����й켣��������Ϣ�ɹ���nullptr -> ¼����й켣��������Ϣʧ��
struct PersonListNode * InputTrailAndHealthInfo(PersonListNode * q)
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
			TrailAndHealthListNode * q = p->P_PersonInfo.P_TrailAndHealthListNode;
			while (q != nullptr) {
				q = q->next;
			}
			q = TrailAndHealthInfoListCreate(Time, Place, Temperature);
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
struct PersonListNode * SearchTrailAndHealthInfo(PersonListNode * q)
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
			cout << "������" << p->P_PersonInfo.Name << endl;
			cout << "���֤�ţ�" << p->P_PersonInfo.ID << endl;
			cout << "�Ա�" << p->P_PersonInfo.P_Sex << endl;
			cout << "���䣺" << p->P_PersonInfo.Age << endl;
			cout << "��ͥ��ַ��" << p->P_PersonInfo.Address << endl;
			TrailAndHealthListNode * r = p->P_PersonInfo.P_TrailAndHealthListNode;
			if (q == nullptr) {
				cout << "�����޳��й켣��������Ϣ��" << endl;
				return p;
			}
			while (q != nullptr) {
				cout << "ʱ�䣺" << r->P_TrailInfo.Time << endl;
				cout << "\t�ص㣺" << r->P_TrailInfo.Place << endl;
				cout << "\t���£�" << r->P_HealthInfo.Temperature << endl;
				q = q->next;
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
		TrailAndHealthListNode * r = p->P_PersonInfo.P_TrailAndHealthListNode;
		while (r != nullptr) {
			bool DoesPersonInfoOutput = false;
			if (r->P_HealthInfo.Temperature > 37.3) {
				if (DoesPersonInfoOutput == false) {
					cout << "������" << p->P_PersonInfo.Name << endl;
					cout << "���֤�ţ�" << p->P_PersonInfo.ID << endl;
					cout << "�Ա�" << p->P_PersonInfo.P_Sex << endl;
					cout << "���䣺" << p->P_PersonInfo.Age << endl;
					cout << "��ͥ��ַ��" << p->P_PersonInfo.Address << endl;
				}
				cout << "ʱ�䣺" << r->P_TrailInfo.Time << endl;
				cout << "\t�ص㣺" << r->P_TrailInfo.Place << endl;
				cout << "\t���£�" << r->P_HealthInfo.Temperature << endl;
			}
			r = r->next;
		}
		p = p->next;
	}
}