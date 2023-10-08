using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 1LL * price * count * (count + 1) / 2;
    
    // long long answer = 0;
    // while (count--){
    //     answer += price * (count + 1);
    // }
    
    if (answer > money)
        return answer - money;
    return 0;
}
