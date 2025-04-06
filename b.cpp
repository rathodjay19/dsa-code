// bit mask

int solve(int mask, vector<vector<int>> &a, vector<int> &dp)
{
    int ind = __builtin_popcount(mask), ans = 0;

    if (ind == a.size())
        return 1;

    if (dp[mask] != -1)
        return dp[mask];

    for (int w = 0; w < a.size(); w++)
    {
        if (a[ind][w] == 1 && !(mask & 1 << w))
        {
            ans = (ans + solve(mask | (1 << w), a, dp)) % mod;
        }
    }

    return dp[mask] = ans;
}
void code()
{
    ll n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    fi(0, n)
    {
        fj(0, n) cin >> a[i][j];
    }

    int mask = 1 << n;
    vector<int> dp(mask, -1);
    // cout<<solve( 0, a,dp);

    function<int(int)> solve = [&](int mask) -> ll
    {
        int ind = __builtin_popcount(mask), ans = 0;
        if (ind == a.size())
            return 1;
        if (dp[mask] != -1)
            return dp[mask];

        for (int w = 0; w < a.size(); w++)
        {
            if (a[ind][w] == 1 && !(mask & 1 << w))
                ans = (ans + solve(mask | (1 << w))) % mod;
        }
        return dp[mask] = ans;
    };
    cout << solve(0) << endl;
}

// PBDS" stands for Policy-Based Data Structures

/*
Given an array arr containing non-negative integers. Count and return an array ans where ans[i] denotes the number of smaller elements on right side of arr[i].

Examples:

Input: arr[] = [12, 1, 2, 3, 0, 11, 4]
Output: [6, 1, 1, 1, 0, 1, 0]
Explanation: There are 6 smaller elements right after 12. There is 1 smaller element right after 1. And so on.



int: The type of elements in the set.
null_type: Indicates that the set does not map keys to values.
less_equal<int>: Allows duplicate elements by using less_equal comparator.
rb_tree_tag: Specifies that the underlying data structure is a red-black tree.
tree_order_statistics_node_update: A tag to enable order statistics.
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

class Solution
{
public:
    vector<int> constructLowerArray(vector<int> &arr)
    {
        ordered_set o_set;
        vector<int> ans(arr.size(), 0);
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            ans[i] = o_set.order_of_key(arr[i]);
            o_set.insert(arr[i]);
        }
        return ans;
    }
};

/////////////////////// ===>1 BASED INDEXING
// https : // leetcode.com/problems/count-number-of-teams/?envType=daily-question&envId=2024-07-29

const int N = 1e5 + 10;
int bit[N]; // 1 based

// bit[i]= sum from j+1 to ith index              ,here j=ith number-rightmostbit

// ith index 's value do +=x;--> so we have to change all value which contain ith index in bit array

// i&-i --> give right most bit of number
// in update we are adding this bit to every index in bit
void update(int i, int x)
{
    for (; i < N; i += (i & -i))
        bit[i] += x;
}

// 13 -1101
// 12 =1100-->13 to 13
// 8  =1000-->9 to 12
// 0  =0000 ->1 to 8
int sum(int i) // give sum till ith index --> 13= 1101
{
    int ans = 0;
    for (; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

int main()
{
    for (int i = 1; i <= n; i++)
    {
        update(i, a[i - 1]); // update(i,a[i])
    }

    while (q--)
    {
        if (qq[i][0] == 1) // type 1 query --> update ith index by value X;
        {
            update(i, x - a[i]);
            a[i] = x;
        }
        else
        { // give sum from l to r

            cout << sum(r) - sum(l - 1) << endl;
        }
    }
}

//  inversion count==> a[i] > a[j] && i < j

// 8 4 9 2 8
// 0 1 0 3 1

// for 8   --> sum(max)-sum(8)==0 then do bit[8]=1;    0 0 0 0 0 0 0 1 0 0 0
// now for 4-> sum(max)-sum(4) =1 then do bit[4]=1     0 0 0 1 0 0 0 1 0 0 0
// 9 --> 0-0 =0
// 2 ---> 3-0==3

for (int i = 1; i <= n; i++)
{
    ans[i] = (sum(n) - sum(a[i])); //// here a[i]<=1e5  so making array is possible but
    update(a[i], 1);
}

// but what if===> a[i]>=1e5--===> 1e18??????????/

// do we really need big number for our answer
// because at max number of distict element can be N== 1e5

// [ 1e9, 1e8, 1e5,10,100,1e8]???? we can't make 1e9 array--> do mapping
// [  5 ,  4 ,  3,  1, 2 , 4 ]??? answer for both will be same

//  HOW TO DO MAPPING

map<long long, int> mp;
for (int i = 0; i < N; i++)
    mp[a[i]]; // just put value;

now give its key in sorted order by starting 1

    int cnt = 1;
for (auto &it : mp)
{
    it.second = cnt;
    cnt++;
}

for (int i = 0; i < N; i++)
{
    a[i] = mp[a[i]];
}

int countSubstring(const string &s)
{
    int count = 0;
    size_t pos = s.find("1100");

    while (pos != string::npos)
    {
        count++;
        pos = s.find("1100", pos + 1); // Move to the next occurrence
    }

    return count;
}
