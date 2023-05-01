from graphviz import Graph

def convexComb (k, u, v):
    if not len(u) == len(v):
        raise ValueError("vectors need to have same length")
    ans = []
    for i in range(len(u)):
        ans.append((1 - k) * u[i] + k * v[i])
    return ans

class Animator:
    def __init__ (self, path, fname, xl, xr, yl, yr):
        self.vertices = {}
        self.edges = {}
        self.frameID = 0
        self.path = path
        self.fname = fname
        self.xlMargin = xl
        self.xrMargin = xr
        self.ylMargin = yl
        self.yrMargin = yr

    def addVertex (self, name, **attrs):
        self.vertices[name] = attrs

    def setVertexAttr (self, name, attr, val):
        self.vertices[name][attr] = val

    def setVertexPos (self, name, x, y):
        self.vertices[name]["pos"] = str(x) + "," + str(y) + "!"

    def addEdge (self, u, v, fillRate, **attrs):
        self.edges[(u, v)] = [0, fillRate, attrs]

    def setFillRate (self, u, v, fillRate):
        self.edges[(u, v)][1] = fillRate

    def setFillDir (self, u, v, fillDir):
        self.edges[(u, v)][0] = fillDir

    def draw (self):
        G = Graph(format="png", engine="neato", directory = self.path)
        G.attr("node", shape = "circle")
        G.attr(splines = "true")
        G.attr(sep = "1")

        G.node("dlMargin", pos = str(self.xlMargin) + "," + str(self.ylMargin) + "!",
               color = "white", fontcolor = "white")
        G.node("drMargin", pos = str(self.xrMargin) + "," + str(self.ylMargin) + "!",
               color = "white", fontcolor = "white")
        G.node("ulMargin", pos = str(self.xlMargin) + "," + str(self.yrMargin) + "!",
               color = "white", fontcolor = "white")
        G.node("urMargin", pos = str(self.xrMargin) + "," + str(self.yrMargin) + "!",
               color = "white", fontcolor = "white")

        for (name, attrs) in self.vertices.items():
            G.node(name, **attrs)
        for (u, v), (fillDir, fillRate, attrs) in self.edges.items():
            if fillRate > 0.005:
                if fillDir == 0:
                    G.edge(u, v, **attrs, penwidth = "3", color = "black;" + str(fillRate) + ":white")
                else:
                    G.edge(v, u, **attrs, penwidth = "3", color = "black;" + str(fillRate) + ":white")
            if fillRate < 0.999:
                if fillDir == 0:
                    G.edge(u, v, **attrs)
                else:
                    G.edge(v, u, **attrs)
        G.render(self.fname + str(self.frameID).zfill(4))
        self.frameID += 1

    def sleep (self, frames):
        for i in range(frames):
            self.draw()

    def moveVertices (self, targets, steps = 40):
        for vertex in targets:
            if not "pos" in self.vertices[vertex]:
                raise ValueError("vertex does not have set position")

        currents = {}
        for vertex in targets:
            currents[vertex] = list(map(int, self.vertices[vertex]["pos"].replace("!", "").split(",")))

        for k in range(1, steps + 1):
            for vertex in targets:
                cc = convexComb(k / steps, currents[vertex], targets[vertex])
                self.setVertexPos(vertex, cc[0], cc[1])
            self.draw()         

    def fillEdge (self, u, v, step = 0.05):
        (p, q) = (u, v)
        if (u, v) in self.edges:
            self.setFillDir(u, v, 0)
            (p, q) = (u, v)
        elif (v, u) in self.edges:
            self.setFillDir(v, u, 1)
            (p, q) = (v, u)
        else:
            raise ValueError("no such edge exists!")

        fillRate = 0
        while fillRate < 0.999:
            fillRate += step
            self.setFillRate(p, q, fillRate)
            self.draw()