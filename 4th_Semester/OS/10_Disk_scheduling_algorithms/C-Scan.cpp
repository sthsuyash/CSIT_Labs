// C++ program to demonstrate
// C-SCAN Disk Scheduling algorithm
#include <bits/stdc++.h>
using namespace std;

// Code by Vikram Chaurasia

int size = 8;
int disk_size = 200;

void CSCAN(int arr[], int head)
{
	int seek_count = 0;
	int distance, cur_track;
	vector<int> left, right;
	vector<int> seek_sequence;

	// appending end values
	// which has to be visited
	// before reversing the direction
	left.push_back(0);
	right.push_back(disk_size - 1);

	// tracks on the left of the
	// head will be serviced when
	// once the head comes back
	// to the beginning (left end).
	for (int i = 0; i < size; i++) {
		if (arr[i] < head)
			left.push_back(arr[i]);
		if (arr[i] > head)
			right.push_back(arr[i]);
	}

	// sorting left and right vectors
	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());

	// first service the requests
	// on the right side of the
	// head.
	for (int i = 0; i < right.size(); i++) {
		cur_track = right[i];
		// appending current track to seek sequence
		seek_sequence.push_back(cur_track);

		// calculate absolute distance
		distance = abs(cur_track - head);

		// increase the total count
		seek_count += distance;

		// accessed track is now new head
		head = cur_track;
	}

	// once reached the right end
	// jump to the beginning.
	head = 0;

	// adding seek count for head returning from 199 to 0
	seek_count += (disk_size - 1);

	// Now service the requests again
	// which are left.
	for (int i = 0; i < left.size(); i++) {
		cur_track = left[i];

		// appending current track to seek sequence
		seek_sequence.push_back(cur_track);

		// calculate absolute distance
		distance = abs(cur_track - head);

		// increase the total count
		seek_count += distance;

		// accessed track is now the new head
		head = cur_track;
	}

	cout << "Total number of seek operations = "
		<< seek_count << endl;

	cout << "Seek Sequence is" << endl;
}

// Driver code
int main()
{

	// request array
	int arr[size] = { 98, 183, 41, 122, 14, 124, 65, 67};
	int head = 53;

	cout << "Initial position of head: " << head << endl;
	CSCAN(arr, head);

	return 0;
}
