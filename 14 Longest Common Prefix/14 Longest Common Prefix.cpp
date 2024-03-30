#include <iostream>
#include <vector>
#include <string>
using namespace std;
string longestCommonPrefix(vector<string>& strs);
int main()
{
    //cout << "Hello World!\n";
    vector<string> strs = {"flower", "flow", "flight"};
	string d = longestCommonPrefix(strs);
    cout << d;
}

 string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0)
    {
		return "";
	}
	string prefix = strs[0];
	for (int i = 1; i < strs.size(); i++)
	{
		while (strs[i].find(prefix) != 0)
		{
			prefix = prefix.substr(0, prefix.length() - 1);
			if (prefix.empty())
			{
				return "";
			}
		}
	}
	return prefix;

}
