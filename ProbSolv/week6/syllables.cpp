#include <stdio.h>

int main() {
	char word[30];
	int n, vowel, count;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		count = 0;
		vowel = 0;
		scanf(" %s", word);
		for (int j = 0; word[j] != '\0'; j++) {
			if (word[j] == 'a' || word[j] == 'e' ||
				word[j] == 'i' || word[j] == 'o' ||
				word[j] == 'u') {
				vowel++;
			}
			else {
				vowel = 0;
			}
			if (vowel == 1) {
				count++;
			}
		}
		printf("%d\n", count);
	}
}