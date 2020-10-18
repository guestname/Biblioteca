#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// Primes for NTT
// 65537        = 1 + (2 ^ 16)
// 7340033      = 1 + 7 * (2 ^ 20)
// 998244353    = 1 + 7 * 17 * (2 ^ 23)
// 469762049    = 1 + 7 * (2 ^ 26)
// 167772161    = 1 + 5 * (2 ^ 25)

template<typename T>
void fft(vector<T>& p, vector<T>& aux, T x, int idx, int n)
{
    if (n == 1) return;

    int k = n >> 1, ldx = idx, rdx = idx + k;

    for (int i = 0, cur = ldx, nxt = rdx; i < n; ++i, swap(cur, nxt))
        aux[cur + (i >> 1)] = p[idx + i];

    fft(aux, p, x * x, ldx, k), fft(aux, p, x * x, rdx, k);

    for (auto [i, xp] = tuple(0, T(1)); i < n; ++i, xp *= x)
        p[idx + i] = aux[ldx + (i % k)] + xp * aux[rdx + (i % k)];
}

template<typename T>
void fft(vector<T>& p, T root)
{
    assert(__builtin_popcount(size(p)) == 1);
    static vector<T> aux;
    aux.resize(max(size(aux), size(p)));
    fft(p, aux, root, 0, size(p));
}

template<typename T>
vector<T> multiply(vector<T> p, vector<T> q, T root)
{
    fft(p, root), fft(q, root);
    for (int i = 0; i < size(p); ++i) p[i] *= q[i];

    fft(p, T(1) / root);
    for (int i = 0; i < size(p); ++i) p[i] /= T(size(p));

    return p;
}

int main()
{ _
    exit(0);
}