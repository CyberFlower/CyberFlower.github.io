---
layout: post
title: Knuth DP Optimization
subtitle: Knuth DP Optimization 알고리즘
date: 2019-07-25
categories: Algorithm
tags: Algorithm
author: Miryu
---

DP Optimization은 DP 점화식이 어떠한 특정 조건을 만족할 경우 시간복잡도를 줄여줄 수 있는 기법이다.
유명한 DP Optimization기법에는 Knuth Optimization, Divide & Conquer Optimization, Convex Hull Optimization(Convex Hull Trick) 이 있는데, 이 글에서는 Knuth Optimization만 다루고, 나머지는 다른 게시물에서 소개하도록 하겠다.

### 1. 예시 문제: 파일 합치기 2(BOJ 13974)
https: /www.acmicpc.net/problem/13974

파일 합치기(BOJ 11066) 문제에서는 $K$가 최대 500이므로, $O(K^{3})$의 시간복잡도로 해결할 수 있다.
그러나 이 문제에서는 $K$가 최대 5000이므로, $O(K^{3})$의 시간복잡도로는 TLE가 나게 된다.

### 2. Knuth Optimization의 조건과 최적화
Knuth Optimization은 점화식이 다음과 같은 조건을 만족할 때 사용할 수 있다.

조건 1)
$DP[i][j]=min_{i<k<j}(DP[i][k]+DP[k][j])+C[i][j]$

조건 2)
$a \le b \le c \le d$ 일때 $C[a][c]+C[b][d] \le C[a][d]+C[b][c]$ 를 만족한다.

조건 3)
$a \le b \le c \le d$ 일때 $C[b][c] \le C[a][d]$ 를 만족한다.

이 세 조건을 만족하면, $DP[i][j]=min_{i<k<j}(DP[i][k]+DP[k][j])+C[i][j]$ 에서 $DP[i][j]$를 최소로 만드는 k를 $KN[i][j]$라고 하면 $KN[i][j-1] \le KN[i][j] \le KN[i+1][j]$를 만족한다.

따라서 이를 이용하면 $O(N^{3})$의 DP를 $O(N^{2})$까지 줄일 수 있다.

구현 Tip. $KN[i][j-1] \le KN[i][j] \le KN[i+1][j]$ 의 조건을 활용하기 위해서,
DP[i][j]를 채우는 순서를 i와 j의 차이가 커지는 방향으로 진행해야 한다.

### 3. Knuth Optimization의 사용

우선 파일 합치기 문제를 $O(K^{3})$로 해결할 때 사용했던 점화식을 다시 한 번 살펴보자.
$DP[i][j]$=i번부터 j번까지를 합치는 데에 드는 비용으로 정의하면, $DP[i][j]=min(DP[i][k]+DP[k+1][j])(i \le k < j) + (\sum_{p=i}^{j} {C_{p}})$ 의 식이 된다.

우선 $\sum_{p=i}^{j} {C_{p}}$를 $S[i][j]$라고 생각하면 이 S[i][j]는 조건 2와 조건 3을 만족한다.
조건 1을 만족시키기 위해 $DP[i][j]$=i+1번부터 j번까지를 합치는 데에 드는 비용으로 재정의하면,
$DP[i][j]=min_{i<k<j}(DP[i][k]+DP[k][j])+S[i+1][j]$ 이라는 점화식이 나오고, 이는 Knuth Optimization의
세 가지 조건을 모두 만족하므로, $O(K^{2})$까지 시간복잡도를 줄일 수 있다.

코드는 다음과 같다.

```cpp
#include<bits/stdc++.h>
#define oo 1987654321
using namespace std;
int C[5555], S[5555], DP[5555][5555], KN[5555][5555];
int main(void)
{
	int T;
 	scanf("%d",&T);
  	while(T--)
  	{
    	int K;
    	scanf("%d",&K);
    	for(int i=1;i<=K;i++)
    	{
    		scanf("%d",&C[i]);
    		S[i]=S[i-1]+C[i]; // 본문에서의 S[i+1][j]= 코드에서의 S[j]-S[i]
		}
		for(int i=0;i<K;i++)
		{
			DP[i][i+1]=0;
			KN[i][i+1]=i+1;
		}
		for(int d=2;d<=K;d++)for(int i=0;i+d<=K;i++)
		{
			int j=i+d;
			DP[i][j]=oo;
			for(int k=KN[i][j-1];k<=KN[i+1][j];k++)
			{
				int tmp=DP[i][k]+DP[k][j]+S[j]-S[i];
				if(DP[i][j]>tmp) DP[i][j]=tmp, KN[i][j]=k;
			}
		}
		printf("%d\n",DP[0][K]);
  	}
  	return 0;
}
```

### 4. 추가 팁
만약 $DP[i][j]=min_{i<k<j}(DP[i][k]+DP[k][j])+C[i][j]$이 아닌, $DP[i][j]=max_{i<k<j}(DP[i][k]+DP[k][j])+C[i][j]$ 형태의 점화식이 나왔다면,
$nDP[i][j]=-DP[i][j]$로 바꿔주어
$$nDP[i][j]=max_{i<k<j}(nDP[i][k]+nDP[k][j])-C[i][j]$$
가 된다.
이 때, -C[i][j]가 조건 2와 3을 만족한다면, Knuth Optimization을 사용할 수 있다.
