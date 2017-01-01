-- SJ version
console : (
	main :# (params : required#array<string>) {
		write('Pick a number:')
		num1 : read<int>()
		num2 : read<int>()
		write(num1 * num2)
	}
)

-- C version
int main(int argc, char* argv[]) {
	int num1, num2;
	printf('Pick a number:');
	scanf('%d', &num1);
	scanf('%d', &num2);
	printf('%d', num1 * num2)
}