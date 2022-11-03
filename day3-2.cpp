#include<bits/stdc++.h>
#include<string>

using namespace	std;

vector<string> keepBits(int index, vector<string> list, char thing) {
	vector<string> newVector;
	for (int i = 0; i < list.size(); ++i)
	{
		if (list[i].at(index) == thing) {
			newVector.push_back(list[i]);
		}
	}
	return(newVector);
}

int determineBitCount(int index, vector<string> list, char thing) {
	int count = 0;
	for (int i = 0; i < list.size(); ++i)
	{
		if (list[i].at(index) == thing) {
			count++;
		}
	}
	return(count);
}

int binToDec(string str) {
	int count = 0;
	if (str.at(str.length()-1) == '1') {
		count++;
	}
	for (int i = 0; i < str.length()-1; ++i)
	{
		//cout << (str.at(i)-'0')*pow(2,str.length()-i-1) << endl;
		count += (str.at(i)-'0')*pow(2,str.length()-i-1);
	}
	return(count);
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<string> data;

	int inputSize = 1000;
	int individialInputLen = 12;



	for (int i = 0; i < inputSize; ++i)
	{
		string a;
		cin >> a;
		data.push_back(a);
	}

	vector<string> data2 = data;

	for (int i = 0; i < individialInputLen; ++i)
	{
		/*cout << "\n i = " << i << endl;
		for (int k = 0; k < data.size(); ++k)
		{
			cout << data[k] << endl;
		}*/
		vector<string> newVector;
		//cout << "bit count for 1 is " << determineBitCount(i, data, '1') << endl;
		if (determineBitCount(i, data, '1') >= determineBitCount(i, data, '0')) {
			newVector = keepBits(i, data, '1');
		}
		else {
			newVector = keepBits(i, data, '0');
		}
		data.clear();
		//cout << newVector.size() << endl;
		
		for (int i = 0; i < newVector.size(); ++i)
		{
			data.push_back(newVector[i]);
		}
		newVector.clear();
		if (data.size() == 1) {
			break;
		}
	}

	string oxy = data[0];

	for (int i = 0; i < individialInputLen; ++i)
	{
		vector<string> newVector;
		if (determineBitCount(i, data2, '1') >= determineBitCount(i, data2, '0')) {
			newVector = keepBits(i, data2, '0');
		}
		else {
			newVector = keepBits(i, data2, '1');
		}

		data2.clear();
		
		for (int i = 0; i < newVector.size(); ++i)
		{
			data2.push_back(newVector[i]);
		}
		newVector.clear();
		if (data2.size() == 1) {
			break;
		}
	}

	string co2 = data2[0];
	
	cout << endl << binToDec(oxy) * binToDec(co2);
}
