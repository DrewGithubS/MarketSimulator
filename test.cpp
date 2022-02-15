#include "SortedList.cpp"
#include <cstdio>

int main() {
	SortedList<int, false> * test = new SortedList<int, false>();
	fflush(stdout);
	int array[10] = {4, -65757655, 4343, 8, 1, 765765, 9, -2, 6, 7000000};
	for(int i = 0; i < 10; i++) {
		printf("\t%d inserting %d\n", i, array[i]);
		fflush(stdout);
		test->insert(&test, array[i]);
		// printf("1\n");
		SortedList<int, false> * test2 = test;
		for(int j = 0; j <= i; j++) {
			printf("%d ", test2->getHeadData());
			fflush(stdout);
			test2 = test2->getNext();
		}
		printf("\n");
		fflush(stdout);
	}

	test->removeHead(&test);

	for(int j = 0; j < 9; j++) {
		printf("%d ", test->getHeadData());
		fflush(stdout);
		test = test->getNext();
	}
}
