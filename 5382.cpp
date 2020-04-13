#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

template <typename T> void print(T vec) { for (auto d : vec) cout << d << ' '; cout << '\n'; }
template<typename T> void print2D(T mat) { for (auto vec : mat) print(vec); }

void KMP(string X, string Y, vector<int> &ans) {
	int m = X.length();
	int n = Y.length();


	// if X's length is less than that of Y's
	if (m < n){
		return;
	}

	// next[i] stores the index of next best partial match
	int next[n + 1];

	for (int i = 0; i < n + 1; i++)
		next[i] = 0;

	for (int i = 1; i < n; i++) {
		int j = next[i + 1];

		while (j > 0 && Y[j] != Y[i])
			j = next[j];

		if (j > 0 || Y[j] == Y[i])
			next[i + 1] = j + 1;
	}

	for (int i = 0, j = 0; i < m; i++)
	{
		if (X[i] == Y[j])
		{
			if (++j == n)
                ans.push_back(i - j + 1);
                return ;
		}
		else if (j > 0) {
			j = next[j];
			i--;	// since i will be incremented in next iteration
		}
	}
    return ;
}

string entityParser(string text) {
        //&quot;
        cout<<text;
        vector<int> idx;
        KMP(text, "&quot;", idx);
        for(int id : idx) {
            cout<<id;
            text.replace(id, 6, "\"");
        }
        idx.clear();
        
        // &apos; '
        
        KMP(text, "&apos;" , idx);
        for(int id : idx) {
            text.replace(id, 6, "'");
        }
        idx.clear();
        
        //&amp;  &
        
        KMP(text, "&amp;", idx);
        cout<<1;
        print(idx);
        for(int id : idx) {
            cout<<id;
            text.replace(id, 5, "&");
        }
        idx.clear();
        
        //&gt; >
        
        KMP(text, "&gt;", idx);
        for(int id : idx) {
            text.replace(id, 4, ">");
        }
        idx.clear();
        
        // &lt; <
        
        KMP(text, "&lt;", idx);
        for(int id : idx) {
            text.replace(id, 4, "<");
        }
        idx.clear();
        
        //&frasl;   /
        
        KMP(text, "&quot;", idx);
        for(int id : idx) {
            text.replace(id, 6, "//");
        }
        idx.clear();
        return text;
    }


    int main() {
        string str;
        getline(cin, str);
        cout<<entityParser(str);
    }