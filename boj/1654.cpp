#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;
int ans;

int main(){
    int k; cin >> k;
    int n; cin >> n;
    for( int i = 0; i < k; i ++ ){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end()); 

    //이분탐색 시작 (시간복잡도 log n)
    int left = 1, right = v[0], mid;
	
	while (left <= right)
	{
		// mid 연산
		mid = (left + right) / 2;
        
		// 몫의 합을 저장하는 변수
		int now = 0; 
        
		for (int i = 0; i < k; i++)
		{
			//mid로 나눈 몫을 저장
			now += v[i] / mid;
		}

		if (now >= n)
		{
			// 현재 mid로 나눈 값이 N보다 크거나 같다면,
			// left를 움직여 길이가 더 긴 경우는 가능한지 검사
			left = mid + 1;
            
			// N개를 만들 수 있을 때, 답을 더 큰 값으로 계속 갱신
			ans = max(ans,mid);
		}
		else
		{
			// 현재 mid로 나눈 값이 N보다 작다면,
			// right 움직여 길이가 더 짧은 경우는 가능한지 검사
			right = mid - 1;
		}
	}
	
	cout << ans << '\n';
    //이분탐색 끝
}