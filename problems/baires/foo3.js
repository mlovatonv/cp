function alarmClock(setTime, timeToSet) {
	const [hour1, minute1] = setTime.split(":").map(s => parseInt(s));
	const [hour2, minute2] = timeToSet.split(":").map(s => parseInt(s));

	const hourChanges = Math.min(Math.abs(hour1 - hour2), hour1 + (24 - hour2));
	const minuteChanges = Math.min(Math.abs(minute1 - minute2), minute1 + (60 - minute2));

	return hourChanges + minuteChanges;
}

