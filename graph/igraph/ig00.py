
import matplotlib.pyplot as plt
import igraph as ig


# g = ig.Graph.Famous("petersen")
g = ig.Graph(edges=[[0, 1], [1, 2], [1, 3], [0, 3]])
vts_label = ['0', '1', '2', '3']
# g = ig.Graph.Adjacency([[0, 1, 1], [0, 0, 0], [0, 0, 1]])

print(g.summary(verbosity=1))

nv = g.vcount()
ne = g.ecount()

for v in g.vs:
    print(v)
for e in g.es:
    print(e)

e = g.es[0]
v1, v2 = e.source, e.target

v = g.vs[0]
edges = v.incident()

fig, ax = plt.subplots()
ig.plot(g, target=ax, vertex_label=vts_label)
plt.show()
