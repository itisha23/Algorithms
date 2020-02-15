	#include<iostream>
	#include<vector>
	#include<set>
	#define f(i,a,b) for(i=a; i<b; i++)

	//Assumning unique triplets

    // count all triplets such that A[i] > A[j] > A[k] such that i<j<k;

	using namespace std;
	typedef long long int ll;

	int main() {

		ll t;
		cin >> t;
		while (t--) {
			ll n, i, x, ind;
			cin >> n;
			vector<ll>vec;
			f(i, 0, n) {
				cin >> x;
				vec.push_back(x);
			}

			int* greater = new int[n];
			int* smaller = new int[n];

			for (i = 0; i < n; i++) {
				greater[i] = 0;
				smaller[i] = 0;
			}


			set<ll>se;
			se.insert(vec[n - 1]);

			for (i = n - 2; i >= 0; i--) {
				ind = distance(se.begin(), se.lower_bound(vec[i]));
				smaller[i] = ind;
				se.insert(vec[i]);
			}

			set<ll>se2;
			se2.insert(vec[0]);

			for (i = 1; i < n; i++) {
				ind = distance(se2.lower_bound(vec[i]), se2.end());
				greater[i] = ind;
				se2.insert(vec[i]);
			}


			for (i = 0; i < n; i++)
				cout << smaller[i] << " ";

			cout << endl;

			for (i = 0; i < n; i++)
				cout << greater[i] << " ";


		}
	}