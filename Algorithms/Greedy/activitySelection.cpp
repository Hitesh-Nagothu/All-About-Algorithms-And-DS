#include <bits/stdc++.h> 
using namespace std;

struct Activity {
    int start, finish;
};

bool activityCompare(Activity s1, Activity s2)
{
    return (s1.start < s2.start);
}

void printMaxActivities(Activity arr[], int n)
{
    sort(arr, arr + n, activityCompare);

    int i = 0;
    cout << "Following activities are selected \n";

    //pick one dude, see next due, if nont overallping, just add that due ad got to next, or else keep moving
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << "(" << arr[j].start << ", " << arr[j].finish << "), ";
            i = j;
        }
    }
}

int main()
{
    // Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, 
    //                   {5, 7}, {8, 9}}; 
    Activity arr[] = { {1,50}, {2,52}, {3,54} };
    int n = sizeof(arr) / sizeof(arr[0]);
    printMaxActivities(arr, n);  //greedy implementation, could also be solved using DP LIS
    return 0;
}
