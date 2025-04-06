//MODULAR MULTIPLICATIVE INVERSE

(a / b) % m != (a % m / b % m) % m;

(a / b) % m = (a * b ^ -1) % m;
= (a % m * b ^ -1 % m) % m;

/*
so how to find b^-1??

b* inverse(b)==1

(b*inv(b))%mod==1;

invb(b)--> 1 to mod-1===>    T.C. => O(MOD);



fermet theorum
a^(m-1) = 1.mod m
a^(m-2) = a^-1 mod m
a^(m-2)%mod= a^-1;

done
*/

const ll N = 2e5 + 5;

ll fact[N];
ll invFact[N];

ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void init()
{
    fact[0] = 1;
    f(i, 1, N)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    invFact[N - 1] = power(fact[N - 1], mod - 2);
    rf(i, N - 2, 0)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }
}

ll nCr(ll n, ll r)
{
    if (r > n || r < 0)
        return 0;
    return ((fact[n] * invFact[n - r]) % mod * invFact[r]) % mod;
}




// print nCr

const int N = 2e5 + 2;
int fact[N];

int main(){
    fact[0] = 1;
    for (int i = 1; i <= N;i++){
        fact[i] = (fact[i - 1] * 1LL * i) % mod;
    }

    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k; // nCr= n! / (r! * (n-r)!)
        // we can't do normal mod in this, because of divison

        int ans = fact[n];
        int denominator = (fact[r] *1LL * fact[n - r]) % mod;

        // ans=ans/denominator;
        ans = ans * power(denominator, mod - 2);
    }
}



// find how many times given string comes at most times as distinct subsequence

string tar = "back";

backback = > 2 bbaack = > 1 //(   distict--> any char in at most one subsequence)
                        bxabcacfkck = > 2

                                      map<char, int>
                                          mp;
for (int i = n - 1; i >= 0; i--)
{
    if (s[i] == 'k')
        mp[s[i]]++;
    else if (s[i] == 'c')
    {
        if (mp['k'] > 0)
        {
            mp['k']--;
            mp['c']++;
        }
    }
    else if (s[i] == 'a')
    {
        if (mp['c'] > 0)
        {
            mp['c']--;
            mp['a'] += ;
        }
    }
    else if (s[i] == 'b')
    {
        if (mp['a'] > 0)
        {
            mp['a']--;
            mp['b']++;
        }
    }
}

number of times "back" = > mp['b'];
number of times "ack" = > mp['a'];