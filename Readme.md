## 關於本項目

Ghostman is a Search Algorithm's Demo about Blind Search algorithm and Heuristic Search.


## 寫在前面

- 本項目是一個關于搜索算法的演示軟件，無任何商業用途
- 本項目爲本人本科階段一個大作業，未進行嚴格的軟件測試
- 該演示軟件使用Visual Studio 2013 進行開發，請注意編譯器的版本
- 你可以下載該演示程序的源碼，僅供學習，勿用于任何商業用途

## 軟體介面

![軟體介面](http://7xi3e9.com1.z0.glb.clouddn.com/2015-06-30_083602.jpg)

## 演算法

- 該算法演示程序主要演示如下幾個算法
	- 深度優先搜索算法（DFS）
	- 廣度優先搜索算法（BFS）
	- A星算法（A*）
	- 迭代加深的A星算法（IDA*）
	- 模擬退火算法（SA）


## 軟體使用

- 總的演示程序分爲三塊
	 - 迷宮尋路部分（用于演示BFS、DFS以及A*算法）
	 - 八數碼、井字圖部分（用于演示IDA*算法）
	 - 模擬退火部分（單獨用于演示SA算法）


##迷宮尋路部分

- 起點和終點（用于設置起點和終點）
- 直接執行（直接運行算法，幷得到路徑）
- 單步執行（單步執行算法）
- 靜態擴展（算法覆蓋範圍的靜態擴展）
- 動態擴展（算法覆蓋範圍的動態擴展）

![enter image description here](http://7xi3e9.com1.z0.glb.clouddn.com/2.PNG)

## 八數碼、井字圖部分

- 只支持執行按鈕
- 兩個演示均采用IDA*算法
- 點擊執行按鈕後，將會先進行八數碼的演示（左邊的的拼圖），然後進行井字圖的演示


![enter image description here](http://7xi3e9.com1.z0.glb.clouddn.com/3.PNG)

## 模擬退火部分 

- 只支持執行按鈕
- 紅色方塊代表火源
- 藍色點代表最安全的位置
- 最安全的位置定義爲：離火源最遠的點。（也就是和最近的那個火源的距離最大的點）
- 由于精度誤差（這裏演示轉換爲了整型變量），可能有個別點不太精確。

![enter image description here](http://7xi3e9.com1.z0.glb.clouddn.com/4.PNG)

## 開發者們

```
typedef struct WEI_LEE{
    char college[233] = "Chang'an University";
    char skill[233] = "Algorithm";
    char email[233] = "bigballon@outlook.com";
}BIGBALLON;


typedef struct JILONG_WAN{
    char college[233] = "Chang'an University";
    char skill[233] = "web";
    char email[233] = "1312369496@qq.com";
}BLong;

typedef struct SHIJIE_WENG{
    char college[233] = "Chang'an University";
    char skill[233] = "Safety";
    char email[233] = "907527136@qq.com";
}ShiningRay;

typedef struct ZUOWEN_DAI{
    char college[233] = "Chang'an University";
    char skill[233] = "C++";
    char email[233] = "270993760@qq.com";
}ZUOZUO;
```
