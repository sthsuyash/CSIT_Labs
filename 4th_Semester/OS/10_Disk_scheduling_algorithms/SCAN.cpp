// SCAN Disk Scheduling algorithm

#include <bits/stdc++.h>
using namespace std;

int size = 8;
int disk_size = 200;

void SCAN(int arr[], int head, string direction)
{
	int seek_count = 0;
	int distance, cur_track;
	vector<int> left, right;
	vector<int> seek_sequence;

	// appending end values
	// which has to be visited
	// before reversing the direction
	if (direction == "left")
		left.push_back(0);
	else if (direction == "right")
		right.push_back(disk_size - 1);

	for (int i = 0; i < size; i++) {
		if (arr[i] < head)
			left.push_back(arr[i]);
		if (arr[i] > head)
			right.push_back(arr[i]);
	}

	// sorting left and right vectors
	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());

	// run the while loop two times.
	// one by one scanning right
	// and left of the head
	int run = 2;
	while (run--) {
		if (direction == "left") {
			for (int i = left.size() - 1; i >= 0; i--) {
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
			direction = "right";
		}
		else if (direction == "right") {
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
			direction = "left";
		}
	}

	cout << "Total number of seek operations = "
		<< seek_count << endl;
	}

// Driver code
int main()
{

	// request array
	int arr[size] = { 98, 183, 41, 122, 14, 124, 65, 67 };
	int head = 53;
	string direction = "right";

	SCAN(arr, head, direction);

	return 0;
}
