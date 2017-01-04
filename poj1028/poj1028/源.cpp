#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	string cmd;//���������
	string url="";//��ǰҳ���·��
	stack<string> forward, backward;

	backward.push("http://www.acm.org/");//initial

	while (cin >> cmd)
	{
		if (cmd == "QUIT")
		{
			break;
		}
		else if (cmd == "BACK")
		{
			if (backward.empty())
			{
				cout << "Ignored" << endl;
			}
			else
			{
				//��ʼurl��Ϊ�գ����е�ǰ����ҳ�棬Ӧ�����ʼ��״̬
				if (url != "")
				{
					forward.push(url);
				}
				url = backward.top();
				backward.pop();
				cout << url<<endl;
			}
		}
		else if (cmd == "FORWARD")
		{
			if (forward.empty())
			{
				cout << "Ignored" << endl;
			}
			else
			{
				//��ʼurl��Ϊ�գ����е�ǰ����ҳ�棬Ӧ�����ʼ��״̬
				if (url != "")
				{
					backward.push(url);
				}
				url = forward.top();
				forward.pop();
				cout << url<<endl;
			}
		}
		else if (cmd == "VISIT")
		{
			//��ʼurl��Ϊ�գ����е�ǰ����ҳ�棬Ӧ�����ʼ��״̬
			if (url != "")
			{
				backward.push(url);
			}
			cin >> url;
			//����ǰ��ջ���
			while (!forward.empty())
			{
				forward.pop();
			}
			cout << url<<endl;
		}
	}
	return 0;
}