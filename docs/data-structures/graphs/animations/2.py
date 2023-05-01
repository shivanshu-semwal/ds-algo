from animator import Animator

def toAnimLabel (num):
    return "v" + str(num + 1)
            
class DFSAnimator:    
    def __init__ (self, inFileName, outDir, outFileName):
        fi = open(inFileName, "rt")
        (vertexc, edgec) = map(int, fi.readline().split())
        self.vertexc = vertexc
        self.edgec = edgec

        self.initCoords = [(0, 0) for i in range(vertexc)]
        self.finalCoords = [(0, 0) for i in range(vertexc)]
        for i in range(vertexc):
            (ix, iy, tx, ty) = map(int, fi.readline().split())
            self.initCoords[i] = [ix, iy]
            self.finalCoords[i] = [tx, ty]
        xlMargin = min(min(i[0] for i in self.initCoords),
                       min(t[0] for t in self.finalCoords)) - 1
        xrMargin = max(max(i[0] for i in self.initCoords),
                       max(t[0] for t in self.finalCoords)) + 1
        ylMargin = min(min(i[1] for i in self.initCoords),
                       min(t[1] for t in self.finalCoords)) - 1
        yrMargin = max(max(i[1] for i in self.initCoords),
                       max(t[1] for t in self.finalCoords)) + 1

        self.animator = Animator(outDir, outFileName, xlMargin, xrMargin, ylMargin, yrMargin)
            
        for i in range(vertexc):
            self.animator.addVertex(toAnimLabel(i), label = str(i + 1))
            self.animator.setVertexPos(toAnimLabel(i), self.initCoords[i][0], self.initCoords[i][1])
            self.animator.setVertexAttr(toAnimLabel(i), "style", "filled")
            self.animator.setVertexAttr(toAnimLabel(i), "fillcolor", "white")

        self.adj = [[] for i in range(vertexc)]
        for i in range(edgec):
            (u, v) = map(int, fi.readline().split())
            self.adj[u].append(v)
            self.adj[v].append(u)
            self.animator.addEdge(toAnimLabel(u), toAnimLabel(v), 0)

        fi.close()

    def drawBuildDFS (self, vertex, visited):
        visited[vertex] = True
        self.animator.setVertexAttr(toAnimLabel(vertex), "fillcolor", "red")
        self.animator.sleep(10)
        for nxt in self.adj[vertex]:
            if not visited[nxt]:
                self.animator.setVertexAttr(toAnimLabel(vertex), "fillcolor", "gray")
                self.animator.fillEdge(toAnimLabel(vertex), toAnimLabel(nxt))
                self.drawBuildDFS(nxt, visited)
                self.animator.setVertexAttr(toAnimLabel(vertex), "fillcolor", "red")
                self.animator.sleep(10)
        self.animator.setVertexAttr(toAnimLabel(vertex), "fillcolor", "gray")
            
    def drawBuild (self, root):
        visited = [False for i in range(self.vertexc)]
        self.drawBuildDFS(root, visited)

        targets = {}
        for i in range(self.vertexc):
            targets[toAnimLabel(i)] = self.finalCoords[i]

        self.animator.moveVertices(targets)
        self.animator.sleep(50)
    
dfsanim = DFSAnimator("graph.txt", "frames", "frame")
dfsanim.drawBuild(0)