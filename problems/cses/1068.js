const readline = require('readline').createInterface({
	input: process.stdin,
	output: process.stdout
});

let result = ''

readline.question('', n => {
	result += n
	n = Number(n)
	while (n !== 1) {
		if (n % 2 === 0) {
			n = n / 2;
		} else {
			n = 3 * n + 1;
		}
		result += ' ' + n
	}
	console.log(result)
	readline.close()
});
