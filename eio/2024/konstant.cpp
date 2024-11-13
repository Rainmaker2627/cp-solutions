#include <vector>
#include <tuple>
#include "secret_int.h"

secret_int ith_element(std::vector<secret_int> A, secret_int i) {
	secret_int x = secret_int(0);
	for (int j = 0; j < A.size(); ++j) {
		x += (j == i) * A[j];
	} return x;
}

void sort_arr(std::vector<secret_int>& A) {
	int n=A.size();
	for (int p = 1; p < n; p*=2) {
		for (int k = p; k >= 1; k/=2) {
			for (int j = k%p; j <= n-1-k; j+=2*k) {
				for (int i = 0; i <= std::min(k-1, n-j-k-1); ++i) {
					if ((i+j)/(2*p) == (i+j+k)/(2*p)) {
						secret_int a = A[i+j], b = A[i+j+k];
						A[i+j] = (a<=b)*a+(a>b)*b;
						A[i+j+k] = (a<=b)*b+(a>b)*a;
					}
				}
			}
		}
	}
}

secret_int connected_components(std::vector<std::vector<secret_int>> A) {
	int n=A.size();
	const int inf = 10000000;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			A[i][j]=A[i][j]+((A[i][j]==0)*(i!=j))*inf;
		}
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				A[i][j]=A[i][j]*(A[i][j]<=A[i][k]+A[k][j]) + (A[i][k]+A[k][j])*(A[i][j]>A[i][k]+A[k][j]);
			}
		}
	}

	secret_int c=0;
	std::vector<secret_int> t(n, 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c=c+(A[i][j]!=inf)*t[i];
			t[j]=t[j]*(A[i][j]==inf);
		}
	}
	return c;
}

#include<algorithm>
std::tuple<secret_int, secret_int, std::vector<secret_int>> graph_path(std::vector<std::vector<secret_int>> A, secret_int B, secret_int C) {
	int n = A.size();
	const std::uint32_t inf = 4294967295;

	std::vector<secret_int> d(n, 0), p(n, 0);
	for (int i = 0; i < n; ++i) {
		d[i]=inf*(i!=B); p[i]=i;
	}

	for (int i = 0; i < n-1; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				p[k] = p[k]*((d[k]<=d[j]+A[j][k])+(A[j][k]==0)+(d[j]==inf)>0) + j*(d[k]>d[j]+A[j][k])*(A[j][k]>0)*(d[j]<inf);
				d[k] = d[k]*((d[k]<=d[j]+A[j][k])+(A[j][k]==0)+(d[j]==inf)>0) + (d[j]+A[j][k])*(d[k]>d[j]+A[j][k])*(A[j][k]>0)*(d[j]<inf);
			}
		}
	}

	secret_int x=ith_element(d, C), y=2-(B==C);
	std::vector<secret_int> t(n, 0), z(n, 0); t[0]=C;
	for (int i = 1; i <= n; ++i) {
		t[i]=ith_element(p, t[i-1]);
		y = y+(t[i]!=B);
	}

	for (int i = 0; i < n; ++i) {
		z[i]=ith_element(t, y+i-(y+i>=n)*n);
	} std::reverse(z.begin(), z.end());
	
	return std::make_tuple(x, y, z);
}

std::vector<int> primes;
secret_int is_prime(secret_int N) {
	secret_int p=1;

	int n=1<<16;
	if (primes.size()==0) {
		std::vector<bool> prime(1<<16, true);
		prime[0] = prime[1] = false;
		for (int i = 0; i*i <= n; ++i) {
			if (!prime[i]) continue;
			for (int j = i*i; j <= n; j+=i) {
				prime[j]=false;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (prime[i]) primes.push_back(i);
		}
	}

	int x=30;
	for (int i : primes) {
		while (4294967295/i < (1<<x)) x--;
		secret_int a=N, b=i, q=0;
		for (int j = x; j >= 0; --j) {
			q=q+(1<<j)*((i<<j)<=a);
			a=a-(i<<j)*((i<<j)<=a);
		} p=p*(((N-q*i)>0)*(N!=i)+(N==i));
 	}

	return p*(N!=1);
}
