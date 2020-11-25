#include "Global.h"

vector<int>* bridge;
bool* visited;
int* previous;

void BFS::Bridge(int _f, int _t) {
	if (find(bridge[_f].begin(), bridge[_f].end(), _t) == bridge[_f].end()) bridge[_f].push_back(_t);
	if (find(bridge[_t].begin(), bridge[_t].end(), _f) == bridge[_t].end()) bridge[_t].push_back(_f);
}

void BFS::Search(int _root) {
	queue<int> queue;
	queue.push(_root);
	visited[_root] = true;

	while (!queue.empty()) {
		int x = queue.front();
		queue.pop();
		cout << x << " ";
		for (int i = 0; i < bridge[x].size(); i++) {
			int y = bridge[x][i];
			if (!visited[y]) {
				queue.push(y);
				visited[y] = true;
			}
		}
	}
	cout << endl;
}

void BFS::SearchToDest(int _root, int _dest) {
	queue<int> queue;
	queue.push(_root);
	visited[_root] = true;
	list<int> path;
	
	while (!queue.empty()) {
		int x = queue.front();
		queue.pop();
		for (int i = 0; i < bridge[x].size(); i++) {
			int y = bridge[x][i];
			if (!visited[y]) {
				queue.push(y);
				visited[y] = true;
				if (y == _dest) {
					int parent = x;
					path.push_front(y);
					while (previous[x] > 0) {
						path.push_front(x);
						x = previous[x];
					}
					list<int>::iterator iter;
					cout << "최단 경로는 ";
					for (iter = path.begin(); iter != path.end(); iter++) {
						cout << *iter << " ";
					}
					cout << "입니다." << endl;
					return;
				}
				previous[y] = x;
			}
		}
	}
}

int BFS::Main() {
	bridge = new vector<int>[7];
	Bridge(0, 1);
	Bridge(0, 4);
	Bridge(0, 5);
	Bridge(1, 2);
	Bridge(1, 3);
	Bridge(1, 4);
	Bridge(2, 3);
	Bridge(2, 6);
	Bridge(3, 5);
	Bridge(5, 6);
	visited = new bool[7]{false};
	previous = new int[7]{-1};

	srand((unsigned int)time(NULL));
	int start = rand() % 7;
	int end = rand() % 7;

	cout << "시작 : " << start << endl;
	cout << "목적지 : " << end << endl;
	SearchToDest(start, end);

	delete[] bridge;
	return 0;
}