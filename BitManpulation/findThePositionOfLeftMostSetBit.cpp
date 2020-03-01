// Divide by 2, and keep addinf bits

int count =0;
while(n){
    n/=2;
    count++;
}

//Method2:
//simply take log of that number to get the position of MSB

int x = log(n);
