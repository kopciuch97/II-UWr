#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main() {
	unsigned int m, n, t, a1, a2, b1, b2;
	scanf("%d %d %d", &m, &n, &t);
	
	vector<pair<pair<unsigned int, unsigned int>, pair<unsigned int, unsigned int> > > vec;
	map<pair<unsigned int, unsigned int>, unsigned int> MapOfPoints;
	
	for(unsigned int i = 0; i < t; i++) {
		scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
		vec.push_back(make_pair (make_pair(a1, b1), make_pair(a2, b2)));
		MapOfPoints[make_pair(a2, b2)] = 0;
	}

	sort(vec.begin(), vec.end());
	MapOfPoints[make_pair(0,0)] = 1;
	
	for (unsigned int i = 0; i < t; i++) {
		MapOfPoints[(vec[i]).second] = (MapOfPoints[(vec[i]).second] + MapOfPoints[(vec[i]).first]) % 999979;
	}

	printf("%d", MapOfPoints[make_pair(m,n)]);
	return 0;
}
