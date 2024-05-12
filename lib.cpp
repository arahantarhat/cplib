#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <tuple>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

#define int long long
typedef long double ld;
typedef pair<int, int> pii;
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair
#define L first
#define R second

// safe double operations and etc

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


long long div_ceil (long long a, long long b) {
	return (b ›= 0 ? (a + b - 1) : a) / b;
}

int binpow(int a, int b){
	int r = 1;
	while(b){
		if(b & 1){
			r = r * a;
		}
		a = a * a;
		b >>= 1;
	}
	return r;
}

// number theory

bool isPrime(int n){
	if(n <= 1) return 0;
	for(int i = 2; i < (n / 2); i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

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

int modFactorial(int n, int m) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result = (result * i) % m;
    }
    return result;
}

int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedGCD(a, m, x, y);
    if (gcd != 1) return -1; // Modular inverse does not exist
    return (x % m + m) % m;
}

// combinatorics

int permutations(int n, int k) {
    return factorial(n) / factorial(n - k);
}

int combinations(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int binomialCoefficient(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

int catalanNumber(int n) {
    return binomialCoefficient(2 * n, n) / (n + 1);
}
