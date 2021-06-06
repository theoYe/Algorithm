//
// Created by dell on 2021/6/6.
//

/*
 * 将字符串S传唤为整数
 */
int hashFunc(char S[], int len){
    int id =0 ;
    for(int i =0;i < len;i ++){
        if(S[i] > 'A' && S[i] <= 'Z'){
            id = id * 52 + (S[i] - 'A');
        }else if (S[i] > 'a' && S[i] <= 'z'){
            id = id * 52 + (S[i] - 'a') + 26;
        }
    }
    return id;
}
