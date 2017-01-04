#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	string cmd;//输入的命令
	string url="";//当前页面的路径
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
				//初始url不为空，即有当前访问页面，应用于最开始的状态
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
				//初始url不为空，即有当前访问页面，应用于最开始的状态
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
			//初始url不为空，即有当前访问页面，应用于最开始的状态
			if (url != "")
			{
				backward.push(url);
			}
			cin >> url;
			//将向前的栈清空
			while (!forward.empty())
			{
				forward.pop();
			}
			cout << url<<endl;
		}
	}
	return 0;
}