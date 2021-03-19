/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start

// 102/102 cases passed (64 ms)
// Your runtime beats 87.38 % of cpp submissions
// Your memory usage beats 71.57 % of cpp submissions (32.3 MB)
class ParkingSystem {
   private:
    int m_big;
    int m_medium;
    int m_small;

   public:
    ParkingSystem(int big, int medium, int small)
        : m_big(big), m_medium(medium), m_small(small) {}

    bool addCar(int carType) {
        if (carType == 1) {
            if (m_big > 0) {
                m_big -= 1;
                return true;
            }
        }
        if (carType == 2) {
            if (m_medium > 0) {
                m_medium -= 1;
                return true;
            }
        }
        if (carType == 3) {
            if (m_small > 0) {
                m_small -= 1;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end
