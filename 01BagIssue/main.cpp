//
//  main.cpp
//  01BagIssue
//
//  Created by Wesrindo on 2019/11/28.
//  Copyright © 2019 Wesrindo. All rights reserved.
//
//ADD SOMETHING//////
#include <iostream>

#define GOOD_NUM 4//可选物品数量
#define BAG_CAPA 30//背包的容量

int weight[GOOD_NUM] = {12,8,9,5};//数组存储物品的重量
int value[GOOD_NUM] = {15,10,12,8};//数组存储物品的价值

int max_value = 0;//保存最大值
bool max_choice[GOOD_NUM] = {0,0,0,0};//保存最佳组合 0代表没选 1代表选了

using namespace std;
int main(int argc, const char * argv[]) {
    for (int i = 0; i < GOOD_NUM; i++) {//从选择第0个开始
        int current_value = 0;
        int current_weight = 0;
        bool current_choice[GOOD_NUM] = {0,0,0,0};
        for (int j = i; j < GOOD_NUM; j++) {
            if (current_weight + weight[j] <= BAG_CAPA){
                current_weight += weight[j];
                current_value += value[j];
                current_choice[j] = 1;
            }
        }
        if (current_value >= max_value){
            max_value = current_value;
            memcpy(max_choice, current_choice, GOOD_NUM);
        }
    }
    cout << "max value =" << max_value << endl;
    for (int i = 0 ; i < GOOD_NUM; i++) {
        cout << max_choice[i] << "\t" ;
    }
    cout << endl;
    return 0;
}
