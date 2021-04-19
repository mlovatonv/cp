function foo(s1, s2) {
	let diff = 0;
	for (let i = 0; i < s1.length; ++i) {
		if (s1[i] != s2[i]) ++diff;
		if (diff > 1) return false;
	}
	return true;
}

function bfs(graph, size, origin) {
	const q = []; // queue
	const dis = []; // dis[x] = minimum distance from origin to x
	const vis = []; // visited
	for	(let i = 0; i < size; ++i) {
		dis[i] = 700;
		vis[i] = false;
	}
	dis[origin] = 0;
	vis[origin]=true;
	q.push(origin);
	while (q.length > 0) {
		const x = q[0];
		q.shift();
		graph[x].forEach(v => {
			if(!vis[v]){
				dis[v]=dis[x]+1;
				vis[v]=true;
				q.push(v);
			}
		})
	}
	return dis;
}

function wordLadder(beginWord, endWord, wordList) {
	const list = [beginWord, endWord, ...wordList];
	const size = list.length;
	const graph = [];
	for (let i = 0; i < size; ++i) {
		graph[i] = [];
		for (let j = 0; j < size; ++j) {
			if(i !== j && foo(list[i], list[j])){
				graph[i].push(j);
			}
		}
	}
	const dis = bfs(graph, size, 0);
	const ans = dis[1] + 1;
	return ans != 700 ? ans : 0;
}

console.log(wordLadder("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]));
