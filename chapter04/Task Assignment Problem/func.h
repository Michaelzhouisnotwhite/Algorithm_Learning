#pragma once

#include<vector>
using namespace std;
#define MAXN 4
extern int n;
extern int c[MAXN][MAXN];
extern vector<vector<int>> ps;
void Insert(vector<int> s, int i, vector<vector<int>> &ps1);
void Perm(int n);
void Allocate(int n, int& mini, int& minc);