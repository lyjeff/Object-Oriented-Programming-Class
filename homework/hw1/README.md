# OOP HW1
###### tags: `OOP` `HW`
### Flows Control

---
## Input
|Line| Content ... |
|----| ----------- |

|1.| nodes | undirectedLinks |
|--| ----- | --------------- |

|2.| linkID | firstNode | secondNode | linkCapacity |
|--| ------ | --------- | ---------- | ------------ |
...

|n.| requestFlows |
|--| ------------ |

|n+1.| flowID | sourceID | destinationID | flowSize |
| -- | ------ | -------- | ------------- | -------- |
...

---
## Output

|Line| Content ... |
|----| ----------- |

|1.| acceptedFlows | totalThroughput |
|--| ------------- | --------------- |

|2.| flowID | firstNode | secondNode | … | lastNode |
|--| ------ | --------- | ---------- | - | -------- |
...


---
## Algorithm
### ![](https://i.imgur.com/XNSOCxa.png)

---

### Dijkstra's Algorithm + Priority Queue
- [Source: 演算法筆記](http://www.csie.ntnu.edu.tw/~u91029/Path.html#6)


```c++
// 要丟進Priority Queue的點
// b是點，d是可能的最短路徑長度。
// a可以提出來，不必放在Node裡。
struct Node {int b, d;};
bool operator<(Node n1, Node n2) {return n1.d > n2.d;}
 
int w[9][9];    // adjacency matrix
int d[9];
int parent[9];
bool visit[9];
 
void dijkstra_with_priority_queue(int source)
{
    for (int i=0; i<9; i++) visit[i] = false;
    for (int i=0; i<9; i++) d[i] = 1e9;
 
    // C++ STL的Priority Queue
    priority_queue<Node> pq;
 
    d[source] = 0;
    parent[source] = source;
    pq.push((Node){source, d[source]});
 
    for (int i=0; i<9; i++)
    {
        // 找出下一個要加入到最短路徑樹的點。
        int a = -1;
        while (!pq.empty() && visit[a = pq.top().b])
            pq.pop();   // 最後少pop一次，不過無妨。
 
        if (a == -1) break;
        visit[a] = true;
 
        for (int b=0; b<9; b++)
            if (!visit[b] && d[a] + w[a][b] < d[b])
            {
                d[b] = d[a] + w[a][b];
                parent[b] = a;
                // 交由Priority Queue比較大小
                pq.push( (Node){b, d[b]} );
            }
    }
}
```
---
