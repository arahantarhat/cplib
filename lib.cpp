// Competitive Programming Helper
#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long double ld;
typedef pair<int, int> pii;
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair
#define L first
#define R second
#define endl "\n"

#define fo(i, l, r) for(int i = l; i < r; i++) // denotes open set
#define fc(i, l, r) for(int i = l; i <= r; i++) // denotes closed set
#define rfo(i, l, r) for(int i = r; i > l; i--) // r means reversed
#define rfc(i, l, r) for(int i = r; i >= l; i--) // r means reversed

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
}

// Prime check
bool isPrime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

// Greatest common divisor
int gcd(int a, int b) {
	return __gcd(a, b);
}

// Least common multiple
int lcm(int a, int b) {
	return (a / __gcd(a, b)) * b;
}

// Sieve of Eratosthenes
vector<int> sieve(int n) {
	vector<bool> is_prime(n + 1, true);
	vector<int> primes;
	for (int p = 2; p * p <= n; ++p) {
		if (is_prime[p]) {
			for (int i = p * p; i <= n; i += p)
				is_prime[i] = false;
		}
	}
	for (int p = 2; p <= n; ++p) {
		if (is_prime[p]) primes.push_back(p);
	}
	return primes;
}

// Factorize
vector<int> factorize(int n) {
	vector<int> factors;
	for (int p = 2; p * p <= n; ++p) {
		while (n % p == 0) {
			factors.push_back(p);
			n /= p;
		}
	}
	if (n > 1) factors.push_back(n);
	return factors;
}

// Euler's Totient Function
int phi(int n) {
	int result = n;
	for (int p = 2; p * p <= n; ++p) {
		if (n % p == 0) {
			while (n % p == 0) n /= p;
			result -= result / p;
		}
	}
	if (n > 1) result -= result / n;
	return result;
}

// Integer square root
int isqrt(int n) {
	int lo = 0, hi = n;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (mid * mid <= n) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return lo - 1;
}

// Ceiling division
long long div_ceil(long long a, long long b) {
	return (b >= 0 ? (a + b - 1) : a) / b;
}

// Binary exponentiation
int binpow(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) {
			r *= a;
		}
		a *= a;
		b >>= 1;
	}
	return r;
}

struct Graph {
	int vertices;
	vector<vector<int> > adj;
	int edges;

	Graph(int v) : vertices(v), adj(v), edges(0) {}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges++;
	}

	void addDirectedEdge(int u, int v) {
		adj[u].push_back(v);
		edges++;
	}

	int getNumVertices() {
		return vertices;
	}

	int getNumEdges() {
		return edges;
	}

	void print_graph() {
		cout << "Graph adjacency list:" << endl;
		for (int i = 0; i < vertices; ++i) {
			cout << i << " -> ";
			for (int v : adj[i]) {
				cout << v << " ";
			}
			cout << endl;
		}
	}
};

// Iterative DFS
void iterativeDFS(int start, const vector<vector<int>>& adj) {
	int n = adj.size();
	vector<bool> visited(n, false);
	stack<int> stk;
	stk.push(start);

	while (!stk.empty()) {
		int node = stk.top();
		stk.pop();

		if (!visited[node]) {
			visited[node] = true;

			for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
				if (!visited[*it]) {
					stk.push(*it);
				}
			}
		}
	}
}

// Iterative BFS
void iterativeBFS(int start, const vector<vector<int>>& adj) {
	int n = adj.size();
	vector<bool> visited(n, false);
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int neighbor : adj[node]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
}

const int MAXN = 1000;

struct DSU {
	vector<int> lst[MAXN];
	int parent[MAXN];
	int set_count;

	DSU() {
		set_count = 0;
	}

	void make_set(int v) {
		lst[v] = vector<int>(1, v);
		parent[v] = v;
		set_count++;
	}

	int find_set(int v) {
		return parent[v];
	}

	void union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (lst[a].size() < lst[b].size())
				swap(a, b);
			while (!lst[b].empty()) {
				int v = lst[b].back();
				lst[b].pop_back();
				parent[v] = a;
				lst[a].push_back(v);
			}
			set_count--;
		}
	}

	int size_of_set(int v) {
		return lst[find_set(v)].size();
	}

	int get_set_count() const {
		return set_count;
	}

	void print_dsu() {
		cout << "Disjoint Set Union State:" << endl;
		for (int i = 0; i < MAXN; ++i) {
			if (!lst[i].empty()) {
				cout << "Set " << i << ": ";
				for (int v : lst[i]) {
					cout << v << " ";
				}
				cout << endl;
			}
		}
	}
};

struct FenwickTree {
	vector<int> bit; 
	vector<int> original;
	int n;

	FenwickTree(int n) {
		this->n = n;
		bit.assign(n + 1, 0);       
		original.assign(n + 1, 0);  
	}

	FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
		original = vector<int>(a.size() + 1, 0);
		for (int i = 1; i <= n; i++) {
			add(i, a[i - 1]); 
		}
	}

	int sum(int r) {
		int ret = 0;
		for (; r > 0; r -= r & -r)
			ret += bit[r];
		return ret;
	}

	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int idx, int delta) {
		original[idx] += delta;
		for (; idx <= n; idx += idx & -idx)
			bit[idx] += delta;
	}

	void pointUpdate(int idx, int newValue) {
		int delta = newValue - original[idx];
		original[idx] = newValue;
		for (; idx <= n; idx += idx & -idx)
			bit[idx] += delta;
	}

	void print() {
		cout << "Original vector: ";
		for (int i = 1; i <= n; ++i) {
			cout << original[i] << " ";
		}
		cout << endl;

		cout << "Fenwick Tree: ";
		for (int i = 1; i <= n; ++i) {
			cout << bit[i] << " ";
		}
		cout << endl;

		cout << "Prefix sums paths:" << endl;
		for (int i = 1; i <= n; ++i) {
			cout << "bit[" << i << "]: ";
			int idx = i;
			int path_sum = 0;
			vector<int> path;
			while (idx > 0) {
				path.push_back(original[idx]);
				path_sum += original[idx];
				idx -= idx & -idx;
			}
			for (int j = path.size() - 1; j >= 0; --j) {
				cout << path[j] << " ";
			}
			cout << ": " << path_sum << endl;
		}
	}
};

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
			 tree_order_statistics_node_update>
	indexed_set;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename Key, typename Value>
using indexed_map = tree<Key, Value, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;
