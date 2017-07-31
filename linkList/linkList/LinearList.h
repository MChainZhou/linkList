//
//  LinearList.h
//  LinearList
//
//  Created by apple on 2017/7/27.
//  Copyright © 2017年 apple. All rights reserved.
//

#ifndef LinearList_h
#define LinearList_h

#include <stdio.h>


#ifndef LINEARKIST_STRUCT

//数组里面的值的类型
typedef void* LinearListNodeValue;
//线性表结构体
typedef void LinearList;
#endif


/** 定义一个线性表*/
LinearList *listCreat(int capacity);
/** 释放线性表*/
void listReleas(LinearList *list);
/** 清空线性表*/
void listClear(LinearList *list);
/** 获取线性表的长度*/
int listLenght(LinearList *list);
/** 线性表新增数据*/
void listAddValue(LinearList *list,LinearListNodeValue value);
/** 线性表插入数据*/
void listInsterValue(LinearList *list,LinearListNodeValue value, int index);
/** 根据下标获取数据*/
LinearListNodeValue listGet(LinearList *list, int index);
/** 设置元素*/
void listSet(LinearList *list,int index,LinearListNodeValue value);
/** 删除元素*/
void listDele(LinearList *list,int index);
/** 删除某个值的所有数据*/
void listDeleValue(LinearList *list,LinearListNodeValue value);
#endif /* LinearList_h */
