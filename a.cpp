
#include <bits/stdc++.h>
using namespace std;

partial_sort(nums.begin(), nums.begin() + 4, nums.end());                    // first 4 min ele
partial_sort(nums.rbegin(), nums.rbegin() + 4, nums.rend(), greater<int>()); // 4 largest ele

/* Function to calculate x raised to the power y in
 * O(logn)*/
int power(int x, int n)
{
    int result = 1;
    while (n > 0)
    {
        if (n & 1 == 1) // y is odd
        {
            result = result * x;
        }
        x = x * x;
        n = n >> 1; // y=y/2;
    }
    return result;
}

int fast_Power(int x, unsigned int y)
{
    int temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}
double solve(double x, long n) // https: // leetcode.com/problems/powx-n/solutions/3808565/binary-exponentiation-concept-theory-recursive-solution-reason-why-use-long-instead-of-int/
{

    if (n == 0)
        return 1; // base case

    if (n < 0)
        return solve(1 / x, -n); // for negative value of n

    if (n % 2 == 0)
    {
        // for even value of n
        return solve(x * x, n / 2); // binary exponentiation
    }
    // for odd value of n
    else
        return x * solve(x * x, (n - 1) / 2);
}

// GET PRIME NUMBER TILL n---> sieve eratosthenes method--> N* log(log(N))
const int N = 1e6 + 1;
vector<bool> prime(N, true);
vector<int> primeNum;
void sieve()
{
    for (int num = 2; num * num <= N; num++)
    {
        if (prime[num] == true)
        {
            // multiple of num and are less than num^2 are
            // already been marked.
            for (int p = i * i; p <= N; i += p) // or int i=i*2;
            {
                prime[p] = false;
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (prime[i] == true)
            primeNum.push_back(i);
    }
}

void sieve(int n, vector<bool> &prime)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

// sort vector of pair
//  1 // Using simple sort() function to sort for FIRST ELEMENT
sort(vect.begin(), vect.end());
// 2      VIA SECOND ELEMENT
sort(vect.begin(), vect.end(), sortbysec);

bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

const int N = 1e3 + 1;
int seg[4 * N];
void build(int ind, int low, int high, vector<int> &a)
{

    if (low == high)
    {
        seg[ind] = a[low];
        return;
    }

    int mid = low + (high - low) / 2;
    build(2 * ind + 1, low, mid, a);
    build(2 * ind + 2, mid + 1, high, a);

    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int querry(int ind, int low, int high, int l, int r)
{
    // if (lazy[ind] != 0)
    // {
    //     seg[ind] = (high - low + 1) * lazy[ind];

    //     if (low != high)
    //     {
    //         lazy[2 * ind + 1] += lazy[ind];
    //         lazy[2 * ind + 2] += lazy[ind];
    //     }
    // }

    if (low >= l && high <= r)
    { /// completely lie
        return seg[ind];
    }

    if (high < l || low > r)
    { // NOT LIE
        return INT_MIN;
    }

    // overlap-->left&right

    int mid = low + (high - low) / 2;

    int left = querry(2 * ind + 1, low, mid, l, r);
    int right = querry(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}

void pointUpdate(int ind, int low, int high, int node, int val)
{
    if (low == high)
    {
        seg[ind] = val; // if val is how much increase than.....=> seg[ind] +=val;
    }
    else
    {
        int mid = (low + high) >> 1;
        if (node <= mid && node >= low)
            ,
                pointUpdate(2 * ind + 1, low, mid, node, val);
        else
            pointUpdate(2 * ind + 2, mid + 1, high, node, val);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
}

// LAZY PROPAGATION ..---> for RANGE UPDATE

int lazy[4 * N];
void rangeUpdate(int ind, int low, int high, int l, int r, int val)
{
    if (lazy[ind] != 0)
    {
        seg[ind] = (high - low + 1) * lazy[ind];

        if (low != high)
        {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
    }

    if (low > r || high < l || low > high)
        return;

    if (low <= l && r <= high)
    {
        seg[ind] += (high - low + 1) * val;
        if (low != high)
        {
            lazy[2 * ind + 1] += val;
            lazy[2 * ind + 2] += val;
        }
        //// 3######//
        return; /////////////////////// return for now
    }

    int mid = (high + low) >> 1;

    rangeUpdate(2 * ind + 1, low, mid, l, r, val);
    rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}
bool isArrayRotated(vector<int> &a, int n)
{
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            cnt++;
    }

    if (cnt == 0)
    {
        return 1;
    }

    if (cnt == 1 && a[n - 1] <= a[0])
        return 1;

    return 0;
}

void printDivisors(int n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, print only one
            if (n / i == i)
                cout << " " << i;

            else // Otherwise print both
                cout << " " << i << " " << n / i;
        }
    }
}

class DisjointSet
{
    vector<int> rank, parent, size;
    int distinctComponents;

public:
    DisjointSet(int n)
    {
        distinctComponents = n;
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int countCompo(int n)
    {
        int cnt = 0;

        for (int i = 0; i < n; i++)
            if (findUltimateParent(i) == i)
                cnt++;

        return cnt;
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        // path compression
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int up_u = findUltimateParent(u);
        int up_v = findUltimateParent(v);

        if (up_u == up_v)
            return;

        distinctComponents--; // decrease the number of components

        if (rank[up_u] < rank[up_v])
        {
            parent[up_u] = up_v;
        }
        else if (rank[up_u] > rank[up_v])
        {
            parent[up_v] = up_u;
        }
        else
        {
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int up_u = findUltimateParent(u);
        int up_v = findUltimateParent(v);

        
        if (up_u == up_v)
            return;

        distinctComponents--; // decrease the number of components
        if (size[up_u] >= size[up_v])
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
        else
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
    }
    
    bool united()
    {
        return distinctComponents == 1;
    }
};

int main()
{
    // dis joint set
    int V;
    // cin >> V;//
    V = 7;

    DisjointSet d(V);

    d.unionBySize(1, 2);
    d.unionBySize(2, 3);
    d.unionBySize(4, 5);
    d.unionBySize(6, 7);
    d.unionBySize(5, 6);

    if (d.findUltimateParent(3) == d.findUltimateParent(7))
    {
        cout << "Same component";
    }
    else
        cout << "different component";
    cout << endl;
    d.unionBySize(3, 7);

    if (d.findUltimateParent(3) == d.findUltimateParent(7))
    {
        cout << "Same component";
    }
    else
        cout << "different component";
}

int dp[20][2][4];

int solve(string &s, int ind, int tight, int cnt)
{
    if (ind == s.size())
        return 1;
    if (ind == s.size())
        return cnt;
    if (dp[ind][tight][cnt] != -1)
        return dp[ind][tight][cnt];

    int limit = (tight == 1 ? (s[ind] - '0') : 9);

    int ans = 0;

    for (int i = 0; i <= limit; i++)
    {
        int updatedCnt = cnt + (i != 0);

        if (updatedCnt <= 3)
            ans += solve(s, ind + 1, (tight & (i == s[ind] - '0')), updatedCnt);
    }
    return dp[ind][tight][cnt] = ans;
}
void code()
{
    ll l, r;
    cin >> l >> r;

    string R = to_string(r);
    memset(dp, -1, sizeof(dp));
    int right = solve(R, 0, 1, 0);

    string L = to_string(l - 1);
    memset(dp, -1, sizeof(dp));
    int left = solve(L, 0, 1, 0);
    cout << right - left << endl;
}