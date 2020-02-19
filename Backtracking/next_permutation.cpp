
void func(string s){

    int arr[] = {3,1,2 };

    // next_permutation return true  the next_permuatation in lexicographical order is possible and also it performs the permuatations, if it is not  possible(netx is lesser tah pervios, although it converts next into smallest), it returns false

    sort(arr, arr+3);

    do{

        cout<<arr[0]<<arr[1]<<arr[2];
    }while(next_permutation(arr, arr+n))
}