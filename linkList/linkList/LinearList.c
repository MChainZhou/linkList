//
//  LinearList.c
//  LinearList
//
//  Created by apple on 2017/7/27.
//  Copyright © 2017年 apple. All rights reserved.
//

typedef void * LinearListNodeValue;

// 节点结构体
typedef struct _LinearListNodeValue LinearListNode;

struct _LinearListNodeValue{
    LinearListNodeValue value;
    LinearListNode *next;
};

//数组结构体->链表
typedef struct {
    int length;
    LinearListNode* header;//指向头节点
}LinearList;

#define LINEARKIST_STRUCT

#include "LinearList.h"
#include <stdlib.h>
#include <string.h>


//定义一个函数创建线性表
LinearList *listCreat(int capacity){
    if (capacity < 0) {
        return NULL;
    }
    LinearList * list = malloc(sizeof(LinearList) + sizeof(LinearListNode));
    //当内存不够的时候有可能创建失败
    if (list) {
        list->length = 0;
        list->header = (LinearListNode *)(list + 1);
        list->header->next = NULL;
    }
    
    return list;
}


/** 释放线性表*/
void listReleas(LinearList *list){
    if (list == NULL) {
        return;
    }
    //清空线性表
    listClear(list);
    free(list);
}

/** 清空线性表*/
void listClear(LinearList *list){
    if (list == NULL) {
        return;
    }
    //拿到表头
    LinearListNode *header = list->header;
    while (header) {
        //要删除的节点
        LinearListNode *removeNode = header->next;
        if (removeNode == NULL) break;
        header->next = removeNode->next;
        free(removeNode);
        removeNode = NULL;
    }
    list->length = 0;
}

/** 获取线性表的长度*/
int listLenght(LinearList *list){
    if (list == NULL) {
        return 0;
    }
    
    return list->length;
}

/** 根据下标获取数据*/
LinearListNodeValue listGet(LinearList *list, int index){
    if (list == NULL || index < 0 || index >= list->length) {
        return 0;
    }
    //拿到头节点
    LinearListNode *header = list->header;
    for (int i = 0; i <= index; i ++) {
        header = header->next;
    }
    
    return header->value;
}

/** 线性表插入数据*/
void listInsterValue(LinearList *list,LinearListNodeValue value, int index){
    if (list == NULL || index < 0 || index > list->length) {
        return;
    }
    
    //拿到头节点
    LinearListNode *currentNode = list->header;
    //拿到要插入的位置的前一个节点
    for (int i = 0; i < index; i ++) {
        currentNode = currentNode->next;
    }
    //创建一个新节点
    LinearListNode *newNode = malloc(sizeof(LinearListNode));
    if (newNode == NULL) return;
    newNode->value = value;
    newNode->next = currentNode->next;//插入节点的下一个节点赋值
    
    currentNode->next = newNode;//将新增节点的地址给index-1节点的next
    //数量增加
    list->length ++;
    
}

/** 线性表新增数据*/
void listAddValue(LinearList *list,LinearListNodeValue value){
    listInsterValue(list, value, list->length);
}

/** 设置元素*/
void listSet(LinearList *list,int index,LinearListNodeValue value){
    if (list == NULL || index < 0 || index > list->length -1) {
        return;
    }
    //拿到头节点
    LinearListNode *currentNode = list->header;
    for (int i = 0; i <= index; i ++) {
        currentNode = currentNode->next;
    }
    currentNode->value = value;
    
}
/** 删除元素*/
void listDele(LinearList *list,int index){
    if (list == NULL || index < 0 || index > list->length -1) {
        return;
    }
    
    //拿到头节点
    LinearListNode *currentNode = list->header;
    //拿到要删除的节点的上一个节点
    for (int i = 0; i < index; i ++) {
        currentNode = currentNode->next;
    }
    //得到要删除的节点
    LinearListNode *removeNode = currentNode->next;
    currentNode->next = removeNode->next;
    //释放要删除的节点
    free(removeNode);
    list->length --;
}


/** 删除某个值的所有数据*/
void listDeleValue(LinearList *list,LinearListNodeValue value){
    if (list == NULL) {
        return;
    }
    
    //拿到头节点
    LinearListNode *currentNode = list->header;
    while (currentNode) {
        //
        LinearListNode *nextNode = currentNode->next;
        if (nextNode == NULL) return;
        if (currentNode->value == value) {//删除
            currentNode->next = currentNode->next;
            //释放
            free(currentNode);
            list->length -= 1;
        }else{//不用删除
            currentNode = nextNode;
        }
    }
}


