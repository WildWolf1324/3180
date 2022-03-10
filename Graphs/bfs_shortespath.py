graph = {
  'A' : ['B','C'],
  'B' : ['D', 'E'],
  'C' : ['F'],
  'D' : [],
  'E' : ['F'],
  'F' : []
}

visited = {} # Hashtable to keep track of visited nodes and distance.
queue = []     #Initialize a queue

def bfs(visited, graph, node):
  visited[node] = 0
  queue.append(node)

  while queue:
    s = queue.pop(0) 
    print (s, end = " ") 

    for neighbour in graph[s]:
      if neighbour not in visited:
        visited[neighbour] = visited[s]+1
        queue.append(neighbour)

# Driver Code
bfs(visited, graph, 'A')
print();
for key, val in visited.items():
	print(key, val)
