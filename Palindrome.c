bool isPalindrome(int x){
    if(x<0)return 0;
    unsigned int temp=0,org=x;
    while(x>0)
    {
        temp=(temp*10)+(x%10);
        x=x/10;
    }
    if(temp==org)return 1;
    return 0;

}
