function checkLuhnNumber(number) {
	const n = number.length;
	let acc = 0;
	for (let i = 0; i < n; ++i) {
		let digit = parseInt(number[i]);
		if (digit & 1) {
			digit *= 2;
			if (digit >= 10) {
				digit -= 9;
			}
		}
		acc += digit;
	}
	return acc % 10 != 0;
}

function getNumber(amount){
	return parseInt(amount.slice(1))
}

function creditCardProvider(operations) {
	const db = {};
	operations.forEach(op => {
		switch (op[0]) {
			case "Add": {
				let value;
				if (checkLuhnNumber(op[2])) {
					value = {
						balance: 0,
						limit: getNumber(op[3]),
					}			
				} else {
					value = "error"
				}
				db[op[1]] = value;
				break;
			}
			case "Charge": {
				if (!db[op[1]] || db[op[1]] == "error") {
					break;
				}
				const amount = getNumber(op[2]);
				const account = db[op[1]];
				if (account.balance + amount <= account.limit){
					db[op[1]].balance = account.balance + amount;	
				}
				break;
			}
			case "Credit": {
				if (!db[op[1]] || db[op[1]] == "error") {
					break;
				}
				const amount = getNumber(op[2]);
				const account = db[op[1]];
				db[op[1]].balance = account.balance - amount;	
				break;
			}
			default: break;
		}
	})
	const ans = Object.keys(db).map(
		key => [key, (db[key] === "error" ? "error" : `$${db[key].balance}`) ])
	return ans;
}


