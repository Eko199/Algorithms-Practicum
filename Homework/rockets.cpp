#include<bits/stdc++.h>
using namespace std;

pair<unsigned, unsigned long> buildings[300005];
pair<unsigned, unsigned> rockets[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	size_t n, m;
	cin >> n >> m;
	
	for (size_t i = 0; i < n; ++i) {
		cin >> buildings[i].second >> buildings[i].first;
	}
	
	for (size_t i = 0; i < m; ++i) {
		cin >> rockets[i].first >> rockets[i].second;
	}
	
	sort(rockets, rockets + m);
	
	unsigned long width = 0;
	unsigned result = 0;
	size_t rocketI = 0;
	
	for (size_t i = 0; i < n; ++i) {
		width += buildings[i].second;
		
		while (rocketI < m && rockets[rocketI].first <= width) {
			if (rockets[rocketI].second <= buildings[i].first
			     ||  rockets[rocketI].first == width && i < n - 1 && rockets[rocketI].second <= buildings[i + 1].first) {
				++result;
			}
			
			++rocketI;
		}
	}
	
	cout << result;
	return 0;
}