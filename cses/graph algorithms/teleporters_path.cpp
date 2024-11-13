#include<bits/stdc++.h>
using namespace std;

int n, m;

struct node {
	int value;
	node *prev, *next;

	node(int v) {
		this->value=v;
		this->next=nullptr;
		this->prev=nullptr;
	}

	void insert(node *v) {
		v->next=next;
		v->prev=this;
		this->next=v;
	}
};

vector<set<int>> e;

void dfs(int v, node *n) {
	while (!e[v].empty()) {
		auto t=*e[v].begin();
		e[v].erase(t);
		node *c=new node(t);
		(*n).insert(c);
		dfs(t,c);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	e.assign(n+1, set<int>());
	vector<int> in(n+1, 0), out(n+1, 0);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].insert(b);
		in[b]++; out[a]++;
	}

	for (int i = 2; i < n; ++i) {
		if (in[i]!=out[i]) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	if ((in[1]+1!=out[1]) || (in[n]!=out[n]+1)) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	queue<int> q;
	vector<int> p(n+1, 0);
	q.push(1); p[1]=1;
	while (!q.empty()) {
		int c=q.front();
		q.pop();
		for (auto i = e[c].begin(); i != e[c].end(); ++i) {
			if (p[*i]) continue;
			p[*i]=c;
			q.push(*i);
		}
	}

	int c=n;
	stack<int> s;
	while (p[c]!=c) {
		s.push(c);
		c=p[c];
	}

	node *begin = new node(1);
	node *current = begin;
	while (!s.empty()) {
		node *t = new node(s.top());
		(*current).insert(t);
		int v=current->value;
		e[v].erase(s.top());
		dfs(v, current);
		current=t;
		s.pop();
	} dfs(current->value, current);

	current=begin;
	vector<int> ans;
	while (current!=nullptr) {
		ans.push_back(current->value);
		current=current->next;
	}

	if (ans.size()!=m+1) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	for(auto i : ans) {
		cout << i << ' ';
	} cout << '\n';

	return 0;
}