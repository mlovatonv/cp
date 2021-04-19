const livingWarriors = function (warriors) {
	return warriors.reduce(function (acc, w) { return w.h > 0 ? acc + 1: acc; }, 0);		
}

function allianceVersusMonster(healthPoints, attackDamage) {
	let monsterH = healthPoints[0];
	const monsterA = attackDamage[0];
	const warriorsA = attackDamage.slice(1, attackDamage.length);
	const warriors = healthPoints.slice(1, healthPoints.length).map(
		function (h, idx) { return {h, a: warriorsA[idx] } });
	warriors.sort(function (x, y) { return x.a - y.a }).reverse();
	for (let i = 0; i < warriors.length; ++i) {
		const warrior = warriors[i];
		let attacks = Math.floor(warrior.h / monsterA);
		if (attacks > 0 && warrior.h % monsterA === 0) {
			attacks -= 1;
		}
		monsterH -= attacks * warrior.a;
		if (monsterH <= 0) break;
		warrior.h -= attacks * monsterA;
	}
	if (monsterH > 0) {
		for (let i = 0; i < warriors.length; ++i) {
			const warrior = warriors[i];
			monsterH -= warrior.a;
			if (monsterH <= 0) break;
			warrior.h -= monsterA;
		}
	}
	if (monsterH > 0) return 0;
	return livingWarriors(warriors);
}

console.log(allianceVersusMonster([110, 30, 50], [12, 11, 20]));
