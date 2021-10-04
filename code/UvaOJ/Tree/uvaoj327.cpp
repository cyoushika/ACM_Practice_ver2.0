#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int main() {
	char str[1000];
	int num[26];
	for(int i = 0; i < 26; i++)
		num[i] = i + 1;
	while(gets(str)) {
		map<char,int>res;
		map<char,int>cur;
		int len = strlen(str);
		int sum = 0;
		for(int i = 0; i < len; i++) {
			if(str[i] >= 'a' && str[i] <= 'z') {
				res[str[i]] = num[str[i]-'a'];
				cur[str[i]] = num[str[i]-'a'];
				int j = i - 1, k = i + 1;
				while(j > 0 && str[j] == ' ') j--;
				while(k < len && str[k] == ' ') k++;
				if(j - 1 >= 0 && str[j] == str[j-1]) {
					if(str[j] == '+') {
						res[str[i]]++;
						cur[str[i]]++;
					}
					else {
						res[str[i]]--;
						cur[str[i]]--;
					}
					j = j - 2;
				}
				else if(k + 1 < len && str[k] == str[k+1]) {
					if(str[k] == '+')
						res[str[i]]++;
					else
						res[str[i]]--;
				}
				while(str[j] == ' ' && j > 0)j--;
				if(j <= 0) sum = sum + cur[str[i]];
				else if(str[j] == '-') sum = sum - cur[str[i]];
				else sum = sum + cur[str[i]];
			}
		}
		printf("Expression: %s\n", str);
		printf("    value = %d\n",sum);
		map<char, int>::iterator it = res.begin();
		for(it; it != res.end();it++)
			printf("    %c = %d\n",it->first, it->second);

	}
}
