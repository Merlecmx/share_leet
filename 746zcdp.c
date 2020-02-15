int min(int f1, int f2){
    return f1 > f2 ? f2 : f1;
}

int minCostClimbingStairs(int* cost, int costSize){
    int f1 = 0, f2 = 0;
    for (int i = costSize - 1; i >= 0; i--) {
        int f0 = cost[i] + min(f1, f2);//f1,f2分别代表cost[i+1],cost[i+2]
        f2 = f1;
        f1 = f0;
    }
    return min(f1, f2);
}
