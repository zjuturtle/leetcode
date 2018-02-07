//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
//Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
//
//For example,
//
//		Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
//
//		Return:
//        ["AAAAACCCCC", "CCCCCAAAAA"].


#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		if (s.size() < 10)
			return vector<string>();
		vector<long long> dna;
		vector<string> res;
		for (int i = 0; i < s.size() - 9; i++)
			dna.push_back(string2int(s,i));
		sort(dna.begin(), dna.end());
		for (auto i = 1; i < dna.size();i++) {
			if (dna[i] == dna[i - 1]) {
				res.push_back(int2string(dna[i]));
				long long tmp = dna[i];
				while (true) {
					if (i + 1 < dna.size()) {
						if (dna[i + 1] == tmp)
							i++;
						else
							break;
					}
					else {
						break;
					}
				}
			}
			
		}
		return res;
	}

	long long string2int(string& s,int start) {		
		long long res = 0;
		for (int i = 9; i != -1; --i) {
			if (s[start + i] == 'A') {
				res = res<<2;
			}
			if (s[start + i] == 'T') {
				res = (res<<2)+1;
			}
			if (s[start + i] == 'C') {
				res = (res << 2) +2;
			}
			if (s[start + i] == 'G') {
				res = (res << 2) +3;
			}
		}
		return res;
	}
	string int2string(long long num) {
		string res = "";
		for (int i = 0; i < 10; i++) {
			auto tmp = num % 4;
			if (tmp == 0)
				res.append("A");
			if (tmp == 1)
				res.append("T");
			if (tmp == 2)
				res.append("C");
			if (tmp == 3)
				res.append("G");
			num=num >> 2;
		}
		return res;
	}
};
int main() {
	string ss = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution s;

	auto t = s.findRepeatedDnaSequences(ss);
	for (auto it = t.begin(); it != t.end(); it++) {
		cout << *it << endl;
	}
	getchar();
	return 0;
}