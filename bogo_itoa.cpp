/****************************************************************************
  MIT License

  Copyright (c) 2017 John McDonald

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int atoi(const char* a)
{
	int result = 0;
	if (!a)
		return result;

	bool b_neg = a[0] == '-';
	if (b_neg)
		++a;

	while (a[0])
	{
		int digit = a[0] - '0';
		if (digit < 0 || digit > 9)
			return result;
		result = result * 10 + digit;
		++a;
	}

	if (b_neg)
		result *= -1;

	return result;
}

char* bogo_itoa(int n)
{
	char* result = new char[12];

	do {
		int n_chars = 1 + (rand() % (ARRAY_SIZE(result) - 2));
		int start = rand() % 2;

		if (start != 0) {
			n_chars += 1;
			result[0] = '-';
		}

		for (int i = start; i < n_chars; ++i)
			result[i] = '0' + (rand() % 10);
		result[n_chars] = 0;

		if (result[0] == '-' && result[1] == '0' && result[2] == 0)
			continue;
	} while(atoi(result) != n);

	return result;
}

int main(int argc, char* argv[])
{
	srand(42);

	printf("%d\n", atoi("0"));
	printf("%d\n", atoi("-1"));
	printf("%d\n", atoi("1"));
	printf("%d\n", atoi("10"));
	printf("%d\n", atoi("-2147483648"));
	printf("%d\n", atoi("2147483647"));

	printf("%s\n", bogo_itoa(0));
	printf("%s\n", bogo_itoa(-1));
	printf("%s\n", bogo_itoa(1));
	printf("%s\n", bogo_itoa(142));

	return 0;
}
