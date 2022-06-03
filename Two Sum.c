/* Problem: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order. */



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* data=NULL;
int cmp(const void* a, const void* b)
{
    return data[*(int*)a] - data[*(int*)b];
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
//int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int l, r, vl, vr;
    int* ix  = (int*)malloc(numsSize * sizeof(int));
    int* res = (int*)malloc(2 * sizeof(int));
    for(r = 0; r < numsSize; r++)
        ix[r] = r;
    
    data = nums;    
    qsort(ix, numsSize, sizeof(int), cmp); // sort indexes by value
    vl=nums[ix[0]], vr=nums[ix[numsSize-1]];
    
    for(l = 0, r = numsSize-1; l < r && vl + vr != target; )
    {
        if(vl + vr > target) { r--; vr = nums[ix[r]]; }
        else                 { l++; vl = nums[ix[l]]; }
    }
    res[0] = ix[l]; 
    res[1] = ix[r];
    *returnSize = 2;
    free(ix);
    return res;
}
