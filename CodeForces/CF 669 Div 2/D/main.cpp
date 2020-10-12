

#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e5+10;
vector<int> adj[MAX];
vector<int> dist(MAX);
vector<bool> vis(MAX);

void bfs(int s) {
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while(!q.empty()) {
		s = q.front();
		q.pop();
		for(auto i : adj[s]) {
			if(!vis[i]) {
				vis[i] = true;
				dist[i] = dist[s] + 1;
				q.push(i);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}
	stack<int> st;
	st.push(0);

	for(int i = 1; i < n; i++) {
		while(!st.empty() and h[st.top()] > h[i]) {
			st.pop();
		}
		if(!st.empty()) {
			adj[st.top()].push_back(i);
		}
		st.push(i);
	}

	while(!st.empty()) st.pop();
	st.push(0);

	for(int i = 1; i < n; i++) {
		while(!st.empty() and h[st.top()] < h[i]) {
			st.pop();
		}
		if(!st.empty()) {
			adj[st.top()].push_back(i);
		}
		st.push(i);
	}



	while(!st.empty()) st.pop();
	st.push(n-1);

	for(int i = n-2; i >= 0; i--) {
		while(!st.empty() and h[st.top()] < h[i]) {
			st.pop();
		}
		if(!st.empty()) {
			adj[i].push_back(st.top());
		}
		st.push(i);
	}

	while(!st.empty()) st.pop();
	st.push(n-1);

	for(int i = n-2; i >= 0; i--) {
		while(!st.empty() and h[st.top()] > h[i]) {
			st.pop();
		}
		if(!st.empty()) {
			adj[i].push_back(st.top());
		}
		st.push(i);
	}


	bfs(0);
	cout << dist[n-1] << '\n';


	return 0;
}

