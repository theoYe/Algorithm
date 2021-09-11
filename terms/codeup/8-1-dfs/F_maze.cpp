//
// Created by dell on 2021/9/10.
//



#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

const int direction[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
int n , m ;
int pathCount=  0;

int flag[20][20] = {false};
int path[100][2] = {0};
vector<int> start(2);
vector<int> mazeEnd(2);
int maze[1000][1000]= {0};

void printPath( vector<vector<int>> path){
    for (int i = 0; i < path.size() - 1; ++i) {
        printf("(%d,%d)->", path[i][0], path[i][1]);
    }

    auto loc = path.back();
    path.pop_back();
    printf("(%d,%d)\n", loc[0], loc[1]);
}
//void printPath( int[]   path [], int index){
//    for (int i = 0; i < index - 1; ++i) {
//        printf("(%d,%d)->", path[i][0], path[i][1]);
//    }
//
//    printf("(%d,%d)\n", loc[0], loc[1]);
//}

bool judge(int x, int y){
    //走过
    if(flag[x][y]) return false;
    //不能走
    if(maze[x][y] == 0) return  false;
    return true;
}
void DFS(vector<int> curLocation, int index){


    //递归终点
    if (curLocation[0] == mazeEnd[0] && curLocation[1] == mazeEnd[1]){
        //到了终点
        //打印路径
        pathCount++;

        for(int i =0 ; i < index - 1; i++){
            printf("(%d,%d)->",path[i][0],path[i][1]);
        }
        printf("(%d,%d)\n",path[index-1][0],path[index-1][1]);

        return ;
    }

    //分岔口
    for (int i = 0 ; i < 4 ; i ++){
        vector<int>  newLocation(2);

        newLocation[0] = curLocation[0] + direction[i][0];
        newLocation[1] = curLocation[1] + direction[i][1];

        if(judge(newLocation[0], newLocation[1])){
            flag[newLocation[0]][newLocation[1]] = true;
            //利用 index 同时还原了现场
            path[index][0] = newLocation[0];
            path[index][1] = newLocation[1];

            DFS(newLocation , index + 1);
            //递归后还原现场
            flag[newLocation[0]][newLocation[1]] = false;
        }
    }



}

//
////这么写超时的。。。不要去push path 。。。
//void dfs(vector<int> curLocation, vector<vector<int>> path){
//
//    //递归终点
//    if (curLocation[0] == mazeEnd[0] && curLocation[1] == mazeEnd[1]){
//        //到了终点
//        //打印路径
//        pathCount++;
//        printPath(path);
//        return ;
//    }
//
//    //分岔口
//    for (int i = 0 ; i < 4 ; i ++){
//        vector<int>  newLocation(2);
//        newLocation[0] = curLocation[0] + direction[i][0];
//        //   &&  (newLocation != path.top())
//        newLocation[1] = curLocation[1] + direction[i][1];
//        if( maze[newLocation[0]][newLocation[1]] ){
//            //没走过
//            if(flag[newLocation[0]][newLocation[1]] == false ){
//                flag[newLocation[0]][newLocation[1]] = true;
//                path.push_back(newLocation);
//                dfs(newLocation , path);
//                //递归后还原现场
//                path.pop_back();
//                flag[newLocation[0]][newLocation[1]] = false;
//            }
//        }
//    }
//
//
//}


//二维数组初始化？

int main(){
    while( cin >> n >> m){

        // read data
        for(int i= 1; i <= n ; i ++){
            for(int j= 1; j <=m ; j++){
                cin >> maze[i][j] ;
            }
        }
        cin >> start[0] >> start[1];
        cin >> mazeEnd[0] >> mazeEnd[1];

        if(judge(start[0] , start[1])){
            int index = 0;
            path[index][0] = start[0];
            path[index][1] = start[1];
            flag[start[0]][start[1]] = true;
            DFS(start , index+1);
            if(pathCount == 0){
                printf("-1\n");
                pathCount = 0;
            }
        }
        // 起点不能走
        else{
            printf("-1\n");
        }

    }

    return 0;
}


#if 0

2 2
1 1
1 1
1 1
2 2

2 2
1 0
0 1
1 1
2 2

2 2
0 0
0 1
1 1
2 2
#endif