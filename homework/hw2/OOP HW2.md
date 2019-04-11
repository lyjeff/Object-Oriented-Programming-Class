# OOP HW2
###### tags: `OOP` `HW`
> [color=lightblue][name=J.Y.Lin] [time=Wed, Apr 3, 2019 10:38 PM]

## Online Bipartite Matching Problem
> [color=yellow]Deadline : 2019/04/16 Tue :scream:
> :angel:Deadline: 2019/04/09 Tue

> [color=lightgreen]
> - [作業投影片](https://drive.google.com/file/d/1VWK8Y671w0VmbK7Uwt8CzW0TUZSgjuK9/view?usp=sharing)
> - 測資
>   - [範例測資input](https://drive.google.com/open?id=19VoonSAhEhoZPuA4eJbpAmf2lGLOdJje) (**random seed = ==1==**)
>   - [範例測資output](https://drive.google.com/file/d/1jtP1wCh-5gt1ApXCJ8-OcDyEpiLQSB_x/view?usp=sharing)
>   - demo測資input
>       - [request1.txt](https://drive.google.com/file/d/14411vEOxkb7CeI9syc2pfUtoehnNxbnA/view?usp=sharing)
>       - [request2.txt](https://drive.google.com/open?id=1U28GfWj_LU3a3Na_YEQFc8l5OAK7VsSS)
>       - [request3.txt](https://drive.google.com/open?id=1lA87OY-LvKq6nSKSZPL0UMDfVW0eIB_D)
>   - demo測資output
>       - from Jeff Lin (**random seed = ==1==**)
>           - [result_1.txt](https://drive.google.com/file/d/1GR03q-0oZxTaq-Hsvdty0FxmvdnpkVIs/view?usp=sharing)
>           - [result_2.txt](https://drive.google.com/file/d/1VylLeVlpBZo9PGZtufiH02SnQFmO9gDd/view?usp=sharing)
>           - [result_3.txt](https://drive.google.com/open?id=11cY6AuDNMtn8VkqzJ1NGp44zBymeB1Vo)
> - 快速連結
>   - [Input Format](#嗨，大家過得好嗎)
>   - [Output Format](#作業交出去，分數輕鬆拿，大家…做不出來…嗚嗚嗚嗚)
>   - [作業提示原文](#連連看技總複習)
>   - [作業提示翻譯](#師爺，翻譯出來給我聽，什麼他媽的叫他媽的驚喜！)
>   - [老師要求](#老師の要求des)
>   - [工具總整理](#原來是…我沒梗了)


## 嗨，大家過得好嗎
![](https://i.imgur.com/hifXOXh.png)


## 作業交出去，分數輕鬆拿，大家...做不出來...嗚嗚嗚嗚
![](https://i.imgur.com/eLOHWsO.png)


## 連連看技總複習
![](https://i.imgur.com/76tiRub.png)

### 師爺，翻譯出來給我聽，什麼他媽的叫他媽的驚喜！
- 指定算法：
    1. 對於每個時段：
    2. 為每個到達request統一隨機分配[0,1]中的值
    3. 將具有最小ID的可用resource分配給具有最大隨機值的未滿足的request
    4. 重複步驟3，直到沒有可用resource
    5. 轉到下一個時段的步驟1
- 注意：
    1. [使用default_random_engine和uniform_real_distribution](https://blog.gtwang.org/programming/cpp-random-number-generator-and-probability-distribution-tutorial/)
    2. 讓隨機種子成為主函數的參數(就是[argv](https://blog.gtwang.org/programming/c-cpp-tutorial-argc-argv-read-command-line-arguments/)的啦)
    3. 定義class Resource和Request，並使用[vector](https://mropengate.blogspot.com/2015/07/cc-vector-stl.html)儲存class Resource和Request的對象
    4. 通過push_back生成新resource和request
    5. 設計靜態成員變量和靜態成員函數來計算並獲得滿意請求的數量

### 老師の要求des
```cpp=
// You need forward declaration
class Resource
{
    int id;
    bool matched;
    int requestId;
  public:
    // constructors…
    bool operator->* (Request &b){…}
    // ->* check whether both of them are un-matched.
    // If they are, then match them and return true;
    // otherwise, return false
    // accessor
};
class Request
{
    int id;
    bool matched;
    int resourceId;
    double weight; // a random value, indicates the priority
  public:
    // constructors…
    friend class Resource;
    // accessor
};
```


## 原來是...我沒梗了
- [演算法筆記 - Matching](http://www.csie.ntnu.edu.tw/~u91029/Matching.html)
- [default_random_engine && uniform_real_distribution](https://blog.gtwang.org/programming/cpp-random-number-generator-and-probability-distribution-tutorial/)
- [Vector介紹](https://mropengate.blogspot.com/2015/07/cc-vector-stl.html)
- [Class 簡介](https://openhome.cc/Gossip/CppGossip/ClassABC.html)
- [Class 完整介紹](https://pydoing.blogspot.com/2012/10/cpp-class.html)
- DFS+精簡過的 adjacency matrix([來源 : 演算法筆記](http://www.csie.ntnu.edu.tw/~u91029/Matching.html#4))(應該用不到)
```cpp=
int nx, ny;             // X的點數目、Y的點數目
int mx[100], my[100];   // X各點的配對對象、Y各點的配對對象
bool vy[100];           // 記錄Graph Traversal拜訪過的點
bool adj[100][100];     // 精簡過的adjacency matrix
 
// 以DFS建立一棵交錯樹
bool DFS(int x)
{
    for (int y=0; y<ny; ++y)
        if (adj[x][y] && !vy[y])
        {
            vy[y] = true;
 
            // 找到擴充路徑
            if (my[y] == -1 || DFS(my[y]))
            {
                mx[x] = y; my[y] = x;
                return true;
            }
        }
    return false;
}
 
int bipartite_matching()
{
    // 全部的點初始化為未匹配點。
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));
 
    // 依序把X中的每一個點作為擴充路徑的端點，
    // 並嘗試尋找擴充路徑。
    int c = 0;
    for (int x=0; x<nx; ++x)
//      if (mx[x] == -1)    // x為未匹配點，這行可精簡。
        {
            // 開始Graph Traversal
            memset(vy, false, sizeof(vy));
            if (DFS(i)) c++;
        }
    return c;
}
```