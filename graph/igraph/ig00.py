import igraph as ig

# import matplotlib.pyplot as plt


g = ig.Graph(edges=[[0, 1], [1, 2], [1, 3], [0, 3]])
# g = ig.Graph.Famous("petersen")
# g = ig.Graph.Adjacency([[0, 1, 1], [0, 0, 0], [0, 0, 1]])
# g = ig.Graph.Tree(127, 2)

print(g.summary(verbosity=1))

adj_mat = g.get_adjacency()
print(f"adj mat:\n {adj_mat}")

print(f"nv: {g.vcount()}, ne: {g.ecount()}")

# for v in g.vs:
#     print(v)
# for e in g.es:
#     print(e)

e = g.es[0]
v1, v2 = e.source, e.target

v = g.vs[0]
edges = g.incident(v)
print(edges)

layout = g.layout(layout='auto')
vts_label = ['0', '1', '2', '3']
ig.plot(g, layout="kamada_kawai", vertex_label=vts_label)
