#include <stdio.h>
#include <stdlib.h>

int arr[1000000];

int maximum(int a, int b) { if (a > b) return a; else return b; }

int main(){ 

	int n, min = 1000000000, max = 0, avg;
	long long int s, sum;

	scanf("%d %lld", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		max = maximum(max, arr[i]);
	}

	min = 1;

	while (min <= max) {
		sum = 0;
		avg = (max + min) / 2;

		for (int i = 0; i < n; i++) {
			if (arr[i] - avg > 0) sum += (arr[i] - avg);
		}
		if (sum < s) max = avg - 1;
		else min = avg + 1;
	}
	printf("%d", max);
	return 0;
}