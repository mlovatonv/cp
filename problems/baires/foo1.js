function validate(balances, requestIdx, fromIdx, toIdx, amount) {
	if (
		(fromIdx && fromIdx > balances.length) ||
		(toIdx && toIdx > balances.length) ||
		(fromIdx && balances[fromIdx - 1] < amount)
	) {
		console.log(balances, requestIdx, fromIdx, toIdx, amount);
		throw -parseInt(requestIdx + 1);
	}
}

function transfer(balances, requestIdx, fromIdx, toIdx, amount) {
	validate(balances, requestIdx, fromIdx, toIdx, amount);
	balances[fromIdx - 1] -= amount;
	balances[toIdx - 1] += amount;
}

function deposit(balances, requestIdx, toIdx, amount) {
	validate(balances, requestIdx, null, toIdx, amount);
	balances[toIdx - 1] += amount;
}

function withdraw(balances, requestIdx, fromIdx, amount) {
	validate(balances, requestIdx, fromIdx, null, amount);
	balances[fromIdx - 1] -= amount;
}

function bankRequests(balances, requests) {
	try {
		requests.forEach((request, requestIdx) => {
			const words = request.split(" ");
			const op = words[0];
			switch (op) {
				case "withdraw":
					withdraw(balances, requestIdx, parseInt(words[1]), parseInt(words[2]));
					break;
				case "transfer":
					transfer(balances, requestIdx, parseInt(words[1]), parseInt(words[2]), parseInt(words[3]));
					break;
				case "deposit":
					deposit(balances, requestIdx, parseInt(words[1]), parseInt(words[2]));
					break;
			}
		})
		return balances;
	} catch (err) {
		return [err];
	}
}

console.log(bankRequests([10, 100, 20, 50, 30], ["withdraw 2 10", "transfer 5 1 20", "deposit 5 20", "transfer 3 4 15"]));
