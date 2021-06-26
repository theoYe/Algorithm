//
// Created by dell on 2021/6/6.
//


/*
 * 将字符串S转换为整数
 */
int hashFunc(char S[], int len){
    int id =0 ;
    for(int i =0;i < len;i ++){
        if(S[i] > 'A' && S[i] <= 'Z'){
            id = id * 62 + (S[i] - 'A');
        }else if (S[i] > 'a' && S[i] <= 'z'){
            id = id * 62 + (S[i] - 'a') + 26;
        }else if (S[i] >= 0 && S[i] <= 9){
            // 数字
            id = id * 62 + S[i] + 52;
        }
    }
    return id;
}

int main(){



    return 0;
}