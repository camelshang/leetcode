// sum of two integers(not allowed to use '+' or '-')


//iteration
int getSum(int a,int b){
    while(b != 0){
        int carry = a & b;
        a ^= b;
        b = carry << 1;
    }
    return a;
}

// recursive
int getSum(int a,int b){
    if(b == 0){
        return a;
    }
    return sum(a^b, (a&b)<<1);
}