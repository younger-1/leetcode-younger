// 作者：总想玩世不恭
// 链接：https://www.nowcoder.com/discuss/617638?channel=-1&source_id=profile_follow_post_nctrack
// 来源：牛客网
#include <mutex>
#include <queue>
#include <condition_variable>

using namespace std;
mutex g_mutex;
condition_variable cv;
queue<int> q;
bool flag = 0; // 0放，1取
 
int get() {
    lock_guard<mutex> mtx(g_mutex);
    cv.wait(mtx,[] {return flag==1;});
    int val = q.front();
    q.pop();
    flag = 0;
    cv.notify_one();
    return val;
}
 
void put(int val) {
    lock_guard<mutex> mtx(g_mutex);
    cv.wait(mtx,[] {return flag==0;});
    q.push(val);
    flag = 1;
    cv.notify_one();
    return;
}
