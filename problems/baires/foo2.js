function ConsecutiveCharacterRepeatedOnce(str) {
	let ans = "";
	const n = str.length;
	let i = 0, j = 0;
	while (i < n) {
		j = i + 1;
		while (j < n) {
			if (str[j] != str[i]) break;
			++j;
		}
		if ((j - i) == 2){
			ans += str[i];
		}
		i += (j - i);
	}
	return ans;
}

