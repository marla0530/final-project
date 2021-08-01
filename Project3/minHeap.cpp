#include "minHeap.h"

void minHeap::insert(string name, double power) {
	//add new element
	heap.push_back(make_pair(name, power));

	filterUp(heap.size() - 1);

}

void minHeap::filterUp(int index) {

	int parent = (index - 1) / 2;
	if ((parent >= 0) && ((heap[index].second < heap[parent].second) || ((heap[index].second == heap[parent].second) && heap[index].first < heap[parent].first)))
	{
		swap(heap[index], heap[parent]);
		filterUp(parent);
	}
}


void minHeap::pop() {
	swap(heap[0], heap[heap.size() - 1]);
	heap.pop_back();
	heapifyDown(0);
}


void minHeap::heapifyDown(int index) {

	int smallest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;


	if (left < heap.size() && heap[smallest].second >= heap[left].second)
	{
		smallest = left;
	}
	if (right < heap.size() && heap[smallest].second >= heap[right].second) {
		smallest = right;
		if (heap[left].second == heap[right].second) {
			if (heap[left].first < heap[right].first) {
				smallest = left;
			}
			else {
				smallest = right;

			}
		}
	}
	if (index != smallest) {
		swap(heap[index], heap[smallest]);
		heapifyDown(smallest);
	}

}

stack<pair<string, double>> minHeap::storeData() {
	stack<pair<string, double>> s;
	int temp = heap.size();
	for (int i = 0; i < temp; i++) {
		s.push(heap[0]);
		pop();
	}
	return s;
}

vector<pair<string, double >> minHeap::topX(int x) {
	auto s = storeData();
	vector<pair<string, double >> temp;
	for (unsigned int i = 0; i < x; i++) {
		temp.push_back(s.top());
		s.pop();
	}
	return temp;
}
