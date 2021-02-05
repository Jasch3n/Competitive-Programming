graph = {}

def add_vertex(v):
    global graph
    graph[v] = []

def add_edge_from(v1, v2):
    global graph
    if v1 not in graph:
        graph[v1] = []
    graph[v1].append(v2)

def print_graph(G):
    for i in graph.keys():
        for j in range (len(graph[i])):
            print(i, "->", graph[i][j])

no_superior_list = []
n = int(input())
for i in range(1, n + 1):
    add_vertex(i)
for i in range(1, n + 1):
    superior = int(input())
    if superior != -1:
        add_edge_from(superior, i)
    else:
        no_superior_list.append(i)

def recur(superior):
    max = 0
    if not graph[superior]:
        return 0
    for underling in graph[superior]:
        temp = 1 + recur(underling)
        if temp > max:
            max = temp
    return max

ans = 0
for superior in no_superior_list:
    ans_guess = recur(superior)
    if  ans_guess > ans:
        ans = ans_guess
print(ans + 1)
#print_graph(graph)