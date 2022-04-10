

int romanToInt(char * s){
    int decimals[]={1,5,10,50,100,500,1000},i,j, result,prev,current;
    char romans[]={'I','V','X','L','C','D','M'};
    for(i=0;i<strlen(s)-1;i++)
    {
        for(j=0;j<strlen(romans)-1;j++)
        {
            if (s[i]==romans[j])
            {
                break;
            }
        }
        if(i==0)
        {
            current=result=decimals[j];
        }
        else{
            current=decimals[j];
            if(prev<current){
                result = result + current-2*prev;
            }
            else
                result=result+current;
        }
        prev=current;
    }
    return result;
}
