
import matplotlib.pyplot as plt
import igraph as ig

fig, ax = plt.subplots()
g = ig.Graph.Famous("petersen")
ig.plot(g, target=ax)
plt.show()
